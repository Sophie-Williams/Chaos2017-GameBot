#ifndef SRC_CAMERA_H_
#define SRC_CAMERA_H_

#include "WPILib.h"
#include "Servo.h"

class Camera
{
  private:

	Servo cameraPanServo;

	Servo cameraTiltServo;





  public:
	Camera( int servo_id, int servo_id2);
	void Teleop();
	int Looking;
};

#endif /* SRC_CAMERA_H_ */
