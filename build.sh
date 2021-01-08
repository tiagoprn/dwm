#!/bin/bash
set -e
notify-send -u critical 'Compiling and installing/updating dwm...'
DESTDIR=~/local PREFIX='' make clean install
# echo 'Converting man page to html...'
# groff -man -T html larbs.mom > larbs.html
# echo 'Finished'
notify-send -u critical "DWM will be restarted now..."
pkill -HUP dwm
