#include <Robot.h>
#include <cstdint>
#include <cmath>
#include "WPILib.h"

void Robot::AutonomousInit() {
	// Setup
	robotDrive.SetSafetyEnabled(false);
}

void Robot::AutonomousPeriodic() {
	Wait(0.005);
}

void Robot::Turn( float absSpeed, float targetAngle ) {
	float angle;
	float offset;
	float speed;

	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();
	
	do {
		// Find the offsets for the rest of the math
		angle = gyro.GetAngle();
		offset = angle - targetAngle;
		
		// Calculate output speed
		if(offset > 0)
			speed = -absSpeed;
		else
			speed = absSpeed;

		// Turn
		robotDrive.ArcadeDrive(0.0, speed);
		UpdateMotors();

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while( abs(offset) > 1 && timer.Get() < 5 ); // Repeat until target is reached or we timeout.

	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
}

void Robot::Backward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.ArcadeDrive(-Speed, gyro.GetAngle() * 0.1 );
		UpdateMotors();
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
	timer.Stop();
}

void Robot::Forward( float Speed, float Time ) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while ( timer.Get() <= Time ) {
		robotDrive.ArcadeDrive(Speed, -gyro.GetAngle() * 0.1 );
		UpdateMotors();
		Wait(0.005);
	}
	
	// Leave everything as we found it
	robotDrive.ArcadeDrive(0.0, 0.0);
	UpdateMotors();
	timer.Stop();
}
