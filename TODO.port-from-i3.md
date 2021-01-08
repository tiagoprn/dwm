---

## BINDSYMS

```
- [ ] bindsym Mod1+r exec --no-startup-id lxappearance
- [ ] bindsym Mod1+o exec --no-startup-id pavucontrol
- [ ] bindsym $mod+c exec --no-startup-id "/home/pi/apps/scripts/bin/customize_capslock.sh"
- [ ] bindsym Mod1+p exec --no-startup-id "notify-send 'Taking screenshot...' --urgency low -t 600; mkdir -p ~/screenshots && flatpak run --filesystem=host org.flameshot.Flameshot full -p ~/screenshots -d 2000"
- [ ] bindsym Mod1+Shift+p exec --no-startup-id "notify-send 'Taking screenshot (CTRL+s to save)...' --urgency critical -t 1300; mkdir -p ~/screenshots &&  flatpak run --filesystem=host org.flameshot.Flameshot gui -p ~/screenshots -d 2000"
- [ ] a command to see the desktop, without the windows
- [ ] bindsym Mod1+y exec --no-startup-id /home/pi/apps/scripts/bin/zenity-video-launcher.sh
- [ ] bindsym Mod1+k exec --no-startup-id "/home/pi/apps/scripts/rofi/toggle_keyboards.py"
- [ ] bindsym Mod1+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/personal -C ~/.local/share/qutebrowser/personal/config/config.py"
- [ ] bindsym Mod1+Shift+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/work/dafiti -C ~/.local/share/qutebrowser/work/dafiti/config/config.py"
- [ ] notify-send 'Activating keyboard backlight...' --urgency low; /home/pi/apps/scripts/bin/keyboard-backlight.sh &


- [ ] TODO: the nnn binding (Win+r) is not working. I must find a way to hold a terminal there. Maybe start with /bin/bash and then use xdotool to type "nnn<ENTER>"?
- [ ] /home/pi/apps/scripts/bin/i3-vim.sh & (use the same solution from nnn)
- [ ] /home/pi/apps/scripts/bin/i3-personal-calendar.sh & (use the same solution from nnn)
- [ ] /home/pi/apps/scripts/bin/i3-dashboard.sh & (use the same solution from nnn)


- [ ] bindsym $mod+Shift+n exec --no-startup-id networkmanager_dmenu


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
