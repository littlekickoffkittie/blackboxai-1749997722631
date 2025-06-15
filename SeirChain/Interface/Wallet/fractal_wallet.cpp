#include "fractal_wallet.hpp"
#include "crypto_utils.hpp"
#include "../Economics/waclanium_token.hpp"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>

using SeirChain::Core::Utils::sha256;
using SeirChain::Interface::Economics::getBalance;
using SeirChain::Interface::Economics::transferTokens;

namespace SeirChain {
namespace Interface {
namespace Wallet {

// Helper function to generate a random hex string of given length
static std::string generateRandomHex(size_t length) {
    static const char hex_chars[] = "0123456789abcdef";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);
    std::stringstream ss;
    for (size_t i = 0; i < length; ++i) {
        ss << hex_chars[dis(gen)];
    }
    return ss.str();
}

FractalWallet::FractalWallet() {
    generateKeyPair();
}

FractalWallet::~FractalWallet() {
    // Cleanup if needed
}

void FractalWallet::generateKeyPair() {
    generateKeys();
}

void FractalWallet::generateKeys() {
    // Generate a random 64-character hex string as private key
    private_key_ = generateRandomHex(64);
    // Derive public key as SHA256 hash of private key (placeholder for real asymmetric key derivation)
    public_key_ = sha256(private_key_);
}

std::string FractalWallet::getPublicKey() const {
    return public_key_;
}

std::string FractalWallet::signTransaction(const std::string& transaction_data) const {
    return signData(transaction_data);
}

std::string FractalWallet::signData(const std::string& data) const {
    // Sign data by hashing data concatenated with private key
    return sha256(data + private_key_);
}

bool FractalWallet::verifySignature(const std::string& transaction_data, const std::string& signature) const {
    return verifyData(transaction_data, signature);
}

bool FractalWallet::verifyData(const std::string& data, const std::string& signature) const {
    // Verify signature by regenerating and comparing
    std::string expected_signature = sha256(data + private_key_);
    return (signature == expected_signature);
}

// Query token balance for this wallet
double FractalWallet::getTokenBalance() const {
    return getBalance(public_key_);
}

// Transfer tokens from this wallet to another account
bool FractalWallet::transferToken(const std::string& to_account, double amount) {
    return transferTokens(public_key_, to_account, amount);
}

} // namespace Wallet
} // namespace Interface
} // namespace SeirChain
