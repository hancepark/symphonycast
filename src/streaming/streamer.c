#include <gst/gst.h>
#include <glib.h>
#include "streamer.h"

struct _SymphonyStreamer {
    GObject parent;
    GstElement *pipeline;
    GstElement *source;
    GstElement *videoconvert;
    GstElement *encoder;
    GstElement *payloader;
    GstElement *udpsink;
    gchar *host;
    gint port;
};

G_DEFINE_TYPE(SymphonyStreamer, symphony_streamer, G_TYPE_OBJECT)

static void
symphony_streamer_dispose(GObject *object)
{
    SymphonyStreamer *streamer = SYMPHONY_STREAMER(object);

    if (streamer->pipeline) {
        gst_element_set_state(streamer->pipeline, GST_STATE_NULL);
        g_clear_object(&streamer->pipeline);
    }

    G_OBJECT_CLASS(symphony_streamer_parent_class)->dispose(object);
}

static void
symphony_streamer_finalize(GObject *object)
{
    SymphonyStreamer *streamer = SYMPHONY_STREAMER(object);
    g_free(streamer->host);

    G_OBJECT_CLASS(symphony_streamer_parent_class)->finalize(object);
}

static void
symphony_streamer_class_init(SymphonyStreamerClass *klass)
{
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->dispose = symphony_streamer_dispose;
    object_class->finalize = symphony_streamer_finalize;
}

static void
symphony_streamer_init(SymphonyStreamer *self)
{
    self->host = g_strdup("127.0.0.1");
    self->port = 5000;
}

SymphonyStreamer *
symphony_streamer_new(void)
{
    return g_object_new(SYMPHONY_TYPE_STREAMER, NULL);
}

gboolean
symphony_streamer_init_pipeline(SymphonyStreamer *streamer)
{
    streamer->pipeline = gst_pipeline_new("symphony-streamer");
    streamer->source = gst_element_factory_make("videotestsrc", "source");
    streamer->videoconvert = gst_element_factory_make("videoconvert", "converter");
    streamer->encoder = gst_element_factory_make("x264enc", "encoder");
    streamer->payloader = gst_element_factory_make("rtph264pay", "payloader");
    streamer->udpsink = gst_element_factory_make("udpsink", "sink");

    if (!streamer->pipeline || !streamer->source || !streamer->videoconvert ||
        !streamer->encoder || !streamer->payloader || !streamer->udpsink) {
        g_error("Failed to create elements");
        return FALSE;
    }

    g_object_set(G_OBJECT(streamer->udpsink),
                "host", streamer->host,
                "port", streamer->port,
                NULL);

    g_object_set(G_OBJECT(streamer->encoder),
                "tune", 4,
                "speed-preset", 1,
                NULL);

    gst_bin_add_many(GST_BIN(streamer->pipeline),
                     streamer->source,
                     streamer->videoconvert,
                     streamer->encoder,
                     streamer->payloader,
                     streamer->udpsink,
                     NULL);

    if (!gst_element_link_many(streamer->source,
                              streamer->videoconvert,
                              streamer->encoder,
                              streamer->payloader,
                              streamer->udpsink,
                              NULL)) {
        g_error("Failed to link elements");
        return FALSE;
    }

    return TRUE;
}

gboolean
symphony_streamer_start(SymphonyStreamer *streamer)
{
    GstStateChangeReturn ret;
    ret = gst_element_set_state(streamer->pipeline, GST_STATE_PLAYING);
    return (ret != GST_STATE_CHANGE_FAILURE);
}

void
symphony_streamer_stop(SymphonyStreamer *streamer)
{
    gst_element_set_state(streamer->pipeline, GST_STATE_NULL);
}

void
symphony_streamer_set_host(SymphonyStreamer *streamer, const gchar *host)
{
    g_free(streamer->host);
    streamer->host = g_strdup(host);
    if (streamer->udpsink) {
        g_object_set(G_OBJECT(streamer->udpsink), "host", streamer->host, NULL);
    }
}

void
symphony_streamer_set_port(SymphonyStreamer *streamer, gint port)
{
    streamer->port = port;
    if (streamer->udpsink) {
        g_object_set(G_OBJECT(streamer->udpsink), "port", streamer->port, NULL);
    }
}ㄴ