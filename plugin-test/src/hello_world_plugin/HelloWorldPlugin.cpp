#include <memory>
#include <map>
#include <boost/dll/alias.hpp>

#include "plugin_sdk/PluginApi.hpp"
#include "print_message/PrintMessageApi.hpp"

#include "MyPrint.hpp"
#include "MyError.hpp"

using namespace plugin_sdk;

namespace hello_plugin {

// This plugins object create function pointer type
typedef std::shared_ptr<PluginObject> (*createFunction)();

#define PLUGIN_REG(x) {x::TYPE,&x::create}

// This plugins implementation of PluginFactory
class HelloWorldPlugin : public PluginFactory {
public:
    virtual bool supportsType(const char* type) const override {
        return pluginSupportedTypes_.find(type) != pluginSupportedTypes_.end();
    }

protected:
    virtual std::shared_ptr<PluginObject> InternalCreateInstance(const char* type) const {
        if(supportsType(type))
            return (pluginSupportedTypes_.at(type))();
        throw new PluginTypeNotFound(type);
    }

public: // entry point
    static std::shared_ptr<PluginFactory> GetPlugin() {
        if(!singleton_)
            singleton_ = std::make_shared<HelloWorldPlugin>();
        return singleton_;
    }

private:
    static std::unordered_map<std::string, createFunction> pluginSupportedTypes_;
    static std::shared_ptr<HelloWorldPlugin> singleton_;
}; // class HelloWorldPlugin
std::shared_ptr<HelloWorldPlugin> HelloWorldPlugin::singleton_;

// Add more object type names and constructor functions to create here.
std::unordered_map<std::string, createFunction> HelloWorldPlugin::pluginSupportedTypes_ {
    PLUGIN_REG(MyPrint),
    PLUGIN_REG(MyError)
};
} // namespace hello_plugin

BOOST_DLL_ALIAS(hello_plugin::HelloWorldPlugin::GetPlugin, GetFactory)
