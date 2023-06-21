/**
	@brief   Class that provides methods for state and event handling
	@author  Alexander Pohl <alex@ahpohl.com>
*/

#ifndef STATEEVENTS_H_
#define STATEEVENTS_H_

#include <string>
#include <cstdint>

class StateEvents
{
public:
	/** Operating state and flags and their string representations */
	struct StateEvt_t {
		uint16_t St;
		uint16_t StVnd;
	    uint32_t Evt1;
	    uint32_t Evt2;
	    uint32_t EvtVnd1;
	    uint32_t EvtVnd2;
	    uint32_t EvtVnd3;
	    uint32_t EvtVnd4;
		std::string StStr;
		std::string StVndStr;
		std::string EvtStr;
		std::string EvtVndStr;
	};

	/** */
	bool SetStateVendor(StateEvt_t &state_evt);

	/** */
	bool SetEventVendor(StateEvt_t &state_evt);

private:
	/** */
	enum class StatesVendor : uint16_t {
		I_STATUS_OFF = 1,
		I_STATUS_SLEEPING,
		I_STATUS_STARTING,
		I_STATUS_MPPT,
		I_STATUS_THROTTLED,
		I_STATUS_SHUTTING_DOWN,
		I_STATUS_FAULT,
		I_STATUS_STANDBY,
		I_STATUS_NO_BUSINIT,
		I_STATUS_NO_COMM_INV,
		I_STATUS_SN_OVERCURRENT,
		I_STATUS_BOOTLOAD,
		I_STATUS_AFCI,
	};
};

#endif /* STATEEVENTS_H_ */
