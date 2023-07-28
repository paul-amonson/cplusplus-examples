release:
	mkdir -p _build
	cmake -S . -B _build
	make -C _build

debug:
	mkdir -p _build
	cmake -S . -B _build
	make -C _build

all:	release

clean:
	rm -rf _build installed

install:	release
	mkdir -p installed/lib installed/bin installed/include/plugin_sdk installed/include/config_sdk
	cp _build/config/src/config_sdk/libconfig_sdk_lib.a installed/lib/
	cp _build/plugin-test/src/plugin_sdk/libplugin_sdk_lib.a installed/lib/
	cp _build/config/src/testing/tester installed/bin/
	cp _build/plugin-test/src/app/app installed/bin/
	cp _build/plugin-test/src/hello_world_plugin/hello-plugin.plugin installed/bin/
	cp config/src/config_sdk/ConfigFactory.hpp installed/include/config_sdk/
	cp plugin-test/src/plugin_sdk/PluginApi.hpp installed/include/plugin_sdk/
