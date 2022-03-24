//
//  Simulator.cpp
//  Lab08
//
//  Created by Journey Curtis on 3/17/22.
//

#include "Simulator.h"

/*********************************
 * SIMULATOR :: INPUT
 * INPUTS  :: ui
 * OUTPUTS :: NONE
 * Handles the input from the user
 ********************************/
void Simulator::input(Interface &ui) {
   // Movement of howitzer
   if (ui.isUp())
      howitzer.rotateUp();
   else if (ui.isDown())
      howitzer.rotateDown();
   else if (ui.isLeft())
      howitzer.rotateLeft();
   else if (ui.isRight())
      howitzer.rotateRight();
   
   // Firing of howitzer
   if (ui.isSpace() && !projectile.isAlive())
      fire();
}

/********************************
 * SIMULATOR :: FIRE
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * Fires the projectile. Done by
 * calling the fire methods from
 * howitzer and projectile.
 *******************************/
void Simulator::fire() {
   howitzer.fire();
   projectile.fire(howitzer.getAngle(), *howitzer.getPosition(), tInterval);
}

/******************************
 * SIMULATOR :: ISTARGETHIT
 * INPUTS  :: NONE
 * OUTPUTS :: isHit
 * Method to determine if the
 * projectile was close enough
 * to count as a hit.
 ****************************/
bool Simulator::isTargetHit() {
   float targetX = ground.getTarget().getMetersX();
   float targetY = ground.getTarget().getMetersY();
   float distance = projectile.getDistance();
   float altitude = projectile.getAltitude();
   
   if ((distance >= (targetX - 20)) && (distance <= (targetX + 20)))
      if ((altitude >= (targetY - 10)) && (altitude <= (targetY + 10)))
         return true;
   
   return false;
}

/*********************************
 * SIMULATOR :: RUNSIMULATION
 * INPUTS  :: ui
 * OUTPUTS :: NONE
 * Runs the simulator by calling
 * all the methods.
 ********************************/
void Simulator::runSimulation(Interface ui) {
   input(ui);
   
   advance();
   
   if (isTargetHit())
      reset();

   display();
}

/*********************************
 * SIMULATOR :: ADVANCE
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * Move any objects. For now it is
 * the projectile.
 ********************************/
void Simulator::advance() {
   projectile.move(tInterval);
   
   if (ground.getElevationMeters(projectile.getPosition()) <= 0) {
       projectile.kill();
   }
   if (projectile.getAltitude() < 0)
       projectile.kill();
}

/*****************************
 * SIMULATOR :: DISPLAY
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * draw all the objects in the 
 * simulation
 ****************************/
void Simulator::display() {
   ogstream gout;
   ground.draw(gout);
   howitzer.draw(gout);
   projectile.draw(gout);

   // Display status
   Position start = Position();
   start.setPixelsX(570);
   start.setPixelsY(490);
   gout.setPosition(start);
   if (!projectile.isAlive())
       gout << "Angle: " << howitzer.getAngle();
   else {
       gout << "Altitude: " << projectile.getAltitude() << endl;
       gout << "Speed: " << projectile.getSpeed() << endl;
       gout << "Distance: " << projectile.getDistance() << endl;
       gout << "Hangtime: " << projectile.getHangTime() << endl;
       gout << "Pos: " << projectile.getPosition().getMetersX() << " - " 
           << projectile.getPosition().getMetersY() << endl;
       gout << "Ground: " << ground.getElevationMeters(projectile.getPosition()) << endl;
       gout << "Alive: " << projectile.isAlive();
   }
}

/**********************************
 * SIMULATOR :: RESET
 * INPUTS  :: NONE
 * OUTPUTS :: NONE
 * Resets the simulator for another
 * round.
 *********************************/
void Simulator::reset() {
   double topBorder = ptUpperRight.getMetersY();
   double rightBorder = ptUpperRight.getMetersX();
   
   double x = ((double)rand() / (double)RAND_MAX * (rightBorder));
   double y = ((double)rand() / (double)RAND_MAX * (topBorder));
   
   Position p(x, y);
   
   howitzer.reset(p);
   ground.reset(*howitzer.getPosition());
   projectile.reset();
}
