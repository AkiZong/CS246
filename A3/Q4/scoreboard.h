#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__
#include <iostream>

/* ScoreBoard is a class to record a scoreboard's information: how many games
   have been played, how many grids have been used, where a player's moves come
   from(stdin or .txt), who wins the game, whether the game is over, which round
   is the game, whether the game has started
 */
class ScoreBoard{
        ScoreBoard();
        static ScoreBoard* singleton;
        int a[9];
        static void deleteboard();
	public:
		int gamernd;
		int numofgrid;
        std::string inputtype[2];
		static ScoreBoard* getInstance();
		int whowins();
		bool gameover();
		int gameround();
		void makeMove(const int& mv, const int& name);
		void startGame();
        bool already(const std::string& move);
		bool quit;
};

#endif

