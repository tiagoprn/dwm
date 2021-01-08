---

## BINDSYMS

```
bindsym Mod1+c exec --no-startup-id "/home/pi/apps/scripts/bin/clippy_rofi.py"
bindsym $mod+Shift+Return exec --no-startup-id st -f 'Iosevka:size=12:antialias=true:autohint=true' -e bash -c "TERM=screen-256color /home/pi/apps/scripts/bin/start_random_tmux_session_name.sh"
bindsym Mod1+Tab exec --no-startup-id rofi -show window -drun-icon-theme
bindsym $mod+e restart dwm (get the command used on the "?" icon on the topbar)
bindsym Mod1+Shift+Up exec xbacklight -inc 20 # increase screen brightness
bindsym Mod1+Shift+Down exec xbacklight -dec 20 # decrease screen brightness
bindsym Mod1+space exec playerctl play-pause
bindsym Mod1+Right exec playerctl next
bindsym Mod1+Left exec playerctl previous
bindsym Mod1+Up exec --no-startup-id pactl set-sink-volume 0 +5% #increase sound volume
bindsym Mod1+Down exec --no-startup-id pactl set-sink-volume 0 -5% #decrease sound volume
bindsym Mod1+Shift exec --no-startup-id pactl set-sink-mute 0 toggle # mute sound
bindsym $mod+i exec --no-startup-id /home/pi/apps/scripts/rofi/vim_shortcuts.py
bindsym Mod1+r exec --no-startup-id lxappearance
bindsym Mod1+w exec --no-startup-id sxiv -r -q -o $(ls -t --color=never ~/Wallpapers/*) | xargs feh --bg-scale
bindsym $mod+n exec --no-startup-id "notify-send 'Launching pcmanfm...' --urgency low; pcmanfm"
bindsym $mod+b exec --no-startup-id /home/pi/apps/scripts/rofi/bookmarks.py
bindsym Mod1+p exec --no-startup-id "notify-send 'Taking screenshot...' --urgency low -t 600; mkdir -p ~/screenshots && flatpak run --filesystem=host org.flameshot.Flameshot full -p ~/screenshots -d 2000"
bindsym Mod1+Shift+p exec --no-startup-id "notify-send 'Taking screenshot (CTRL+s to save)...' --urgency critical -t 1300; mkdir -p ~/screenshots &&  flatpak run --filesystem=host org.flameshot.Flameshot gui -p ~/screenshots -d 2000"
bindsym Mod1+o exec --no-startup-id pavucontrol
bindsym $mod+Shift+n exec --no-startup-id networkmanager_dmenu
bindsym Mod1+y exec --no-startup-id /home/pi/apps/scripts/bin/zenity-video-launcher.sh
bindsym $mod+o exec --no-startup-id "notify-send 'Deactivating the compton compositor through /home/pi/apps/scripts/bin/toggle_compositor.sh ...' --urgency low; /home/pi/apps/scripts/bin/toggle_compositor.sh"
bindsym $mod+m exec --no-startup-id "notify-send 'Configuring monitors with arandr...' --urgency low; arandr && i3-msg reload"
bindsym Mod1+k exec --no-startup-id "/home/pi/apps/scripts/rofi/toggle_keyboards.py"
bindsym $mod+s exec --no-startup-id "/home/pi/apps/scripts/rofi/snippets.sh"
bindsym $mod+c exec --no-startup-id "/home/pi/apps/scripts/bin/customize_capslock.sh"
bindsym Mod1+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/personal -C ~/.local/share/qutebrowser/personal/config/config.py"
# bindsym Mod1+Shift+b exec --no-startup-id "flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/work/dafiti -C ~/.local/share/qutebrowser/work/dafiti/config/config.py"
# /home/pi/apps/scripts/bin/i3-vim.sh &
# /home/pi/apps/scripts/bin/i3-personal-calendar.sh &
# /home/pi/apps/scripts/bin/i3-dashboard.sh &
# notify-send 'Activating keyboard backlight...' --urgency low; /home/pi/apps/scripts/bin/keyboard-backlight.sh &
# TODO: think a better way to do this: arandr && /home/pi/apps/scripts/bin/i3_change_wallpaper.sh &
# TODO: a command to see the desktop, without the windows
```
