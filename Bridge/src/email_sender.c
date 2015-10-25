#include <stdio.h>

#include "imessage_sender.h"
#include "email_sender.h"

static void EmailSender_send(IMessageSender*, char*);

EmailSender* EmailSender_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	EmailSender* emailSender = addr;

	emailSender->send = EmailSender_send;

	return emailSender;
}

void EmailSender_destruct(EmailSender* emailSender)
{
}

void EmailSender_send(IMessageSender* imessageSender, char* content)
{
	printf("Send message by email! Content: '%s'\n", content);
}
