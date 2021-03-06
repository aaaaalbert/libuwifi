/*
 * libuwifi - Userspace Wifi Library
 *
 * Copyright (C) 2005-2016 Bruno Randolf (br1@einfach.org)
 *
 * This source code is licensed under the GNU Lesser General Public License,
 * Version 3. See the file COPYING for more details.
 */

#ifndef _UWIFI_CONF_H_
#define _UWIFI_CONF_H_

#include "ccan/list/list.h"
#include "wlan80211.h"
#include "channel.h"
#include "platform.h"

#define IF_NAMESIZE		16

struct uwifi_interface {
	char			ifname[IF_NAMESIZE + 1];
	int			channel_time;		/* dwell time in usec */
	int			channel_max;
	bool			channel_scan;
	int			channel_scan_rounds;
	int			channel_set_num;	/* value we want to set */
	enum uwifi_chan_width	channel_set_width;	/* value we want to set */
	bool			channel_set_ht40plus;	/* value we want to set */

	/* not config but state */
	int			sock;
	struct list_head	wlan_nodes;
	uint32_t		last_nodetimeout;
	struct uwifi_channels	channels;
	int			num_channels;
	bool			channel_initialized;

	int			channel_idx;		/* index into channels array */
	enum uwifi_chan_width	channel_width;
	bool			channel_ht40plus;	/* channel is HT40+ */
	uint32_t		last_channelchange;

	int			if_phy;
	unsigned int		if_freq;
	unsigned int		max_phy_rate;
	int			if_type;
	int			arphdr;			/* the device ARP type */
};

// TODO: move? platform specific or not?

bool uwifi_init(struct uwifi_interface* intf);
void uwifi_fini(struct uwifi_interface* intf);

#endif
