#ifndef QRCODE_AUTHORIZING_STATE_H
#define QRCODE_AUTHORIZING_STATE_H

#include "abstract_qrcode_state.h"
#include "qrcode_state_machine.h"

typedef struct _QRCodeAuthorizingState QRCodeAuthorizingState;

struct _QRCodeAuthorizingState
{
	union
	{
		AbstractQRCodeState;
		AbstractQRCodeState abstractQRCodeState;
	};
};

extern QRCodeAuthorizingState* QRCodeAuthorizingState_construct(void*, QRCodeStateMachine*);
extern void QRCodeAuthorizingState_destruct(QRCodeAuthorizingState*);

#endif
