#ifndef ABSTRACT_QRCODE_STATE_H
#define ABSTRACT_QRCODE_STATE_H

#include "iqrocde_state.h"
#include "qrocde_state_machine.h"

typedef struct _AbstractQRCodeState AbstractQRCodeState;

struct _AbstractQRCodeState
{
	QRCodeStateMachine *stateMachine;
	IQRCodeState iqrcodeState;
};

extern void constructAbstractQRCodeState(void*, QRCodeStateMachine*);
extern void destructAbstractQRCodeState(AbstractQRCodeState*);

#endif
