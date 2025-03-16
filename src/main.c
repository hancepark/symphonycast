#include <stdio.h>
#include "discovery/discovery.h"
#include "streaming/streaming.h"

int main(int argc, char *argv[]) {
    // Initialize the Discovery module
    if (discovery_init() != 0) {
        fprintf(stderr, "Failed to initialize Discovery module\n");
        return 1;
    }

    // Initialize the Streaming module
    if (streaming_init() != 0) {
        fprintf(stderr, "Failed to initialize Streaming module\n");
        discovery_cleanup();
        return 1;
    }

    // Start the main loop
    // This is where the application would typically enter its main processing loop
    // For now, we will just print a message
    printf("SymphonyCast is running...\n");

    // Cleanup before exiting
    streaming_cleanup();
    discovery_cleanup();

    return 0;
}