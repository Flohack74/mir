/*
 * Copyright © 2018-2020 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 or 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Alan Griffiths <alan@octopull.co.uk>
 */

#include "miral/external_client.h"

#include "launch_app.h"
#include "open_desktop_entry.h"

#include <mir/options/option.h>
#include <mir/server.h>

#include <stdexcept>

namespace mo = mir::options;

struct miral::ExternalClientLauncher::Self
{
    mir::Server* server = nullptr;

    AppEnvironment env;
    AppEnvironment x11_env;
};

namespace
{
void parse_env(std::string const& value, miral::AppEnvironment& map)
{
    for (auto i = begin(value); i != end(value); )
    {
        auto const j = find(i, end(value), ':');

        auto equals = find(i, j, '=');

        auto const key = std::string(i, equals);
        if (j != equals) ++equals;
        auto const val = std::string(equals, j);

        if (key[0] == '-')
        {
            map[key.substr(1)] = std::experimental::nullopt;
        }
        else
        {
            map[key] = val;
        }

        if ((i = j) != end(value)) ++i;
    }
}
}

void miral::ExternalClientLauncher::operator()(mir::Server& server)
{
    self->server = &server;

    static auto const app_env = "app-env";
    static auto const default_env = "GDK_BACKEND=wayland,x11:QT_QPA_PLATFORM=wayland:SDL_VIDEODRIVER=wayland:"
        "-QT_QPA_PLATFORMTHEME:NO_AT_BRIDGE=1:QT_ACCESSIBILITY:QT_LINUX_ACCESSIBILITY_ALWAYS_ON:MOZ_ENABLE_WAYLAND=1:"
        "_JAVA_AWT_WM_NONREPARENTING=1:-GTK_MODULES:-OOO_FORCE_DESKTOP:-GNOME_ACCESSIBILITY:-QT_IM_MODULE";
    static auto const app_x11_env = "app-env-x11";
    static auto const default_x11_env = "GDK_BACKEND=x11:QT_QPA_PLATFORM=xcb:SDL_VIDEODRIVER=x11";
    static auto const app_env_amend = "app-env-amend";
    static auto const default_env_amend = "";

    server.add_configuration_option(
        app_env,
        "Base environment for launched apps",
        default_env);

    server.add_configuration_option(
            app_env_amend,
            "Amendments to environment for launched apps",
            default_env_amend);

    server.add_configuration_option(
        app_x11_env,
        "X11 changes to --app-env for launched apps",
        default_x11_env);

    server.add_init_callback([self=self, &server]
         {
             auto const options = server.get_options();

             parse_env(options->get(app_env, default_env), self->env);
             parse_env(options->get(app_env_amend, default_env_amend), self->env);

             self->x11_env = self->env; // base the X11 environment on the "normal" one
             parse_env(options->get(app_x11_env, default_x11_env), self->x11_env);
         });
}

auto miral::ExternalClientLauncher::launch(std::vector<std::string> const& command_line) const -> pid_t
{
    if (!self->server)
    {
        BOOST_THROW_EXCEPTION(std::logic_error("Cannot launch apps when server has not started"));
    }

    auto const wayland_display = self->server->wayland_display();
    auto const x11_display = self->server->x11_display();

    return launch_app_env(command_line, wayland_display, x11_display, self->env);
}

miral::ExternalClientLauncher::ExternalClientLauncher() : self{std::make_shared<Self>()} {}

auto  miral::ExternalClientLauncher::launch_using_x11(std::vector<std::string> const& command_line) const -> pid_t
{
    if (!self->server)
    {
        BOOST_THROW_EXCEPTION(std::logic_error("Cannot launch apps when server has not started"));
    }

    if (auto const x11_display = self->server->x11_display())
    {
        auto const wayland_display = self->server->wayland_display();
        return launch_app_env(command_line, wayland_display, x11_display, self->x11_env);
    }

    return -1;
}

void miral::ExternalClientLauncher::snapcraft_launch(const std::string& desktop_file) const
{
    if (!self->server)
    {
        BOOST_THROW_EXCEPTION(std::logic_error("Cannot launch apps when server has not started"));
    }

    open_desktop_entry(desktop_file);
}

miral::ExternalClientLauncher::~ExternalClientLauncher() = default;
