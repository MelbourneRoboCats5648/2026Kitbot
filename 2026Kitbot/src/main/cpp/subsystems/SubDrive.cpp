// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDrive.h"
#include <frc/smartdashboard/SmartDashboard.h>


SubDrive::SubDrive(){
    FrontLeftDrive.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    FrontRightDrive.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    BackLeftDrive.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
    BackRightDrive.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);

    FrontLeftDrive.SetInverted(true);
    BackLeftDrive.SetInverted(true);

    BackLeftDrive.Follow(FrontLeftDrive);
    BackRightDrive.Follow(FrontRightDrive);
    frc::SmartDashboard::PutData("Drivebase", &_drivebase);
}

frc2::CommandPtr SubDrive::Drive(frc2::CommandXboxController &driverController){
       return Run([this,&driverController]{
        _drivebase.ArcadeDrive(driverController.GetLeftY(), (driverController.GetLeftX()*0.8));});
}

// This method will be called once per scheduler run
void SubDrive::Periodic() {}
