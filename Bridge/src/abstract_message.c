#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imessage_sender.h"
#include "abstract_message.h"

static char* AbstractMessage_getContent(AbstractMessage*);
static void AbstractMessage_setContent(AbstractMessage*, char*);
static void AbstractMessage_sendMessage(AbstractMessage*);

void AbstractMessage_construct(void* addr, IMessageSender* sender)
{
	if (addr == NULL)
	{
		return;
	}

	AbstractMessage* abstractMessage = addr;
	abstractMessage->sender = sender;
	abstractMessage->content = NULL;

	abstractMessage->getContent = AbstractMessage_getContent;
	abstractMessage->setContent = AbstractMessage_setContent;
	abstractMessage->sendMessage = AbstractMessage_sendMessage;
}

void AbstractMessage_destruct(AbstractMessage* abstractMessage)
{
	free(abstractMessage->content);
}

char* AbstractMessage_getContent(AbstractMessage* abstractMessage)
{
	return abstractMessage->content;
}

void AbstractMessage_setContent(AbstractMessage* abstractMessage, char* content)
{
	free(abstractMessage->content);
	abstractMessage->content = strdup(content);
}

void AbstractMessage_sendMessage(AbstractMessage* abstractMessage)
{
	abstractMessage->sender->send(abstractMessage->sender, abstractMessage->content);
}
