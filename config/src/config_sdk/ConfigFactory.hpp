#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <exception>

namespace config_sdk {

    class ConfigAlreadyInitialized : std::exception {};
    class ConfigNotInitialized : std::exception {};
    class ConfigKeyNotFound : std::exception {};

    class ConfigView {
    public:
        virtual const std::string& get(const char* key) const = 0;
        virtual int getInt(const char* key) const  = 0;
        virtual long getLong(const char* key) const = 0;
        virtual int getDouble(const char* key) const = 0;
        virtual bool getBool(const char* key) const = 0;

    protected:
        ConfigView() {};
    };

    class Config {
    public:
        virtual const std::string& get(const char* key) const = 0;
        virtual int getInt(const char* key) const  = 0;
        virtual long getLong(const char* key) const = 0;
        virtual int getDouble(const char* key) const = 0;
        virtual bool getBool(const char* key) const = 0;

        virtual void set(const char* key, const char* value) = 0;
        virtual void setInt(const char* key, int value) = 0;
        virtual void setLong(const char* key, long value) = 0;
        virtual void setDouble(const char* key, double value) = 0;
        virtual void setBool(const char* key, bool value) = 0;

    protected:
        Config() {};
    };
    namespace factory {
        const void initialize(std::unordered_map<std::string, std::string>& properties);
        std::shared_ptr<ConfigView> getConfigView();
        std::shared_ptr<Config> getConfigCopy();
    }
}
