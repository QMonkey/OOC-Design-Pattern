#ifndef NOQRCODE_STATE_H
#define NOQRCODE_STATE_H

#include "abstract_qrcode_state.h"
#include "qrcode_state_machine.h"

typedef struct _NoQRCodeState NoQRCodeState;

struct _NoQRCodeState
{
	union
	{
		AbstractQRCodeState;
		AbstractQRCodeState abstractQRCodeState;
	};
};

extern NoQRCodeState* constructNoQRCodeState(void*, QRCodeStateMachine*);
extern void destructNoQRCodeState(NoQRCodeState*);

#endif
