Sure, here's the contents for the file `/symphonycast/symphonycast/tests/discovery/mdns_test.c`:

#include <gst/gst.h>
#include <gst/check/gstcheck.h>
#include "mdns_server.h"

GST_CHECK_INIT();

static void test_mdns_server_initialization(void) {
    MdnsServer *server = mdns_server_new();
    g_assert_nonnull(server);
    g_assert_true(mdns_server_start(server));
    mdns_server_free(server);
}

static void test_mdns_service_advertisement(void) {
    MdnsServer *server = mdns_server_new();
    g_assert_nonnull(server);
    g_assert_true(mdns_server_start(server));

    g_assert_true(mdns_server_advertise_service(server, "TestService", 1234, "TestProtocol"));

    // Additional checks can be added here to verify service advertisement

    mdns_server_free(server);
}

int main(int argc, char *argv[]) {
    gst_init(&argc, &argv);
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/mdns/server_initialization", test_mdns_server_initialization);
    g_test_add_func("/mdns/service_advertisement", test_mdns_service_advertisement);

    return g_test_run();
}