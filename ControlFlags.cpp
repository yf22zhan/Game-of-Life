#pragma once
#include "ControlFlags.h"

ControlFlags::ControlFlags() :
	run_flag(false),
	step_flag(false),
	clear_flag(false),
	random_flag(false),
	color_flag(false),
	hide_grid_flag(false)
{
}

ControlFlags::~ControlFlags()
{
}