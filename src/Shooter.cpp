#include <Shooter.h>
#include <cstdint>
#include "WPILib.h"

Shooter::Shooter( int talon_id, int talon_id2 ):
	shooterLeft( talon_id ),
	shooterRight( talon_id2 )

{
}

void Shooter::Teleop() {
	// Set shooter speed
	SetSpeed(0.42);


}

void Shooter::SetSpeed( float speed) {
	shooterLeft.Set( -speed );
	shooterRight.Set( speed );
}


void Shooter::Auto(){

	// Set shooter speed
		SetSpeed(0.43);

}


