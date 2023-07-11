#include "StateEvents.h"

bool StateEvents::SetStateEventsStr(StateEvt_t &state_evt)
{
	switch (state_evt.St)
	{
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
		state_evt.StStr = "Standby";
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
		ErrorStr = std::string("Invalid operating state (") + std::to_string(state_evt.St) + ")";
		return false;
	}

	if (!state_evt.Evt1) {
		;
	} else if ((state_evt.Evt1 >> 0) & 1) {
		state_evt.EvtStr = "Ground fault";
	} else if ((state_evt.Evt1 >> 1) & 1) {
		state_evt.EvtStr = "DC over voltage";
	} else if ((state_evt.Evt1 >> 2) & 1) {
		state_evt.EvtStr = "AC disconnect open";
	} else if ((state_evt.Evt1 >> 3) & 1) {
		state_evt.EvtStr = "DC disconnect open";
	} else if ((state_evt.Evt1 >> 4) & 1) {
		state_evt.EvtStr = "Grid shutdown";
	} else if ((state_evt.Evt1 >> 5) & 1) {
		state_evt.EvtStr = "Cabinet open";
	} else if ((state_evt.Evt1 >> 6) & 1) {
		state_evt.EvtStr = "Manual shutdown";
	} else if ((state_evt.Evt1 >> 7) & 1) {
		state_evt.EvtStr = "Over temperature";
	} else if ((state_evt.Evt1 >> 8) & 1) {
		state_evt.EvtStr = "Frequency above limit";
	} else if ((state_evt.Evt1 >> 9) & 1) {
		state_evt.EvtStr = "Frequency under limit";
	} else if ((state_evt.Evt1 >> 10) & 1) {
		state_evt.EvtStr = "AC voltage above limit";
	} else if ((state_evt.Evt1 >> 11) & 1) {
		state_evt.EvtStr = "AC voltage under limit";
	} else if ((state_evt.Evt1 >> 12) & 1) {
		state_evt.EvtStr = "Blown string fuse";
	} else if ((state_evt.Evt1 >> 13) & 1) {
		state_evt.EvtStr = "Under temperature";
	} else if ((state_evt.Evt1 >> 14) & 1) {
		state_evt.EvtStr = "Generic Memory or Communication error (internal)";
	} else if ((state_evt.Evt1 >> 15) & 1) {
		state_evt.EvtStr = "Hardware test failure";
	} else {
		ErrorStr = std::string("Invalid event flag (") + std::to_string(state_evt.Evt1) + ")";
		return false;
	}

	if (!state_evt.EvtVnd1) {
		;
	} else if ((state_evt.EvtVnd1 >> 0) & 1) {
		state_evt.EvtStr = "DC Insulation fault";
	} else if ((state_evt.EvtVnd1 >> 1) & 1) {
		state_evt.EvtStr = "Grid error";
	} else if ((state_evt.EvtVnd1 >> 2) & 1) {
		state_evt.EvtStr = "Overcurrent AC";
	} else if ((state_evt.EvtVnd1 >> 3) & 1) {
		state_evt.EvtStr = "Overcurrent DC";
	} else if ((state_evt.EvtVnd1 >> 4) & 1) {
		state_evt.EvtStr = "Overtemperature";
	} else if ((state_evt.EvtVnd1 >> 5) & 1) {
		state_evt.EvtStr = "Power low";
	} else if ((state_evt.EvtVnd1 >> 6) & 1) {
		state_evt.EvtStr = "DC low";
	} else if ((state_evt.EvtVnd1 >> 7) & 1) {
		state_evt.EvtStr = "Intermediate circuit error";
	} else if ((state_evt.EvtVnd1 >> 8) & 1) {
		state_evt.EvtStr = "AC frequency too high";
	} else if ((state_evt.EvtVnd1 >> 9) & 1) {
		state_evt.EvtStr = "AC frequency too low";
	} else if ((state_evt.EvtVnd1 >> 10) & 1) {
		state_evt.EvtStr = "AC voltage too high";
	} else if ((state_evt.EvtVnd1 >> 11) & 1) {
		state_evt.EvtStr = "AC voltage too low";
	} else if ((state_evt.EvtVnd1 >> 12) & 1) {
		state_evt.EvtStr = "Direct current feed in";
	} else if ((state_evt.EvtVnd1 >> 13) & 1) {
		state_evt.EvtStr = "Relay problem";
	} else if ((state_evt.EvtVnd1 >> 14) & 1) {
		state_evt.EvtStr = "Internal power stage error";
	} else if ((state_evt.EvtVnd1 >> 15) & 1) {
		state_evt.EvtStr = "Control problems";
	} else if ((state_evt.EvtVnd1 >> 16) & 1) {
		state_evt.EvtStr = "Guard Controller - AC voltage error";
	} else if ((state_evt.EvtVnd1 >> 17) & 1) {
		state_evt.EvtStr = "Guard Controller - AC Frequency Error";
	} else if ((state_evt.EvtVnd1 >> 18) & 1) {
		state_evt.EvtStr = "Energy transfer not possible";
	} else if ((state_evt.EvtVnd1 >> 19) & 1) {
		state_evt.EvtStr = "Reference power source AC outside tolerances";
	} else if ((state_evt.EvtVnd1 >> 20) & 1) {
		state_evt.EvtStr = "Error during anti islanding test";
	} else if ((state_evt.EvtVnd1 >> 21) & 1) {
		state_evt.EvtStr = "Fixed voltage lower than current MPP voltage";
	} else if ((state_evt.EvtVnd1 >> 22) & 1) {
		state_evt.EvtStr = "Memory fault";
	} else if ((state_evt.EvtVnd1 >> 23) & 1) {
		state_evt.EvtStr = "Display";
	} else if ((state_evt.EvtVnd1 >> 24) & 1) {
		state_evt.EvtStr = "Internal communication error";
	} else if ((state_evt.EvtVnd1 >> 25) & 1) {
		state_evt.EvtStr = "Temperature sensors defective";
	} else if ((state_evt.EvtVnd1 >> 26) & 1) {
		state_evt.EvtStr = "DC or AC board fault";
	} else if ((state_evt.EvtVnd1 >> 27) & 1) {
		state_evt.EvtStr = "ENS error";
	} else if ((state_evt.EvtVnd1 >> 28) & 1) {
		state_evt.EvtStr = "Fan error";
	} else if ((state_evt.EvtVnd1 >> 29) & 1) {
		state_evt.EvtStr = "Defective fuse";
	} else if ((state_evt.EvtVnd1 >> 30) & 1) {
		state_evt.EvtStr = "Output choke connected to wrong poles";
	} else if ((state_evt.EvtVnd1 >> 31) & 1) {
		state_evt.EvtStr = "The buck converter relay does not open at high DC voltage";
	} else {
		ErrorStr = std::string("Invalid vendor event flag 1 (") + std::to_string(state_evt.EvtVnd1) + ")";
		return false;
	}

	if (!state_evt.EvtVnd2) {
		;
	} else if ((state_evt.EvtVnd2 >> 0) & 1) {
		state_evt.EvtStr = "No SolarNet communication";
	} else if ((state_evt.EvtVnd2 >> 1) & 1) {
		state_evt.EvtStr = "Inverter address incorrect";
	} else if ((state_evt.EvtVnd2 >> 2) & 1) {
		state_evt.EvtStr = "24h no feed in";
	} else if ((state_evt.EvtVnd2 >> 3) & 1) {
		state_evt.EvtStr = "Faulty plug connections";
	} else if ((state_evt.EvtVnd2 >> 4) & 1) {
		state_evt.EvtStr = "Incorrect phase allocation";
	} else if ((state_evt.EvtVnd2 >> 5) & 1) {
		state_evt.EvtStr = "Grid conductor open or supply phase has failed";
	} else if ((state_evt.EvtVnd2 >> 6) & 1) {
		state_evt.EvtStr = "Incompatible or old software";
	} else if ((state_evt.EvtVnd2 >> 7) & 1) {
		state_evt.EvtStr = "Power derating due to overtemperature";
	} else if ((state_evt.EvtVnd2 >> 8) & 1) {
		state_evt.EvtStr = "Jumper set incorrectly";
	} else if ((state_evt.EvtVnd2 >> 9) & 1) {
		state_evt.EvtStr = "Incompatible feature";
	} else if ((state_evt.EvtVnd2 >> 10) & 1) {
		state_evt.EvtStr = "Defective ventilator/air vents blocked";
	} else if ((state_evt.EvtVnd2 >> 11) & 1) {
		state_evt.EvtStr = "Power reduction on error";
	} else if ((state_evt.EvtVnd2 >> 12) & 1) {
		state_evt.EvtStr = "Arc detected";
	} else if ((state_evt.EvtVnd2 >> 13) & 1) {
		state_evt.EvtStr = "AFCI self test failed";
	} else if ((state_evt.EvtVnd2 >> 14) & 1) {
		state_evt.EvtStr = "Current sensor error";
	} else if ((state_evt.EvtVnd2 >> 15) & 1) {
		state_evt.EvtStr = "DC switch fault";
	} else if ((state_evt.EvtVnd2 >> 16) & 1) {
		state_evt.EvtStr = "AFCI defective";
	} else if ((state_evt.EvtVnd2 >> 17) & 1) {
		state_evt.EvtStr = "AFCI manual test successful";
	} else if ((state_evt.EvtVnd2 >> 18) & 1) {
		state_evt.EvtStr = "Power stack supply missing";
	} else if ((state_evt.EvtVnd2 >> 19) & 1) {
		state_evt.EvtStr = "AFCI communication stopped";
	} else if ((state_evt.EvtVnd2 >> 20) & 1) {
		state_evt.EvtStr = "AFCI manual test failed";
	} else if ((state_evt.EvtVnd2 >> 21) & 1) {
		state_evt.EvtStr = "AC polarity reversed";
	} else if ((state_evt.EvtVnd2 >> 22) & 1) {
		state_evt.EvtStr = "AC measurement device fault";
	} else if ((state_evt.EvtVnd2 >> 23) & 1) {
		state_evt.EvtStr = "Flash fault";
	} else if ((state_evt.EvtVnd2 >> 24) & 1) {
		state_evt.EvtStr = "General error";
	} else if ((state_evt.EvtVnd2 >> 25) & 1) {
		state_evt.EvtStr = "Grounding fault";
	} else if ((state_evt.EvtVnd2 >> 26) & 1) {
		state_evt.EvtStr = "Power limitation fault";
	} else if ((state_evt.EvtVnd2 >> 27) & 1) {
		state_evt.EvtStr = "External NO contact open";
	} else if ((state_evt.EvtVnd2 >> 28) & 1) {
		state_evt.EvtStr = "External overvoltage protection has tripped";
	} else if ((state_evt.EvtVnd2 >> 29) & 1) {
		state_evt.EvtStr = "Internal processor program status";
	} else if ((state_evt.EvtVnd2 >> 30) & 1) {
		state_evt.EvtStr = "SolarNet issue";
	} else if ((state_evt.EvtVnd2 >> 31) & 1) {
		state_evt.EvtStr = "Supply voltage fault";
	} else {
		ErrorStr = std::string("Invalid vendor event flag 2 (") + std::to_string(state_evt.EvtVnd2) + ")";
		return false;
	}

	if (!state_evt.EvtVnd3) {
		;
	} else if ((state_evt.EvtVnd3 >> 0) & 1) {
		state_evt.EvtStr = "Time error";
	} else if ((state_evt.EvtVnd3 >> 1) & 1) {
		state_evt.EvtStr = "USB error";
	} else if ((state_evt.EvtVnd3 >> 2) & 1) {
		state_evt.EvtStr = "DC high";
	} else if ((state_evt.EvtVnd3 >> 3) & 1) {
		state_evt.EvtStr = "Init error";
	} else {
		ErrorStr = std::string("Invalid vendor event flag 3 (") + std::to_string(state_evt.EvtVnd3) + ")";
		return false;
	}

	return true;
}
