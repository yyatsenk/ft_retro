#include "Enemy.hpp"

Enemy & Enemy::operator=(Enemy const & copy)
{
	if (this != &copy)
	{
		this->x = copy.getX();
		this->y = copy.getY();
		this->xMax = copy.xMax;
		this->yMax = copy.yMax;
		this->visual = copy.visual;
		this->curwin = copy.curwin;
		this->hitToDie = copy.getHitToDie();
	}

	return (*this);
}

Enemy::Enemy(Enemy const & copy)
{
	*this = copy;

	return ;
}

Enemy::~Enemy(void)
{
	return ;
}

Enemy::Enemy(void)
{
	return ;
}

Enemy::Enemy(WINDOW * win, char c)
{
	int		i;

	i = -1;
	this->hp = 1;
	this->curwin = win;
	this->hitToDie = 1;
	getmaxyx(this->curwin, yMax, xMax);
	keypad(curwin, true);
	this->x = xMax - 3;
	this->y = std::rand() % (yMax - 4) + 1;
	this->visual = c;
	bullets = new Bullet *[3];
	while (++i < 3)
		bullets[i] = NULL;
	mvwaddch(curwin, y, x, visual);

	return ;
}

Bullet**			Enemy::getBullets() const
{
	return (bullets);
}

void	Enemy::killBul()
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (bullets[i] != NULL && bullets[i]->getX() <= 1)
		{
			delete(bullets[i]);
			bullets[i] = NULL;
			bulInUse--;
		}
	}
}

void			Enemy::moveBul()
{
	int			i;

	i = -1;
	while (++i < 3)
	{
		if (bullets[i] != NULL)
			bullets[i]->fly(-1);
	}
}

void		Enemy::createBullet()
{
	int		i;

	i = -1;
	while (++i < 3 && bulInUse < 3)
	{
		if (bullets[i] == NULL)
		{
			bullets[i] = new Bullet(curwin, x - 1, y);
			bulInUse++;
			return ;
		}
	}
}

void			Enemy::setX(int x)
{
	this->x = x;
}

void			Enemy::move()
{
	mvwaddch(curwin, y, x, ' ');
	x--;
	if (x <= 1)
		x = 1;
	mvwaddch(curwin, y, x, visual | COLOR_PAIR(2));
}

int				Enemy::getX() const
{
	return (x);
}

int				Enemy::getY() const
{
	return (y);
}

WINDOW *		Enemy::getWin() const
{
	return (curwin);
}

char			Enemy::getVisual() const
{
	return (visual);
}

Bullet*			Enemy::getBullet(int i) const
{
	return (bullets[i]);
}

int				Enemy::getHitToDie() const
{
	return (hitToDie);
}

void			Enemy::setHitToDie(int i)
{
	hitToDie = i;
}

int				Enemy::checkCollision(int x, int y)
{	
	if (this->x == x && this->y == y)
			return (1);
	return (0);
}

void			Enemy::clearEnemy()
{
	mvwaddch(curwin, y, x, ' ');
}