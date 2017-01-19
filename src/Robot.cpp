#include <Robot.h>
#include <cstdint>
#include "WPILib.h"

Robot::Robot():
	// Actual Motor Controllers
	frontRight(1),
	frontLeft(2),
	rearLeft(3),
	rearRight(4),

	// Fake Motor Controllers
	PWMfr(0),
	PWMfl(1),
	PWMrl(2),
	PWMrr(3),
	
	// Controllers
	driver(5),
	copilot(4),

	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMfl, PWMrl, PWMfr, PWMrr)

{
	robotDrive.SetExpiration(0.3);
	compressor.Start();
}

// TODO: Check if WPILib is fixed yet.
void Robot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontLeft.Set(-PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	
	frontRight.Set(-PWMfr.Get());
	rearRight.Set(PWMrr.Get());
}

START_ROBOT_CLASS(Robot);
