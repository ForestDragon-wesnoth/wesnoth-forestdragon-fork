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

#define GETTEXT_DOMAIN "wesnoth-lib"

#include "gui/dialogs/reachmap_options.hpp"

#include "gui/auxiliary/iterator/iterator.hpp"
#include "gui/core/event/dispatcher.hpp"
#include "gui/widgets/button.hpp"
#include "gui/widgets/grid.hpp"
#include "gui/widgets/toggle_button.hpp"
#include "gui/widgets/window.hpp"

#include "game_config.hpp"
#include "preferences/preferences.hpp"
#include <functional>

namespace gui2::dialogs
{
namespace
{
std::string get_reachmap_widget_prefix(const std::string& base_id)
{
	return "reachmap_" + base_id + "_";
}

} // namespace

REGISTER_DIALOG(reachmap_options)

reachmap_options::reachmap_options()
	: modal_dialog(window_id())
{
}

void reachmap_options::pre_show()
{
	setup_reachmap_group("standard_color", prefs::get().reach_map_color());

//TODO: uncomment later if it's necessary

//	connect_signal_mouse_left_click(
//		find_widget<button>("orb_defaults"), std::bind(&reachmap_options::reset_orb_callback, this));

}

void reachmap_options::post_show()
{
}


//THE TOGGLE NOT NEEDED FOR REACHMAP, DELETE LATER
//void reachmap_options::setup_reachmap_toggle(const std::string& base_id, bool& shown)
//{
//	const std::string prefix = get_reachmap_widget_prefix(base_id);
//	toggle_button& toggle = find_widget<toggle_button>(prefix + "show");
//	toggle.set_value_bool(shown);
//
//	connect_signal_mouse_left_click(toggle, std::bind(&reachmap_options::toggle_reachmap_callback, this, std::ref(shown)));
//}
//
//void reachmap_options::toggle_reachmap_callback(bool& storage)
//{
//	// The code for the two-color groups uses this for both the main setting and the two_color setting - if
//	// you add any extra logic here, check that it's still also applicable to the two_color setting.
//	storage = !storage;
//}

void reachmap_options::setup_reachmap_group(const std::string& base_id, const std::string& initial)
{

//THE TOGGLE NOT NEEDED FOR REACHMAP, DELETE LATER
//	setup_reachmap_toggle(base_id, shown);

	//
	// Set up the toggle group.
	//
	group<std::string>& group = groups_[base_id];

	// Grid containing each color option toggle.
	const std::string prefix = get_reachmap_widget_prefix(base_id);
	grid& selection = find_widget<grid>(prefix + "selection");

	for(iteration::bottom_up_iterator<true, false, true> iter(selection); !iter.at_end(); ++iter) {
		if(toggle_button* button = dynamic_cast<toggle_button*>(iter.get())) {
			const std::string& id = button->id();
			group.add_member(button, id.substr(prefix.size()));
		}
	}

	group.set_member_states(initial);
}

//THE TOGGLE NOT NEEDED FOR REACHMAP, DELETE LATER
//void reachmap_options::reset_reachmap_toggle(const std::string& base_id, bool shown)
//{
//	const std::string prefix = get_reachmap_widget_prefix(base_id);
//
//	toggle_button& toggle = find_widget<toggle_button>(prefix + "show");
//	toggle.set_value_bool(shown);
//}

void reachmap_options::reset_reachmap_group(const std::string& base_id, const std::string& initial)
{
//THE TOGGLE NOT NEEDED FOR REACHMAP, DELETE LATER
//	reset_reachmap_toggle(base_id, shown);

	groups_[base_id].set_member_states(initial);
}

void reachmap_options::reset_reachmap_callback()
{
//	show_unmoved_ = game_config::show_unmoved_orb;
//	show_partial_ = game_config::show_partial_orb;
//	show_disengaged_ = game_config::show_disengaged_orb;
//	show_moved_ = game_config::show_moved_orb;
//	show_ally_ = game_config::show_ally_orb;
//	two_color_ally_ = game_config::show_status_on_ally_orb;
//	show_enemy_ = game_config::show_enemy_orb;

	reset_reachmap_group("standard_color", game_config::colors::reach_map_color);
}

} // namespace gui2::dialogs
