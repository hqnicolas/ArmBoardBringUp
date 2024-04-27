// SPDX-License-Identifier: GPL-2.0+
//
// Copyright (C) 2019 Christian Hewitt <christianshewitt@gmail.com>
// Copyright (C) 2024 Matej Kseneman <matej.kseneman@gmail.com>

/*
 * Keytable for the H96 MAX v56 TV Box remote control
 */

#include <media/rc-map.h>
#include <linux/module.h>

#define RC_MAP_H96_MAX_V56 "rc-h96-max-v56"

static struct rc_map_table h96_max_v56_LUT[] = {
	{ 0x8081, KEY_POWER },

	{ 0x8083, KEY_MENU },
	{ 0x8073, KEY_HOME },

	{ 0x8038, KEY_UP },
	{ 0x8040, KEY_DOWN },
	{ 0x8037, KEY_LEFT },
	{ 0x8039, KEY_RIGHT },
	{ 0x8013, KEY_OK },

	{ 0x8027, KEY_BACK },
	
	{ 0x8089, KEY_VOLUMEDOWN },
	{ 0x8087, KEY_VOLUMEUP },

	{ 0x8048, KEY_MUTE }, // mouse
};

static struct rc_map_list h96_max_v56_map = {
	.map = {
		.scan     = h96_max_v56_LUT,
		.size     = ARRAY_SIZE(h96_max_v56_LUT),
		.rc_proto = RC_PROTO_NEC,
		.name     = RC_MAP_H96_MAX_V56,
	}
};

static int __init init_rc_map_h96_max_v56(void)
{
	return rc_map_register(&h96_max_v56_map);
}

static void __exit exit_rc_map_h96_max_v56(void)
{
	rc_map_unregister(&h96_max_v56_map);
}

module_init(init_rc_map_h96_max_v56)
module_exit(exit_rc_map_h96_max_v56)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Matej Kseneman <matej.kseneman@gmail.com>");
MODULE_DESCRIPTION("H96 MAX v56 TV Box remote controller keytable");
