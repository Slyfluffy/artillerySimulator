/*************************************************************
 * 1. Name:
 *      Olivia Seymour, Journey Curtis
 * 2. Assignment Name:
 *      Lab 07: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      The hardest part by far is trying to understand the physics.
 *		It's been very frustrating.
 * 5. How long did it take for you to complete the assignment?
 *      We spent about 6 hours on this.
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <cmath>        // for CMATH
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "environment.h"
#include "position.h"   // for POINT
using namespace std;

const float M_PI = 3.14159;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
//class Demo
//{
//public:
//   Demo(Position ptUpperRight) :
//      ptUpperRight(ptUpperRight),
//      ground(ptUpperRight),
//      time(0.0),
//      angle(0.0)
//   {
//      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
//      ground.reset(ptHowitzer);
//      for (int i = 0; i < 20; i++)
//      {
//         projectilePath[i].setPixelsX((double)i * 2.0);
//         projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
//      }
//   }
//
//   Ground ground;                 // the ground
//   Position  projectilePath[20];  // path of the projectile
//   Position  ptHowitzer;          // location of the howitzer
//   Position  ptUpperRight;        // size of the screen
//   double angle;                  // angle of the howitzer
//   double time;                   // amount of time since the last firing
//};
//
///*************************************
// * All the interesting work happens here, when
// * I get called back from OpenGL to draw a frame.
// * When I am finished drawing, then the graphics
// * engine will wait until the proper amount of
// * time has passed and put the drawing on the screen.
// **************************************/
//void callBack(const Interface* pUI, void* p)
//{
//   // the first step is to cast the void pointer into a game object. This
//   // is the first step of every single callback function in OpenGL.
//   Demo* pDemo = (Demo*)p;
//
//   //
//   // accept input
//   //
//
//   // move a large amount
//   if (pUI->isRight())
//      pDemo->angle += 0.05;
//   if (pUI->isLeft())
//      pDemo->angle -= 0.05;
//
//   // move by a little
//   if (pUI->isUp())
//      pDemo->angle += (pDemo->angle >= 0 ? -0.003 : 0.003);
//   if (pUI->isDown())
//      pDemo->angle += (pDemo->angle >= 0 ? 0.003 : -0.003);
//
//   // fire that gun
//   if (pUI->isSpace())
//      pDemo->time = 0.0;
//
//   //
//   // perform all the game logic
//   //
//
//   // advance time by half a second.
//   pDemo->time += 0.5;
//
//   // move the projectile across the screen
//   for (int i = 0; i < 20; i++)
//   {
//      double x = pDemo->projectilePath[i].getPixelsX();
//      x -= 1.0;
//      if (x < 0)
//         x = pDemo->ptUpperRight.getPixelsX();
//      pDemo->projectilePath[i].setPixelsX(x);
//   }
//
//   //
//   // draw everything
//   //
//
//   ogstream gout(Position(10.0, pDemo->ptUpperRight.getPixelsY() - 20.0));
//
//   // draw the ground first
//   pDemo->ground.draw(gout);
//
//   // draw the howitzer
//   gout.drawHowitzer(pDemo->ptHowitzer, pDemo->angle, pDemo->time);
//
//   // draw the projectile
//   for (int i = 0; i < 20; i++)
//      gout.drawProjectile(pDemo->projectilePath[i], 0.5 * (double)i);
//
//   // draw some text on the screen
//   gout.setf(ios::fixed | ios::showpoint);
//   gout.precision(1);
//   gout << "Time since the bullet was fired: "
//      << pDemo->time << "s\n";
//}
//
//double Position::metersFromPixels = 40.0;

float computeDragForce(float density, float soundV, float velocity, float surfaceArea);
float computeForce(float mass, float acceleration) { return mass * acceleration; }
float computeAirDensity(float altitude);


float convertToRadians(float degree) { return (2 * M_PI * (degree / 360)); }

float computeAngleFromComponents(float dx, float dy) { return atan2(dy, dx); }
float computeArea(float diameter) { return M_PI * ((diameter / 2) * (diameter / 2)); }

float calculateForce(float mass, float acceleration) { return mass * acceleration; }
float calculateVSpeed(float dy, float angle) { return dy * cos(angle); }
float calculateHSpeed(float dx, float angle) { return dx * sin(angle); }
float calculateTSpeed(float dx, float dy) { return sqrt((dx * dx) + (dy * dy)); }

int getAngle();
void displayResult(double distance, float hangtime);

float linearInterpolation(float x, float x0, float x1, float y0, float y1);

//float getDragCoefficient(float mach);



/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
//   Position ptUpperRight;
//   ptUpperRight.setPixelsX(700.0);
//   ptUpperRight.setPixelsY(500.0);
//   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
//   Interface ui(0, NULL,
//      "Demo",   /* name on the window */
//      ptUpperRight);
//
//   // Initialize the demo
//   Demo demo(ptUpperRight);
//
//   // set everything into action
//   ui.run(callBack, &demo);

   //cout << computeAirDensity(80000) << endl;

	// Get the initial info
	float angle = convertToRadians(getAngle());
	Position* point = new Position(0, 0);
	float velocity = 827;
	const float mass = 46.8;
	const float area = computeArea(.15489);
	float airDensity = 1.225;
	float hangtime = 0;

	// Do the math
	do {
		// Get sound velocity
		float soundVelocity = computeVelocitySound(point->getMetersY());
		// Use that to get mach
		float mach = velocity / soundVelocity;
		// Get the drag force
		float dragForce = computeDragForce(airDensity, soundVelocity, velocity, area);
		// Acceleration now
		float acc = dragForce / mass;
		// Velocities
		float dx = sin(angle) * velocity;
		float dy = cos(angle) * velocity;
		// Accelerations
		float ddx = -sin(angle) * acc;
		float ddy = -cos(angle) * acc - computeGravity(point->getMetersY());
		// Update position
		point->addMetersX(point->getMetersX() + dx * .5 + .5 * ddx * .25);
		point->addMetersY(point->getMetersY() + dy * .5 + .5 * ddy * .25);
		// Update velocity
		dx += ddx * .5;
		dy += ddy * .5;
		velocity = calculateTSpeed(dx, dy);
		// Update angle
		angle = computeAngleFromComponents(dx, dy);
		// Update air density
		airDensity = computeAirDensity(point->getMetersY());
		// Update hangtime
		hangtime += .5;

	} while (point->getMetersY() > 0);
	// Show the results
	displayResult(point->getMetersX(), hangtime);
	


   return 0;

}

int getAngle() {
	cout << "What is the angle of the howitzer where 0 is up? ";
	int angle;
	cin >> angle;
	return angle;
}

void displayResult(double distance, float hangtime) {
	cout << "Distance:     " << distance << "m     ";
	cout << "Hang Time:     " << hangtime << "s     \n";
}

float computeDragForce(float density, float soundV, float velocity, float surfaceArea) {
	float c = computeCoefficient(velocity, soundV);
	return .5 * c * density * velocity * velocity * surfaceArea;
}

float linearInterpolation(float x, float x0, float x1, float y0, float y1) {
	float y = (y0 + ((x - x0) * (y1 - y0)) / (x1 - x0));
	return y;
}
//
//float getDragCoefficient(float m) {
//	// Put our tables in here
//	float mach[16] = { .3, .5, .7, .89, .92, .96, .98, 1, 1.02, 
//		1.06, 1.24, 1.53, 1.99, 2.87, 2.89, 5};
//	float dragCoef[16] = { .1629, .1659, .2031, .2597, .301, 
//		.3287, .4002, .4258, .4335, .4483, .4064, .3663, .2897, .2297, .2306, .2656};
//
//	// Find where our mach is in this array
//	for (int i = 0; m < mach[i]; i++) {
//
//	}
// }


