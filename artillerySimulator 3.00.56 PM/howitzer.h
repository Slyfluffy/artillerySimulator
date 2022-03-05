//
//  howitzer.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef howitzer_h
#define howitzer_h
#include "position.h"

class Howitzer {
private:
   Position p;
   float angle;
   float age;
   
public:
   Howitzer();
   Howitzer(Position p);
   
   void rotateLeft();
   void rotateRight();
   
   void rotateUp();
   void rotateDown();
   
   void fire() { age = 2; }
   void reset();
   
   void draw(ogstream & gout);
};

#endif /* howitzer_h */
