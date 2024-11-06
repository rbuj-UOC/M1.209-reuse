#!/bin/sh
rm -rf autom4te.cache
rm -f aclocal.m4 ltmain.sh

echo "Running aclocal..." ;  aclocal --force --install -I m4 || exit 1
echo "Running autoconf..." ; autoconf --force || exit 1
echo "Running automake..." ; automake --force --add-missing --copy --gnu || exit 1
