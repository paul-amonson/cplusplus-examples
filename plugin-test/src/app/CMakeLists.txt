add_executable(app App.cpp)

set_target_properties(app PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(app PUBLIC ${Boost_DIRS} plugin_sdk_lib print_message_lib)
target_link_libraries(app PUBLIC ${Boost_LIBRARIES} plugin_sdk_lib print_message_lib)
