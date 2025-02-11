/*
 * Copyright © 2018-2019 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Christopher James Halse Rogers <christopher.halse.rogers@canonical.com>
 */

#ifndef MIR_FRONTEND_WL_KEYBOARD_H
#define MIR_FRONTEND_WL_KEYBOARD_H

#include "wayland_wrapper.h"
#include "keyboard_helper.h"
#include "wl_seat.h"

namespace mir
{
namespace frontend
{
class WlSurface;

class WlKeyboard
    : public wayland::Keyboard,
      private WlSeat::FocusListener,
      private KeyboardCallbacks
{
public:
    WlKeyboard(wl_resource* new_resource, WlSeat& seat);

    ~WlKeyboard();

    void handle_event(MirInputEvent const* event, WlSurface& surface);

private:
    WlSeat& seat;
    std::unique_ptr<KeyboardHelper> const helper;
    wayland::Weak<WlSurface> focused_surface;

    /// WlSeat::FocusListener override
    void focus_on(WlSurface* surface) override;

    /// KeyboardCallbacks overrides
    /// @{
    void send_repeat_info(int32_t rate, int32_t delay) override;
    void send_keymap_xkb_v1(mir::Fd const& fd, size_t length) override;
    void send_key(uint32_t timestamp, int scancode, bool down) override;
    void send_modifiers(uint32_t depressed, uint32_t latched, uint32_t locked, uint32_t group) override;
    /// @}
};
}
}

#endif // MIR_FRONTEND_WL_KEYBOARD_H
