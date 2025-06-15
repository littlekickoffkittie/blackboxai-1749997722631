#pragma once

#include <string>
#include <vector>

namespace SeirChain {
namespace Interface {
namespace Wallet {

class FractalWallet {
public:
    FractalWallet();
    ~FractalWallet();

    // Generate a new key pair
    void generateKeyPair();

    // Get public key
    std::string getPublicKey() const;

    // Sign a transaction data string
    std::string signTransaction(const std::string& transaction_data) const;

    // Verify a signed transaction
    bool verifySignature(const std::string& transaction_data, const std::string& signature) const;

private:
    std::string private_key_;
    std::string public_key_;

    // Helper functions for key management and signing
    void generateKeys();
    std::string signData(const std::string& data) const;
    bool verifyData(const std::string& data, const std::string& signature) const;
};

} // namespace Wallet
} // namespace Interface
} // namespace SeirChain
