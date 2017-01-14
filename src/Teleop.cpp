#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {

	// Drive
	robotDrive.MecanumDrive_Cartesian (
		driver.GetY(GenericHID::kLeftHand), // Forward movement
		driver.GetX(GenericHID::kLeftHand), // Sideways movement
		driver.GetX(GenericHID::kRightHand) // Rotational movement
	);

	UpdateMotors();

	Wait(0.005);
}
