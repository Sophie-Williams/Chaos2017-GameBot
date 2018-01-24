#ifndef SRC_CLIMBER_H_
#define SRC_CLIMBER_H_

#include "CANTalon.h"
#include "WPILib.h"

class Climber
{
  private:
	CANTalon climberMotor;

  public:
	Climber( int talon_id );

	void Set( float speed );

	void Hold( float Speed );
};

#endif /* SRC_CLIMBER_H_ */
