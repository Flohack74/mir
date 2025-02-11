/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This file is generated from text-input-unstable-v2.xml
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#include "text-input-unstable-v2_wrapper.h"

#include <boost/throw_exception.hpp>
#include <boost/exception/diagnostic_information.hpp>

#include <wayland-server-core.h>

#include "mir/log.h"

namespace mir
{
namespace wayland
{
extern struct wl_interface const wl_seat_interface_data;
extern struct wl_interface const wl_surface_interface_data;
extern struct wl_interface const zwp_text_input_manager_v2_interface_data;
extern struct wl_interface const zwp_text_input_v2_interface_data;
}
}

namespace mw = mir::wayland;

namespace
{
struct wl_interface const* all_null_types [] {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr};
}

// TextInputV2

struct mw::TextInputV2::Thunks
{
    static int const supported_version;

    static void destroy_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            wl_resource_destroy(resource);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::destroy()");
        }
    }

    static void enable_thunk(struct wl_client* client, struct wl_resource* resource, struct wl_resource* surface)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->enable(surface);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::enable()");
        }
    }

    static void disable_thunk(struct wl_client* client, struct wl_resource* resource, struct wl_resource* surface)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->disable(surface);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::disable()");
        }
    }

    static void show_input_panel_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->show_input_panel();
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::show_input_panel()");
        }
    }

    static void hide_input_panel_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->hide_input_panel();
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::hide_input_panel()");
        }
    }

    static void set_surrounding_text_thunk(struct wl_client* client, struct wl_resource* resource, char const* text, int32_t cursor, int32_t anchor)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->set_surrounding_text(text, cursor, anchor);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::set_surrounding_text()");
        }
    }

    static void set_content_type_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t hint, uint32_t purpose)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->set_content_type(hint, purpose);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::set_content_type()");
        }
    }

    static void set_cursor_rectangle_thunk(struct wl_client* client, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->set_cursor_rectangle(x, y, width, height);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::set_cursor_rectangle()");
        }
    }

    static void set_preferred_language_thunk(struct wl_client* client, struct wl_resource* resource, char const* language)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->set_preferred_language(language);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::set_preferred_language()");
        }
    }

    static void update_state_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t serial, uint32_t reason)
    {
        try
        {
            auto me = static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
            me->update_state(serial, reason);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV2::update_state()");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
    }

    static struct wl_interface const* enable_types[];
    static struct wl_interface const* disable_types[];
    static struct wl_interface const* enter_types[];
    static struct wl_interface const* leave_types[];
    static struct wl_message const request_messages[];
    static struct wl_message const event_messages[];
    static void const* request_vtable[];
};

int const mw::TextInputV2::Thunks::supported_version = 1;

mw::TextInputV2::TextInputV2(struct wl_resource* resource, Version<1>)
    : client{wl_resource_get_client(resource)},
      resource{resource}
{
    if (resource == nullptr)
    {
        BOOST_THROW_EXCEPTION((std::bad_alloc{}));
    }
    wl_resource_set_implementation(resource, Thunks::request_vtable, this, &Thunks::resource_destroyed_thunk);
}

mw::TextInputV2::~TextInputV2()
{
    wl_resource_set_implementation(resource, nullptr, nullptr, nullptr);
}

void mw::TextInputV2::send_enter_event(uint32_t serial, struct wl_resource* surface) const
{
    wl_resource_post_event(resource, Opcode::enter, serial, surface);
}

void mw::TextInputV2::send_leave_event(uint32_t serial, struct wl_resource* surface) const
{
    wl_resource_post_event(resource, Opcode::leave, serial, surface);
}

void mw::TextInputV2::send_input_panel_state_event(uint32_t state, int32_t x, int32_t y, int32_t width, int32_t height) const
{
    wl_resource_post_event(resource, Opcode::input_panel_state, state, x, y, width, height);
}

void mw::TextInputV2::send_preedit_string_event(std::string const& text, std::string const& commit) const
{
    const char* text_resolved = text.c_str();
    const char* commit_resolved = commit.c_str();
    wl_resource_post_event(resource, Opcode::preedit_string, text_resolved, commit_resolved);
}

void mw::TextInputV2::send_preedit_styling_event(uint32_t index, uint32_t length, uint32_t style) const
{
    wl_resource_post_event(resource, Opcode::preedit_styling, index, length, style);
}

void mw::TextInputV2::send_preedit_cursor_event(int32_t index) const
{
    wl_resource_post_event(resource, Opcode::preedit_cursor, index);
}

void mw::TextInputV2::send_commit_string_event(std::string const& text) const
{
    const char* text_resolved = text.c_str();
    wl_resource_post_event(resource, Opcode::commit_string, text_resolved);
}

void mw::TextInputV2::send_cursor_position_event(int32_t index, int32_t anchor) const
{
    wl_resource_post_event(resource, Opcode::cursor_position, index, anchor);
}

void mw::TextInputV2::send_delete_surrounding_text_event(uint32_t before_length, uint32_t after_length) const
{
    wl_resource_post_event(resource, Opcode::delete_surrounding_text, before_length, after_length);
}

void mw::TextInputV2::send_modifiers_map_event(struct wl_array* map) const
{
    wl_resource_post_event(resource, Opcode::modifiers_map, map);
}

void mw::TextInputV2::send_keysym_event(uint32_t time, uint32_t sym, uint32_t state, uint32_t modifiers) const
{
    wl_resource_post_event(resource, Opcode::keysym, time, sym, state, modifiers);
}

void mw::TextInputV2::send_language_event(std::string const& language) const
{
    const char* language_resolved = language.c_str();
    wl_resource_post_event(resource, Opcode::language, language_resolved);
}

void mw::TextInputV2::send_text_direction_event(uint32_t direction) const
{
    wl_resource_post_event(resource, Opcode::text_direction, direction);
}

void mw::TextInputV2::send_configure_surrounding_text_event(int32_t before_cursor, int32_t after_cursor) const
{
    wl_resource_post_event(resource, Opcode::configure_surrounding_text, before_cursor, after_cursor);
}

void mw::TextInputV2::send_input_method_changed_event(uint32_t serial, uint32_t flags) const
{
    wl_resource_post_event(resource, Opcode::input_method_changed, serial, flags);
}

bool mw::TextInputV2::is_instance(wl_resource* resource)
{
    return wl_resource_instance_of(resource, &zwp_text_input_v2_interface_data, Thunks::request_vtable);
}

uint32_t const mw::TextInputV2::ContentHint::none;
uint32_t const mw::TextInputV2::ContentHint::auto_completion;
uint32_t const mw::TextInputV2::ContentHint::auto_correction;
uint32_t const mw::TextInputV2::ContentHint::auto_capitalization;
uint32_t const mw::TextInputV2::ContentHint::lowercase;
uint32_t const mw::TextInputV2::ContentHint::uppercase;
uint32_t const mw::TextInputV2::ContentHint::titlecase;
uint32_t const mw::TextInputV2::ContentHint::hidden_text;
uint32_t const mw::TextInputV2::ContentHint::sensitive_data;
uint32_t const mw::TextInputV2::ContentHint::latin;
uint32_t const mw::TextInputV2::ContentHint::multiline;
uint32_t const mw::TextInputV2::ContentPurpose::normal;
uint32_t const mw::TextInputV2::ContentPurpose::alpha;
uint32_t const mw::TextInputV2::ContentPurpose::digits;
uint32_t const mw::TextInputV2::ContentPurpose::number;
uint32_t const mw::TextInputV2::ContentPurpose::phone;
uint32_t const mw::TextInputV2::ContentPurpose::url;
uint32_t const mw::TextInputV2::ContentPurpose::email;
uint32_t const mw::TextInputV2::ContentPurpose::name;
uint32_t const mw::TextInputV2::ContentPurpose::password;
uint32_t const mw::TextInputV2::ContentPurpose::date;
uint32_t const mw::TextInputV2::ContentPurpose::time;
uint32_t const mw::TextInputV2::ContentPurpose::datetime;
uint32_t const mw::TextInputV2::ContentPurpose::terminal;
uint32_t const mw::TextInputV2::UpdateState::change;
uint32_t const mw::TextInputV2::UpdateState::full;
uint32_t const mw::TextInputV2::UpdateState::reset;
uint32_t const mw::TextInputV2::UpdateState::enter;
uint32_t const mw::TextInputV2::InputPanelVisibility::hidden;
uint32_t const mw::TextInputV2::InputPanelVisibility::visible;
uint32_t const mw::TextInputV2::PreeditStyle::default_;
uint32_t const mw::TextInputV2::PreeditStyle::none;
uint32_t const mw::TextInputV2::PreeditStyle::active;
uint32_t const mw::TextInputV2::PreeditStyle::inactive;
uint32_t const mw::TextInputV2::PreeditStyle::highlight;
uint32_t const mw::TextInputV2::PreeditStyle::underline;
uint32_t const mw::TextInputV2::PreeditStyle::selection;
uint32_t const mw::TextInputV2::PreeditStyle::incorrect;
uint32_t const mw::TextInputV2::TextDirection::auto_;
uint32_t const mw::TextInputV2::TextDirection::ltr;
uint32_t const mw::TextInputV2::TextDirection::rtl;

struct wl_interface const* mw::TextInputV2::Thunks::enable_types[] {
    &wl_surface_interface_data};

struct wl_interface const* mw::TextInputV2::Thunks::disable_types[] {
    &wl_surface_interface_data};

struct wl_interface const* mw::TextInputV2::Thunks::enter_types[] {
    nullptr,
    &wl_surface_interface_data};

struct wl_interface const* mw::TextInputV2::Thunks::leave_types[] {
    nullptr,
    &wl_surface_interface_data};

struct wl_message const mw::TextInputV2::Thunks::request_messages[] {
    {"destroy", "", all_null_types},
    {"enable", "o", enable_types},
    {"disable", "o", disable_types},
    {"show_input_panel", "", all_null_types},
    {"hide_input_panel", "", all_null_types},
    {"set_surrounding_text", "sii", all_null_types},
    {"set_content_type", "uu", all_null_types},
    {"set_cursor_rectangle", "iiii", all_null_types},
    {"set_preferred_language", "s", all_null_types},
    {"update_state", "uu", all_null_types}};

struct wl_message const mw::TextInputV2::Thunks::event_messages[] {
    {"enter", "uo", enter_types},
    {"leave", "uo", leave_types},
    {"input_panel_state", "uiiii", all_null_types},
    {"preedit_string", "ss", all_null_types},
    {"preedit_styling", "uuu", all_null_types},
    {"preedit_cursor", "i", all_null_types},
    {"commit_string", "s", all_null_types},
    {"cursor_position", "ii", all_null_types},
    {"delete_surrounding_text", "uu", all_null_types},
    {"modifiers_map", "a", all_null_types},
    {"keysym", "uuuu", all_null_types},
    {"language", "s", all_null_types},
    {"text_direction", "u", all_null_types},
    {"configure_surrounding_text", "ii", all_null_types},
    {"input_method_changed", "uu", all_null_types}};

void const* mw::TextInputV2::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk,
    (void*)Thunks::enable_thunk,
    (void*)Thunks::disable_thunk,
    (void*)Thunks::show_input_panel_thunk,
    (void*)Thunks::hide_input_panel_thunk,
    (void*)Thunks::set_surrounding_text_thunk,
    (void*)Thunks::set_content_type_thunk,
    (void*)Thunks::set_cursor_rectangle_thunk,
    (void*)Thunks::set_preferred_language_thunk,
    (void*)Thunks::update_state_thunk};

mw::TextInputV2* mw::TextInputV2::from(struct wl_resource* resource)
{
    if (wl_resource_instance_of(resource, &zwp_text_input_v2_interface_data, TextInputV2::Thunks::request_vtable))
    {
        return static_cast<TextInputV2*>(wl_resource_get_user_data(resource));
    }
    return nullptr;
}

// TextInputManagerV2

struct mw::TextInputManagerV2::Thunks
{
    static int const supported_version;

    static void destroy_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            wl_resource_destroy(resource);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputManagerV2::destroy()");
        }
    }

    static void get_text_input_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* seat)
    {
        wl_resource* id_resolved{
            wl_resource_create(client, &zwp_text_input_v2_interface_data, wl_resource_get_version(resource), id)};
        if (id_resolved == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        try
        {
            auto me = static_cast<TextInputManagerV2*>(wl_resource_get_user_data(resource));
            me->get_text_input(id_resolved, seat);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputManagerV2::get_text_input()");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<TextInputManagerV2*>(wl_resource_get_user_data(resource));
    }

    static void bind_thunk(struct wl_client* client, void* data, uint32_t version, uint32_t id)
    {
        auto me = static_cast<TextInputManagerV2::Global*>(data);
        auto resource = wl_resource_create(
            client,
            &zwp_text_input_manager_v2_interface_data,
            std::min((int)version, Thunks::supported_version),
            id);
        if (resource == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        try
        {
            me->bind(resource);
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputManagerV2 global bind");
        }
    }

    static struct wl_interface const* get_text_input_types[];
    static struct wl_message const request_messages[];
    static void const* request_vtable[];
};

int const mw::TextInputManagerV2::Thunks::supported_version = 1;

mw::TextInputManagerV2::TextInputManagerV2(struct wl_resource* resource, Version<1>)
    : client{wl_resource_get_client(resource)},
      resource{resource}
{
    if (resource == nullptr)
    {
        BOOST_THROW_EXCEPTION((std::bad_alloc{}));
    }
    wl_resource_set_implementation(resource, Thunks::request_vtable, this, &Thunks::resource_destroyed_thunk);
}

mw::TextInputManagerV2::~TextInputManagerV2()
{
    wl_resource_set_implementation(resource, nullptr, nullptr, nullptr);
}

bool mw::TextInputManagerV2::is_instance(wl_resource* resource)
{
    return wl_resource_instance_of(resource, &zwp_text_input_manager_v2_interface_data, Thunks::request_vtable);
}

mw::TextInputManagerV2::Global::Global(wl_display* display, Version<1>)
    : wayland::Global{
          wl_global_create(
              display,
              &zwp_text_input_manager_v2_interface_data,
              Thunks::supported_version,
              this,
              &Thunks::bind_thunk)}
{
}

auto mw::TextInputManagerV2::Global::interface_name() const -> char const*
{
    return TextInputManagerV2::interface_name;
}

struct wl_interface const* mw::TextInputManagerV2::Thunks::get_text_input_types[] {
    &zwp_text_input_v2_interface_data,
    &wl_seat_interface_data};

struct wl_message const mw::TextInputManagerV2::Thunks::request_messages[] {
    {"destroy", "", all_null_types},
    {"get_text_input", "no", get_text_input_types}};

void const* mw::TextInputManagerV2::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk,
    (void*)Thunks::get_text_input_thunk};

mw::TextInputManagerV2* mw::TextInputManagerV2::from(struct wl_resource* resource)
{
    if (wl_resource_instance_of(resource, &zwp_text_input_manager_v2_interface_data, TextInputManagerV2::Thunks::request_vtable))
    {
        return static_cast<TextInputManagerV2*>(wl_resource_get_user_data(resource));
    }
    return nullptr;
}

namespace mir
{
namespace wayland
{

struct wl_interface const zwp_text_input_v2_interface_data {
    mw::TextInputV2::interface_name,
    mw::TextInputV2::Thunks::supported_version,
    10, mw::TextInputV2::Thunks::request_messages,
    15, mw::TextInputV2::Thunks::event_messages};

struct wl_interface const zwp_text_input_manager_v2_interface_data {
    mw::TextInputManagerV2::interface_name,
    mw::TextInputManagerV2::Thunks::supported_version,
    2, mw::TextInputManagerV2::Thunks::request_messages,
    0, nullptr};

}
}
