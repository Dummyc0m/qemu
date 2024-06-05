/*
 * Balloon
 *
 * Copyright IBM, Corp. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_BALLOON_H
#define QEMU_BALLOON_H

#include "exec/cpu-common.h"
#include "qapi/qapi-types-machine.h"

typedef void (QEMUBalloonEvent)(void *opaque, ram_addr_t target);
typedef void (QEMUBalloonWorkingSetRequest)(void *opaque);
typedef void (QEMUBalloonWorkingSetConfig)(void *opaque, uint32_t i0,
                                  uint32_t i1, uint32_t i2, uint32_t refresh,
                                  uint32_t report);
typedef void (QEMUBalloonStatus)(void *opaque, BalloonInfo *info);

int qemu_add_balloon_handler(QEMUBalloonEvent *event_func,
                             QEMUBalloonStatus *stat_func,
                             QEMUBalloonWorkingSetRequest *ws_func,
                             QEMUBalloonWorkingSetConfig *config_func,
                             void *opaque);
void qemu_remove_balloon_handler(void *opaque);

#endif
