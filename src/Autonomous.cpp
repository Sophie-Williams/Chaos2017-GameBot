#include <Robot.h>
#include <cstdint>
#include <cmath>
#include "WPILib.h"

void Robot::AutonomousInit() {

	autoSelected = chooser.GetSelected();
	// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
	std::cout << "Auto selected: " << autoSelected << std::endl;
	robotDrive.SetSafetyEnabled(false);

	if (autoSelected == RedHighGoal) {

		fuelLoader.Set(0);
		shooter.Auto();
		Forward(.45, 1.25);
		Forward(.25, .25);
		Turn(.5, -28);
		Forward(.5, 1.4);
		Strafe(-.5, 1);
		fuelLoader.Auto();
		Forward(.1, 8);

	} else if (autoSelected == BlueHighGoal) {

		fuelLoader.Set(0);
		shooter.Auto();
		Forward(.45, 1.25);
		Forward(.25, .25);
		Turn(.5, -108);
		Forward(.5, 1.4);
		fuelLoader.Auto();
		Forward(.1, 8);

	} else if (autoSelected == BreakBaseline) {

		Forward(0.5, 1.5);
	} else if (autoSelected == redRightGearblueLeftGear) {
		Forward(.45, 1.5);
		Forward(.25, .25);
		Turn(.5, 50);
		Forward(.5, .25);
		Forward(.2, 10);
	} else if (autoSelected == redLeftGearblueRightGear) {

	} else {
		Forward(0.5, 0.75);
		Forward(0.2, 10);
		Forward(0, 4);
	}
}
void Robot::AutonomousPeriodic() {
	Wait(0.005);

	if (autoSelected == RedHighGoal) {

		// Setup
		robotDrive.SetSafetyEnabled(false);

		fuelLoader.Set(0);
		shooter.Auto();
		Forward(.45, 1.25);
		Forward(.25, .25);
		Turn(.5, -28);
		Forward(.5, 1.4);
		Strafe(-.5, 1);
		fuelLoader.Auto();
		Forward(.1, 8);


	} else if (autoSelected == BlueHighGoal) {

		// Setup
		robotDrive.SetSafetyEnabled(false);

		fuelLoader.Set(0);
		shooter.Auto();
		Forward(.45, 1.25);
		Forward(.25, .25);
		Turn(.5, -108);
		Forward(.5, 1.4);
		fuelLoader.Auto();
		Forward(.1, 8);

	} else if (autoSelected == BreakBaseline) {

		Forward(0.5, 1.5);
	} else if (autoSelected == redRightGearblueLeftGear) {
		Forward(.45, 1.5);
		Forward(.25, .25);
		Turn(.5, 50);
		Forward(.5, .25);
		Forward(.2, 10);
	} else if (autoSelected == redLeftGearblueRightGear) {
		Forward(.45, 1.25);
		Forward(.25, .25);
		Turn(.5, -28);
		Forward(.5, .25);
		Forward(.2, 10);

	} else {
		Forward(0.5, 0.75);
		Forward(0.2, 10);

	}

}

void Robot::Turn(float absSpeed, float targetAngle) {
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
		if (offset < 0)
			speed = absSpeed;
		else
			speed = -absSpeed;

		// Turn
		robotDrive.MecanumDrive_Cartesian(0, 0, speed);
		UpdateMotors();

		// Keep CPU from catching fire and network from exploding in a fireball of packets.
		Wait(0.005);

	} while (abs(offset) > 1 && timer.Get() < 5); // Repeat until target is reached or we timeout.

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
	UpdateMotors();
	Wait(0.5);
}

void Robot::Backward(float Speed, float Time) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while (timer.Get() <= Time) {
		Wait(0.005);
		robotDrive.MecanumDrive_Cartesian(-Speed, 0, gyro.GetAngle() * 0.1);
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();
}

void Robot::Forward(float Speed, float Time) {
	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while (timer.Get() <= Time) {
		Wait(0.005);
		robotDrive.MecanumDrive_Cartesian(Speed, 0, gyro.GetAngle() * 0.1);
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();

}

void Robot::Strafe(float Speed, float Time) {

	// Reset the gyro to 0 degrees
	gyro.Reset();

	// Initialize Timer
	Timer timer;
	timer.Reset();
	timer.Start();

	// Move straight, changing angle to adjust for drift
	while (timer.Get() <= Time) {
		Wait(0.005);
		robotDrive.MecanumDrive_Cartesian(0, Speed, gyro.GetAngle() * 0.1);
		UpdateMotors();
	}

	// Leave everything as we found it
	robotDrive.MecanumDrive_Cartesian(0, 0, 0);
	UpdateMotors();
	timer.Stop();

}
