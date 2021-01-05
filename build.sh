#!/bin/bash
echo 'Compiling and installing dwm...'
DESTDIR=~/local PREFIX='' make clean install
echo 'Converting man page to html...'
groff -man -T html larbs.mom > larbs.html
echo 'Finished'
