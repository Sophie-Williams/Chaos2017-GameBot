#include <Robot.h>
#include <cstdint>
#include <cmath>
#include "WPILib.h"
	//forward at 0.4 for 1second =44"
void Robot::AutonomousInit() {
	// Setup
	robotDrive.SetSafetyEnabled(false);
	Forward(0.4,1.8);
	Turn(0.2,90);
	Forward(0.4,1.15);
	Turn(0.2,-90);
	Forward(0.4,1.25);
	Turn(0.2,-90);
	Forward(0.4,1.6);
	Turn(0.2,90);
	Forward(0.4,2.5);
	//Start of reverse
	Forward(-0.4,2.25);
	Turn(0.2,-90);
	Forward(-0.4,1.6);
	Turn(0.2,90);
	Forward(-0.4,1.1);
	Turn(0.2,90);
	Forward(-0.4,1.15);
	Turn(0.2,-90);
	Forward(-0.4,1.8);
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
		offset = targetAngle - angle;

		// Calculate output speed
		if(offset < 0)
			speed = absSpeed;
		else
			speed = -absSpeed;

		// Turn
		robotDrive.MecanumDrive_Cartesian(0, 0, speed);
		UpdateMotors();

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while( abs(offset) > 1 && timer.Get() < 5 ); // Repeat until target is reached or we timeout.

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
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
		Wait(0.005);
		robotDrive.MecanumDrive_Cartesian(-Speed, 0, gyro.GetAngle() * 0.1 );
		UpdateMotors();
	}
	
	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
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
		Wait(0.005);
		robotDrive.MecanumDrive_Cartesian(Speed, 0, gyro.GetAngle() * 0.1 );
		UpdateMotors();
	}
	
	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();
}
