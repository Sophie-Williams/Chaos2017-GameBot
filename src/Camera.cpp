#include <Camera.h>
#include <cstdint>
#include "WPILib.h"

Camera::Camera(int servo_id, int servo_id2) :
		cameraPanServo(servo_id),
		cameraTiltServo(servo_id2),
		Looking(2)
{
}
void Camera::Teleop() {
// Set servo according to state


	if (Looking == 1) {
		cameraTiltServo.SetAngle(20);
		cameraPanServo.SetAngle(100);

	} else if (Looking == 2) {
		cameraTiltServo.SetAngle(-2);
		cameraPanServo.SetAngle(40);
	} else{
		cameraTiltServo.SetAngle(60);
		cameraPanServo.SetAngle(40);
	}
}
