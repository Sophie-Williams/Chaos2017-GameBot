#include <Shooter.h>
#include <cstdint>
#include "WPILib.h"

Shooter::Shooter( int talon_id, int talon_id2 ):
	shooterLeft( talon_id ),
	shooterRight( talon_id2 )
{
}

void Shooter::Set( float Speed, float speed) {
	shooterLeft.Set( Speed );
	shooterRight.Set( speed );

}
