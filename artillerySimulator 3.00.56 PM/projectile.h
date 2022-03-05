//
//  projectile.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef projectile_h
#define projectile_h

#include <vector>

#include "position.h"
#include "velocity.h"

using namespace std;

struct Mapping {
   float domain;
   float range;
};

class Projectile {
private:
   Position p;
   Velocity v;
   vector<Position> tail;
   
   float angle;
   float hangTime;
   
public:
   float linearInterpolation(float x, float x0, float x1, float y0, float y1)   { return 0; }
   float linearInterpolation(const Mapping zero, const Mapping one, float d)    { return 0; }
   float linearInterpolation(const Mapping map[], int numMapping, float domain) { return 0; }
   
   float computeAirDensity(float altitude) { return 0; }
   float computeVelocitySound(float altitude) { return 0; }
   float computeGravity(float altitude) { return 0; }
   float computeCoefficient(float v, float vSound) { return 0; }
   
public:
   Projectile() { }
   Projectile(float angle, Position p);
   Projectile& operator = (const Projectile &p);
   
   const float getAltitude();
   const float getDistance();
   const float getSpeed();
   const float getHangTime();
   const Position getPosition();
   const Velocity getVelocity();
   
   void move();
   
   void reset();
   void draw(ogstream & gout);
};

#endif /* projectile_h */
