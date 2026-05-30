// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"

SubShooter::SubShooter(){
    ShooterMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Coast);
}

frc2::CommandPtr SubShooter::StartShooter(){
    return StartEnd(
        [this]{ShooterMotor.Set(1);},
        [this]{ShooterMotor.Set(0);});
}

// This method will be called once per scheduler run
void SubShooter::Periodic() {}
