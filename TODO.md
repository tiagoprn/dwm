- [ ] `TODO.port-from-i3.md`: Port i3 bindsyms

- [ ] Add comments to all bindings on config.h, so that I can run with a rofi cheatsheet (copy from vim.cheatsheet)

```
cat /storage/src/dwm/config.h | grep 'description: ' | sort | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\*/---/g' | sed 's/\*\///g'
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\*/---/g' | sed 's/\*\///g' | sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\///g' |  sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\///g' | sed 's/,//g' | sed 's/\\$//g' |  sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\//=>/g' | sed 's/,//g' | sed 's/\\$//g' |  sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\//=>/g' | sed 's/,//g' | sed 's/\\$//g' | sed 's/\t/ /g' | sed 's/ \+/ /g' | sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\//=>/g' | sed 's/,//g' | sed 's/\\$//g' | sed 's/\t/ /g' | sed 's/ \+/ /g' | sed 's/MODKEY/MOD/g' | sed 's/ShiftMask/Shift/g'| sed 's/ControlMask/Ctrl/g' | sed 's/|/\+/g' | sed 's/ XK_/\+/g' | sed 's/spawn SHCMD(//g' | sed 's/)$//g' |  sort
cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\//=>/g' | sed 's/,//g' | sed 's/\\$//g' | sed 's/\t/ /g' | sed 's/ \+/ /g' | sed 's/MODKEY/MOD/g' | sed 's/ShiftMask/Shift/g'| sed 's/ControlMask/Ctrl/g' | sed 's/|/\+/g' | sed 's/ XK_/\+/g' | sed 's/spawn SHCMD(//g' | sed 's/)$//g' | sed 's/TAGKEYS(/TAGKEYS_MACRO_VALUES::/g' | sed 's/STACKKEYS(/STACKKEYS_MACRO_VALUES::/g' | sort

cat /storage/src/dwm/config.h | grep 'description: ' | sed 's/{ //g' | sed 's/ }//g'  | sed 's/\/\* description: //g' | sed 's/\*\//=>/g' | sed 's/,//g' | sed 's/\\$//g' | sed 's/\t/ /g' | sed 's/ \+/ /g' | sed 's/MODKEY/MOD/g' | sed 's/ShiftMask/Shift/g'| sed 's/ControlMask/Ctrl/g' | sed 's/|/\+/g' | sed 's/ XK_/\+/g' | sed 's/spawn SHCMD(//g' | sed 's/)$//g' | sed 's/TAGKEYS(//g' | sed 's/STACKKEYS(//g' | sort

```

- [ ] Instalar e configurar o khal e o vdirsyncer para o scratchpad do personal-calendar funcionar.
- [ ] Check if scratchpads for vim and personal-calendar are opened floating with urxvt on picom with no transparency

- [ ] Bring some i3 bindsyms to dwm using shkxd?

- [x] Remap mod+d to run the rofi apps menu, and mod+shift+d to run dmenu
- [x] Remap mod+z as on i3, and change the logoff dwm command if os=raspbian (`loginctl terminate-user pi`)
- [x] Configure dwm autostart on `startdwm`
- [x] Remove the keyboard shortcuts that I will not use
- [x] Remove garbage from dwmblocks, organize and keep it more minimal.
- [x] Move the script I used on i3blocks (load average, memory, caps lock etc to dwmblocks.
