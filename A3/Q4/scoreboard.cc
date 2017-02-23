#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include "scoreboard.h"

using namespace std;

// ScoreBoard(): initializa a ScoreBoard
ScoreBoard::ScoreBoard():gamernd(0),quit(false),numofgrid(0){};

// singleton
ScoreBoard* ScoreBoard::singleton=NULL;

// deleteboard(): delete the singleton scoreboard
void ScoreBoard::deleteboard() {
    delete singleton;
}

// getInstance(): singleton
ScoreBoard* ScoreBoard::getInstance(){
	if (singleton) return singleton;
	singleton = new ScoreBoard();
    atexit(deleteboard);
	return singleton;
}

// whowins(): returns which player wins or draw in the certain game
int ScoreBoard::whowins(){
	if((a[0]==a[1])&&(a[0]==a[2])){
		return a[0];
	}else if((a[3]==a[4])&&(a[3]==a[5])){
		return a[3];
	}else if((a[6]==a[7])&&(a[6]==a[8])){
		return a[6];
	}else if((a[0]==a[3])&&(a[3]==a[6])){
		return a[0];
	}else if((a[1]==a[4])&&(a[4]==a[7])){
		return a[1];
	}else if((a[2]==a[5])&&(a[5]==a[8])){
		return a[2];
	}else if((a[0]==a[4])&&(a[0]==a[8])){
		return a[0];
	}else if((a[2]==a[4])&&(a[4]==a[6])){
		return a[2];
	}else if(numofgrid==9){
		return 12;
	}
	return 0;
}

// gameover(): determine if the game has been quit
bool ScoreBoard::gameover(){
	return quit;
}

// gameround(): return which round is the game in
int ScoreBoard::gameround(){
	return gamernd;
}

// nameMove(tmp, name): players make move
void ScoreBoard::makeMove(const int& tmp, const int& name){
	a[tmp]=name;
}

// startGame(): statrt a new game (initialize the scoreboard)
void ScoreBoard::startGame(){
	for (int i=0;i<9;i++){
		a[i]=i;
	}
	numofgrid=0;
	quit=false;
	cin >> inputtype[0];
	cin >> inputtype[1];
}

// already(move): determine if the grid has been taken or not
bool ScoreBoard::already(const string &move){
	int mv;
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
	if(a[mv]<10){
		return false;
	}else{
		return true;
	}
}



















