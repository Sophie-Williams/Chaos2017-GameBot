#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

/* Define Robot ID (0: Main Robot, 1: Practice Robot) */
#define	ROBOT_ID	0

/* Constants for Competition Robot */
#if ROBOT_ID == 0

	// Drive Train
	#define	REAR_RIGHT_CANTALON_ID		13
	#define	REAR_LEFT_CANTALON_ID		15
	#define	FRONT_LEFT_CANTALON_ID		17
	#define	FRONT_RIGHT_CANTALON_ID		20

	// Subsystems
	#define	CLIMBER_CANTALON_ID			16

#endif

/* Constants for Practice Robot */
#if ROBOT_ID == 1

	// Drive Train
	#define	REAR_RIGHT_CANTALON_ID		5
	#define	REAR_LEFT_CANTALON_ID		7
	#define	FRONT_LEFT_CANTALON_ID		9
	#define	FRONT_RIGHT_CANTALON_ID		12

	// Subsystems
	#define	CLIMBER_CANTALON_ID			8

#endif

#endif /* SRC_CONFIG_H_ */
