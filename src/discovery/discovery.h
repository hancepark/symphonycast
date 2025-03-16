#ifndef DISCOVERY_H
#define DISCOVERY_H

#include <glib-object.h>

// Function to initialize the mDNS server
void discovery_init(void);

// Function to start the mDNS server
void discovery_start(void);

// Function to stop the mDNS server
void discovery_stop(void);

// Function to cleanup resources used by the Discovery module
void discovery_cleanup(void);

#endif // DISCOVERY_H