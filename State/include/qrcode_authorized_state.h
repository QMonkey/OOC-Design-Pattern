#ifndef QRCODE_AUTHORIZED_STATE_H
#define QRCODE_AUTHORIZED_STATE_H

#include "abstract_qrcode_state.h"
#include "qrcode_state_machine.h"

typedef struct _QRCodeAuthorizedState QRCodeAuthorizedState;

struct _QRCodeAuthorizedState
{
	union
	{
		AbstractQRCodeState;
		AbstractQRCodeState abstractQRCodeState;
	};
};

extern QRCodeAuthorizedState* QRCodeAuthorizedState_construct(void*, QRCodeStateMachine*);
extern void QRCodeAuthorizedState_destruct(QRCodeAuthorizedState*);

#endif
