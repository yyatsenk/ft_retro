#ifndef BOSS_HPP
# define BOSS_HPP

#include "Enemy.hpp"

class Boss : public Enemy
{
	public	:
		Boss & operator=(Boss const & copy);
		Boss();
		Boss(WINDOW * win, char c);
		Boss(Boss const & copy);
		~Boss();

		void			clearEnemy();
		void			move();
		int				checkCollision(int x, int y);
};

#endif