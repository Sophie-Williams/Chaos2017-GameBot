#ifndef SRC_DEADBANDXBOXCONTROLLER_H_
#define SRC_DEADBANDXBOXCONTROLLER_H_

#include "WPILib.h"

class DeadbandXboxController: XboxController {
	using XboxController::XboxController;

	public:
		double GetX(enum frc::GenericHID::JoystickHand hand, double deadband);
		double GetY(enum frc::GenericHID::JoystickHand hand, double deadband);
};

#endif /* SRC_ROBOT_H_ */
