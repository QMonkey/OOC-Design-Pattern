#ifndef FINDPWD_MESSAGE_H
#define FINDPWD_MESSAGE_H

#include "abstract_message.h"

typedef struct _FindPwdMessage FindPwdMessage;

struct _FindPwdMessage
{
	union
	{
		AbstractMessage;
		AbstractMessage abstractMessage;
	};
};

extern FindPwdMessage* FindPwdMessage_construct(void*, IMessageSender*);
extern void FindPwdMessage_destruct(FindPwdMessage*);

#endif
