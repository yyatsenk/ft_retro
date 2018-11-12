#include "Boss.hpp"

Boss & Boss::operator=(Boss const & copy)
{
	if (this != &copy)
		Enemy::operator=(copy);

	return (*this);
}

Boss::Boss(Boss const & copy) : Enemy(copy)
{
	return ;
}

Boss::~Boss(void)
{
	return ;
}

Boss::Boss(void)
{
	return ;
}

Boss::Boss(WINDOW * win, char c) : Enemy(win, c)
{
	hitToDie = 15000;
	return ;
}

void			Boss::move()
{


	mvwaddch(curwin, y -1, x, ' ');
	mvwaddch(curwin, y + 1, x, ' ');
	mvwaddch(curwin, y, x, ' ');
	mvwaddch(curwin, y -1, x + 1, ' ');
	mvwaddch(curwin, y + 1, x + 1, ' ');
	mvwaddch(curwin, y, x + 1, ' ');
	x--;
	if (x <= 1)
		x = 1;
	mvwaddch(curwin, y - 1, x, '<' | COLOR_PAIR(3));
	mvwaddch(curwin, y + 1, x,  '<' | COLOR_PAIR(3));
	mvwaddch(curwin, y, x, '<' | COLOR_PAIR(3));
	mvwaddch(curwin, y, x + 1, '(' | COLOR_PAIR(3));
	mvwaddch(curwin, y + 1, x + 1, '(' | COLOR_PAIR(3));
	mvwaddch(curwin, y -1, x + 1, '(' | COLOR_PAIR(3));
}

int				Boss::checkCollision(int x, int y)
{	
	int			j;

	j = -2;
	while (++j < 3)
		if (x == this->x && y == this->y + j)
				return (1);
	return (0);
}

void			Boss::clearEnemy()
{
	mvwaddch(curwin, y - 1, x, ' ');
	mvwaddch(curwin, y + 1, x, ' ');
	mvwaddch(curwin, y, x, ' ');
	mvwaddch(curwin, y - 1, x + 1, ' ');
	mvwaddch(curwin, y + 1, x + 1, ' ');
	mvwaddch(curwin, y, x + 1, ' ');
}