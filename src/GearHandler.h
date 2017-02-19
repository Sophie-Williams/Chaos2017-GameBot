#ifndef SRC_GEARHANDLER_H_
#define SRC_GEARHANDLER_H_

#include "WPILib.h"
#include "CANTalon.h"

class GearHandler
{
  private:
	CANTalon gearHandlerMotor;

  public:
	GearHandler( int talon_id );

	void Set( float speed );
};

#endif /* SRC_GEARHANDLER_H_ */
