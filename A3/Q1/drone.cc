#include "drone.h"
#include <iostream>
#include <string>
using namespace std;

// Drone(): Drone will start at coordinates (0,0), facing north
Drone::Drone(): face('N'), total(1) {
    this->p.ew = 0;
    this->p.ns = 0;
    for (int j=0; j<51; j++) {
        this->visited[j]=this->p;
    }
}

// forward(): move one unit forward
void Drone::forward() {
    if (this->face == 'N') {
        this->p.ns++;
    } else if (this->face == 'S') {
        this->p.ns--;
    } else if (this->face == 'E') {
        this->p.ew++;
    } else {
        this->p.ew--;
    }
    this->visited[total] = this->p;
    this->total++;
}

// backward(): move one unit backward
void Drone::backward() {
    if (this->face == 'N') {
        this->p.ns--;
    } else if (this->face == 'S') {
        this->p.ns++;
    } else if (this->face == 'E') {
        this->p.ew--;
    } else {
        this->p.ew++;
    }
    this->visited[total] = this->p;
    this->total++;
}

// left(): turn 90 degrees to the left, while remaining in the same location
void Drone::left() {
    if (this->face == 'N') {
        this->face = 'W';
    } else if (this->face == 'S') {
        this->face = 'E';
    } else if (this->face == 'E') {
        this->face = 'N';
    } else {
        this->face = 'S';
    }
}

// right(): turn 90 degrees to the right, while remaining in the same location
void Drone::right() {
    if (this->face == 'N') {
        this->face = 'E';
    } else if (this->face == 'S') {
        this->face = 'W';
    } else if (this->face == 'E') {
        this->face = 'S';
    } else {
        this->face = 'N';
    }
}

// current(): returns the current position
Position Drone::current() {
    return this->p;
}

// totalDistance(): total units of distance travelled by the drone
int Drone::totalDistance() {
    return this->total-1;
}

// manhattanDistance(): Manhattan distance between current position and origin
int Drone::manhattanDistance() {
    int ew=this->p.ew;
    int ns=this->p.ns;
    if ((ew < 0) && (ns < 0)) {
        return (-1 * ew) + (-1 * ns);
    } else if (ew < 0) {
        return (-1 * ew) + ns;
    } else if (ns < 0) {
        return ew + (-1 * ns);
    } else {
        return ew + ns;
    }
}

// repeated(): true if the current position is one that the drone has previously visited
bool Drone::repeated() {
    for (int j=0; j<this->total-1; j++) {
        if ((this->visited[j].ew == this->p.ew) &&
            (this->visited[j].ns == this->p.ns)) {
            return true;
        }
    }
    return false;
}

