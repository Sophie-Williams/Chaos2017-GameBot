#ifndef SRC_AGITATOR_H_
#define SRC_AGITATOR_H_

#include "WPILib.h"
#include "CANTalon.h"
#include "Servo.h"

class Agitator
{
  private:
	CANTalon agitator;


	Servo agitatorServo;

	bool agitating;

  public:
	Agitator( int talon_id, int servo_id);

	void SetSpeed(float speed);
	void SetState(bool newState);
	bool GetState();

	void Teleop();
};

#endif /* SRC_Agitator_H_ */
