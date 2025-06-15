// waclanium_token.cpp
// Implements the Waclanium token economics for SeirChain.
// Provides functions for token issuance, transfer, and balance management.

#include "waclanium_token.hpp"
#include <string>
#include <unordered_map>

namespace SeirChain {
namespace Interface {
namespace Economics {

std::unordered_map<std::string, double> balances;

// Issue tokens to an account
void issueTokens(const std::string& account, double amount) {
    balances[account] += amount;
}

// Transfer tokens between accounts
bool transferTokens(const std::string& from, const std::string& to, double amount) {
    if (balances[from] < amount) {
        return false;
    }
    balances[from] -= amount;
    balances[to] += amount;
    return true;
}

// Get balance of an account
double getBalance(const std::string& account) {
    return balances[account];
}

} // namespace Economics
} // namespace Interface
} // namespace SeirChain
