/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static unsigned int borderpx  = 2;        /* border pixel of windows */
static unsigned int snap      = 32;       /* snap pixel */
static unsigned int gappih    = 10;       /* horiz inner gap between windows */
static unsigned int gappiv    = 10;       /* vert inner gap between windows */
static unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */
static char *fonts[]          = { "Iosevka:size=12:antialias=true:autohint=true", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#ffffff";
static char selbordercolor[]        = "#3d550c";
static char selbgcolor[]            = "#013220";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;

/* The option -title below sets WM_NAME, or the window name, that is passed here so the scratchpad functionality works. */


/* const char *spcmd1[] = {"urxvt", "-hold", "-title", "vimnotes", "-e", "bash", "-c", "~/apps/scripts/bin/vim-notes.sh", NULL }; */
/* const char *spcmd2[] = {"urxvt", "-hold", "-title", "personalcalendar", "-e", "bash", "-c", "~/apps/scripts/bin/i3-personal-calendar.sh", NULL }; */
/* const char *spcmd3[] = {"urxvt", "-hold", "-title", "dropdownterm", "-e", "bash", "-c", "~/apps/scripts/bin/dropdown-term.sh", NULL }; */

const char *spcmd1[] = {"bash", "-c", "~/apps/scripts/bin/vim-notes.sh", NULL };
const char *spcmd2[] = {"bash", "-c", "~/apps/scripts/bin/i3-personal-calendar.sh", NULL };
const char *spcmd3[] = {"st", "-n", "dropdownterm", "-g", "120x34", NULL};
/* const char *spcmd4[] = {"chromium-browser", NULL }; */

static Sp scratchpads[] = {
	/* name          		cmd  */
	{"vimnotes",      		spcmd1},
	{"personalcalendar", 	     	spcmd2},
	{"dropdownterm",      		spcmd3},
	/* {"chromium",      		spcmd4}, */
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	*/
	/* class    		instance      		title       	 	tags mask    	isfloating   	isterminal  	noswallow  	monitor */
	{ "Gimp",     		NULL,       		NULL,       	    	1 << 8,       	0,           	0,         	0,        	-1 },
	{ TERMCLASS,  		NULL,       		NULL,       	    	0,            	0,           	1,         	0,        	-1 },
	{ NULL,       		NULL,       		"Event Tester",   	0,            	0,           	0,         	1,        	-1 },
	{ NULL,      		"vimnotes",    		NULL,       	    	SPTAG(0),     	1,           	1,         	1,        	-1 },
	{ NULL,      		"personalcalendar", 	NULL,       	    	SPTAG(1),     	1,           	1,         	1,        	-1 },
	{ NULL,      		"dropdownterm",    	NULL,       	    	SPTAG(2),     	1,           	1,         	1,        	-1 },
	/* { "Chromium-browser",	NULL,  		  	NULL,       	    	SPTAG(3),     	1,           	1,         	1,        	-1 }, */
	{ "Sxiv",    		NULL,    		NULL,       	    	0,     		1,           	0,         	1,        	-1 },
	{ "Arandr",    		NULL,    		NULL,       	    	0,     		1,           	0,         	1,        	-1 },
};

/* layout(s) */
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "[D]",	deck },			/* Master on left, slaves in monocle-like mode on right */
 	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	/* description: (dwm:TAGKEYS_MACRO) */ { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	/* description: (dwm:TAGKEYS_MACRO) */ { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	/* description: (dwm:TAGKEYS_MACRO) */ { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	/* description: (dwm:TAGKEYS_MACRO) */ { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \

#define STACKKEYS(MOD,ACTION) \
	/* description: (dwm:STACKKEYS_MACRO) */ { MOD,	XK_j,	ACTION##stack,	{.i = INC(+1)} }, \
	/* description: (dwm:STACKKEYS_MACRO) */ { MOD,	XK_k,	ACTION##stack,	{.i = INC(-1)} }, \
	/* description: (dwm:STACKKEYS_MACRO) */ { MOD,  	XK_v,   ACTION##stack,  {.i = 0} }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { TERMINAL, NULL };

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",		STRING,	&normbordercolor },
		{ "color8",		STRING,	&selbordercolor },
		{ "color0",		STRING,	&normbgcolor },
		{ "color4",		STRING,	&normfgcolor },
		{ "color0",		STRING,	&selfgcolor },
		{ "color4",		STRING,	&selbgcolor },
		{ "borderpx",		INTEGER, &borderpx },
		{ "snap",		INTEGER, &snap },
		{ "showbar",		INTEGER, &showbar },
		{ "topbar",		INTEGER, &topbar },
		{ "nmaster",		INTEGER, &nmaster },
		{ "resizehints",	INTEGER, &resizehints },
		{ "mfact",		FLOAT,	&mfact },
		{ "gappih",		INTEGER, &gappih },
		{ "gappiv",		INTEGER, &gappiv },
		{ "gappoh",		INTEGER, &gappoh },
		{ "gappov",		INTEGER, &gappov },
		{ "swallowfloating",	INTEGER, &swallowfloating },
		{ "smartgaps",		INTEGER, &smartgaps },
};

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
	/* description: (dwm:STACKKEYS_MACRO_VALUES) */ STACKKEYS(MODKEY,                          focus)
	/* description: (dwm:STACKKEYS_MACRO_VALUES) */ STACKKEYS(MODKEY|ShiftMask,                push)

	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_1,		0)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_2,		1)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_3,		2)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_4,		3)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_5,		4)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_6,		5)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_7,		6)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_8,		7)
	/* description: (dwm:TAGKEYS_MACRO_VALUES) */ TAGKEYS(XK_9,		8)

								/* modifier                     key        		function        argument */

	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_0,			tag,		{.ui = ~0 } },
	/* description: (dwm) */ 				{ MODKEY,			XK_BackSpace,		killclient,	{0} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_a,			defaultgaps,	{0} },
	/* description: (dwm) */ 				{ MODKEY,			XK_space,		zoom,		{0} },

	/* description: (dwm) */ 				{ MODKEY,			XK_h,			setmfact,	{.f = -0.05} },
	/* description: (dwm) */ 				{ MODKEY,			XK_l,			setmfact,      	{.f = +0.05} },

	/* description: (dwm) */ 				{ MODKEY,			XK_o,			incnmaster,     {.i = +1} },
	/* description: (dwm) */  				{ MODKEY|ShiftMask,		XK_o,			incnmaster,     {.i = -1} },

	/* description: (dwm) */  				{ MODKEY,			XK_Right,		focusmon,	{.i = +1} },
	/* description: (dwm) */ 				{ MODKEY,			XK_Left,		focusmon,	{.i = -1} },

	/* description: (dwm) */ 				{ MODKEY,			XK_p,			incrgaps,	{.i = +3} },
	/* description: (dwm) */ 				{ MODKEY,			XK_x,			incrgaps,	{.i = -3} },

	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_Left,		tagmon,		{.i = -1} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_Right,		tagmon,		{.i = +1} },

	/* description: (dwm) */ 				{ MODKEY,			XK_0,			view,		{.ui = ~0} },
	/* description: (dwm) */ 				{ MODKEY,			XK_backslash,		view,		{0} },
	/* description: (dwm) */ 				{ MODKEY,			XK_Tab,			view,		{0} },

	/* description: (dwm) */ 				{ MODKEY,			XK_Page_Up,		shiftview,	{.i = -1} },
	/* description: (dwm) */ 				{ MODKEY,			XK_Page_Down,		shiftview,	{.i = +1} },
	/* description: (dwm) */ 				{ MODKEY,			XK_g,			shiftview,	{.i = -1} },
	/* description: (dwm) */ 				{ MODKEY,			XK_semicolon,		shiftview,	{.i = 1} },

	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_Page_Down,		shifttag,	{.i = +1} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_Page_Up,		shifttag,	{.i = -1} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_semicolon,		shifttag,	{.i = 1} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_g,			shifttag,	{.i = -1} },

	/* description: (dwm) */ 				{ MODKEY,			XK_a,			togglegaps,	{0} },
	/* description: (dwm) */ 				{ MODKEY,			XK_s,			togglesticky,	{0} },
	/* description: (dwm) */ 				{ MODKEY,			XK_f,			togglefullscr,	{0} },
	/* description: (dwm:scratchpad) vimnotes */ 		{ MODKEY,			XK_n,			togglescratch,	{.ui = 0} },
	/* description: (dwm:scratchpad) personalcalendar */ 	{ Mod1Mask,			XK_l,			togglescratch,	{.ui = 1} },
	/* description: (dwm:scratchpad) dropdownterm */ 	{ Mod1Mask,			XK_t,			togglescratch,	{.ui = 2} },
	/* description: (dwm:scratchpad) chromium 		{ Mod1Mask,			XK_a,			togglescratch,	{.ui = 3} }, */
	/* description: (dwm) */ 				{ MODKEY,			XK_b,			togglebar,	{0} },
	/* description: (dwm) */ 				{ MODKEY|ShiftMask,		XK_space,		togglefloating,	{0} },

	/* description: (dwm:layouts) bstack */ 		{ MODKEY|ShiftMask,		XK_t,			setlayout,	{.v = &layouts[1]} },
	/* description: (dwm:layouts) tile */ 			{ MODKEY,			XK_t,			setlayout,	{.v = &layouts[0]} },
	/* description: (dwm:layouts) spiral */ 		{ MODKEY,			XK_y,			setlayout,	{.v = &layouts[2]} },
	/* description: (dwm:layouts) dwindle */ 		{ MODKEY|ShiftMask,		XK_y,			setlayout,	{.v = &layouts[3]} },
	/* description: (dwm:layouts) deck */ 			{ MODKEY,			XK_u,			setlayout,	{.v = &layouts[4]} },
	/* description: (dwm:layouts) monocle */ 		{ MODKEY|ShiftMask,		XK_u,			setlayout,	{.v = &layouts[5]} },
	/* description: (dwm:layouts) centeredmaster */ 	{ MODKEY,			XK_i,			setlayout,	{.v = &layouts[6]} },
	/* description: (dwm:layouts) centeredfloatingmaster */ { MODKEY|ShiftMask,		XK_i,			setlayout,	{.v = &layouts[7]} },
	/* description: (dwm:layouts) floating */ 		{ MODKEY|ShiftMask,		XK_f,			setlayout,	{.v = &layouts[8]} },

	/* description: (cmd) */ 				{ MODKEY,			XK_e,			spawn,          SHCMD("rofi -show drun -drun-icon-theme") },
	/* description: (cmd) */ 				{ MODKEY|ShiftMask,		XK_e,			spawn,          SHCMD("dmenu_run") },
	/* description: (cmd) */ 				{ MODKEY, 			XK_z,			spawn,          SHCMD("~/apps/scripts/rofi/shutdown.py") },
	/* description: (cmd) */ 				{ MODKEY, 			XK_c,			spawn,          SHCMD("clippy_rofi.py") },
	/* description: (cmd) */ 				{ MODKEY,			XK_Return,		spawn,		{.v = termcmd} },
	/* description: (cmd) */ 				{ MODKEY, 			XK_d,			spawn,          SHCMD("~/apps/scripts/rofi/dwm_cheatsheet.sh") },
	/* description: (cmd) */ 				{ MODKEY|ShiftMask,		XK_Return,		spawn,          SHCMD("st -e bash -c 'TERM=screen-256color ~/apps/scripts/bin/start_random_tmux_session_name.sh'") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_Tab,			spawn,          SHCMD("rofi -show window -drun-icon-theme") },
	/* description: (cmd) */ 				{ MODKEY|ShiftMask,		XK_d,			spawn,          SHCMD("notify-send -u critical 'Restarting dwm...' && pkill -HUP dwm") },
	/* description: (cmd) increase screen brightness */ 	{ Mod1Mask|ShiftMask,		XK_Up,			spawn,          SHCMD("xbacklight -inc 20") },
	/* description: (cmd) decrease screen brightness */	{ Mod1Mask|ShiftMask,		XK_Down,		spawn,          SHCMD("xbacklight -dec 20") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_space,		spawn,          SHCMD("playerctl play-pause && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_Right,		spawn,          SHCMD("playerctl next && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_Left,		spawn,          SHCMD("playerctl previous && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) increase sound volume */		{ Mod1Mask,			XK_Up,			spawn,          SHCMD("pactl set-sink-volume 0 +5% && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) decrease sound volume */		{ Mod1Mask,			XK_Down,		spawn,          SHCMD("pactl set-sink-volume 0 -5% && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) mute/unmute sound */ 		{ Mod1Mask,			XK_Shift_L,		spawn,          SHCMD("pactl set-sink-mute 0 toggle && kill -44 $(pidof dwmblocks)") },
	/* description: (cmd) */ 				{ MODKEY|ShiftMask,		XK_v,			spawn,          SHCMD("~/apps/scripts/rofi/vim_shortcuts.py") },
	/* description: (cmd) */ 				{ MODKEY|ShiftMask, 		XK_b,			spawn,          SHCMD("~/apps/scripts/rofi/bookmarks.py") },
	/* description: (cmd) wallpaper (m to mark) */   	{ Mod1Mask, 			XK_w,			spawn,          SHCMD("sxiv -r -q -o $(ls -t --color=never ~/Wallpapers/*) | xargs feh --bg-scale") },
	/* description: (cmd) */ 				{ Mod1Mask, 			XK_s,			spawn,          SHCMD("~/apps/scripts/rofi/snippets.sh") },
	/* description: (cmd) */ 				{ Mod1Mask, 			XK_o,			spawn,          SHCMD("~/apps/scripts/bin/toggle_compositor.sh") },
	/* description: (cmd) */ 				{ MODKEY, 			XK_m,			spawn,          SHCMD("arandr && reload_wallpaper.sh") },
	/* description: (cmd) file manager - nnn */		{ MODKEY, 	 		XK_r,			spawn,          SHCMD("urxvt -name nnn --hold -e nnn") },
	/* description: (cmd) file manager - pcmanfm */		{ MODKEY|ShiftMask,		XK_r,			spawn,          SHCMD("pcmanfm") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_h,			spawn,		SHCMD("urxvt -name nnn --hold -e htop") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_r,			spawn,		SHCMD("lxappearance") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_c,			spawn,		SHCMD("~/apps/scripts/bin/customize_capslock.sh") },
	/* description: (cmd) echo keys typed on screen */	{ Mod1Mask,			XK_n,			spawn,		SHCMD("killall screenkey || screenkey &") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_v,			spawn,		SHCMD("pavucontrol") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_k,			spawn,		SHCMD("~/apps/scripts/rofi/toggle_keyboards.py") },
	/* description: (cmd) */ 				{ Mod1Mask|ShiftMask,		XK_k,			spawn,		SHCMD("~/apps/scripts/bin/keyboard-backlight.sh") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_p,			spawn,		SHCMD("notify-send 'Taking screenshot...' --urgency low -t 600; mkdir -p ~/screenshots && flameshot full -p ~/screenshots -d 2000") },
	/* description: (cmd) */ 				{ Mod1Mask|ShiftMask,		XK_p,			spawn,		SHCMD("notify-send 'Taking screenshot (CTRL+s to save)...' --urgency critical -t 1300; mkdir -p ~/screenshots &&  flameshot gui -p ~/screenshots -d 2000") },
	/* description: (cmd) */ 				{ Mod1Mask,			XK_b,			spawn,		SHCMD("flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/personal -C ~/.local/share/qutebrowser/personal/config/config.py") },
	/* description: (cmd) */ 				{ Mod1Mask|ShiftMask,		XK_b,			spawn,		SHCMD("flatpak run --filesystem=host org.qutebrowser.qutebrowser -B ~/.local/share/qutebrowser/work/dafiti -C ~/.local/share/qutebrowser/work/dafiti/config/config.py") },

	/* OTHER EXAMPLES */

	/* urxvt -name vim --hold -e bash -c "TERM=screen-256color $TMUXP_BIN load /storage/src/devops/tmuxp/notes.yml"; */

	/* { MODKEY,			XK_e,			spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks; rmdir ~/.abook") }, */
	/* { 0,				XK_Print,		spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") }, */
	/* { MODKEY|ShiftMask,		XK_n,			spawn,		SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+6 dwmblocks") }, */
	/* { MODKEY,			XK_Insert,		spawn,		SHCMD("xdotool type $(cat ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e vim /storage/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },
};
