# Copyright (C) 2024 Robert Buj <rbuj2uoc.edu>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
# 02110-1301, USA.

AC_INIT([reuse],[0.1],[https://github.com/rbuj-UOC/M1.209-reuse])
AC_COPYRIGHT([Copyright (C) 2024 Robert Buj])
AC_PREREQ(2.60)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 foreign])
AM_SILENT_RULES([yes])
AM_MAINTAINER_MODE
AC_PROG_CC
AC_PROG_CC_STDC
AC_CONFIG_FILES([
Makefile
src/Makefile
src/base/Makefile
src/test/Makefile
])
AC_OUTPUT

echo "
Configure summary:

      ${PACKAGE_STRING}
      `echo $PACKAGE_STRING | sed "s/./=/g"`
      prefix:                     ${prefix}
      compiler:                   ${CC}
      cflags:                     ${CFLAGS}
"
