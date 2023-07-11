#pragma once

#include <iostream>
#include <memory>

#include "plugin_sdk/PluginApi.hpp"
#include "error_message/ErrorMessageApi.hpp"

namespace hello_plugin {
class MyError : public plugin_sdk::PluginObject, public error_message::ErrorMessageApi {
public:
    virtual void PrintError(const char* text) override {
        std::cerr << "Error: " << text << std::endl;
    }

    // Required From plugin_sdk::PluginObject
    virtual const char* type() { return TYPE; }

    // Required by this plugin design not the SDK
    static std::shared_ptr<plugin_sdk::PluginObject> create() {
        return std::make_shared<MyError>();
    }
    static const char* TYPE;
};
const char* MyError::TYPE = "Error";
}
