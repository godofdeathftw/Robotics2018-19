#pragma config(Sensor, in1,    DriveMode,      sensorPotentiometer)
#pragma config(Motor,  port2,           MotorR1,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           MotorR2,       tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port8,           MotorL1,       tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port9,           MotorL2,       tmotorVex393_MC29, openLoop)


#pragma platform(VEX2)

#pragma competitionControl(Competition)

#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting();
}

task usercontrol()
{
	while (true)
	{
		if (SensorValue[DriveMode] < 2027.5){
			if (vexRT[Ch2] < 0)
			{
				motor[MotorL1] = vexRT[Ch2] - vexRT[Ch1];
				motor[MotorL2] = vexRT[Ch2] - vexRT[Ch1];
				motor[MotorR1] = vexRT[Ch2] + vexRT[Ch1];
				motor[MotorR2] = vexRT[Ch2] + vexRT[Ch1];
			}
			else if (vexRT[Ch2] > 0){
				motor[MotorL1] = vexRT[Ch2] + vexRT[Ch1];
				motor[MotorL2] = vexRT[Ch2] + vexRT[Ch1];
				motor[MotorR1] = vexRT[Ch2] - vexRT[Ch1];
				motor[MotorR2] = vexRT[Ch2] - vexRT[Ch1];
			}
			} else if (SensorValue[DriveMode] > 2027.5){
			motor[MotorL1] = vexRT[Ch2] + vexRT[Ch1];
			motor[MotorL2] = vexRT[Ch2] + vexRT[Ch1];
			motor[MotorR1] = vexRT[Ch2] - vexRT[Ch1];
			motor[MotorR2] = vexRT[Ch2] - vexRT[Ch1];
		}
		/*
		motor[Lift1] = vexRT[Ch3];  //Lif
		*/
	}
}
