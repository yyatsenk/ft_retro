#ifndef BULLET_HPP
# define BULLET_HPP

# include <ncurses.h>
# include <iostream>

class				Bullet
{
	private :
		int 		x;
		int			y;
		WINDOW *	curwin;
		char		visual;

	public :
		Bullet & operator=(Bullet const & copy);
		Bullet(WINDOW * win, int x, int y);
		Bullet(void);
		Bullet(Bullet const & copy);
		~Bullet(void);

		void			fly(int i);
		int				getX()  const;
		int				getY()	const;
		char			getVisual() const;
		WINDOW *		getWin() const;
		void			setX(int x);
};

#endif

