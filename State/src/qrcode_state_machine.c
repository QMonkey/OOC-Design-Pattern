#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "qrcode_state_machine.h"

static void QRCodeStateMachine_setState(QRCodeStateMachine*, enum _QRCodeState);
static void QRCodeStateMachine_getQRCode(IQRCodeState*);
static void QRCodeStateMachine_scanQRCode(IQRCodeState*);
static void QRCodeStateMachine_auth(IQRCodeState*);
static void QRCodeStateMachine_cancel(IQRCodeState*);

QRCodeStateMachine* newQRCodeStateMachine()
{
	return constructQRCodeStateMachine(malloc(sizeof(QRCodeStateMachine)));
}

QRCodeStateMachine* constructQRCodeStateMachine(void *addr)
{
	if(addr == NULL)
	{
		return NULL;
	}
}

void destructQRCodeStateMachine(QRCodeStateMachine *stateMachine)
{
}

void deleteQRCodeStateMachine(QRCodeStateMachine *stateMachine)
{
	destructQRCodeStateMachine(stateMachine);
	free(stateMachine);
}

void QRCodeStateMachine_setState(QRCodeStateMachine *stateMachine, enum _QRCodeState qrcodeState)
{
	switch(qrcodeState)
	{
	NOQRCODE:
		stateMachine->currentState = stateMachine->noQRCodeState;
		break;

	VALID:
		stateMachine->currentState = stateMachine->qrcodeValidState;
		break;

	AUTHORIZING:
		stateMachine->currentState = stateMachine->qrcodeAuthorizingState;
		break;

	AUTHORIZED:
		stateMachine->currentState = stateMachine->qrcodeAuthorizedState;
		break;

	defualt:
		fprintf(stderr, "No such qrcode state!");
	}
}

void QRCodeStateMachine_getQRCode(IQRCodeState *iqrcodeState)
{
	QRCodeStateMachine *stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->getQRCode(stateMachine->currentState);
}

void QRCodeStateMachine_scanQRCode(IQRCodeState *iqrcodeState)
{
	QRCodeStateMachine *stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->scanQRCode(stateMachine->currentState);
}

void QRCodeStateMachine_auth(IQRCodeState *iqrcodeState)
{
	QRCodeStateMachine *stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->auth(stateMachine->currentState);
}

void QRCodeStateMachine_cancel(IQRCodeState *iqrcodeState)
{
	QRCodeStateMachine *stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->cancel(stateMachine->currentState);
}
