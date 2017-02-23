#include "cell.h"
#include "game.h"
using namespace std;


Cell::Cell(): state(0), prevState(0), numNeighbours(0), r(0), c(0) {
    game = NULL;
    for (int i=0; i<4; i++) {
        neighbours[i] = NULL;
    }
}


char Cell::getState() {
    if (state == 0) {
        return '0';
    } else if (state == 1) {
        return '1';
    } else if (state == 2) {
        return '2';
    } else if (state == 3) {
        return '3';
    } else {
        return '4';
    }
}


void Cell::setState(const int &change) {
    prevState = state;
    state = change;
}


void Cell::setCoords(const int r, const int c) {
    this->r = r;
    this->c = c;
}


void Cell::setGame(Game * game) {
    this->game = game;
}


void Cell::addNeighbour(Cell *neighbour) {
    neighbours[numNeighbours] = neighbour;
    numNeighbours++;
}


void Cell::notify( const int & change) {
    if (change!=state){
    prevState = state;
    state = change;
    notify(state, prevState);
    notifyGame();
    }
}


void Cell::notify(const int & current, const int & previous) {
    for (int i=0; i<numNeighbours; i++) {
        if (neighbours[i]->state == previous) {
            neighbours[i]->prevState = previous;
            neighbours[i]->state = current;
            neighbours[i]->notifyGame();
            neighbours[i]->notifyNeighbours();
        }
    }
}


void Cell::notifyNeighbours() {
    notify(state, prevState);
}


void Cell::notifyGame() {
    game->notify(r,c,prevState,state);
}



