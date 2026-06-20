// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/Commands.h>
#include <commands/Autos.h>
#include <subsystems/SubDrive.h>
#include <subsystems/SubShooter.h>
#include <Units/time.h>

frc2::CommandPtr Autos::BasicAuto(
    SubDrive* m_drive,
    SubShooter* m_shooter) {

    return frc2::cmd::Sequence(

        m_drive->AutoDrive(0.5, 0.0).WithTimeout(250_ms),

        m_drive->AutoDrive(0.0, 0.0),

        m_shooter->Intake().WithTimeout(1_s),

        m_shooter->StartShooter().WithTimeout(9_s)

    );
}