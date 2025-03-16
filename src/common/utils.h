#ifndef UTILS_H
#define UTILS_H

#include <glib.h>

// Function to log messages
void log_message(const gchar *message);

// Function to handle errors
void handle_error(const gchar *error_message);

// Function to convert a string to a GList
GList* string_to_glist(const gchar *str, const gchar delimiter);

#endif // UTILS_H