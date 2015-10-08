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

extern QRCodeAuthorizingState*
constructQRCodeAuthorizingState(void*, QRCodeStateMachine*);
extern void destructQRCodeAuthorizingState(QRCodeAuthorizingState*);

#endif
