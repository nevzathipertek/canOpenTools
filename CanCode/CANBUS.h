//program::CAN bus protocol with SN65HVD230 driver header file
// @uthor::Nevzat DURMAZ
//   date::02.01.2021
// update::18.09.2023
//version::01.03
//--------------------------------------------------------------------//
#ifndef CANBUS_H_
#define CANBUS_H_
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
#include <OD.h> //Object Dictionary for Can Open Work Protocol
#include "CO_app_STM32.h"
#include "storage/CO_storage.h"
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
namespace hiper {
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//#define ODT_ARRAY   ODT_ARR
//#define ODT_RECORD  ODT_REC
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
class CANBUS {

	unsigned short CounterOfCommunication{0};

	inline void incCounterOfCom(void) { CounterOfCommunication++; }

public:

	static FDCAN_HandleTypeDef* pCanUsed;
	static TIM_HandleTypeDef* pTimUsed;
	static void (*pCanInit)(void);

	inline CANBUS() = delete;

	inline explicit CANBUS( FDCAN_HandleTypeDef* pUSEDhcan,
			TIM_HandleTypeDef* pUSEDhtim, void (*_CanInitFunc_)(void) ) {
		pCanUsed = pUSEDhcan;
		pTimUsed = pUSEDhtim;
		pCanInit = _CanInitFunc_;
	}

	inline virtual ~CANBUS() {}

	// node ID must be selected, baud is useless here,
	// it takes the configuration of STM32 as baud...
	void init(uint8_t _nodeID_, uint8_t _baudKHz_);

	void sendRequest0(void);
	void sendRequest1(void);
	void sendRequest2(void);
	void sendRequest3(void);

//	inline signed short getPosition(void)const		{ return OD_RAM.x8300_fabricStitchPosition; }
//	inline signed short getCounterOfCom(void)const	{ return OD_RAM.x8301_numberOfProcess; 		}

	uint8_t getNodeIDactive(void)const;
	uint8_t getNodeIDdesired(void)const;
	bool getRedLed(void)const;
	bool getGreenLed(void)const;


	static inline void DelayUs(unsigned int _delTime){ for(unsigned int i=0; i<_delTime; i++); }

};
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
} /* namespace hiper */
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
#endif /* CANBUS_H_ */
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
