/*
 * Copyright © 2012 Canonical Ltd.
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
 * Authored by: Alan Griffiths <alan@octopull.co.uk>
 */
#ifndef MIR_DEFAULT_SERVER_CONFIGURATION_H_
#define MIR_DEFAULT_SERVER_CONFIGURATION_H_

#include "mir/cached_ptr.h"
#include "mir/server_configuration.h"
#include "mir/options/program_option.h"

#include <memory>
#include <string>

namespace mir
{
namespace compositor
{
class BufferAllocationStrategy;
class GraphicBufferAllocator;
class BufferBundleManager;
class Renderables;
class Drawer;
class CompositingStrategy;
class Compositor;
class OverlayRenderer;
}
namespace frontend
{
class Shell;
class Communicator;
class ProtobufIpcFactory;
class SessionMediatorReport;
class MessageProcessorReport;
}

namespace shell
{
class SurfaceFactory;
class SurfaceBuilder;
class InputTargeter;
class SessionContainer;
class FocusSetter;
class FocusSequence;
class PlacementStrategy;
class SessionListener;
class FocusController;
class SessionManager;
}
namespace time
{
class TimeSource;
}
namespace surfaces
{
class BufferBundleFactory;
class SurfaceStackModel;
class SurfaceStack;
class SurfaceController;
class InputRegistrar;
}
namespace graphics
{
class Renderer;
class Platform;
class Display;
class ViewableArea;
class BufferInitializer;
class DisplayReport;
}
namespace input
{
class InputReport;
class InputManager;
class EventFilter;
class InputChannelFactory;
class InputConfiguration;
}

namespace logging
{
class Logger;
}

class DefaultServerConfiguration : public virtual ServerConfiguration
{
public:
    DefaultServerConfiguration(int argc, char const* argv[]);

    /** @name DisplayServer dependencies
     * dependencies of DisplayServer on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<frontend::Communicator> the_communicator();
    virtual std::shared_ptr<graphics::Display>      the_display();
    virtual std::shared_ptr<compositor::Compositor> the_compositor();
    virtual std::shared_ptr<input::InputManager>    the_input_manager();
    virtual std::shared_ptr<MainLoop>               the_main_loop();
    /** @} */

    /** @name graphics configuration - customization
     * configurable interfaces for modifying graphics
     *  @{ */
    virtual std::shared_ptr<graphics::BufferInitializer> the_buffer_initializer();
    virtual std::shared_ptr<graphics::Renderer>          the_renderer();
    virtual std::shared_ptr<graphics::ViewableArea>      the_viewable_area();
    /** @} */

    /** @name graphics configuration - dependencies
     * dependencies of graphics on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<graphics::DisplayReport> the_display_report();
    /** @} */

    /** @name compositor configuration - customization
     * configurable interfaces for modifying compositor
     *  @{ */
    virtual std::shared_ptr<compositor::CompositingStrategy>      the_compositing_strategy();
    virtual std::shared_ptr<compositor::OverlayRenderer>          the_overlay_renderer();
    virtual std::shared_ptr<compositor::BufferAllocationStrategy> the_buffer_allocation_strategy();
    /** @} */

    /** @name compositor configuration - dependencies
     * dependencies of compositor on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<compositor::GraphicBufferAllocator> the_buffer_allocator();
    virtual std::shared_ptr<compositor::Renderables>            the_renderables();
    /** @} */

    /** @name frontend configuration - dependencies
     * dependencies of frontend on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<frontend::SessionMediatorReport>  the_session_mediator_report();
    virtual std::shared_ptr<frontend::MessageProcessorReport> the_message_processor_report();
    virtual std::shared_ptr<frontend::Shell>                  the_frontend_shell();
    /** @} */

    virtual std::shared_ptr<shell::FocusController> the_focus_controller();

    /** @name shell configuration - customization
     * configurable interfaces for modifying shell
     *  @{ */
    virtual std::shared_ptr<shell::SurfaceFactory>    the_shell_surface_factory();
    virtual std::shared_ptr<shell::SessionContainer>  the_shell_session_container();
    virtual std::shared_ptr<shell::FocusSetter>       the_shell_focus_setter();
    virtual std::shared_ptr<shell::FocusSequence>     the_shell_focus_sequence();
    virtual std::shared_ptr<shell::PlacementStrategy> the_shell_placement_strategy();
    virtual std::shared_ptr<shell::SessionListener>   the_shell_session_listener();
    /** @} */

    /** @name shell configuration - dependencies
     * dependencies of shell on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<shell::SurfaceBuilder>     the_surface_builder();
    /** @} */


    /** @name surfaces configuration - customization
     * configurable interfaces for modifying surfaces
     *  @{ */
    virtual std::shared_ptr<surfaces::SurfaceStackModel> the_surface_stack_model();
    /** @} */

    /** @name surfaces configuration - dependencies
     * dependencies of surfaces on the rest of the Mir
     *  @{ */
    virtual std::shared_ptr<surfaces::BufferBundleFactory> the_buffer_bundle_factory();
    /** @} */


    /** @name input configuration
     *  @{ */
    virtual std::shared_ptr<input::InputReport> the_input_report();
    virtual std::shared_ptr<input::InputConfiguration> the_input_configuration();
    virtual std::initializer_list<std::shared_ptr<input::EventFilter> const> the_event_filters();
    virtual std::shared_ptr<surfaces::InputRegistrar> the_input_registrar();
    virtual std::shared_ptr<shell::InputTargeter> the_input_targeter();
    /** @} */

    /** @name logging configuration - customization
     * configurable interfaces for modifying logging
     *  @{ */
    virtual std::shared_ptr<logging::Logger> the_logger();
    /** @} */

    virtual std::shared_ptr<graphics::Platform>  the_graphics_platform();
    virtual std::shared_ptr<time::TimeSource>    the_time_source();

    virtual std::shared_ptr<shell::SessionManager> the_session_manager();

protected:
    // add_options() allows configuration specializations to add their
    // own options. This MUST be called before the first invocation of
    // the_options() - typically during construction.
    boost::program_options::options_description_easy_init add_options();
    virtual std::shared_ptr<options::Option> the_options() const;

    virtual std::shared_ptr<input::InputChannelFactory> the_input_channel_factory();

    CachedPtr<frontend::Communicator> communicator;
    CachedPtr<shell::SessionManager> session_manager;


    std::shared_ptr<input::InputConfiguration> input_configuration;

    CachedPtr<input::InputReport> input_report;
    CachedPtr<input::InputManager>    input_manager;
    CachedPtr<surfaces::InputRegistrar> input_registrar;
    CachedPtr<shell::InputTargeter> input_targeter;
    CachedPtr<graphics::Platform>     graphics_platform;
    CachedPtr<graphics::BufferInitializer> buffer_initializer;
    CachedPtr<compositor::GraphicBufferAllocator> buffer_allocator;
    CachedPtr<graphics::Display>      display;

    CachedPtr<frontend::ProtobufIpcFactory>  ipc_factory;
    CachedPtr<frontend::SessionMediatorReport> session_mediator_report;
    CachedPtr<frontend::MessageProcessorReport> message_processor_report;
    CachedPtr<compositor::BufferAllocationStrategy> buffer_allocation_strategy;
    CachedPtr<graphics::Renderer> renderer;
    CachedPtr<compositor::BufferBundleManager> buffer_bundle_manager;
    CachedPtr<surfaces::SurfaceStack> surface_stack;
    CachedPtr<shell::SurfaceFactory> shell_surface_factory;
    CachedPtr<shell::SessionContainer>  shell_session_container;
    CachedPtr<shell::FocusSetter>       shell_focus_setter;
    CachedPtr<shell::FocusSequence>     shell_focus_sequence;
    CachedPtr<shell::PlacementStrategy> shell_placement_strategy;
    CachedPtr<shell::SessionListener> shell_session_listener;
    CachedPtr<compositor::CompositingStrategy> compositing_strategy;
    CachedPtr<compositor::OverlayRenderer> overlay_renderer;
    CachedPtr<compositor::Compositor> compositor;
    CachedPtr<logging::Logger> logger;
    CachedPtr<graphics::DisplayReport> display_report;
    CachedPtr<surfaces::SurfaceController> surface_controller;
    CachedPtr<time::TimeSource> time_source;
    CachedPtr<MainLoop> main_loop;

private:
    int const argc;
    char const** const argv;
    std::shared_ptr<boost::program_options::options_description> const program_options;
    std::shared_ptr<options::Option> mutable options;

    // the communications interface to use
    virtual std::shared_ptr<frontend::ProtobufIpcFactory> the_ipc_factory(
        std::shared_ptr<frontend::Shell> const& shell,
        std::shared_ptr<graphics::ViewableArea> const& display,
        std::shared_ptr<compositor::GraphicBufferAllocator> const& allocator);

    virtual std::string the_socket_file() const;
};
}


#endif /* MIR_DEFAULT_SERVER_CONFIGURATION_H_ */
