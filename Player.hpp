#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <iostream>
# include <ncurses.h>
# include "Bullet.hpp"
# include "Enemy.hpp"

class				Player
{
	private	:
		int				x;
		int				y;
		int				xMax;
		int				yMax;
		char			visual;
		WINDOW *		curwin;
		Bullet **		bullets;
		int				hitPoint;
		int				level;
		int				score;
		int				gsc;
	
	public :

		Player & operator=(Player const & copy);
		Player(WINDOW * win, int y, int x, char c);
		Player(void);
		Player(Player const & copy);
		~Player(void);

		void 		mvUp();
		void 		mvDown();
		void 		mvRight();
		void 		mvLeft();
		void 		display();
		int			getMV();
		void		createBullet();
		Bullet *	getBullet(int i) const;
		void		deleteBullet();
		void		flyBullet();
		int			getX() const;
		int			getY() const;
		int			getHitPoint() const;
		int			getScore() const;
		int			getLevel() const;
		void		setLevel(int i);
		void		setHitPoint(int i);
		void		setScore(int i);
		int			getGS() const;
		void		setGS(int i);
};

#endif
