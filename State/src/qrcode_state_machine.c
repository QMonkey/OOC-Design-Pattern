#include <stdio.h>

#include "base.h"
#include "qrcode_state_machine.h"
#include "noqrcode_state.h"
#include "qrcode_valid_state.h"
#include "qrcode_authorizing_state.h"
#include "qrcode_authorized_state.h"

static void QRCodeStateMachine_setState(QRCodeStateMachine*, enum _QRCodeState);
static void QRCodeStateMachine_getQRCode(IQRCodeState*);
static void QRCodeStateMachine_scanQRCode(IQRCodeState*);
static void QRCodeStateMachine_auth(IQRCodeState*);
static void QRCodeStateMachine_cancel(IQRCodeState*);
static void QRCodeStateMachine_spend(IQRCodeState*);

QRCodeStateMachine* QRCodeStateMachine_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	QRCodeStateMachine* qrcodeStateMachine = addr;
	qrcodeStateMachine->noQRCodeState = &new (NoQRCodeState, qrcodeStateMachine)->iqrcodeState;
	qrcodeStateMachine->qrcodeValidState = &new (QRCodeValidState, qrcodeStateMachine)->iqrcodeState;
	qrcodeStateMachine->qrcodeAuthorizingState = &new (QRCodeAuthorizingState, qrcodeStateMachine)->iqrcodeState;
	qrcodeStateMachine->qrcodeAuthorizedState = &new (QRCodeAuthorizedState, qrcodeStateMachine)->iqrcodeState;
	qrcodeStateMachine->currentState = qrcodeStateMachine->noQRCodeState;

	qrcodeStateMachine->setState = QRCodeStateMachine_setState;
	qrcodeStateMachine->getQRCode = QRCodeStateMachine_getQRCode;
	qrcodeStateMachine->scanQRCode = QRCodeStateMachine_scanQRCode;
	qrcodeStateMachine->auth = QRCodeStateMachine_auth;
	qrcodeStateMachine->cancel = QRCodeStateMachine_cancel;
	qrcodeStateMachine->spend = QRCodeStateMachine_spend;

	return qrcodeStateMachine;
}

void QRCodeStateMachine_destruct(QRCodeStateMachine* stateMachine)
{
	delete (NoQRCodeState, container_of(stateMachine->noQRCodeState, NoQRCodeState, iqrcodeState));
	delete (QRCodeValidState, container_of(stateMachine->qrcodeValidState, QRCodeValidState, iqrcodeState));
	delete (QRCodeAuthorizingState, container_of(stateMachine->qrcodeAuthorizingState, QRCodeAuthorizingState, iqrcodeState));
	delete (QRCodeAuthorizedState, container_of(stateMachine->qrcodeAuthorizedState, QRCodeAuthorizedState, iqrcodeState));
}

void QRCodeStateMachine_setState(QRCodeStateMachine* stateMachine,
				 enum _QRCodeState qrcodeState)
{
	switch (qrcodeState)
	{
	case NOQRCODE:
		stateMachine->currentState = stateMachine->noQRCodeState;
		break;

	case VALID:
		stateMachine->currentState = stateMachine->qrcodeValidState;
		break;

	case AUTHORIZING:
		stateMachine->currentState =
		    stateMachine->qrcodeAuthorizingState;
		break;

	case AUTHORIZED:
		stateMachine->currentState =
		    stateMachine->qrcodeAuthorizedState;
		break;

	default:
		fprintf(stderr, "No such qrcode state!\n");
	}
}

void QRCodeStateMachine_getQRCode(IQRCodeState* iqrcodeState)
{
	QRCodeStateMachine* stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->getQRCode(stateMachine->currentState);
}

void QRCodeStateMachine_scanQRCode(IQRCodeState* iqrcodeState)
{
	QRCodeStateMachine* stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->scanQRCode(stateMachine->currentState);
}

void QRCodeStateMachine_auth(IQRCodeState* iqrcodeState)
{
	QRCodeStateMachine* stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->auth(stateMachine->currentState);
}

void QRCodeStateMachine_cancel(IQRCodeState* iqrcodeState)
{
	QRCodeStateMachine* stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->cancel(stateMachine->currentState);
}

void QRCodeStateMachine_spend(IQRCodeState* iqrcodeState)
{
	QRCodeStateMachine* stateMachine = container_of(iqrcodeState, QRCodeStateMachine, iqrcodeState);
	stateMachine->currentState->spend(stateMachine->currentState);
}
