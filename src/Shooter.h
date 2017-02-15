#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_

#include "WPILib.h"
#include "CANTalon.h"

class Shooter
{
  private:
	CANTalon shooterLeft;
	CANTalon shooterRight;

  public:
	Shooter( int talon_id, int talon_id2);

	void Set(float Speed, float speed);
};

#endif /* SRC_SHOOTER_H_ */
