#include "game.h"
#include "controller.h"

using namespace std;


Game::Game(): gridSize(0) {
    theGrid = NULL;
    notification = NULL;
}


Game::~Game() {
    for (int i=0; i<gridSize*gridSize; i++) {
        delete theGrid[i];
    }
    delete [] theGrid;
}


void Game::notify(int r, int c, unsigned int oldState, unsigned int newState) {
    notification->notify(r, c, newState+48);
    colours[oldState]--;
    colours[newState]++;
}


bool Game::isWon() {
    for (int i=0; i<5; i++) {
        if (colours[i] == gridSize*gridSize) {
            return true;
        }
    }
    return false;
}


void Game::init(int n, GameNotification *gameNotification) {
    //clearGame();
    notification=gameNotification;
    colours[0]=n*n;
    for(int i=1;i<5;i++){
        colours[i]=0;
    }
    theGrid=new Cell*[n*n];
    for(int i=0;i<n*n;i++){
        theGrid[i]=new Cell;
    }
    gridSize=n;
    for (int i=0;i<gridSize;i++){
        for (int j=0;j<gridSize;j++){
            //cout<<i*gridSize+j<<endl;
            //theGrid[i*gridSize+j]=new Cell;
            theGrid[i*gridSize+j]->setCoords(i,j);
            //cout<<theGrid[i*gridSize+j]->getState()<<endl;
            theGrid[i*gridSize+j]->setGame(this);
            if((i==0)&&(j==0)){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
            }else if((i==0)&&(j==gridSize-1)){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
            }else if((i==gridSize-1)&&(j==gridSize-1)){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
            }else if((i==gridSize-1)&&(j==0)){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
            }else if(i==0){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
            }else if(i==gridSize-1){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
            }else if(j==0){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
            }else if(j==gridSize-1){
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
            }else{
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i+1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[(i-1)*gridSize+j]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j-1]);
                theGrid[i*gridSize+j]->addNeighbour(theGrid[i*gridSize+j+1]);
            }
        }
    }
}



void Game::change(const int & c) {
    theGrid[0]->notify(c);
}


void Game::init(int r, int c, int change) {
    if ((r>=0) && (r<gridSize) &&
        (c>=0) && (c<gridSize) &&
        (change >=0) && (change<=4)) {
        colours[theGrid[r*gridSize+c]->getState()-48]--;
        theGrid[r*gridSize+c]->setState(change);
        colours[change]++;
    }
}


void Game::clearGame() {
    for (int i=0; i<gridSize*gridSize; i++) {
        delete theGrid[i];
    }
    delete[] theGrid;
}


