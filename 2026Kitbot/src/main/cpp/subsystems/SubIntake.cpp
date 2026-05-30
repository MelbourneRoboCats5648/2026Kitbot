// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"

SubIntake::SubIntake(){
    IntakeMotor.SetNeutralMode(ctre::phoenix::motorcontrol::NeutralMode::Brake);
}

frc2::CommandPtr SubIntake::Intake(){
    return StartEnd(
        [this]{IntakeMotor.Set(1);},
        [this]{IntakeMotor.Set(0);});
}

frc2::CommandPtr SubIntake::Shoot(){
    return StartEnd(
        [this]{IntakeMotor.Set(-1);},
        [this]{IntakeMotor.Set(0);});
}


// This method will be called once per scheduler run
void SubIntake::Periodic() {}
