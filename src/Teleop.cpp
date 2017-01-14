#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include <iostream>

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {

	// Drive
	robotDrive.ArcadeDrive (
		-driver.GetRawAxis(1),		// Forward movement
		-driver.GetRawAxis(4)		// Rotational movement
	);

	UpdateMotors();

	Wait(0.005);
}
