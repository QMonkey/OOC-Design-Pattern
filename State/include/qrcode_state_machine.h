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
        IQRCodeState *currentState;
        IQRCodeState *noQRCodeState;
        IQRCodeState *qrcodeValidState;
        IQRCodeState *qrcodeAuthorizingState;
        IQRCodeState *qrcodeAuthorizedState;

	void (*setState)(QRCodeStateMachine*, enum _QRCodeState);
	IQRCodeState iqrcodeState;
};

extern QRCodeStateMachine* newQRCodeStateMachine();
extern QRCodeStateMachine* constructQRCodeStateMachine(void*);
extern void destructQRCodeStateMachine(QRCodeStateMachine*);
extern void deleteQRCodeStateMachine(QRCodeStateMachine*);

#endif
