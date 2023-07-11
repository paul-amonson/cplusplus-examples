#include <locale>
#include <algorithm>

#include "ConfigFactory.hpp"

namespace config_sdk {

///////////// Common Implementation ////////////////
    const std::string& get_(const std::unordered_map<std::string, std::string>& ref, const char* key) {
        if(ref.find(key) == ref.end())
            throw new ConfigKeyNotFound();
        return ref.at(key);
    }

    int getInt_(const std::unordered_map<std::string, std::string>& ref, const char* key) {
        return std::atoi(get_(ref, key).c_str());
    }

    long getLong_(const std::unordered_map<std::string, std::string>& ref, const char* key) {
        return std::atol(get_(ref, key).c_str());
    }
    
    int getDouble_(const std::unordered_map<std::string, std::string>& ref, const char* key) {
        return std::stod(get_(ref, key).c_str());
    }

    std::unordered_map<std::string,bool> boolNames_({
        {"1",     true },
        {"true",  true },
        {"yes",   true },
        {"on",    true }
    });

    bool getBool_(const std::unordered_map<std::string, std::string>& ref, const char* key) {
        std::string value = get_(ref, key);
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        if(boolNames_.find(value) == boolNames_.end()) return false;
        return boolNames_.at(value);
    }

///////////// Config View ////////////////
    class ConfigViewImpl : public ConfigView {
    public:
        ConfigViewImpl(const std::unordered_map<std::string, std::string>& ref)
            : reference_(ref) { }

        virtual const std::string& get(const char* key) const {
            return get_(reference_, key);
        }

        virtual int getInt(const char* key) const {
            return getInt_(reference_, key);
        }

        virtual long getLong(const char* key) const {
            return getLong_(reference_, key);
        }

        virtual int getDouble(const char* key) const{
            return getDouble_(reference_, key);
        }

        virtual bool getBool(const char* key) const{
            return getBool_(reference_, key);
        }

    private:
        const std::unordered_map<std::string, std::string>& reference_;
    };

///////////// Config ////////////////
    class ConfigImpl : public Config {
    public:
        ConfigImpl(std::unordered_map<std::string, std::string>& ref)
        : copy_(ref) { }

        virtual const std::string& get(const char* key) const {
            return get_(copy_, key);
        }
        virtual int getInt(const char* key) const {
            return getInt_(copy_, key);
        }

        virtual long getLong(const char* key) const {
            return getLong_(copy_, key);
        }

        virtual int getDouble(const char* key) const {
            return getDouble_(copy_, key);
        }

        virtual bool getBool(const char* key) const {
            return getBool_(copy_, key);
        }

        virtual void set(const char* key, const char* value) {
            copy_[key] = value;
        }

        virtual void setInt(const char* key, int value) {
            set(key, std::to_string(value).c_str());
        }

        virtual void setLong(const char* key, long value) {
            set(key, std::to_string(value).c_str());
        }

        virtual void setDouble(const char* key, double value) {
            set(key, std::to_string(value).c_str());
        }

        virtual void setBool(const char* key, bool value) {
            set(key, value?"true":"false");
        }

    private:
        std::unordered_map<std::string, std::string> copy_;
    };

///////////// Global ////////////////
    namespace factory {
        bool initialized_ = false;
        std::unordered_map<std::string, std::string> storage_;
        const void initialize(
            std::unordered_map<std::string, std::string>& properties)
        {
            if(initialized_) throw new ConfigAlreadyInitialized();
            storage_.merge(properties);
            initialized_ = true;
        }

        std::shared_ptr<ConfigView> getConfigView() {
            return std::reinterpret_pointer_cast<ConfigView>(std::make_shared<ConfigViewImpl>(storage_));
        }

        std::shared_ptr<Config> getConfigCopy() {
            return std::reinterpret_pointer_cast<Config>(std::make_shared<ConfigImpl>(storage_));
        }
    }
}
