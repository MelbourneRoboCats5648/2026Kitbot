// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>

class SubDrive;
class SubShooter;

namespace Autos {

frc2::CommandPtr BasicAuto(
    SubDrive* m_drive,
    SubShooter* m_shooter);
/**
 * Example static factory for an autonomous command.
 */
}  // namespace autos
