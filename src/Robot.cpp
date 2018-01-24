#include <Robot.h>
#include <cstdint>
#include "WPILib.h"
#include "Climber.h"
#include "Config.h"

Robot::Robot():

	// Actual Motor Controllers
	frontRight(FRONT_RIGHT_CANTALON_ID),
	frontLeft(FRONT_LEFT_CANTALON_ID),
	rearLeft(REAR_LEFT_CANTALON_ID),
	rearRight(REAR_RIGHT_CANTALON_ID),

	// Fake Motor Controllers
	PWMfr(0),
	PWMfl(1),
	PWMrl(2),
	PWMrr(3),
	
	// Controllers
	driver(5),
	copilot(4),

	// Subsystems
	climber(CLIMBER_CANTALON_ID),
	shooter(SHOOTER_LEFT_CANTALON_ID, SHOOTER_RIGHT_CANTALON_ID),
	fuelLoader(LOADER_CANTALON_ID),
	gearHandler(GEAR_CANTALON_ID),
	camera(5, 6),

	//Auto Switches
	Auto0(0),
	Auto1(1),
	Auto2(2),
	Auto3(3),
	Auto4(4),


	// Assorted In's and Out's
	gyro(),
	pdu(0),
	accelerometer(),


	// NOTE: Documentation says (fl, rl, fr, rr), but it is actually (fr, fl, rr, rl)
	robotDrive(PWMfr, PWMfl, PWMrr, PWMrl),

	// Flag variables
	climbing(false),
	loading(false),
	handling(false)

{
	CameraServer::GetInstance()->StartAutomaticCapture();
	  robotDrive.SetExpiration(0.3);

	  chooser.AddDefault(CenterGear, CenterGear);
	  chooser.AddObject(RedHighGoal, RedHighGoal);
	  chooser.AddObject(BlueHighGoal, BlueHighGoal);
	  chooser.AddObject(BreakBaseline, BreakBaseline);
	  chooser.AddObject(redRightGearblueLeftGear, redRightGearblueLeftGear);
	  chooser.AddObject(redLeftGearblueRightGear, redLeftGearblueRightGear);
	  frc::SmartDashboard::PutData("Auto Modes", &chooser);

}

// TODO: Check if WPILib is fixed yet.
void Robot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontLeft.Set(-PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	
	frontRight.Set(-PWMfr.Get());
	rearRight.Set(PWMrr.Get());
}

START_ROBOT_CLASS(Robot);
