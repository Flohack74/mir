/*
 * Copyright © 2013 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
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


#ifndef MIR_ANDROID_PLATFORM_H_
#define MIR_ANDROID_PLATFORM_H_

#ifdef ANDROID
// use the android headers
#ifndef ANDROIDFW_UTILS
#define ANDROIDFW_UTILS(name) <utils/name>
#endif
#else
// use the ubuntu headers
#ifndef ANDROIDFW_UTILS
#define ANDROIDFW_UTILS(name) <ubuntu/name>
#endif
#endif



#endif /* MIR_ANDROID_PLATFORM_H_ */
