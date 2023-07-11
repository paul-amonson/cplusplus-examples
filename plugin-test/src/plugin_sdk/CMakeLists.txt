add_library(plugin_sdk_lib PluginApi.hpp)

set_target_properties(plugin_sdk_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(plugin_sdk_lib PUBLIC ${Boost_DIRS})
target_link_libraries(plugin_sdk_lib PUBLIC ${Boost_LIBRARIES})
