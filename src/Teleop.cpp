#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include <iostream>
#include "Climber.h"
#include "Shooter.h"
#include "Roller.h"

double deadband(double input) {

	float deadband = 0.2;

	if (fabs(input) <= deadband) {
		return 0;
	} else {
		return input;
	}

}

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {

	// Drive with deadband
	robotDrive.MecanumDrive_Cartesian(
		-0.5 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
		 0.5 * deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
		-0.5 * deadband(driver.GetX(GenericHID::kRightHand))  // Rotational movement
	);

	// Climbing Control
	if (climbing) {
		if (driver.GetBButton()) {
			climbing = false;
		} else if (pdu.GetCurrent(12) >= 30.0) {
			climber.Set(0.1);
		} else {
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

	// Roller Control
	if (rolling) {
		if (driver.GetYButton()) {
			rolling = false;
		} else if (pdu.GetCurrent(15) >= 20.0) {
			roller.Set(0.1);
		} else {
			roller.Set(1.0);
		}
	} else {
		if (driver.GetXButton()) {
			rolling = true;
		} else if (driver.GetYButton()) {
			roller.Set(-1);
		} else {
			roller.Set(0);
		}
	}


	// Shooter Control
	if (copilot.GetYButton()) {
		shooter.SetState(false);
	} else if (copilot.GetXButton()) {
		shooter.SetState(true);
	}

	// Update Shooter
	shooter.Teleop();

	UpdateMotors();

	Wait(0.005);

}

