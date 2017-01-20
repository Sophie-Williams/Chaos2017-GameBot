#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include <iostream>

void Deadband(double (&Joystick)[3]) {

	float deadband = 0.5;

	if (fabs(Joystick[0]) <= deadband) {
		Joystick[0] = 0;
	}

	if (fabs(Joystick[1]) <= deadband) {
		Joystick[1] = 0;
	}

	if (fabs(Joystick[2]) <= deadband) {
		Joystick[2] = 0;
	}

}

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {

	double JoystickArray[] = { driver.GetY(GenericHID::kLeftHand), driver.GetX(
			GenericHID::kLeftHand), driver.GetX(GenericHID::kRightHand) };

	Deadband(JoystickArray);

// Drive
	robotDrive.MecanumDrive_Cartesian(
			JoystickArray[0], // Forward movement
			JoystickArray[1], // Sideways movement
			JoystickArray[2] // Rotational movement
			);

	UpdateMotors();

	Wait(0.005);

}

