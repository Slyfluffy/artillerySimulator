//
//  howitzer.cpp
//  Lab08
//
//  Created by Journey Curtis on 3/8/22.
//

#include "howitzer.h"

void Howitzer::rotateLeft() {
   if ((angle > -(M_PI/2)) && (angle <= (M_PI/2)))
      angle -= .05;
   
   if (angle < -(M_PI/2))
      angle = -M_PI/2;
};

void Howitzer::rotateRight() {
   if ((angle >= -(M_PI/2)) && (angle < (M_PI/2)))
      angle += .05;
   
   if (angle > (M_PI/2))
      angle = M_PI/2;
};

void Howitzer::rotateUp() {
   if ((angle >= (-M_PI/2)) && angle < -0.003)
      angle += .003;
   else if ((angle > 0.003 && angle <= (M_PI/2)))
      angle -= .003;
   else
      angle = 0;
};

void Howitzer::rotateDown() {
   if ((angle < 0) && (angle >= (-(M_PI/2) + .003)))
      angle -= .003;
   else if ((angle > 0) && (angle <= ((M_PI/2) - .003)))
      angle += .003;
   else if (angle < (-(M_PI/2) + .003))
      angle = -M_PI/2;
   else if (angle > (M_PI/2) - .003)
      angle = M_PI/2;
};

void Howitzer::reset() {
   
};

void Howitzer::draw(ogstream & gout) {
   
};
