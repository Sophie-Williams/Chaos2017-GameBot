#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include "WPILib.h"
#include "CANTalon.h"
#include "Servo.h"

class Shooter
{
  private:
	CANTalon shooterLeft;
	CANTalon shooterRight;

	Servo shooterServo;

	bool shooting;

  public:
	Shooter( int talon_id, int talon_id2, int servo_id);

	void SetSpeed(float speed);
	void SetState(bool newState);
	bool GetState();

	void Teleop();
};

#endif /* SRC_SHOOTER_H_ */
