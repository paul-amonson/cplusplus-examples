INSTALL_PREFIX := "./installed"

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
	rm -rf _build

install:	release
	mkdir -p ${INSTALL_PREFIX}/lib ${INSTALL_PREFIX}/bin ${INSTALL_PREFIX}/include/plugin_sdk ${INSTALL_PREFIX}/include/config_sdk
	cp _build/config/src/config_sdk/libconfig_sdk_lib.a ${INSTALL_PREFIX}/lib/
	cp _build/plugin-test/src/plugin_sdk/libplugin_sdk_lib.a ${INSTALL_PREFIX}/lib/
	cp _build/config/src/testing/tester ${INSTALL_PREFIX}/bin/
	cp _build/plugin-test/src/app/app ${INSTALL_PREFIX}/bin/
	cp _build/plugin-test/src/hello_world_plugin/hello-plugin.plugin ${INSTALL_PREFIX}/bin/
	cp config/src/config_sdk/ConfigFactory.hpp ${INSTALL_PREFIX}/include/config_sdk/
	cp plugin-test/src/plugin_sdk/PluginApi.hpp ${INSTALL_PREFIX}/include/plugin_sdk/
