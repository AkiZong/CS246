#include "player.h"
#include "scoreboard.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Player* Player::singletonX=NULL;
Player* Player::singletonO=NULL;

// getInstanceo(): initialize the singleton for player X
Player* Player::getInstanceX(){
	if (singletonX) return singletonX;
	singletonX = new Player(10);
    atexit(deletex);
	return singletonX;
}

// getInstanceo(): initialize the singleton for player O
Player* Player::getInstanceO(){
	if (singletonO) return singletonO;
	singletonO = new Player(11);
    atexit(deleteo);
	return singletonO;
}

// deletex(): delete singletonX
void Player::deletex() {
    delete singletonX;
}

// delete0(): delete singletonO
void Player::deleteo() {
    delete singletonO;
}

// Player(nm): initialize the information of a player
Player::Player(int nm):name(nm),winn(0),index(1) {};

// winnum(): return how many times a player wins
int Player::winnum(){
	return winn;
}

// wingame(): if a player wins, add 1 to his/her score
void Player::wingame(){
	winn++;
}

/* makeMove(): fetching the next move and calling the ScoreBoard::makeMove
   method to register the move with the scoreboard
 */
void Player::makeMove(){
	ScoreBoard* board=ScoreBoard::getInstance();
	string move;
	int mv;
	if (board->inputtype[name-10]=="stdin"){
		cin >> move;
		while(board->already(move)){
			cin>>move;
		}
	}else{
		ifstream file (board->inputtype[name-10].c_str());
		for (int i=0;i<index;i++){
			file>>move;
		}
		index++;
		while(board->already(move)){
			index++;
			file>>move;
		}
		cout<<"(plays "<<move<<")"<<endl;
	}
	board->numofgrid++;
	if(move=="NW"){
		mv=0;
	}else if(move=="N"){
		mv=1;
	}else if(move=="NE"){
		mv=2;
	}else if(move=="W"){
		mv=3;
	}else if(move=="C"){
		mv=4;
	}else if(move=="E"){
		mv=5;
	}else if(move=="SW"){
		mv=6;
	}else if(move=="S"){
		mv=7;
	}else if(move=="SE"){
		mv=8;
	}
	board->makeMove(mv,name);
}

// clearindex(): set index to 1
void Player::clearindex(){
	index=1;
}










