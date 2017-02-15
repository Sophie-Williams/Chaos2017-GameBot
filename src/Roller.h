#ifndef SRC_ROLLER_H_
#define SRC_ROLLER_H_

#include "WPILib.h"
#include "CANTalon.h"

class Roller
{
  private:
	CANTalon roller;

  public:
	Roller( int talon_id );

	void Set( float speed );
};

#endif /* SRC_ROLLER_H_ */
