#include <Fuel Loader.h>
#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>
#include <cmath>
#include <iostream>
#include "Climber.h"
#include "Shooter.h"
#include "Camera.h"

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

	// Drive with deadband (Coarse adjustment)
	robotDrive.MecanumDrive_Cartesian(
			-1.5 * deadband(driver.GetY(GenericHID::kLeftHand)), // Forward movement
			deadband(driver.GetX(GenericHID::kLeftHand)), // Sideways movement
			-1.5 * deadband(driver.GetX(GenericHID::kRightHand)) // Rotational movement
	);

	// Climbing Control
	if (climbing) {
		if (driver.GetBButton()) {
			climbing = false;
		} else if (pdu.GetCurrent(3) >= 50) {
			climber.Set(0.1);
		} else {
			climber.Set(1.0);
		}
	} else {
		if (driver.GetAButton()) {
			climbing = true;
		} else if (driver.GetBButton()) {
			climber.Set(.15);

		}

	}

	// Roller Control
	if (loading) {
		if (copilot.GetYButton()) {
			loading = false;
		} else if (pdu.GetCurrent(15) >= 20.0) {
			fuelLoader.Set(0.1);
		} else {
			fuelLoader.Set(.5);
		}
	} else {
		if (copilot.GetXButton()) {
			loading = true;
		} else if (copilot.GetYButton()) {
			fuelLoader.Set(-.5);
		} else {
			fuelLoader.Set(0);
		}
	}

	// Shooter Control
	/*if (copilot.GetAButton()) {
	 shooter.SetState(false);
	 } else if (copilot.GetBButton()) {
	 shooter.SetState(true);
	 }*/

	// Update Shooter
	shooter.Teleop();

	// Camera Control
	if (driver.GetBackButton()) {
		camera.Looking = 1;
	} else if (driver.GetStartButton()) {
		camera.Looking = 2;
	} else if(driver.GetXButton()){
		camera.Looking = 3;
	}
	// Update Camera
	camera.Teleop();

	UpdateMotors();

	Wait(0.005);

}

