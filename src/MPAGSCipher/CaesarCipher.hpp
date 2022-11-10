#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <cctype>
#include <string>
#include "CipherMode.hpp"

class CaesarCipher{
    public:
        explicit CaesarCipher(std::size_t key);
        explicit CaesarCipher(std::string key);

        std::string applyCipher(const std::string& inputText, const CipherMode mode);

    private:
        std::size_t key_;

};


#endif    // MPAGSCIPHER_CAESARCIPHER_HPP