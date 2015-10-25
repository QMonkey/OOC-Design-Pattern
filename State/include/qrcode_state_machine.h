#ifndef QRCODE_STATE_MACHINE_H
#define QRCODE_STATE_MACHINE_H

#include "iqrcode_state.h"

typedef struct _QRCodeStateMachine QRCodeStateMachine;

enum _QRCodeState
{
	NOQRCODE,
	VALID,
	AUTHORIZING,
	AUTHORIZED
};

struct _QRCodeStateMachine
{
	IQRCodeState* currentState;
	IQRCodeState* noQRCodeState;
	IQRCodeState* qrcodeValidState;
	IQRCodeState* qrcodeAuthorizingState;
	IQRCodeState* qrcodeAuthorizedState;

	void (*setState)(QRCodeStateMachine*, enum _QRCodeState);
	union
	{
		IQRCodeState;
		IQRCodeState iqrcodeState;
	};
};

extern QRCodeStateMachine* QRCodeStateMachine_construct(void*);
extern void QRCodeStateMachine_destruct(QRCodeStateMachine*);

#endif
