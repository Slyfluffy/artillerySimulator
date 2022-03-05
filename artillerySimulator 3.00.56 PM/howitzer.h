//
//  howitzer.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef howitzer_h
#define howitzer_h

#include <cmath>
#include "position.h"
#include "uiDraw.h"

class Howitzer {
protected:
   Position p;
   float angle;
   float age;
   
public:
   Howitzer();
   Howitzer(Position p);
   
   const float getAge();
   const float getAngle();
   const Position getPosition();
   
   void setAngle(float angle);
   
   void rotateLeft();
   void rotateRight();
   
   void rotateUp();
   void rotateDown();
   
   void fire() { age = 2; }
   void reset();
   
   void draw(ogstream & gout);
};

#endif /* howitzer_h */
