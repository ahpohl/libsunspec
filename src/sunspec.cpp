#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <modbus/modbus.h>

#include "sunspec.h"
#include "common.h"
#include "inverter.h"

int get_manufacturer(modbus_t *ctx, char *mfg)
{
	uint16_t tab_reg[16];

	int rc = modbus_read_registers(ctx, C001_ADDR_Mn, C001_SIZE_Mn, tab_reg);
	if (rc == -1) {
		fprintf(stderr, "%s\n", modbus_strerror(errno));
		return -1;
	}

	mfg = (char*) malloc(sizeof(char) * 33);
	if (mfg == NULL) {
		printf("Error! memory not allocated.");
		return -1;
	}
	memset(mfg, 0, sizeof(char) * 33);
	char *ptr = mfg;

	for (int i=0; i < rc; i++) {
		char lb = (char) ((tab_reg[i] >> 8) & 0xFF);
		memcpy(ptr, &lb, 1);
		++ptr;
		char hb = (char) tab_reg[i];
		memcpy(ptr, &hb, 1);
		++ptr;
	}
	*ptr = '\0';
	printf("Manufacturer: %s\n", mfg);

	return 0;
}

int get_ac_power(modbus_t *ctx, double *ac_power)
{
	uint16_t ac_power_reg;
	int rc = modbus_read_registers(ctx, 40083, 1, &ac_power_reg);
	if (rc == -1) {
		fprintf(stderr, "%s\n", modbus_strerror(errno));
		return -1;
	}

	*ac_power = (double) ac_power_reg * 0.1;
	printf("AC power now: %.0f W\n", *ac_power);

	return 0;
}

int main(int argc, char **argv)
{
	const int REMOTE_ID = 1;
	modbus_t *ctx;

	ctx = modbus_new_rtu("/dev/serial/by-id/usb-FTDI_FT232R_USB_UART_AC009Y6C-if00-port0", 9600, 'N', 8, 1);
	if (ctx == NULL) {
		fprintf(stderr, "Unable to create the libmodbus context\n");
		return -1;
	}

	if (modbus_connect(ctx) == -1) {
		fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
		modbus_free(ctx);
		return -1;
	}

	//modbus_set_debug(ctx, true);

	if (modbus_set_slave(ctx, REMOTE_ID) == -1) {
		fprintf(stderr, "Invalid slave ID\n");
		modbus_free(ctx);
		return -1;
	}

	modbus_close(ctx);
	modbus_free(ctx);

	return 0;
}
