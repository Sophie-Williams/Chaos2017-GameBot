#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <GearHandler.h>
#include <cstdint>
#include "WPILib.h"
#include "ADXRS450_Gyro.h"
#include "CANTalon.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"
#include "Shooter.h"
#include "Roller.h"
#include "Camera.h"
#include "Agitator.h"

// Main Robot Class
class Robot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	CANTalon frontRight;
	CANTalon frontLeft;
	CANTalon rearLeft;
	CANTalon rearRight;

	// Fake Motor Controllers
	// TODO: Check if WPILib is fixed yet.
	TalonSRX PWMfr;
	TalonSRX PWMfl;
	TalonSRX PWMrl;
	TalonSRX PWMrr;

	// Controllers
	XboxController driver;
	XboxController copilot;

	// Pseudo-subsystem
	Climber climber;
	Shooter shooter;
	Roller roller;
	GearHandler gearHandler;
	Camera camera;
	Agitator agitator;

	// Assorted In's and Out's
	ADXRS450_Gyro gyro;
	PowerDistributionPanel pdu;
	BuiltInAccelerometer accelerometer;
	RobotDrive robotDrive;

	// Flag variables
	bool climbing;
	bool rolling;
	bool handling;

  public:
	// Constructor Method
	Robot();

	// Various Iterators
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	


	// Various Helper Functions
	void UpdateMotors();
	void Forward( float Speed, float Time );
	void Backward( float Speed, float Time );
	void Turn( float absSpeed, float targetAngle );
	int AutoSwitch();
};

#endif /* SRC_ROBOT_H_ */
