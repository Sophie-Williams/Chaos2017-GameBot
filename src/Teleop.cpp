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
		driver.GetY(GenericHID::KLeftHand), // Forward movement
		driver.GetX(GenericHID::KLeftHand), // Sideways movement
		driver.GetX(GenericHID::KRightHand) // Rotational movement
	);

	UpdateMotors();

	Wait(0.005);
}
