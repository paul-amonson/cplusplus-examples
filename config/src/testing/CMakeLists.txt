add_executable(tester App.cpp)

set_target_properties(tester PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(tester PUBLIC ${Boost_DIRS} config_sdk_lib)
target_link_libraries(tester PUBLIC ${Boost_LIBRARIES} config_sdk_lib)
