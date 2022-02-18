//
//  environment.h
//  Lab08
//
//  Created by Journey Curtis on 2/18/22.
//  Serves as a mini library for the environment tables and calculations

#ifndef environment_h
#define environment_h

/****************************************
 * ARTILLERY :: COMPUTENEARBYAIRDENSITY
 * INPUTS    :: altitude, p0, p1
 * OUTPUTS   :: NONE
 * Adjusts the two nearby points to match
 * the Air Density data table.
 ***************************************/
void computeNearbyAirDensity(float altitude, Position * p0, Position * p1) {
   if (altitude < 1000) {
      *p0 = Position(0, 1.225);
      *p1 = Position(1000, 1.112);
   }
   else if (altitude < 2000) {
      *p0 = Position(1000, 1.112);
      *p1 = Position(2000, 1.007);
   }
   else if (altitude < 3000) {
      *p0 = Position(2000, 1.007);
      *p1 = Position(3000, .9093);
   }
   else if (altitude < 4000) {
      *p0 = Position(3000, .9093);
      *p1 = Position(4000, .8194);
   }
   else if (altitude < 5000) {
      *p0 = Position(4000, .8194);
      *p1 = Position(5000, .7364);
   }
   else if (altitude < 6000) {
      *p0 = Position(5000, .7364);
      *p1 = Position(6000, .6601);
   }
   else if (altitude < 7000) {
      *p0 = Position(6000, .6601);
      *p1 = Position(7000, .59);
   }
   else if (altitude < 8000) {
      *p0 = Position(7000, .59);
      *p1 = Position(8000, .5258);
   }
   else if (altitude < 9000) {
      *p0 = Position(8000, .5258);
      *p1 = Position(9000, .4671);
   }
   else if (altitude < 10000) {
      *p0 = Position(9000, .4671);
      *p1 = Position(10000, .4135);
   }
   else if (altitude < 15000) {
      *p0 = Position(10000, .4135);
      *p1 = Position(15000, .1948);
   }
   else if (altitude < 20000) {
      *p0 = Position(15000, .1948);
      *p1 = Position(25000, .08891);
   }
   else if (altitude < 25000) {
      *p0 = Position(20000, .08891);
      *p1 = Position(25000, .04008);
   }
   else if (altitude < 30000) {
      *p0 = Position(25000, .04008);
      *p1 = Position(30000, .01841);
   }
   else if (altitude < 40000) {
      *p0 = Position(30000, .01841);
      *p1 = Position(40000, .003996);
   }
   else if (altitude < 50000) {
      *p0 = Position(40000, .003996);
      *p1 = Position(50000, .001027);
   }
   else if (altitude < 60000) {
      *p0 = Position(50000, .001027);
      *p1 = Position(60000, .0003097);
   }
   else if (altitude < 70000) {
      *p0 = Position(60000, .0003097);
      *p1 = Position(70000, .0000828);
   }
   else if (altitude < 80000) {
      *p0 = Position(70000, .0000828);
      *p1 = Position(60000, .0000185);
   }
}

/************************************************
 * ARTILLERY :: COMPUTEAIRDENSITY
 * INPUTS    :: altitude
 * OUTPUTS   :: airDensity
 * Calculates the air density based on altitude.
 * Calls computeNearbyAirDensity to set p0 and p1
 * to the correct data so we can use it
 ***********************************************/
float computeAirDensity(float altitude) {
   if (altitude > 0) {
      Position p0;
      Position p1;
      computeNearbyAirDensity(altitude, &p0, &p1);
      
      float top = (p1.getMetersY()-p0.getMetersY()) * (altitude - p0.getMetersX());
      return p0.getMetersY() + (top / (p1.getMetersX() - p0.getMetersX()));
   }

   return 1.225;
}

void computeNeabySoundVelocity(float altitude, Position * p0, Position * p1) {
   float multiplyX = int(altitude / 1000);
   float lowX = multiplyX * 1000;
   
   if (altitude < 8000) {
      *p0 = Position(lowX, 340 - (4 * multiplyX));
      *p1 = Position(lowX + 1000, 340 - (4 * (multiplyX + 1)));
   }
   else if (altitude < 9000) {
      *p0 = Position(lowX, 340 - (4 * multiplyX));
      *p1 = Position(lowX + 1000, 340 - (4 * multiplyX + 1) - 1);
   }
   else if (altitude < 10000) {
      *p0 = Position(lowX, 340 - (4 * multiplyX) - 1);
      *p1 = Position(lowX + 1000, 340 - (4 * multiplyX + 1) - 1);
   }
   else if (altitude < 15000) {
      *p0 = Position(lowX, 340 - (4 * multiplyX) - 1);
      *p1 = Position(lowX + 1000, 295);
   }
   else if (altitude <= 25000) {
      *p0 = Position(lowX, 295);
      *p1 = Position(lowX + 1000, 295);
   }
   else if (altitude > 30000) {
      *p0 = Position(25000, 295);
      *p1 = Position(30000, 305);
   }
   else if (altitude < 40000) {
      *p0 = Position(30000, 305);
      *p1 = Position(40000, 324);
   }
}

float computeVelocitySound(float altitude) {
   if (altitude > 0) {
      Position p0;
      Position p1;
      computeNeabySoundVelocity(altitude, &p0, &p1);
      
      float top = (p1.getMetersY()-p0.getMetersY()) * (altitude - p0.getMetersX());
      return p0.getMetersY() + (top / (p1.getMetersX() - p0.getMetersX()));
   }

   return 340;
}

float computeGravity(float altitude) {
   float e = (6371009/(6371009 + altitude));
   return 9.807 * (e * e);
}

#endif /* environment_h */
