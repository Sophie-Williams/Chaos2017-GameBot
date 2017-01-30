#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include <iostream>
#include "Climber.h"

void Deadband(double (&Joystick)[3]) {

	float deadband = 0.2;

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
		-0.5 * JoystickArray[0], // Forward movement
		0.5 * JoystickArray[1], // Sideways movement
		0.5 * JoystickArray[2] // Rotational movement
	);

	if (climbing) {

		if (driver.GetBButton()) {

			climbing = false;
		}

		else if (pdu.GetCurrent(12) >= 30.0) {

			climber.Set(0.1);
		}

		else {
			climber.Set(1.0);
		}
	} else {

		if (driver.GetAButton()) {

			climbing = true;
		} else if (driver.GetBButton()) {

			climber.Set(-1);
		} else {

			climber.Set(0);
		}
	}
	UpdateMotors();

	Wait(0.005);

}

