//! Test that CaeserCipher works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"


TEST_CASE("bad key inputs results in 0 shift", "[input]"){
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // Only need to test one mode as the same key used for both, and set before we get to 
    // using the cryption mode?
    CipherMode test_encryption{CipherMode::Encrypt};

    SECTION("string input to key"){
        CaesarCipher cipher{"x"};
        REQUIRE(cipher.applyCipher(alphabet, test_encryption ) == alphabet);
    }
    // Not sure if this one is needed as the "." would be treated the same as "x" by the constructor?
    SECTION("float input results in key of 0"){
        CaesarCipher cipher{"1.0"};
        REQUIRE(cipher.applyCipher(alphabet, test_encryption) == alphabet);
    }
}

TEST_CASE("integer key between 0 and 26 shifts correctly", "[encryption]"){
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    CaesarCipher cipher{1};

    SECTION("test encryption"){
        CipherMode test_encryption{CipherMode::Encrypt};
        std::string alphabet_shifted{"BCDEFGHIJKLMNOPQRSTUVWXYZA"};
        REQUIRE(cipher.applyCipher(alphabet, test_encryption) == alphabet_shifted);
    }
    SECTION("test decryption"){
        CipherMode test_decryption{CipherMode::Decrypt};
        std::string alphabet_shifted{"ZABCDEFGHIJKLMNOPQRSTUVWXY"};
        REQUIRE(cipher.applyCipher(alphabet, test_decryption) == alphabet_shifted);
    }
}

TEST_CASE("key > 25 wraps around", "[encryption]"){
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    // again only need to test one mode? we established above both modes are working with the correct key
    // so all we are doing now is checking a key > 25 turns into one < 26?
    CipherMode test_encryption{CipherMode::Encrypt};
    CaesarCipher cipher{26};
    REQUIRE(cipher.applyCipher(alphabet, test_encryption) == alphabet);
}