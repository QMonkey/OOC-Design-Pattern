#include <stdio.h>

#include "imessage_sender.h"
#include "sms_sender.h"

static void SMSSender_send(IMessageSender*, char*);

SMSSender* SMSSender_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	SMSSender* smsSender = addr;

	smsSender->send = SMSSender_send;

	return smsSender;
}

void SMSSender_destruct(SMSSender* smsSender)
{
}

void SMSSender_send(IMessageSender* imessageSender, char* content)
{
	printf("Send message by sms! Content: '%s'\n", content);
}
