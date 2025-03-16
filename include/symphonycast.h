#ifndef SYMPHONYCAST_H
#define SYMPHONYCAST_H

#include "discovery/discovery.h"
#include "streaming/streaming.h"

// Public function declarations
void symphonycast_init(void);
void symphonycast_start(void);
void symphonycast_stop(void);
void symphonycast_cleanup(void);

#endif // SYMPHONYCAST_H