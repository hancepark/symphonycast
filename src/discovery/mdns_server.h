#ifndef MDNS_SERVER_H
#define MDNS_SERVER_H

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _MdnsServer MdnsServer;
typedef struct _MdnsServerClass MdnsServerClass;

#define MDNS_TYPE_SERVER (mdns_server_get_type())
G_DECLARE_FINAL_TYPE(MdnsServer, mdns_server, MDNS, SERVER)

MdnsServer* mdns_server_new(void);
void mdns_server_start(MdnsServer *server);
void mdns_server_stop(MdnsServer *server);
void mdns_server_free(MdnsServer *server);

G_END_DECLS

#endif // MDNS_SERVER_H