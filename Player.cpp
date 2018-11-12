#include "Player.hpp"

Player & Player::operator=(Player const & copy)
{
	if (this != &copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->yMax = copy.yMax;
		this->xMax = copy.xMax;
		this->visual = copy.visual;
		this->curwin = copy.curwin;
	}

	return (*this);
}

Player::Player(Player const & copy)
{
	*this = copy;
	
	return ;
}

Player::Player(void)
{
	return ;
}

Player::~Player(void)
{
	return ;
}

Player::Player(WINDOW * win, int y, int x, char c) : x(x), y(y), xMax(0), \
												 yMax(0), visual(c), \
												curwin(win)
{
	int			i;

	i = -1;
	bullets = new Bullet *[64];
	while (++i < 64)
		bullets[i] = NULL;
	getmaxyx(this->curwin, yMax, xMax);
	keypad(curwin, true);
	hitPoint = 10;
	level = 1;
	score = 0;
	gsc = 0;
	return ;
}

void		Player::mvUp()
{
	mvwaddch(curwin, y, x, ' ');
	this->y--;
	if (this->y < 1)
		this->y = 1;
}

void		Player::mvDown()
{
	mvwaddch(curwin, y, x, ' ');
	y++;
	if (y > yMax - 2)
		y = yMax - 2;
}

void		Player::mvLeft()
{

	mvwaddch(curwin, y, x, ' ');
	x--;
	if (x < 1)
		x = 1;
}

void		Player::mvRight()
{

	mvwaddch(curwin, y, x, ' ');
	x++;
	if (x > xMax - 2)
		x = xMax - 2 ;
}

int			Player::getMV()
{
	int		choice;

	choice = wgetch(curwin);
	switch (choice)
	{
		case KEY_UP:
			mvUp();
			break;
		case KEY_DOWN :
			mvDown();
			break;
		case KEY_RIGHT :
			mvRight();
			break;
		case KEY_LEFT :
			mvLeft();
			break;
		case ' ' :
			createBullet();
			break;
		default :
			break;
	}
	return (choice);
}

void		Player::display()
{
	mvwaddch(curwin, y, x, visual | COLOR_PAIR(1));
}

void		Player::createBullet()
{
	int		i;

	i = -1;
	while (++i < 64)
	{
		if (bullets[i] == NULL)
		{
			bullets[i] = new Bullet(curwin, x, y);
			return ;
		}
	}
}

void	Player::deleteBullet()
{
	int i;

	i = -1;
	while (++i < 64)
	{
		if (bullets[i] != NULL && bullets[i]->getX() == xMax - 3)
		{
			delete(bullets[i]);
			bullets[i] = NULL;
		}
	}
}

Bullet *		Player::getBullet(int i) const
{
	return (bullets[i]);
}

void			Player::flyBullet()
{
	int			i;

	i = -1;
	while (++i < 64)
	{
		if (bullets[i] != NULL)
			bullets[i]->fly(1);
	}
}

int				Player::getX() const
{
	return x;
}

int				Player::getGS() const
{
	return gsc;
}

void				Player::setGS(int i)
{
	gsc += i;
}

int				Player::getY() const
{
	return y;
}

int				Player::getScore() const
{
	return (score);
}

int				Player::getLevel() const
{
	return (level);
}

int				Player::getHitPoint() const
{
	return (hitPoint);
}

void			Player::setHitPoint(int hitPoint)
{
	this->hitPoint = hitPoint;
}

void			Player::setLevel(int level)
{
	this->level = level;
}

void			Player::setScore(int score)
{
	this->score = score;
}