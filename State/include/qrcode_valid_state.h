#ifndef QRCODE_VALID_STATE_H
#define QRCODE_VALID_STATE_H

#include "abstract_qrcode_state.h"
#include "qrcode_state_machine.h"

typedef struct _QRCodeValidState QRCodeValidState;

struct _QRCodeValidState
{
	union
	{
		AbstractQRCodeState;
		AbstractQRCodeState abstractQRCodeState;
	};
};

extern QRCodeValidState* QRCodeValidState_construct(void*, QRCodeStateMachine*);
extern void QRCodeValidState_destruct(QRCodeValidState*);

#endif
