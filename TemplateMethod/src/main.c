#include "base.h"
#include "dota2.h"
#include "chess.h"

int main()
{
	Dota2* dota2 = new (Dota2);
	dota2->play(&dota2->abstractGame, 5);

	Chess* chess = new (Chess);
	chess->play(&chess->abstractGame, 2);

	delete (Dota2, dota2);
	delete (Chess, chess);

	return 0;
}
