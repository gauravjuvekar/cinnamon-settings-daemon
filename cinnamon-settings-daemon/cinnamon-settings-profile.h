/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2005 William Jon McCann <mccann@jhu.edu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authors: William Jon McCann <mccann@jhu.edu>
 *
 */

#ifndef __CINNAMON_SETTINGS_PROFILE_H
#define __CINNAMON_SETTINGS_PROFILE_H

#include <glib.h>

G_BEGIN_DECLS

#ifdef ENABLE_PROFILING
#ifdef G_HAVE_ISO_VARARGS
#define cinnamon_settings_profile_start(...) _cinnamon_settings_profile_log (G_STRFUNC, "start", __VA_ARGS__)
#define cinnamon_settings_profile_end(...)   _cinnamon_settings_profile_log (G_STRFUNC, "end", __VA_ARGS__)
#define cinnamon_settings_profile_msg(...)   _cinnamon_settings_profile_log (NULL, NULL, __VA_ARGS__)
#elif defined(G_HAVE_GNUC_VARARGS)
#define cinnamon_settings_profile_start(format...) _cinnamon_settings_profile_log (G_STRFUNC, "start", format)
#define cinnamon_settings_profile_end(format...)   _cinnamon_settings_profile_log (G_STRFUNC, "end", format)
#define cinnamon_settings_profile_msg(format...)   _cinnamon_settings_profile_log (NULL, NULL, format)
#endif
#else
#define cinnamon_settings_profile_start(...)
#define cinnamon_settings_profile_end(...)
#define cinnamon_settings_profile_msg(...)
#endif

void            _cinnamon_settings_profile_log    (const char *func,
                                                const char *note,
                                                const char *format,
                                                ...) G_GNUC_PRINTF (3, 4);

G_END_DECLS

#endif /* __CINNAMON_SETTINGS_PROFILE_H */
