#include "DeadbandXboxController.h"

double DeadbandXboxController::GetX(enum frc::GenericHID::JoystickHand hand, double deadband) {
	double value = XboxController::GetX(hand);

	// Apply Deadband
	if(fabs(value) <= deadband) {
		return 0;
	} else {
		return value;
	}
}

double DeadbandXboxController::GetY(enum frc::GenericHID::JoystickHand hand, double deadband) {
	double value = XboxController::GetY(hand);

	// Apply Deadband
	if(fabs(value) <= deadband) {
		return 0;
	} else {
		return value;
	}
}
