#ifndef TYPES_H
#define TYPES_H

#include <glib.h>

// Define common types used across the project
typedef struct {
    gchar *name;
    gchar *type;
    gchar *domain;
} ServiceInfo;

typedef struct {
    gchar *host;
    guint16 port;
} StreamInfo;

#endif // TYPES_H