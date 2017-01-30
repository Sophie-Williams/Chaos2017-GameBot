#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include "Climber.h"
#include "Config.h"

Robot::Robot():
	// Actual Motor Controllers
	frontRight(FRONT_RIGHT_CANTALON_ID),
	frontLeft(FRONT_LEFT_CANTALON_ID),
	rearLeft(REAR_LEFT_CANTALON_ID),
	rearRight(REAR_RIGHT_CANTALON_ID),

	// Fake Motor Controllers
	PWMfr(0),
	PWMfl(1),
	PWMrl(2),
	PWMrr(3),
	
	// Controllers
	driver(5),
	copilot(4),

	// Subsystems
	climber(CLIMBER_CANTALON_ID),
	pdu(0),

	// Assorted In's and Out's
	gyro(0),
	accelerometer(),
	compressor(),
	robotDrive(PWMfl, PWMrl, PWMfr, PWMrr),

	// Flag variables
	climbing(false)
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
