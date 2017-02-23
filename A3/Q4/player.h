#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>

/* player is a class to record players' information: names, players' score, 
   players' move
 */
class Player{
		static Player* singletonX;
		static Player* singletonO;
        int name;
        int winn;
        int index;
        Player(int);
        static void deletex();
        static void deleteo();
	public:
        static Player* getInstanceX();
        static Player* getInstanceO();
		void clearindex();
		void wingame();
		void makeMove();
		int winnum();

};

#endif

