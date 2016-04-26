#pragma once

class ControlFlags
{
public:
	ControlFlags();
	~ControlFlags();

	bool run_flag;
	bool step_flag;
	bool clear_flag;
	bool random_flag;
	bool color_flag;
	bool hide_grid_flag;
};