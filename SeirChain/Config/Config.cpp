#include "Config.hpp"
#include <fstream>
#include <iostream>

NetworkParameters NetworkParameters::load(const std::string &filepath) {
    NetworkParameters params;
    try {
        auto data = toml::parse(filepath);
        params.max_nodes = toml::find_or<int>(data, "max_nodes", 100);
        params.connection_timeout = toml::find_or<int>(data, "connection_timeout", 30);
        params.topology_refresh_interval = toml::find_or<int>(data, "topology_refresh_interval", 60);
    } catch (const std::exception &e) {
        std::cerr << "Failed to load network parameters: " << e.what() << std::endl;
        throw;
    }
    return params;
}

ConsensusSettings ConsensusSettings::load(const std::string &filepath) {
    ConsensusSettings settings;
    try {
        auto data = toml::parse(filepath);
        settings.proof_of_fractal_difficulty = toml::find_or<int>(data, "proof_of_fractal_difficulty", 5);
        settings.hrc_layers = toml::find_or<int>(data, "hrc_layers", 3);
        settings.fault_tolerance_threshold = toml::find_or<double>(data, "fault_tolerance_threshold", 0.33);
    } catch (const std::exception &e) {
        std::cerr << "Failed to load consensus settings: " << e.what() << std::endl;
        throw;
    }
    return settings;
}

EconomicParameters EconomicParameters::load(const std::string &filepath) {
    EconomicParameters params;
    try {
        auto data = toml::parse(filepath);
        params.token_inflation_rate = toml::find_or<double>(data, "token_inflation_rate", 0.05);
        params.staking_cap = toml::find_or<int>(data, "staking_cap", 1000000);
        params.reward_distribution_rate = toml::find_or<double>(data, "reward_distribution_rate", 0.1);
    } catch (const std::exception &e) {
        std::cerr << "Failed to load economic parameters: " << e.what() << std::endl;
        throw;
    }
    return params;
}

std::unique_ptr<Config> Config::load(const std::string &config_dir) {
    auto config = std::make_unique<Config>();
    config->network_params = NetworkParameters::load(config_dir + "/network_parameters.toml");
    config->consensus_settings = ConsensusSettings::load(config_dir + "/consensus_settings.toml");
    config->economic_params = EconomicParameters::load(config_dir + "/economic_parameters.toml");
    return config;
}
