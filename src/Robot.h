#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <Fuel Loader.h>
#include <GearHandler.h>
#include <cstdint>
#include "WPILib.h"
#include "ADXRS450_Gyro.h"
#include "CANTalon.h"
#include "Climber.h"
#include "PowerDistributionPanel.h"
#include "Shooter.h"
#include "Camera.h"

// Main Robot Class
class Robot: public IterativeRobot
{
  private:

	frc::SendableChooser<std::string> chooser;
	const std::string CenterGear = "Center Gear";
	const std::string RedHighGoal = "Red High Goal";
	const std::string BlueHighGoal = "Blue High Goal";
	const std::string BreakBaseline = "Break The Baseline";
	const std::string redRightGearblueLeftGear = "redRight blueLeft Gear Auto";
	const std::string redLeftGearblueRightGear = "redLeft blueRight Gear Auto";
	std::string autoSelected;


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
	FuelLoader fuelLoader;
	GearHandler gearHandler;
	Camera camera;

	//Autonomous Switch Inputs
	DigitalInput Auto0;
	DigitalInput Auto1;
	DigitalInput Auto2;
	DigitalInput Auto3;
	DigitalInput Auto4;

	// Assorted In's and Out's
	ADXRS450_Gyro gyro;
	PowerDistributionPanel pdu;
	BuiltInAccelerometer accelerometer;
	RobotDrive robotDrive;




	// Flag variables
	bool climbing;
	bool loading;
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
	void Strafe(float Speed, float Time);
	int AutoSwitch();
};

#endif /* SRC_ROBOT_H_ */
