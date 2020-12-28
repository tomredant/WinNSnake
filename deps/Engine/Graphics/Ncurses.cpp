#include <Engine/Graphics/Ncurses.hpp>

#include <curses.h>
//#include <sys/select.h>			// select()
#include <unistd.h>				// STDIN_FILENO

bool Ncurses::init()
{
	initscr();
	// TODO check for failing

	cbreak();    // Character input doesnt require the <enter> key anymore
	curs_set(0); // Makes the blinking cursor invisible
	noecho();    // Wont print the keys received through input
	nodelay(stdscr, TRUE); // Wont wait for input
	keypad(stdscr, TRUE);  // Support for extra keys (life F1, F2, ... )

	// Ncurses' global variable meaning number of milliseconds
	// to wait after the user presses ESC.
	//
	// VIM uses 25ms, so should you.
	// Source: http://en.chys.info/2009/09/esdelay-ncurses/
    //ESCDELAY = 25;

	refresh();   // Refresh the layout (prints whats in the layout bu
	return true;
}

void Ncurses::exit()
{
	erase();
	refresh();
	endwin();
}

int Ncurses::getInput(int delay_ms)
{
    int c;
    nodelay(stdscr, TRUE);
    c = getch();
    nodelay(stdscr, FALSE);
    nocbreak();
    cbreak();
    if(c == ERR)
        return ERR;
	return c;
}

