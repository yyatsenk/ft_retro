#include "Bullet.hpp"

Bullet & Bullet::operator=(Bullet const & copy)
{
	if (this != &copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->curwin = copy.curwin;
		this->visual = copy.visual;
	}

	return (*this);
}

Bullet::Bullet(WINDOW * win, int x, int y) : x(x), y(y), curwin(win)
{
	this->visual = '-';
}

Bullet::Bullet(void)
{
	return ;
}

Bullet::~Bullet(void)
{
	mvwaddch(getWin(), getY(), getX(), ' ');
	return ;
}

Bullet::Bullet(Bullet const & copy)
{
	*this = copy;

	return ;
}

void			Bullet::fly(int i)
{
	mvwaddch(curwin, y, x, ' ');
	x += i;
	mvwaddch(curwin, y, x, visual);
}

void				Bullet::setX(int x)
{
	this->x = x;
}

int					Bullet::getX() const
{
	return (x);
}

int					Bullet::getY() const
{
	return (y);
}

char				Bullet::getVisual() const
{
	return (visual);
}

WINDOW *			Bullet::getWin() const
{
	return (curwin);
}

