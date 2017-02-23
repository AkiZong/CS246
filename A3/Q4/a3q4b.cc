#include "player.h"
#include "scoreboard.h"
#include <iostream>
#include <string>

using namespace std;



int main(){
	ScoreBoard *bone = ScoreBoard::getInstance();
	Player *X = Player::getInstanceX();
	Player *O = Player::getInstanceO();
	string stdincmd;
	while(!bone->gameover()){
        if(cin>>stdincmd){
        //cout<<"stdincmmd: "<<stdincmd<<endl;
		if(stdincmd=="game"){
			bone->startGame();
			if(bone->gameround()%2==0){
				while(!bone->whowins()){
					cout<<"X's move"<<endl;
					X->makeMove();
					if(bone->whowins()){
						break;
					}
					cout<<"O's move"<<endl;
					O->makeMove();
					if(bone->whowins()){
						break;
					}
				}
			}else{
				while(!bone->whowins()){
					cout<<"O's move"<<endl;
					O->makeMove();
					if(bone->whowins()){
						break;
					}
					cout<<"X's move"<<endl;
					X->makeMove();
					if(bone->whowins()){
						break;
					}
				}
			}
			if(bone->whowins()==10){
				X->wingame();
				X->clearindex();
				O->clearindex();
				bone->gamernd++;
				cout<<"X wins"<<endl;
                cout<<"Score is"<<endl;
				cout<<"X "<<X->winnum()<<endl;
				cout<<"O "<<O->winnum()<<endl;
			}else if(bone->whowins()==11){
				O->wingame();
				X->clearindex();
				O->clearindex();
				bone->gamernd++;
				cout<<"O wins"<<endl;
                cout<<"Score is"<<endl;
				cout<<"X "<<X->winnum()<<endl;
				cout<<"O "<<O->winnum()<<endl;
			}else{
				bone->gamernd++;
				cout<<"Draw"<<endl;
                cout<<"Score is"<<endl;
				cout<<"X "<<X->winnum()<<endl;
				cout<<"O "<<O->winnum()<<endl;
			}
		}else if(stdincmd=="quit"){
			bone->quit=true;
		}
        }else{
            break;
        }
    }
	//delete X;
	//delete O;
//	delete bone;
}
