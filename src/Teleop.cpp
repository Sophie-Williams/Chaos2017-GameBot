#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {
	double deadband = 0.5;

	// Drive
	robotDrive.MecanumDrive_Cartesian (
		driver.GetY(GenericHID::kLeftHand, deadband), // Forward movement
		driver.GetX(GenericHID::kLeftHand, deadband), // Sideways movement
		driver.GetX(GenericHID::kRightHand, deadband) // Rotational movement
	);

	UpdateMotors();

	Wait(0.005);
}
