#include "StateEvents.h"

bool StateEvents::SetStateVendorStr(StateEvtVendor_t &state_evt)
{
	switch (state_evt.StVnd) {

	case static_cast<uint16_t>(StatesVendor::I_STATUS_OFF):
		state_evt.StVndStr = "Off";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_SLEEPING):
		state_evt.StVndStr = "Sleeping (auto-shutdown)";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_STARTING):
		state_evt.StVndStr = "Starting up";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_MPPT):
		state_evt.StVndStr = "Tracking power point";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_THROTTLED):
		state_evt.StVndStr = "Forced power reduction";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_SHUTTING_DOWN):
		state_evt.StVndStr = "Shutting down";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_FAULT):
		state_evt.StVndStr = "One or more faults exist";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_STANDBY):
		state_evt.StVndStr = "Standby (service on unit)*might be in Events";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_NO_BUSINIT):
		state_evt.StVndStr = "No SolarNet communication";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_NO_COMM_INV):
		state_evt.StVndStr = "No communication with inverter";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_SN_OVERCURRENT):
		state_evt.StVndStr = "Overcurrent on SolarNet plug detected";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_BOOTLOAD):
		state_evt.StVndStr = "Inverter is being updated";
		break;
	case static_cast<uint16_t>(StatesVendor::I_STATUS_AFCI):
		state_evt.StVndStr = "AFCI Event";
		break;
	default:
		return false;
	}

	return true;
}

bool StateEvents::SetEventVendorStr(StateEvtVendor_t &state_evt)
{
	if (!state_evt.EvtVnd1) {
		return true;
	} else if ((state_evt.EvtVnd1 >> 0) & 1) {
		state_evt.EvtVndStr = "DC Insulation fault";
	} else if ((state_evt.EvtVnd1 >> 1) & 1) {
		state_evt.EvtVndStr = "Grid error";
	} else if ((state_evt.EvtVnd1 >> 2) & 1) {
		state_evt.EvtVndStr = "Overcurrent AC";
	} else if ((state_evt.EvtVnd1 >> 3) & 1) {
		state_evt.EvtVndStr = "Overcurrent DC";
	} else if ((state_evt.EvtVnd1 >> 4) & 1) {
		state_evt.EvtVndStr = "Over-temperature";
	} else if ((state_evt.EvtVnd1 >> 5) & 1) {
		state_evt.EvtVndStr = "Power low";
	} else if ((state_evt.EvtVnd1 >> 6) & 1) {
		state_evt.EvtVndStr = "DC low";
	} else if ((state_evt.EvtVnd1 >> 7) & 1) {
		state_evt.EvtVndStr = "Intermediate circuit error";
	} else if ((state_evt.EvtVnd1 >> 8) & 1) {
		state_evt.EvtVndStr = "AC frequency too high";
	} else if ((state_evt.EvtVnd1 >> 9) & 1) {
		state_evt.EvtVndStr = "AC frequency too low";
	} else if ((state_evt.EvtVnd1 >> 10) & 1) {
		state_evt.EvtVndStr = "AC voltage too high";
	} else if ((state_evt.EvtVnd1 >> 11) & 1) {
		state_evt.EvtVndStr = "AC voltage too low";
	} else if ((state_evt.EvtVnd1 >> 12) & 1) {
		state_evt.EvtVndStr = "Direct current feed in";
	} else if ((state_evt.EvtVnd1 >> 13) & 1) {
		state_evt.EvtVndStr = "Relay problem";
	} else if ((state_evt.EvtVnd1 >> 14) & 1) {
		state_evt.EvtVndStr = "Internal power stage error";
	} else if ((state_evt.EvtVnd1 >> 15) & 1) {
		state_evt.EvtVndStr = "Control problems";
	} else if ((state_evt.EvtVnd1 >> 16) & 1) {
		state_evt.EvtVndStr = "Guard Controller - AC voltage error";
	} else if ((state_evt.EvtVnd1 >> 17) & 1) {
		state_evt.EvtVndStr = "Guard Controller - AC Frequency Error";
	} else if ((state_evt.EvtVnd1 >> 18) & 1) {
		state_evt.EvtVndStr = "Energy transfer not possible";
	} else if ((state_evt.EvtVnd1 >> 19) & 1) {
		state_evt.EvtVndStr = "Reference power source AC outside tolerances";
	} else if ((state_evt.EvtVnd1 >> 20) & 1) {
		state_evt.EvtVndStr = "Error during anti islanding test";
	} else if ((state_evt.EvtVnd1 >> 21) & 1) {
		state_evt.EvtVndStr = "Fixed voltage lower than current MPP voltage";
	} else if ((state_evt.EvtVnd1 >> 22) & 1) {
		state_evt.EvtVndStr = "Memory fault";
	} else if ((state_evt.EvtVnd1 >> 23) & 1) {
		state_evt.EvtVndStr = "Display";
	} else if ((state_evt.EvtVnd1 >> 24) & 1) {
		state_evt.EvtVndStr = "Internal communication error";
	} else if ((state_evt.EvtVnd1 >> 25) & 1) {
		state_evt.EvtVndStr = "Temperature sensors defective";
	} else if ((state_evt.EvtVnd1 >> 26) & 1) {
		state_evt.EvtVndStr = "DC or AC board fault";
	} else if ((state_evt.EvtVnd1 >> 27) & 1) {
		state_evt.EvtVndStr = "ENS error";
	} else if ((state_evt.EvtVnd1 >> 28) & 1) {
		state_evt.EvtVndStr = "Fan error";
	} else if ((state_evt.EvtVnd1 >> 29) & 1) {
		state_evt.EvtVndStr = "Defective fuse";
	} else if ((state_evt.EvtVnd1 >> 30) & 1) {
		state_evt.EvtVndStr = "Output choke connected to wrong poles";
	} else if ((state_evt.EvtVnd1 >> 31) & 1) {
		state_evt.EvtVndStr = "The buck converter relay does not open at high DC voltage";
	} else {
		return false;
	}

	if (!state_evt.EvtVnd1) {
		return true;
	} else if ((state_evt.EvtVnd2 >> 0) & 1) {
		state_evt.EvtVndStr = "No SolarNet communication";
	} else if ((state_evt.EvtVnd2 >> 1) & 1) {
		state_evt.EvtVndStr = "Inverter address incorrect";
	} else if ((state_evt.EvtVnd2 >> 2) & 1) {
		state_evt.EvtVndStr = "24h no feed in";
	} else if ((state_evt.EvtVnd2 >> 3) & 1) {
		state_evt.EvtVndStr = "Faulty plug connections";
	} else if ((state_evt.EvtVnd2 >> 4) & 1) {
		state_evt.EvtVndStr = "Incorrect phase allocation";
	} else if ((state_evt.EvtVnd2 >> 5) & 1) {
		state_evt.EvtVndStr = "Grid conductor open or supply phase has failed";
	} else if ((state_evt.EvtVnd2 >> 6) & 1) {
		state_evt.EvtVndStr = "Incompatible or old software";
	} else if ((state_evt.EvtVnd2 >> 7) & 1) {
		state_evt.EvtVndStr = "Power derating due to overtemperature";
	} else if ((state_evt.EvtVnd2 >> 8) & 1) {
		state_evt.EvtVndStr = "Jumper set incorrectly";
	} else if ((state_evt.EvtVnd2 >> 9) & 1) {
		state_evt.EvtVndStr = "Incompatible feature";
	} else if ((state_evt.EvtVnd2 >> 10) & 1) {
		state_evt.EvtVndStr = "Defective ventilator/air vents blocked";
	} else if ((state_evt.EvtVnd2 >> 11) & 1) {
		state_evt.EvtVndStr = "Power reduction on error";
	} else if ((state_evt.EvtVnd2 >> 12) & 1) {
		state_evt.EvtVndStr = "Arc detected";
	} else if ((state_evt.EvtVnd2 >> 13) & 1) {
		state_evt.EvtVndStr = "AFCI self test failed";
	} else if ((state_evt.EvtVnd2 >> 14) & 1) {
		state_evt.EvtVndStr = "Current sensor error";
	} else if ((state_evt.EvtVnd2 >> 15) & 1) {
		state_evt.EvtVndStr = "DC switch fault";
	} else if ((state_evt.EvtVnd2 >> 16) & 1) {
		state_evt.EvtVndStr = "AFCI defective";
	} else if ((state_evt.EvtVnd2 >> 17) & 1) {
		state_evt.EvtVndStr = "AFCI manual test successful";
	} else if ((state_evt.EvtVnd2 >> 18) & 1) {
		state_evt.EvtVndStr = "Power stack supply missing";
	} else if ((state_evt.EvtVnd2 >> 19) & 1) {
		state_evt.EvtVndStr = "AFCI communication stopped";
	} else if ((state_evt.EvtVnd2 >> 20) & 1) {
		state_evt.EvtVndStr = "AFCI manual test failed";
	} else if ((state_evt.EvtVnd2 >> 21) & 1) {
		state_evt.EvtVndStr = "AC polarity reversed";
	} else if ((state_evt.EvtVnd2 >> 22) & 1) {
		state_evt.EvtVndStr = "AC measurement device fault";
	} else if ((state_evt.EvtVnd2 >> 23) & 1) {
		state_evt.EvtVndStr = "Flash fault";
	} else if ((state_evt.EvtVnd2 >> 24) & 1) {
		state_evt.EvtVndStr = "General error";
	} else if ((state_evt.EvtVnd2 >> 25) & 1) {
		state_evt.EvtVndStr = "Grounding fault";
	} else if ((state_evt.EvtVnd2 >> 26) & 1) {
		state_evt.EvtVndStr = "Power limitation fault";
	} else if ((state_evt.EvtVnd2 >> 27) & 1) {
		state_evt.EvtVndStr = "External NO contact open";
	} else if ((state_evt.EvtVnd2 >> 28) & 1) {
		state_evt.EvtVndStr = "External overvoltage protection has tripped";
	} else if ((state_evt.EvtVnd2 >> 29) & 1) {
		state_evt.EvtVndStr = "Internal processor program status";
	} else if ((state_evt.EvtVnd2 >> 30) & 1) {
		state_evt.EvtVndStr = "SolarNet issue";
	} else if ((state_evt.EvtVnd2 >> 31) & 1) {
		state_evt.EvtVndStr = "Supply voltage fault";
	} else {
		return false;
	}

	if (!state_evt.EvtVnd1) {
		return true;
	} else if ((state_evt.EvtVnd3 >> 0) & 1) {
		state_evt.EvtVndStr = "Time error";
	} else if ((state_evt.EvtVnd3 >> 1) & 1) {
		state_evt.EvtVndStr = "USB error";
	} else if ((state_evt.EvtVnd3 >> 2) & 1) {
		state_evt.EvtVndStr = "DC high";
	} else if ((state_evt.EvtVnd3 >> 3) & 1) {
		state_evt.EvtVndStr = "Init error";
	} else {
		return false;
	}

	return true;
}
