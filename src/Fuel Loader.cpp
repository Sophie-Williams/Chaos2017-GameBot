#include <Fuel Loader.h>
#include <cstdint>
#include "WPILib.h"

FuelLoader::FuelLoader( int talon_id ):
	loaderMotor( talon_id )
{
}

void FuelLoader::Set( float speed ) {
	loaderMotor.Set( -speed );
}

void FuelLoader::Auto(){

loaderMotor.Set(-.5);

}
