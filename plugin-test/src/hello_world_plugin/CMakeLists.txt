set(CMAKE_SHARED_LIBRARY_SUFFIX ".plugin")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_library(hello-plugin SHARED HelloWorldPlugin.cpp MyPrint.hpp)

set_target_properties(hello-plugin PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(hello-plugin PUBLIC ${Boost_DIRS} plugin_sdk_lib print_message_lib)
target_link_libraries(hello-plugin PUBLIC ${Boost_LIBRARIES} plugin_sdk_lib print_message_lib)
