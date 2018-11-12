#include "Game.hpp"

Game &	Game::operator=(Game const & copy)
{
	if (this != &copy)
	{
		this->enemySpeed = copy.getEnemySpeed();
		this->creationSpeed = copy.getCreationSpeed();
		this->bulSpeed = copy.getBulSpeed();
	}

	return (*this);
}

Game::Game()
{
	enemySpeed = 10000; 
	creationSpeed = 50000;
	bulSpeed = 1500;
}

Game::~Game()
{
	return ;
}

Game::Game(Game const & copy)
{
	*this = copy;

	return ;
}

void				Game::createEnemy(Enemy **e, WINDOW * w)
{
	int 			i;

	i = -1;
	while (++i < 64)
	{
		if (e[i] == NULL)
		{
			e[i] = new Enemy(w, '<');
			return ;
		}
	}
}

void				Game::moveAllEnemy(Enemy **e)
{
	int 			i;

	i = -1;
	while (++i < 64)
	{
		if (e[i] != NULL)
			e[i]->move();
	}
}

void				Game::deleteEnemy(Player *p, Enemy **e)
{
	int 			i;

	i = -1;
	while (++i < 64)
	{
		if (e[i] != NULL)
		{
			int j;

			j = -1;
			while (++j < 64)
			{
				if (p->getBullet(j) && e[i]->checkCollision(p->getBullet(j)->getX(), p->getBullet(j)->getY()))
				{
					int k;

					k = -1;
					e[i]->setHitToDie(e[i]->getHitToDie() - 1);
					if (e[i]->getHitToDie() == 0)
					{
						while (++k < 3)
						{
							if (e[i]->getBullet(k))
								delete(e[i]->getBullet(k));
						}
						e[i]->clearEnemy();
						p->setScore(p->getScore() + 5);
						p->setGS(5);
						delete(e[i]->getBullets());
						delete(e[i]);
						e[i] = NULL;
						break ;
					}
				}
				else if (e[i]->getX() <= 1)
				{
					int k;

					k = -1;
					while (++k < 3)
					{
						if (e[i]->getBullet(k))
							delete(e[i]->getBullet(k));
					}
					delete(e[i]->getBullets());
					e[i]->clearEnemy();
					p->setHitPoint(p->getHitPoint() - 1);
					delete(e[i]);
					e[i] = NULL;
					break ;
				}
			}
		}
	}
}

int					Game::checkPlayer(Player *p, Enemy **e)
{
	int 			i;

	i = -1;
	while (++i < 64)
	{
		if (e[i])
		{

			if (p->getX() == e[i]->getX() && p->getY() == e[i]->getY())
				return (1);
		}
		if (p->getHitPoint() <= 0)
			return (1);
	}
	return (0);
}

int 				Game::checkBulEnemy(Enemy **e, Player *p)
{
	int 			i;
	int 			j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		if (e[i])
		{
			while (++j < 3)
			{
				if (e[i]->getBullet(j) != NULL)
				{
					if (e[i]->getBullet(j)->getX() == p->getX() && e[i]->getBullet(j)->getY() == p->getY())
					{
						p->setHitPoint(-1);
						if (p->getHitPoint() < 0)
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

void				Game::deleteBullet(Enemy ** e)
{
	int i;

			i = -1;
			while (++i < 64)
			{
				if (e[i] != NULL)
					e[i]->killBul();
			}
}

void				Game::createBoss(Enemy ** e, Player *p, WINDOW * menuwin)
{
	int 			i;

	i = -1;
	while (++i < 64)
	{
		if(!e[i])
		{
			e[i] = new Boss(menuwin, '*');
			p->setScore(0);
			p->setLevel(p->getLevel() + 1);
			if (enemySpeed > 2000)
				enemySpeed -= 500;
			if (creationSpeed > 10000)
				creationSpeed -= 4000;
			return ;
		}
	}
}

void				Game::initEnemy(Enemy ** e)
{
	int i;
	i = -1;
	while (++i < 64)
		e[i] = NULL;
}

void				Game::statDo(WINDOW *statmenu, Player *p)
{
	int 			sec;
	int 			min;
	int 			flag;

	min = 0;
	flag = 0;
	sec = 0;
	sec = (int)(clock()/1000000.0) % 60;
		if (sec == 59 && flag == 0)
		{
			flag = 1;
			min++;
		}
		if (sec < 59)
			flag = 0;
		mvwprintw(statmenu, 1, 1, "Timer : %02i:%02i", min, sec);
		mvwprintw(statmenu, 2, 1, "Score: %02i", p->getGS());
		mvwprintw(statmenu, 4, 1, "Level : %d", p->getLevel());
		mvwprintw(statmenu, 3, 1, "HP : %d%d", p->getHitPoint()/10, p->getHitPoint() % 10);
		wrefresh(statmenu);
}

void				Game::checkAndDelete(Player *p, Enemy **e)
{
		deleteEnemy(p, e);
		deleteBullet(e);
		p->deleteBullet();
}

void				Game::moveAllBull(Player *p, Enemy **e)
{
	int i;

	i = -1;
	while (++i < 64)
	{
		if (e[i])
			e[i]->moveBul();
	}
	p->flyBullet();
}

void				Game::creationAll(WINDOW *menuwin, Enemy **e)
{
	int i;

			i = -1;
			while (++i < 64)
			{
				if (e[i])
					e[i]->createBullet();
			}
			createEnemy(e, menuwin);
}


int 				Game::getEnemySpeed() const 
{
	return (enemySpeed);
}

int 				Game::getCreationSpeed() const 
{
	return (creationSpeed);
}

int 				Game::getBulSpeed() const
{
	return (bulSpeed);
}