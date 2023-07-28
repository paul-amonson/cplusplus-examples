#include <iostream>
#include <string>

#include "plugin_sdk/PluginApi.hpp"
#include "print_message/PrintMessageApi.hpp"
#include "error_message/ErrorMessageApi.hpp"

int main() {
    auto factory = plugin_sdk::LoadPlugin("./_build/plugin_test/src/hello_world_plugin/hello-plugin.plugin");
    auto printer = factory->CreateInstance<print_message::PrintMessageApi>("Print");
    printer->Print("This is my text message!");
    auto error = factory->CreateInstance<error_message::ErrorMessageApi>("Error");
    error->PrintError("This is my error message!");
    return 0;
}
