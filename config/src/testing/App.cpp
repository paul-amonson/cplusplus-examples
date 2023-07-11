#include "config_sdk/ConfigFactory.hpp"
#include <iostream>

int main() {
    const char* key = "test1";
    std::unordered_map<std::string, std::string> myConfig({
        {key, "OFF"}
    });
    config_sdk::factory::initialize(myConfig);
    auto view = config_sdk::factory::getConfigView();
    auto config = config_sdk::factory::getConfigCopy();

    std::cout << "Original Value: " << key << " = '" << view->get(key) << "'" << std::endl;
    std::cout << "Copy Value: " << key << " = '" << config->get(key) << "'" << std::endl;
    config->set(key, "42");
    std::cout << "Changed Value: " << key << " = '" << config->get(key) << "'" << std::endl;
    std::cout << "Checking Original Value: " << key << " = '" << view->get(key) << "'" << std::endl;
}
