#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imessage_sender.h"
#include "abstract_message.h"
#include "signup_message.h"

static void SignupMessage_setContent(AbstractMessage*, char*);

SignupMessage* SignupMessage_construct(void* addr, IMessageSender* sender)
{
	if (addr == NULL)
	{
		return NULL;
	}

	SignupMessage* signupMessage = addr;

	AbstractMessage_construct(&signupMessage->abstractMessage, sender);
	signupMessage->setContent = SignupMessage_setContent;

	return signupMessage;
}

void SignupMessage_destruct(SignupMessage* signupMessage)
{
	AbstractMessage_destruct(&signupMessage->abstractMessage);
}

void SignupMessage_setContent(AbstractMessage* abstractMessage, char* content)
{
	free(abstractMessage->content);

	char* prefix = "signup: ";
	char* tmp = malloc(sizeof(char) * (strlen(prefix) + strlen(content) + 1));
	abstractMessage->content = strcat(strcpy(tmp, prefix), content);
}
