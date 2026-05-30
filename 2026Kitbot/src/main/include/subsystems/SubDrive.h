// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc2/command/Commands.h>

class SubDrive : public frc2::SubsystemBase {
 public:

    static SubDrive& GetInstance() {
    static SubDrive inst;
    return inst;
  }

  
  SubDrive();

  frc2::CommandPtr Drive(frc2::CommandXboxController &driverController);
  frc2::CommandPtr AutoDrive();

  /**   
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FrontLeftDrive{0};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX FrontRightDrive{1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BackLeftDrive{2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX BackRightDrive{3};

  frc::DifferentialDrive _drivebase{FrontLeftDrive, FrontRightDrive};

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
