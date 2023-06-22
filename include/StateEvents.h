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
	/** Operating state and event flags */
	struct StateEvt_t {
		/// Vendor defined operating state
		uint16_t St;
		/// State as text
		std::string StStr;
		/// Vendor defined event flags (bits 0-31)
	    uint32_t Evt1;
	    /// Vendor defined event flags (bits 32-63)
	    uint32_t Evt2;
	    /// Vendor defined event flags (bits 64-95)
	    uint32_t Evt3;
	    /// Vendor defined event flags (bits 96-127)
	    uint32_t Evt4;
	    /// Event as text
		std::string EvtStr;
	};

protected:
	/** Set state flag string */
	bool SetStateStr(StateEvt_t &state_evt);

	/** Set event flags string */
	bool SetEventStr(StateEvt_t &state_evt);

private:
	/** Operating states */
	enum class OpState : uint16_t {
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
