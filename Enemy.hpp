#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Bullet.hpp"
# include <ncurses.h>
# include <string>
# include <iostream>

class				Enemy
{
	protected :
		int			hp;
		int			x;
		int			y;
		int			xMax;
		int			yMax;
		char		visual;
		int			bulInUse;
		WINDOW *	curwin;
		Bullet **	bullets;
		int			hitToDie;

	public :

		Enemy & operator=(Enemy const & copy);
		Enemy(WINDOW * win, char c);
		Enemy(void);
		Enemy(Enemy const & copy);
		virtual ~Enemy(void);

		virtual void	move();
		virtual int		checkCollision(int x, int y);
		void			createEnemy();
		int				getX() const ;
		int				getY() const ;
		void			setX(int x);
		void			killBul();
		void			moveBul();
		void			createBullet();
		char			getVisual() const;
		Bullet**		getBullets() const;	
		Bullet*			getBullet(int i) const;
		WINDOW *		getWin() const;
		void			setHitToDie(int i) ;
		int				getHitToDie() const ;
		virtual void			clearEnemy();
};

#endif