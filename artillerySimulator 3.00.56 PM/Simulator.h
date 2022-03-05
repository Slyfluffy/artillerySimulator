//
//  Simulator.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef Simulator_h
#define Simulator_h

#include "howitzer.h"
#include "projectile.h"
#include "uiInteract.h"
#include "ground.h"

class Simulator {
private:
   Howitzer howitzer;
   Projectile projectile;
   Interface ui;
   Ground ground;
   
public:
   void input(Interface & ui);
   void fire();
   
   void runSimulation();
   void advance();
   void display();
   void reset();
};

#endif /* Simulator_h */
