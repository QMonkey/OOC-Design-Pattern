#ifndef ABSTRACT_QRCODE_STATE_H
#define ABSTRACT_QRCODE_STATE_H

#include "iqrcode_state.h"
#include "qrcode_state_machine.h"

typedef struct _AbstractQRCodeState AbstractQRCodeState;

struct _AbstractQRCodeState
{
	QRCodeStateMachine *stateMachine;
	union
	{
		IQRCodeState;
		IQRCodeState iqrcodeState;
	};
};

extern void constructAbstractQRCodeState(void*, QRCodeStateMachine*);
extern void destructAbstractQRCodeState(AbstractQRCodeState*);

#endif
