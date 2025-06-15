#ifndef SEIRCHAIN_CONFIG_HPP
#define SEIRCHAIN_CONFIG_HPP

#include <string>
#include <memory>
#include <toml.hpp>  // Assuming toml11 library is used

// Network Parameters Configuration
class NetworkParameters {
public:
    int max_nodes;
    int connection_timeout;
    int topology_refresh_interval;

    static NetworkParameters load(const std::string &filepath);
};

// Consensus Settings Configuration
class ConsensusSettings {
public:
    int proof_of_fractal_difficulty;
    int hrc_layers;
    double fault_tolerance_threshold;

    static ConsensusSettings load(const std::string &filepath);
};

// Economic Parameters Configuration
class EconomicParameters {
public:
    double token_inflation_rate;
    int staking_cap;
    double reward_distribution_rate;

    static EconomicParameters load(const std::string &filepath);
};

// Main Config class aggregating all configurations
class Config {
public:
    NetworkParameters network_params;
    ConsensusSettings consensus_settings;
    EconomicParameters economic_params;

    static std::unique_ptr<Config> load(const std::string &config_dir);
};

#endif // SEIRCHAIN_CONFIG_HPP
