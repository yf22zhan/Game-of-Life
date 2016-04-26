#include "Game.h"
#include <windows.h>

int main(int argc, char** argv)
{
	FreeConsole();
	Game::start();

	return 0;
}