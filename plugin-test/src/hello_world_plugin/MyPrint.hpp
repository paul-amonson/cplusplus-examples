#pragma once

#include <iostream>
#include <memory>

#include "plugin_sdk/PluginApi.hpp"
#include "print_message/PrintMessageApi.hpp"

namespace hello_plugin {
class MyPrint : public plugin_sdk::PluginObject, public print_message::PrintMessageApi {
public:
    virtual void Print(const char* text) override {
        std::cout << text << std::endl;
    }

    // Required From plugin_sdk::PluginObject
    virtual const char* type() { return TYPE; }

    // Required by this plugin design not the SDK
    static std::shared_ptr<plugin_sdk::PluginObject> create() {
        return std::make_shared<MyPrint>();
    }

    static const char* TYPE;
};
const char* MyPrint::TYPE = "Print";
}
