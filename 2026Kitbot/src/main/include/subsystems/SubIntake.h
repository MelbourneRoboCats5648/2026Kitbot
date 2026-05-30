// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Commands.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>

class SubIntake : public frc2::SubsystemBase {
 public:

    static SubIntake& GetInstance() {
    static SubIntake inst;
    return inst;
  }
  SubIntake();

  frc2::CommandPtr Intake();
  frc2::CommandPtr Shoot();


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX IntakeMotor{5};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
