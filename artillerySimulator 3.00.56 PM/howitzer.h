//
//  howitzer.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef howitzer_h
#define howitzer_h

#include "position.h"
#include "uiDraw.h"

const float M_PI = 3.14159;

/***********************************************
 * ARTILLERY :: HOWITZER CLASS
 * This class contains all the data necessary
 * to run a howitzer object in the Artillery
 * Simulator. This includes the position, angle,
 * and drawing of it.
 **********************************************/
class Howitzer {
private:
   Position p;
   double angle;
   float age;
   
public:
   // Constructors
   Howitzer() : p(Position()), angle(0), age(0) {}
   Howitzer(Position p) : p(p), angle(0), age(0) {}
   
   // Getters
   float getAge() const         { return age;   }
   double getAngle() const       { return angle; }
   Position getPosition() const { return p;     }
   
   // Setters
   void setAngle(double angle) { this->angle = angle; }
   
   // Rotation methods
   void rotateLeft();
   void rotateRight();
   void rotateUp();
   void rotateDown();
   
   // Other
   void fire() { age = 2; }
   void reset(Position p);
   void draw(ogstream & gout);
};

#endif /* howitzer_h */
