//
//  testProjectile.h
//  Lab08
//
//  Created by Journey Curtis on 3/5/22.
//

#ifndef testProjectile_h
#define testProjectile_h

#include "physics.h"
#include "projectile.h"
#include <cassert>
class TestProjectile {
public:
   void run() {
      testLinearInterpolation1();
      testLinearInterpolation2();
      testLinearInterpolation3();
      testComputeAirDensity();
      testComputeVelocitySound();
      testComputeGravity();
      testComputeCoefficient();
   }
   
   void testConstructor() {
       // Setup: default constructors
       Projectile* p = new Projectile();
       Position* pos = new Position();
       Velocity* v = new Velocity();
       // Exersize and verify
       assert(p->getPosition().getMetersX() == pos->getMetersX());
       assert(p->getPosition().getMetersY() == pos->getMetersY());

       assert(p->getVelocity().getDx() == v->getDx());
       assert(p->getVelocity().getDy() == v->getDy());
       
       // Teardown
       delete[] p;
       delete[] pos;
       delete[] v;
   }
   
   void testLinearInterpolation1() {
       // Exersize and verify
       // Positive slope
       assert(linearInterpolation(1, 0, 2, 0, 2) == 1.0);
       // Negative slope
       assert(linearInterpolation(1, 0, 2, 2, 0) == 1.0);
       // Horizontal line
       assert(linearInterpolation(1, 0, 2, 0, 0) == 0.0);
       // Vertical line
       assert(linearInterpolation(1, 1, 1, 0, 2) == 1.0);
   }
   
   void testLinearInterpolation2() {
       // Positive slope
       Mapping zero;
       Mapping one;
       zero.domain = 0;
       zero.range = 0;
       one.domain = 2;
       one.range = 2;
       assert(linearInterpolation(zero, one, 1) == 1.0);
       // Negative slope
       zero.range = 2;
       one.range = 0;
       assert(linearInterpolation(zero, one, 1) == 1.0);
       // Horizontal line
       zero.range = 0;
       assert(linearInterpolation(zero, one, 1) == 0.0);
       // Vertical line
       zero.domain = 1;
       one.domain = 1;
       one.range = 2;
       assert(linearInterpolation(zero, one, 1) == 1.0);
   }
   
   void testLinearInterpolation3() {
       // Positive slope
       Mapping zerozero;
       zerozero.domain = 0;
       zerozero.range = 0;
       Mapping zerotwo;
       zerotwo.domain = 0;
       zerotwo.range = 2;
       Mapping twozero;
       twozero.domain = 2;
       twozero.range = 0;
       Mapping twotwo;
       twotwo.domain = 2;
       twotwo.range = 2;
       Mapping onezero;
       onezero.domain = 1;
       onezero.range = 0;
       Mapping onetwo;
       onetwo.domain = 1;
       onetwo.range = 2;
       Mapping map[] = { zerozero, twotwo };
       assert(linearInterpolation(map, 2 , 1) == 1.0);
       // Negative slope
       map[0] = zerotwo;
       map[1] = twozero;
       assert(linearInterpolation(map, 2, 1) == 1.0);
       // Horizontal line
       map[0] = zerozero;
       assert(linearInterpolation(map, 2, 1) == 0.0);
       // Vertical line
       map[0] = onezero;
       map[1] = onetwo;
       assert(linearInterpolation(map, 2, 1) == 1.0);
   }
   
   void testComputeAirDensity() {
       // Table
       assert(computeAirDensity(15000) == 0.1948);
       // Low Interp
       assert(computeAirDensity(500) == 1.1685);
       // High Interp
       assert(computeAirDensity(65000) == 0.00019625);
   }
   
   void testComputeVelocitySound() {
       // Table
       assert(computeVelocitySound(8000) == 308);
       // Low Interp
       assert(computeVelocitySound(500) == 338);
       // High Interp
       assert(computeVelocitySound(35000) == 314.5);
      
   }
   
   void testComputeGravity() {
       // Table
       assert(computeGravity(8000) == 9.782);
       // Low Interp
       assert(computeGravity(500) == 9.8055);
       // High Interp
       assert(computeGravity(8000) == 9.7375);
   }
   
   void testComputeCoefficient() {
       // Table (mach = 1.06)
       assert(computeCoefficient(326.48, 308) == 0.4483);
       // Low Interp (mach = .4)
       assert(computeCoefficient(120, 300) == 0.1644);
       // High Interp (mach = 3.945)
       assert(computeCoefficient(1183.5, 300) == 0.2481);
   }
   
//   void testMove() {
//      Position pos;
//      float angle;
//
//      // -90 degree scenario
//      angle = -M_PI/2;
//      Projectile p(angle, pos);
//      p.move();
//
//      // -45 degree scenario
//      angle = -M_PI/4;
//      p = Projectile(angle, pos);
//      p.move();
//
//      // 0 degree scenario
//      angle = 0;
//      p = Projectile(angle, pos);
//      p.move();
//      assert(p.getVelocity().getDx() == 0);
//      assert(p.getVelocity().getDy() == (827 - computeGravity(0)));
//
//      // 45 degree scenario
//      angle = M_PI/4;
//      p = Projectile(angle, pos);
//      p.move();
//
//
//      // 90 degree scenario
//      angle = M_PI/2;
//      p = Projectile(angle, pos);
//      p.move();
//   }
};

#endif /* testProjectile_h */
