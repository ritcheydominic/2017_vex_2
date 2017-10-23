#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           frontLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armRight,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armLeft,       tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

short rDrive = 0;
short lDrive = 0;

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
  // ..........................................................................
  // Insert user code here.
  // ..........................................................................

  // Remove this function call once you have "real" code.
  AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

/*	Drive Objectives:
 *	- Tank controls
 *	- Speed
 *	- Control
 */
task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

  	// Drive Operations
    rDrive = vexRT[Ch2];
    lDrive = vexRT[Ch3];

    if (lDrive > 5 || lDrive < -5)
    {
    	motor[frontLeft] = lDrive;
    	motor[backLeft] = lDrive;
    }
    else
    {
    	motor[frontLeft] = 0;
    	motor[backLeft] = 0;
    }

    if (rDrive > 5 || rDrive < -5)
    {
    	motor[frontRight] = rDrive;
    	motor[backRight] = rDrive;
    }
    else
    {
    	motor[frontRight] = 0;
    	motor[backRight] = 0;
    }

    // Arm Operations
    if (vexRT[Btn6U] == 1)
    {
    	motor[armRight] = 127;
    	motor[armLeft] = 127;
    }
    else if (vexRT[Btn6D] == 1)
    {
    	motor[armRight] = -127;
    	motor[armLeft] = -127;
    }
    else
    {
    	motor[armRight] = 0;
    	motor[armLeft] = 0;
    }
  }
}