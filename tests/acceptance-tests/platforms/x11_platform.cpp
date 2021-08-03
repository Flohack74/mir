/*
 * Copyright © 2021 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 or 3 as
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
 * Authored by: Christopher James Halse Rogers <christopher.halse.rogers@canonical.com>
 */

#include "test_rendering_platform.h"
#include "test_display_platform.h"

#include "mir_test_framework/executable_path.h"

namespace mtf = mir_test_framework;

namespace
{
class X11PlatformEnv : public mir::test::PlatformTestHarness
{
public:
    void setup() override
    {
    }

    void teardown() override
    {
    }

    auto platform_module() -> std::shared_ptr<mir::SharedLibrary> override
    {
        return std::make_shared<mir::SharedLibrary>(mtf::server_platform("server-x11"));
    }
};

X11PlatformEnv platform_harness;
}

INSTANTIATE_TEST_SUITE_P(X11, DisplayPlatformTest, testing::Values(&platform_harness));
