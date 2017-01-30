#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <cstdint>
#include "WPILib.h"
#include "CANTalon.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"


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
	PowerDistributionPanel pdu;

	// Assorted In's and Out's
	AnalogGyro gyro;
	BuiltInAccelerometer accelerometer;
	Compressor compressor;
	RobotDrive robotDrive;

	// Flag variables
	bool climbing;
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
