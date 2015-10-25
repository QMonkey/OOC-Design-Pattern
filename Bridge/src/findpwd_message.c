#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imessage_sender.h"
#include "abstract_message.h"
#include "findpwd_message.h"

static void FindPwdMessage_setContent(AbstractMessage*, char*);

FindPwdMessage* FindPwdMessage_construct(void* addr, IMessageSender* sender)
{
	if (addr == NULL)
	{
		return NULL;
	}

	FindPwdMessage* findPwdMessage = addr;

	AbstractMessage_construct(&findPwdMessage->abstractMessage, sender);
	findPwdMessage->setContent = FindPwdMessage_setContent;

	return findPwdMessage;
}

void FindPwdMessage_destruct(FindPwdMessage* findPwdMessage)
{
	AbstractMessage_destruct(&findPwdMessage->abstractMessage);
}

void FindPwdMessage_setContent(AbstractMessage* abstractMessage, char* content)
{
	free(abstractMessage->content);

	char* prefix = "findpwd: ";
	char* tmp = malloc(sizeof(char) * (strlen(prefix) + strlen(content) + 1));
	abstractMessage->content = strcat(strcpy(tmp, prefix), content);
}
