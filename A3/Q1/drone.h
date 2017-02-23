#ifndef __DRONE_H__
#define __DRONE_H__
#include <iostream>

/* Position is a structure contains two integers which indicates
   a Drone's 2-dimensional position
 */
struct Position {
    int ew, ns;
};


/* Drone is a class to control a simple robotic drone exploring
   some terrain
 */
struct Drone {
    Position p;
    char face;
    int total;
    Position visited[51];
    Drone();
    void forward();
    void backward();
    void left();
    void right();
    Position current();
    int totalDistance();
    int manhattanDistance();
    bool repeated();
};

#endif