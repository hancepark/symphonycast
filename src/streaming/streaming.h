#ifndef STREAMING_H
#define STREAMING_H

#include <glib-object.h>

G_BEGIN_DECLS

#define STREAMING_TYPE (streaming_get_type())
G_DECLARE_FINAL_TYPE(Streaming, streaming, STREAMING, TYPE)

struct _Streaming {
    GObject parent_instance;
    // Add any necessary fields here
};

Streaming* streaming_new(void);
void streaming_start(Streaming *self);
void streaming_stop(Streaming *self);

G_END_DECLS

#endif // STREAMING_H