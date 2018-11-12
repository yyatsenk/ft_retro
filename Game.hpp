#ifndef GAME_HPP
# define GAME_HPP

# include "Player.hpp"
# include "Enemy.hpp"
# include <ncurses.h>
# include "Boss.hpp"

class Game
{

	private :
		int 	enemySpeed;
		int 	creationSpeed;
		int 	bulSpeed;

	public:
		Game &	operator=(Game const & copy);

		Game();
		~Game();
		Game(Game const & copy);
		void				createEnemy(Enemy **e, WINDOW * w);
		void				moveAllEnemy(Enemy **e);
		void				deleteEnemy(Player *p, Enemy **e);
		int					checkPlayer(Player *p, Enemy **e);
		int 				checkBulEnemy(Enemy **e, Player *p);
		void				deleteBullet(Enemy ** e);
		void				mainGame(Enemy ** e, Player *p, WINDOW * w);
		void				createBoss(Enemy ** e, Player *p, WINDOW * w);
		void				initEnemy(Enemy ** e);
		void				statDo(WINDOW *statmenu, Player *p);
		void				checkAndDelete(Player *p, Enemy **e);
		void				moveAllBull(Player *p, Enemy **e);
		void				creationAll(WINDOW *menuwin, Enemy **e);
		int 				getEnemySpeed() const ;
		int 				getCreationSpeed() const ;
		int 				getBulSpeed() const ;
};

#endif