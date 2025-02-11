/*
 * Copyright © 2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 or 3,
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
 * Authored by: Andreas Pokorny <andreas.pokorny@canonical.com>
 */

#include "../logging_report_factory.h"

#include "compositor_report.h"
#include "display_report.h"
#include "scene_report.h"
#include "shell_report.h"
#include "input_report.h"
#include "seat_report.h"
#include "mir/logging/shared_library_prober_report.h"

namespace mr = mir::report;

mr::LoggingReportFactory::LoggingReportFactory(std::shared_ptr<mir::logging::Logger> const& logger,
                                               std::shared_ptr<time::Clock> const& clock)
    : logger(logger),
    clock(clock)
{
}

std::shared_ptr<mir::compositor::CompositorReport> mr::LoggingReportFactory::create_compositor_report()
{
    return std::make_shared<logging::CompositorReport>(logger, clock);
}

std::shared_ptr<mir::graphics::DisplayReport> mr::LoggingReportFactory::create_display_report()
{
    return std::make_shared<logging::DisplayReport>(logger);
}

std::shared_ptr<mir::scene::SceneReport> mr::LoggingReportFactory::create_scene_report()
{
    return std::make_shared<logging::SceneReport>(logger);
}

std::shared_ptr<mir::input::InputReport> mr::LoggingReportFactory::create_input_report()
{
    return std::make_shared<logging::InputReport>(logger);
}

std::shared_ptr<mir::input::SeatObserver> mr::LoggingReportFactory::create_seat_report()
{
    return std::make_shared<logging::SeatReport>(logger);
}

std::shared_ptr<mir::SharedLibraryProberReport> mr::LoggingReportFactory::create_shared_library_prober_report()
{
    return std::make_shared<mir::logging::SharedLibraryProberReport>(logger);
}

std::shared_ptr<mir::shell::ShellReport> mir::report::LoggingReportFactory::create_shell_report()
{
    return std::make_shared<mir::logging::ShellReport>(logger);
}
