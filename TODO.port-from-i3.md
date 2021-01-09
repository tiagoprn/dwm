---

## COMMANDS

```

dwm-print-all-mapped-keys.sh  | grep 'Alt'

dwm-print-cheatsheet.sh | grep 'Alt'

```


## BINDSYMS

```
TODO: check below why the last one runs, and the other ones on tmux not. Maybe I can start all with /bin/bash and add xdotool to type the tmux load commands once there...

- [ ] MOD+n /home/pi/apps/scripts/bin/vim-notes.sh &
- [ ] Mod1+l /home/pi/apps/scripts/bin/i3-personal-calendar.sh &
- [x] Mod1+t /home/pi/apps/scripts/bin/dropdown-term.sh &

- [ ] Install firefox from flatpak

---

- [ ] bindsym $mod+Shift+n exec --no-startup-id networkmanager_dmenu

- [ ] bindsym Mod1+p exec --no-startup-id "notify-send 'Taking screenshot...' --urgency low -t 600; mkdir -p ~/screenshots && flatpak run --filesystem=host org.flameshot.Flameshot full -p ~/screenshots -d 2000"
- [ ] bindsym Mod1+Shift+p exec --no-startup-id "notify-send 'Taking screenshot (CTRL+s to save)...' --urgency critical -t 1300; mkdir -p ~/screenshots &&  flatpak run --filesystem=host org.flameshot.Flameshot gui -p ~/screenshots -d 2000"

- [ ] bindsym Mod1+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/personal -C ~/.local/share/qutebrowser/personal/config/config.py"
- [ ] bindsym Mod1+Shift+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/work/dafiti -C ~/.local/share/qutebrowser/work/dafiti/config/config.py"

- [ ] a command to see the desktop, without the windows

- [x] bindsym Mod1+v exec --no-startup-id pavucontrol
- [x] bindsym Mod1+k exec --no-startup-id "/home/pi/apps/scripts/rofi/toggle_keyboards.py"
- [x] Mod1+Shift+k /home/pi/apps/scripts/bin/keyboard-backlight.sh &
- [x] bindsym Mod1+r exec --no-startup-id lxappearance
- [x] bindsym $mod+c exec --no-startup-id "/home/pi/apps/scripts/bin/customize_capslock.sh"
- [x] bindsym $mod+n exec --no-startup-id "notify-send 'Launching pcmanfm...' --urgency low; pcmanfm"
- [x] arandr && reload_wallpaper.sh
- [x] bindsym $mod+o exec --no-startup-id "notify-send 'Deactivating the compton compositor through /home/pi/apps/scripts/bin/toggle_compositor.sh ...' --urgency low; /home/pi/apps/scripts/bin/toggle_compositor.sh"
- [x] bindsym $mod+b exec --no-startup-id /home/pi/apps/scripts/rofi/bookmarks.py
- [x] bindsym $mod+s exec --no-startup-id "/home/pi/apps/scripts/rofi/snippets.sh"
- [x] bindsym Mod1+w exec --no-startup-id sxiv -r -q -o $(ls -t --color=never ~/Wallpapers/*) | xargs feh --bg-scale
- [x] bindsym $mod+shift+v exec --no-startup-id /home/pi/apps/scripts/rofi/vim_shortcuts.py
- [x] bindsym Mod1+space exec playerctl play-pause
- [x] bindsym Mod1+Right exec playerctl next
- [x] bindsym Mod1+Left exec playerctl previous
- [x] bindsym Mod1+Up exec --no-startup-id pactl set-sink-volume 0 +5% #increase sound volume
- [x] bindsym Mod1+Down exec --no-startup-id pactl set-sink-volume 0 -5% #decrease sound volume
- [x] bindsym Mod1+Shift exec --no-startup-id pactl set-sink-mute 0 toggle # mute sound
- [x] bindsym Mod1+Shift+Up exec xbacklight -inc 20 # increase screen brightness
- [x] bindsym Mod1+Shift+Down exec xbacklight -dec 20 # decrease screen brightness
- [x] bindsym $mod+shift+d restart dwm (pkill -HUP dwm)
- [x] bindsym Mod1+Tab exec --no-startup-id rofi -show window -drun-icon-theme
- [x] scratchpads: ControlMask+Mod1Mask+1  /* ModMask = Alt (colocar no comando sed da cheatsheet) */
- [x] bindsym $mod+Shift+Return exec --no-startup-id st -e bash -c 'TERM=screen-256color /home/pi/apps/scripts/bin/start_random_tmux_session_name.sh'
```
