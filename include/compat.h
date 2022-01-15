/*
 * InspIRCd -- Internet Relay Chat Daemon
 *
 *   Copyright (C) 2013-2014, 2017, 2021 Sadie Powell <sadie@witchery.services>
 *   Copyright (C) 2013-2014, 2016 Attila Molnar <attilamolnar@hush.com>
 *
 * This file is part of InspIRCd.  InspIRCd is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, version 2.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once

/**
 * @def ATTR_PRINTF(STRINGPOS, FIRSTPOS)
 * Enables the compile-time checking of printf format strings. If a function
 * is marked with this attribute then the compiler will warn if a malformed
 * format string is passed to it.
 */
#if defined __GNUC__
# define ATTR_PRINTF(STRINGPOS, FIRSTPOS) __attribute__((format(printf, STRINGPOS, FIRSTPOS)))
#else
# define ATTR_PRINTF(STRINGPOS, FIRSTPOS)
#endif

/**
 * Windows is very different to UNIX so we have to wrap certain features in
 * order to build on Windows correctly.
 */
#if defined _WIN32
# include "inspircd_win32wrapper.h"
#else
# define ENTRYPOINT int main(int argc, char** argv)
# define DllExport __attribute__ ((visibility ("default")))
# define CoreExport __attribute__ ((visibility ("default")))
# include <unistd.h>
#endif
