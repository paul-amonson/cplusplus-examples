add_library(error_message_lib ErrorMessageApi.hpp)

set_target_properties(error_message_lib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(error_message_lib PUBLIC ${Boost_DIRS})
target_link_libraries(error_message_lib PUBLIC ${Boost_LIBRARIES})
