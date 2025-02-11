/*
 * AUTOGENERATED - DO NOT EDIT
 *
 * This file is generated from text-input-unstable-v3.xml
 * To regenerate, run the “refresh-wayland-wrapper” target.
 */

#include "text-input-unstable-v3_wrapper.h"

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
extern struct wl_interface const zwp_text_input_manager_v3_interface_data;
extern struct wl_interface const zwp_text_input_v3_interface_data;
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

// TextInputV3

struct mw::TextInputV3::Thunks
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
            internal_error_processing_request(client, "TextInputV3::destroy()");
        }
    }

    static void enable_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->enable();
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::enable()");
        }
    }

    static void disable_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->disable();
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::disable()");
        }
    }

    static void set_surrounding_text_thunk(struct wl_client* client, struct wl_resource* resource, char const* text, int32_t cursor, int32_t anchor)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->set_surrounding_text(text, cursor, anchor);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::set_surrounding_text()");
        }
    }

    static void set_text_change_cause_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t cause)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->set_text_change_cause(cause);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::set_text_change_cause()");
        }
    }

    static void set_content_type_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t hint, uint32_t purpose)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->set_content_type(hint, purpose);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::set_content_type()");
        }
    }

    static void set_cursor_rectangle_thunk(struct wl_client* client, struct wl_resource* resource, int32_t x, int32_t y, int32_t width, int32_t height)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->set_cursor_rectangle(x, y, width, height);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::set_cursor_rectangle()");
        }
    }

    static void commit_thunk(struct wl_client* client, struct wl_resource* resource)
    {
        try
        {
            auto me = static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
            me->commit();
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputV3::commit()");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
    }

    static struct wl_interface const* enter_types[];
    static struct wl_interface const* leave_types[];
    static struct wl_message const request_messages[];
    static struct wl_message const event_messages[];
    static void const* request_vtable[];
};

int const mw::TextInputV3::Thunks::supported_version = 1;

mw::TextInputV3::TextInputV3(struct wl_resource* resource, Version<1>)
    : client{wl_resource_get_client(resource)},
      resource{resource}
{
    if (resource == nullptr)
    {
        BOOST_THROW_EXCEPTION((std::bad_alloc{}));
    }
    wl_resource_set_implementation(resource, Thunks::request_vtable, this, &Thunks::resource_destroyed_thunk);
}

mw::TextInputV3::~TextInputV3()
{
    wl_resource_set_implementation(resource, nullptr, nullptr, nullptr);
}

void mw::TextInputV3::send_enter_event(struct wl_resource* surface) const
{
    wl_resource_post_event(resource, Opcode::enter, surface);
}

void mw::TextInputV3::send_leave_event(struct wl_resource* surface) const
{
    wl_resource_post_event(resource, Opcode::leave, surface);
}

void mw::TextInputV3::send_preedit_string_event(std::optional<std::string> const& text, int32_t cursor_begin, int32_t cursor_end) const
{
    const char* text_resolved = nullptr;
    if (text)
    {
        text_resolved = text.value().c_str();
    }
    wl_resource_post_event(resource, Opcode::preedit_string, text_resolved, cursor_begin, cursor_end);
}

void mw::TextInputV3::send_commit_string_event(std::optional<std::string> const& text) const
{
    const char* text_resolved = nullptr;
    if (text)
    {
        text_resolved = text.value().c_str();
    }
    wl_resource_post_event(resource, Opcode::commit_string, text_resolved);
}

void mw::TextInputV3::send_delete_surrounding_text_event(uint32_t before_length, uint32_t after_length) const
{
    wl_resource_post_event(resource, Opcode::delete_surrounding_text, before_length, after_length);
}

void mw::TextInputV3::send_done_event(uint32_t serial) const
{
    wl_resource_post_event(resource, Opcode::done, serial);
}

bool mw::TextInputV3::is_instance(wl_resource* resource)
{
    return wl_resource_instance_of(resource, &zwp_text_input_v3_interface_data, Thunks::request_vtable);
}

uint32_t const mw::TextInputV3::ChangeCause::input_method;
uint32_t const mw::TextInputV3::ChangeCause::other;
uint32_t const mw::TextInputV3::ContentHint::none;
uint32_t const mw::TextInputV3::ContentHint::completion;
uint32_t const mw::TextInputV3::ContentHint::spellcheck;
uint32_t const mw::TextInputV3::ContentHint::auto_capitalization;
uint32_t const mw::TextInputV3::ContentHint::lowercase;
uint32_t const mw::TextInputV3::ContentHint::uppercase;
uint32_t const mw::TextInputV3::ContentHint::titlecase;
uint32_t const mw::TextInputV3::ContentHint::hidden_text;
uint32_t const mw::TextInputV3::ContentHint::sensitive_data;
uint32_t const mw::TextInputV3::ContentHint::latin;
uint32_t const mw::TextInputV3::ContentHint::multiline;
uint32_t const mw::TextInputV3::ContentPurpose::normal;
uint32_t const mw::TextInputV3::ContentPurpose::alpha;
uint32_t const mw::TextInputV3::ContentPurpose::digits;
uint32_t const mw::TextInputV3::ContentPurpose::number;
uint32_t const mw::TextInputV3::ContentPurpose::phone;
uint32_t const mw::TextInputV3::ContentPurpose::url;
uint32_t const mw::TextInputV3::ContentPurpose::email;
uint32_t const mw::TextInputV3::ContentPurpose::name;
uint32_t const mw::TextInputV3::ContentPurpose::password;
uint32_t const mw::TextInputV3::ContentPurpose::pin;
uint32_t const mw::TextInputV3::ContentPurpose::date;
uint32_t const mw::TextInputV3::ContentPurpose::time;
uint32_t const mw::TextInputV3::ContentPurpose::datetime;
uint32_t const mw::TextInputV3::ContentPurpose::terminal;

struct wl_interface const* mw::TextInputV3::Thunks::enter_types[] {
    &wl_surface_interface_data};

struct wl_interface const* mw::TextInputV3::Thunks::leave_types[] {
    &wl_surface_interface_data};

struct wl_message const mw::TextInputV3::Thunks::request_messages[] {
    {"destroy", "", all_null_types},
    {"enable", "", all_null_types},
    {"disable", "", all_null_types},
    {"set_surrounding_text", "sii", all_null_types},
    {"set_text_change_cause", "u", all_null_types},
    {"set_content_type", "uu", all_null_types},
    {"set_cursor_rectangle", "iiii", all_null_types},
    {"commit", "", all_null_types}};

struct wl_message const mw::TextInputV3::Thunks::event_messages[] {
    {"enter", "o", enter_types},
    {"leave", "o", leave_types},
    {"preedit_string", "?sii", all_null_types},
    {"commit_string", "?s", all_null_types},
    {"delete_surrounding_text", "uu", all_null_types},
    {"done", "u", all_null_types}};

void const* mw::TextInputV3::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk,
    (void*)Thunks::enable_thunk,
    (void*)Thunks::disable_thunk,
    (void*)Thunks::set_surrounding_text_thunk,
    (void*)Thunks::set_text_change_cause_thunk,
    (void*)Thunks::set_content_type_thunk,
    (void*)Thunks::set_cursor_rectangle_thunk,
    (void*)Thunks::commit_thunk};

mw::TextInputV3* mw::TextInputV3::from(struct wl_resource* resource)
{
    if (wl_resource_instance_of(resource, &zwp_text_input_v3_interface_data, TextInputV3::Thunks::request_vtable))
    {
        return static_cast<TextInputV3*>(wl_resource_get_user_data(resource));
    }
    return nullptr;
}

// TextInputManagerV3

struct mw::TextInputManagerV3::Thunks
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
            internal_error_processing_request(client, "TextInputManagerV3::destroy()");
        }
    }

    static void get_text_input_thunk(struct wl_client* client, struct wl_resource* resource, uint32_t id, struct wl_resource* seat)
    {
        wl_resource* id_resolved{
            wl_resource_create(client, &zwp_text_input_v3_interface_data, wl_resource_get_version(resource), id)};
        if (id_resolved == nullptr)
        {
            wl_client_post_no_memory(client);
            BOOST_THROW_EXCEPTION((std::bad_alloc{}));
        }
        try
        {
            auto me = static_cast<TextInputManagerV3*>(wl_resource_get_user_data(resource));
            me->get_text_input(id_resolved, seat);
        }
        catch(ProtocolError const& err)
        {
            wl_resource_post_error(err.resource(), err.code(), "%s", err.message());
        }
        catch(...)
        {
            internal_error_processing_request(client, "TextInputManagerV3::get_text_input()");
        }
    }

    static void resource_destroyed_thunk(wl_resource* resource)
    {
        delete static_cast<TextInputManagerV3*>(wl_resource_get_user_data(resource));
    }

    static void bind_thunk(struct wl_client* client, void* data, uint32_t version, uint32_t id)
    {
        auto me = static_cast<TextInputManagerV3::Global*>(data);
        auto resource = wl_resource_create(
            client,
            &zwp_text_input_manager_v3_interface_data,
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
            internal_error_processing_request(client, "TextInputManagerV3 global bind");
        }
    }

    static struct wl_interface const* get_text_input_types[];
    static struct wl_message const request_messages[];
    static void const* request_vtable[];
};

int const mw::TextInputManagerV3::Thunks::supported_version = 1;

mw::TextInputManagerV3::TextInputManagerV3(struct wl_resource* resource, Version<1>)
    : client{wl_resource_get_client(resource)},
      resource{resource}
{
    if (resource == nullptr)
    {
        BOOST_THROW_EXCEPTION((std::bad_alloc{}));
    }
    wl_resource_set_implementation(resource, Thunks::request_vtable, this, &Thunks::resource_destroyed_thunk);
}

mw::TextInputManagerV3::~TextInputManagerV3()
{
    wl_resource_set_implementation(resource, nullptr, nullptr, nullptr);
}

bool mw::TextInputManagerV3::is_instance(wl_resource* resource)
{
    return wl_resource_instance_of(resource, &zwp_text_input_manager_v3_interface_data, Thunks::request_vtable);
}

mw::TextInputManagerV3::Global::Global(wl_display* display, Version<1>)
    : wayland::Global{
          wl_global_create(
              display,
              &zwp_text_input_manager_v3_interface_data,
              Thunks::supported_version,
              this,
              &Thunks::bind_thunk)}
{
}

auto mw::TextInputManagerV3::Global::interface_name() const -> char const*
{
    return TextInputManagerV3::interface_name;
}

struct wl_interface const* mw::TextInputManagerV3::Thunks::get_text_input_types[] {
    &zwp_text_input_v3_interface_data,
    &wl_seat_interface_data};

struct wl_message const mw::TextInputManagerV3::Thunks::request_messages[] {
    {"destroy", "", all_null_types},
    {"get_text_input", "no", get_text_input_types}};

void const* mw::TextInputManagerV3::Thunks::request_vtable[] {
    (void*)Thunks::destroy_thunk,
    (void*)Thunks::get_text_input_thunk};

mw::TextInputManagerV3* mw::TextInputManagerV3::from(struct wl_resource* resource)
{
    if (wl_resource_instance_of(resource, &zwp_text_input_manager_v3_interface_data, TextInputManagerV3::Thunks::request_vtable))
    {
        return static_cast<TextInputManagerV3*>(wl_resource_get_user_data(resource));
    }
    return nullptr;
}

namespace mir
{
namespace wayland
{

struct wl_interface const zwp_text_input_v3_interface_data {
    mw::TextInputV3::interface_name,
    mw::TextInputV3::Thunks::supported_version,
    8, mw::TextInputV3::Thunks::request_messages,
    6, mw::TextInputV3::Thunks::event_messages};

struct wl_interface const zwp_text_input_manager_v3_interface_data {
    mw::TextInputManagerV3::interface_name,
    mw::TextInputManagerV3::Thunks::supported_version,
    2, mw::TextInputManagerV3::Thunks::request_messages,
    0, nullptr};

}
}
