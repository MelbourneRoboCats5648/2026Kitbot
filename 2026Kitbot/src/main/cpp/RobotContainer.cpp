// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "subsystems/SubDrive.h"
#include "subsystems/SubIntake.h"
#include "subsystems/SubShooter.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  SubDrive::GetInstance().SetDefaultCommand(SubDrive::GetInstance().Drive(DriverController));
  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  DriverController.LeftTrigger().WhileTrue(SubIntake::GetInstance().Intake().AlongWith(SubShooter::GetInstance().Intake()));
  DriverController.RightTrigger().WhileTrue(SubShooter::GetInstance().StartShooter());
  DriverController.LeftBumper().WhileTrue(SubIntake::GetInstance().Shoot());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand(){
  return frc2::cmd::None();
}
