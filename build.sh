#!/bin/bash
set -e
notify-send -u critical 'Compiling and installing/updating dwm...'
DESTDIR=~/local PREFIX='' make clean install
notify-send -u critical "DWM will be restarted now..."
pkill -HUP dwm
