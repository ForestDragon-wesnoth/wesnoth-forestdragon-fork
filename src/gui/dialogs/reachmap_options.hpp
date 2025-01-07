/*
	Copyright (C) 2023 - 2024
	Part of the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

#pragma once

#include "gui/dialogs/modal_dialog.hpp"

namespace gui2::dialogs
{
/**
 * @ingroup GUIWindowDefinitionWML
 *
 * A test dialog for testing various gui2 features
 */
class reachmap_options : public modal_dialog
{
public:
	reachmap_options();

	DEFINE_SIMPLE_DISPLAY_WRAPPER(reachmap_options)


private:
	/**
	 * Sets up the checkbox that's common to the no-color, one-color and two-color settings.
	 * Sets its ticked/unticked state and connects the callback for user interaction.
	 */
	void setup_reachmap_toggle(const std::string& base_id, bool& shown);
	void toggle_reachmap_callback(bool& storage);


	virtual void pre_show() override;
	virtual void post_show() override;

	virtual const std::string& window_id() const override;
};

} // namespace gui2::dialogs
