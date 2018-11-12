#include <ncurses.h>
#include <string>
#include "Player.hpp"
#include "Boss.hpp"
#include "Game.hpp"
#include <ctime>


int 				choice(WINDOW *w, int xMax, int yMax)
{
	std::string choices[2] = {"Start", "Exit"};
	int choice;
	int h;

	h = 0;
	keypad(w, true);
	while (1)
	{
		for (int i = 0; i < 2; i++)
		{
			if (i == h)
				wattron(w, A_REVERSE);
			mvwprintw(w, (yMax/2) + i + 1, xMax/2, choices[i].c_str());
			wattroff(w, A_REVERSE);
		}
		choice = wgetch(w);

		switch(choice)
		{
			case KEY_UP:
			h--;
			if (h == -1)
				h = 1;
			break;
			case KEY_DOWN:
			h++;
			if (h == 2)
				h = 0;
			break;
			default:
			break;
		}
		if(choice == 10)
			break;
	}
	return (h);
}

int					main()
{
	initscr();
	noecho();
	cbreak();

	int yMax, xMax, c;
	unsigned int		z;
	getmaxyx(stdscr, yMax, xMax);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	WINDOW * statmenu = newwin(6, 15, 0, 0);
	WINDOW * menuwin = newwin(yMax, xMax, 0 , 0);
	box(statmenu, 0, 0);
	nodelay(statmenu, true);
	refresh();
	wrefresh(statmenu);
	curs_set(0);
	box(menuwin, 0, 0);
	nodelay(menuwin, true);
	refresh();
	wrefresh(menuwin);
	std::srand(time(NULL));

	Game		*g = new Game();
	Enemy		**e = new Enemy *[64];
	Player *p = new Player(menuwin, yMax/2, 1, '>');
	z = 0;
	if (! (c = choice(menuwin, xMax, yMax)))
	{
		clear();
		refresh();
		while (1)
		{
			if (p->getScore() / 100 == 1)
				g->createBoss(e, p, menuwin);
			g->statDo(statmenu, p);
			if (g->checkPlayer(p, e) || g->checkBulEnemy(e, p))
			{
				clear();
				break ;
			}
			g->checkAndDelete(p, e);
			if (z % g->getBulSpeed() == 0)
				g->moveAllBull(p, e);
			if (z % g->getEnemySpeed() == 0)
				g->moveAllEnemy(e);
			if (z % g->getCreationSpeed() == 0)
				g->creationAll(menuwin, e);
			if (p->getMV() == 27)
			{
				clear();
				break ;
			}
			p->display();
			wrefresh(menuwin);
			z++;
		}
	}
	endwin();
	if (!c)
		std::cout << "GAME OVER" << std::endl;
	return (0);
}
