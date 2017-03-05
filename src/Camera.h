#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include "WPILib.h"
#include "CANTalon.h"
#include "Servo.h"

class Camera
{
  private:

	Servo cameraServo;

	bool looking;

  public:
	Camera( int servo_id);

	void SetState(bool newState);
	bool GetState();

	void Teleop();
};

#endif /* SRC_SHOOTER_H_ */
