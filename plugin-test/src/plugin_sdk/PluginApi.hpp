// Plugin SDK
#pragma once

#include <memory>
#include <string>
#include <boost/dll/import.hpp>

namespace plugin_sdk {

class PluginTypeNotFound : std::exception {
public:
    PluginTypeNotFound(const char* type) : msg(type) {}
    virtual const char* what() { return msg; }
private:
    const char* msg;
};

// Objects created from CreateInstance must be derived from this class.
class PluginObject {
    virtual const char* type() = 0;
};

class BOOST_SYMBOL_VISIBLE PluginFactory {
public: // Derived API
    virtual ~PluginFactory() {};
    virtual bool supportsType(const char* type) const = 0;

protected: // Derived API
    virtual std::shared_ptr<PluginObject> InternalCreateInstance(const char* type) const = 0;

public: // Base API
    bool supportsType(const std::string& type) const {
        return supportsType(type.c_str());
    };

    template<typename T> std::shared_ptr<T> CreateInstance(const std::string& type) {
         return CreateInstance<T>(type.c_str());
    }

    template<typename T> std::shared_ptr<T> CreateInstance(const char* type) {
        return std::dynamic_pointer_cast<T>(InternalCreateInstance(type));
    }
}; // class PluginFactory

std::shared_ptr<PluginFactory> LoadPlugin(const char* fullFilename) {
    typedef std::shared_ptr<PluginFactory> (Get__)();
    return boost::dll::import_alias<Get__>(fullFilename, "GetFactory")();
}
} // namespace plugins
