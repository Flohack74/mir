/*
 * Copyright © 2016-2017 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 2 or 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Andreas Pokorny <andreas.pokorny@canonical.com>
 */

#ifndef MIR_COMMON_POINTER_EVENT_H_
#define MIR_COMMON_POINTER_EVENT_H_

#include "mir/events/input_event.h"

#include <optional>

typedef struct MirBlob MirBlob;

struct MirPointerEvent : MirInputEvent
{
    MirPointerEvent();
    MirPointerEvent(MirInputDeviceId dev,
                    std::chrono::nanoseconds et,
                    MirInputEventModifiers mods,
                    std::vector<uint8_t> const& cookie,
                    MirPointerAction action,
                    MirPointerButtons buttons,
                    float x,
                    float y,
                    float dx,
                    float dy,
                    float vscroll,
                    float hscroll);

    auto clone() const -> MirPointerEvent* override;

    auto axis_source() const -> MirPointerAxisSource;
    void set_axis_source(MirPointerAxisSource source);

    float x() const;
    void set_x(float x);

    float y() const;
    void set_y(float y);

    float dx() const;
    void set_dx(float x);

    float dy() const;
    void set_dy(float y);

    float vscroll() const;
    void set_vscroll(float v);

    float hscroll() const;
    void set_hscroll(float h);

    bool vscroll_stop() const;
    void set_vscroll_stop(bool stop);

    bool hscroll_stop() const;
    void set_hscroll_stop(bool stop);

    float vscroll_discrete() const;
    void set_vscroll_discrete(float v);

    float hscroll_discrete() const;
    void set_hscroll_discrete(float h);

    MirPointerAction action() const;
    void set_action(MirPointerAction action);

    MirPointerButtons buttons() const;
    void set_buttons(MirPointerButtons buttons);

    void set_dnd_handle(std::vector<uint8_t> const& handle);
    MirBlob* dnd_handle() const;

private:
    MirPointerAxisSource axis_source_ = mir_pointer_axis_source_none;
    float x_ = 0.0;
    float y_ = 0.0;
    float dx_ = 0.0;
    float dy_ = 0.0;
    float vscroll_ = 0.0;
    float hscroll_ = 0.0;
    bool hscroll_stop_ = false;
    bool vscroll_stop_ = false;
    float hscroll_discrete_ = 0.0;
    float vscroll_discrete_ = 0.0;

    MirPointerAction action_ = {};
    MirPointerButtons buttons_= {};
    std::optional<std::vector<uint8_t>> dnd_handle_;
};

#endif
