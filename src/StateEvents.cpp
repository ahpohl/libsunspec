#include "StateEvents.h"

bool StateEvents::SetStateStr(StateEvt_t &state_evt)
{
	switch (state_evt.St) {

	case static_cast<uint16_t>(OpState::I_STATUS_OFF):
		state_evt.StStr = "Off";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_SLEEPING):
		state_evt.StStr = "Sleeping (auto-shutdown)";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_STARTING):
		state_evt.StStr = "Starting up";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_MPPT):
		state_evt.StStr = "Tracking power point";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_THROTTLED):
		state_evt.StStr = "Forced power reduction";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_SHUTTING_DOWN):
		state_evt.StStr = "Shutting down";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_FAULT):
		state_evt.StStr = "One or more faults exist";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_STANDBY):
		state_evt.StStr = "Standby (service on unit) *might be in Events";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_NO_BUSINIT):
		state_evt.StStr = "No SolarNet communication";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_NO_COMM_INV):
		state_evt.StStr = "No communication with inverter";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_SN_OVERCURRENT):
		state_evt.StStr = "Overcurrent on SolarNet plug detected";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_BOOTLOAD):
		state_evt.StStr = "Inverter is being updated";
		break;
	case static_cast<uint16_t>(OpState::I_STATUS_AFCI):
		state_evt.StStr = "AFCI Event";
		break;
	default:
		return false;
	}

	return true;
}

bool StateEvents::SetEventStr(StateEvt_t &state_evt)
{
	if (!state_evt.Evt1) {
		return true;
	} else if ((state_evt.Evt1 >> 0) & 1) {
		state_evt.EvtStr = "DC Insulation fault";
	} else if ((state_evt.Evt1 >> 1) & 1) {
		state_evt.EvtStr = "Grid error";
	} else if ((state_evt.Evt1 >> 2) & 1) {
		state_evt.EvtStr = "Overcurrent AC";
	} else if ((state_evt.Evt1 >> 3) & 1) {
		state_evt.EvtStr = "Overcurrent DC";
	} else if ((state_evt.Evt1 >> 4) & 1) {
		state_evt.EvtStr = "Overtemperature";
	} else if ((state_evt.Evt1 >> 5) & 1) {
		state_evt.EvtStr = "Power low";
	} else if ((state_evt.Evt1 >> 6) & 1) {
		state_evt.EvtStr = "DC low";
	} else if ((state_evt.Evt1 >> 7) & 1) {
		state_evt.EvtStr = "Intermediate circuit error";
	} else if ((state_evt.Evt1 >> 8) & 1) {
		state_evt.EvtStr = "AC frequency too high";
	} else if ((state_evt.Evt1 >> 9) & 1) {
		state_evt.EvtStr = "AC frequency too low";
	} else if ((state_evt.Evt1 >> 10) & 1) {
		state_evt.EvtStr = "AC voltage too high";
	} else if ((state_evt.Evt1 >> 11) & 1) {
		state_evt.EvtStr = "AC voltage too low";
	} else if ((state_evt.Evt1 >> 12) & 1) {
		state_evt.EvtStr = "Direct current feed in";
	} else if ((state_evt.Evt1 >> 13) & 1) {
		state_evt.EvtStr = "Relay problem";
	} else if ((state_evt.Evt1 >> 14) & 1) {
		state_evt.EvtStr = "Internal power stage error";
	} else if ((state_evt.Evt1 >> 15) & 1) {
		state_evt.EvtStr = "Control problems";
	} else if ((state_evt.Evt1 >> 16) & 1) {
		state_evt.EvtStr = "Guard Controller - AC voltage error";
	} else if ((state_evt.Evt1 >> 17) & 1) {
		state_evt.EvtStr = "Guard Controller - AC Frequency Error";
	} else if ((state_evt.Evt1 >> 18) & 1) {
		state_evt.EvtStr = "Energy transfer not possible";
	} else if ((state_evt.Evt1 >> 19) & 1) {
		state_evt.EvtStr = "Reference power source AC outside tolerances";
	} else if ((state_evt.Evt1 >> 20) & 1) {
		state_evt.EvtStr = "Error during anti islanding test";
	} else if ((state_evt.Evt1 >> 21) & 1) {
		state_evt.EvtStr = "Fixed voltage lower than current MPP voltage";
	} else if ((state_evt.Evt1 >> 22) & 1) {
		state_evt.EvtStr = "Memory fault";
	} else if ((state_evt.Evt1 >> 23) & 1) {
		state_evt.EvtStr = "Display";
	} else if ((state_evt.Evt1 >> 24) & 1) {
		state_evt.EvtStr = "Internal communication error";
	} else if ((state_evt.Evt1 >> 25) & 1) {
		state_evt.EvtStr = "Temperature sensors defective";
	} else if ((state_evt.Evt1 >> 26) & 1) {
		state_evt.EvtStr = "DC or AC board fault";
	} else if ((state_evt.Evt1 >> 27) & 1) {
		state_evt.EvtStr = "ENS error";
	} else if ((state_evt.Evt1 >> 28) & 1) {
		state_evt.EvtStr = "Fan error";
	} else if ((state_evt.Evt1 >> 29) & 1) {
		state_evt.EvtStr = "Defective fuse";
	} else if ((state_evt.Evt1 >> 30) & 1) {
		state_evt.EvtStr = "Output choke connected to wrong poles";
	} else if ((state_evt.Evt1 >> 31) & 1) {
		state_evt.EvtStr = "The buck converter relay does not open at high DC voltage";
	} else {
		return false;
	}

	if (!state_evt.Evt2) {
		return true;
	} else if ((state_evt.Evt2 >> 0) & 1) {
		state_evt.EvtStr = "No SolarNet communication";
	} else if ((state_evt.Evt2 >> 1) & 1) {
		state_evt.EvtStr = "Inverter address incorrect";
	} else if ((state_evt.Evt2 >> 2) & 1) {
		state_evt.EvtStr = "24h no feed in";
	} else if ((state_evt.Evt2 >> 3) & 1) {
		state_evt.EvtStr = "Faulty plug connections";
	} else if ((state_evt.Evt2 >> 4) & 1) {
		state_evt.EvtStr = "Incorrect phase allocation";
	} else if ((state_evt.Evt2 >> 5) & 1) {
		state_evt.EvtStr = "Grid conductor open or supply phase has failed";
	} else if ((state_evt.Evt2 >> 6) & 1) {
		state_evt.EvtStr = "Incompatible or old software";
	} else if ((state_evt.Evt2 >> 7) & 1) {
		state_evt.EvtStr = "Power derating due to overtemperature";
	} else if ((state_evt.Evt2 >> 8) & 1) {
		state_evt.EvtStr = "Jumper set incorrectly";
	} else if ((state_evt.Evt2 >> 9) & 1) {
		state_evt.EvtStr = "Incompatible feature";
	} else if ((state_evt.Evt2 >> 10) & 1) {
		state_evt.EvtStr = "Defective ventilator/air vents blocked";
	} else if ((state_evt.Evt2 >> 11) & 1) {
		state_evt.EvtStr = "Power reduction on error";
	} else if ((state_evt.Evt2 >> 12) & 1) {
		state_evt.EvtStr = "Arc detected";
	} else if ((state_evt.Evt2 >> 13) & 1) {
		state_evt.EvtStr = "AFCI self test failed";
	} else if ((state_evt.Evt2 >> 14) & 1) {
		state_evt.EvtStr = "Current sensor error";
	} else if ((state_evt.Evt2 >> 15) & 1) {
		state_evt.EvtStr = "DC switch fault";
	} else if ((state_evt.Evt2 >> 16) & 1) {
		state_evt.EvtStr = "AFCI defective";
	} else if ((state_evt.Evt2 >> 17) & 1) {
		state_evt.EvtStr = "AFCI manual test successful";
	} else if ((state_evt.Evt2 >> 18) & 1) {
		state_evt.EvtStr = "Power stack supply missing";
	} else if ((state_evt.Evt2 >> 19) & 1) {
		state_evt.EvtStr = "AFCI communication stopped";
	} else if ((state_evt.Evt2 >> 20) & 1) {
		state_evt.EvtStr = "AFCI manual test failed";
	} else if ((state_evt.Evt2 >> 21) & 1) {
		state_evt.EvtStr = "AC polarity reversed";
	} else if ((state_evt.Evt2 >> 22) & 1) {
		state_evt.EvtStr = "AC measurement device fault";
	} else if ((state_evt.Evt2 >> 23) & 1) {
		state_evt.EvtStr = "Flash fault";
	} else if ((state_evt.Evt2 >> 24) & 1) {
		state_evt.EvtStr = "General error";
	} else if ((state_evt.Evt2 >> 25) & 1) {
		state_evt.EvtStr = "Grounding fault";
	} else if ((state_evt.Evt2 >> 26) & 1) {
		state_evt.EvtStr = "Power limitation fault";
	} else if ((state_evt.Evt2 >> 27) & 1) {
		state_evt.EvtStr = "External NO contact open";
	} else if ((state_evt.Evt2 >> 28) & 1) {
		state_evt.EvtStr = "External overvoltage protection has tripped";
	} else if ((state_evt.Evt2 >> 29) & 1) {
		state_evt.EvtStr = "Internal processor program status";
	} else if ((state_evt.Evt2 >> 30) & 1) {
		state_evt.EvtStr = "SolarNet issue";
	} else if ((state_evt.Evt2 >> 31) & 1) {
		state_evt.EvtStr = "Supply voltage fault";
	} else {
		return false;
	}

	if (!state_evt.Evt3) {
		return true;
	} else if ((state_evt.Evt3 >> 0) & 1) {
		state_evt.EvtStr = "Time error";
	} else if ((state_evt.Evt3 >> 1) & 1) {
		state_evt.EvtStr = "USB error";
	} else if ((state_evt.Evt3 >> 2) & 1) {
		state_evt.EvtStr = "DC high";
	} else if ((state_evt.Evt3 >> 3) & 1) {
		state_evt.EvtStr = "Init error";
	} else {
		return false;
	}

	return true;
}
