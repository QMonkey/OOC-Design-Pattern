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

extern QRCodeValidState* newQRCodeValidState(QRCodeStateMachine*);
extern QRCodeValidState* constructQRCodeValidState(void*, QRCodeStateMachine*);
extern void destructQRCodeValidState(QRCodeStateMachine*);
extern void deleteQRCodeValidState(QRCodeStateMachine*);

#endif
