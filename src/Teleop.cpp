#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include <iostream>

void Robot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void Robot::TeleopPeriodic() {

	// Drive
	robotDrive.ArcadeDrive (
		-driver.GetRawAxis(1),		// Forward movement
		-driver.GetRawAxis(4)		// Rotational movement
	);

	UpdateMotors();

	Wait(0.005);
}
