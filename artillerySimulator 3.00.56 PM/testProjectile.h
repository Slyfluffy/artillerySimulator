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
      
   }
   
   void testLinearInterpolation1() {
      
   }
   
   void testLinearInterpolation2() {
      
   }
   
   void testLinearInterpolation3() {
      
   }
   
   void testComputeAirDensity() {
      
   }
   
   void testComputeVelocitySound() {
      
   }
   
   void testComputeGravity() {
      
   }
   
   void testComputeCoefficient() {
      
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
