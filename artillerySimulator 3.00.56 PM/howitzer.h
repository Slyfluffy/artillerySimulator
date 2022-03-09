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

class Howitzer {
private:
   Position p;
   double angle;
   float age;
   
public:
   Howitzer() : p(Position()), angle(0), age(0) {}
   Howitzer(Position p) : p(p), angle(0), age(0) {}
   
   float getAge() const         { return age;   }
   double getAngle() const       { return angle; }
   Position getPosition() const { return p;     }
   
   void setAngle(double angle) { this->angle = angle; }
   
   void rotateLeft();
   
   void rotateRight();
   
   void rotateUp();
   
   void rotateDown();
   
   void fire() { age = 2; }
   void reset();
   
   void draw(ogstream & gout);
};

#endif /* howitzer_h */
