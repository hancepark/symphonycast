#ifndef STREAMER_H
#define STREAMER_H

#include <glib-object.h>

// Define the Streaming structure
typedef struct {
    GObject parent_instance;
    // Add additional fields as necessary
} Streamer;

// Function declarations
Streamer* streamer_new(void);
void streamer_start(Streamer* self);
void streamer_stop(Streamer* self);
void streamer_free(Streamer* self);

#endif // STREAMER_H