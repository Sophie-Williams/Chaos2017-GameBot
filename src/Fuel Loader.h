#ifndef SRC_FUEL_LOADER_H_
#define SRC_FUEL_LOADER_H_

#include "WPILib.h"
#include "CANTalon.h"

class FuelLoader
{
  private:
	CANTalon loaderMotor;

  public:
	FuelLoader( int talon_id );

	void Set( float speed );
	void Auto();
};

#endif /* SRC_FUEL_LOADER_H_ */
