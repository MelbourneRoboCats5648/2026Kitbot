// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc2/command/Commands.h>


class SubShooter : public frc2::SubsystemBase {
 public:
  SubShooter();

    static SubShooter& GetInstance() {
    static SubShooter inst;
    return inst;
  }

  frc2::CommandPtr StartShooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX ShooterMotor{4};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
