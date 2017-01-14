#include <Robot.h>
#include <cstdint>
#include "WPILib.h"

Robot::Robot():
	// Actual Motor Controllers
	frontLeft(7),
	middleLeft(8),
	rearLeft(9),

	frontRight(10),
	middleRight(11),
	rearRight(12),

	// Fake Motor Controllers
	PWMl(0),
	PWMr(1),
	
	// Controllers
	driver(5),
	copilot(4),

	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMl, PWMr)

{
	robotDrive.SetExpiration(0.3);
	compressor.Start();
}

// TODO: Check if WPILib is fixed yet.
void Robot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontLeft.Set(PWMl.Get());
	middleLeft.Set(PWMl.Get());
	rearLeft.Set(PWMl.Get());
	
	frontRight.Set(PWMr.Get());
	middleRight.Set(PWMr.Get());
	rearRight.Set(PWMr.Get());
}

START_ROBOT_CLASS(Robot);
