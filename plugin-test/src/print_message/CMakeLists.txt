add_library(print_message_lib PrintMessageApi.hpp)

set_target_properties(print_message_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(print_message_lib PUBLIC ${Boost_DIRS})
target_link_libraries(print_message_lib PUBLIC ${Boost_LIBRARIES})
