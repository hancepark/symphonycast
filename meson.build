project('symphonycast', 'c', version : '0.1.0', default_options : ['warning_level=2'])

# Dependencies
gst_dep = dependency('gstreamer-1.0')
gst_base_dep = dependency('gstreamer-base-1.0')
gobject_dep = dependency('gobject-2.0')
mdns_dep = dependency('avahi-client', required : true)

# Source files
discovery_sources = files('src/discovery/mdns_server.c')
streaming_sources = files('src/streaming/streamer.c')
common_sources = files('src/common/utils.c')
src_files = [
  'src/streaming/streamer.c',
  'src/main.c'
]
# Executable
executable('symphonycast', 
    src_files + discovery_sources + streaming_sources + common_sources,
    dependencies : [gst_dep, gst_base_dep, gobject_dep, mdns_dep]
)

# Unit tests
test('mdns_test', 'tests/discovery/mdns_test.c', dependencies : [gstreamer_dep, gobject_dep, mdns_dep])
test('streamer_test', 'tests/streaming/streamer_test.c', dependencies : [gstreamer_dep, gobject_dep, mdns_dep])