//! Test that ProcessCommandLine works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

// Could I put the settings definition up here as it's used by eeryone, or is that not allowed?

TEST_CASE("--help input works", "input"){
    std::vector<std::string> args{"", "--help"};
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};

    REQUIRE(processCommandLine(args, settings));
    REQUIRE(settings.helpRequested);
}


TEST_CASE("--version input works", "input"){
    std::vector<std::string> args{"", "--version"};
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};

    REQUIRE(processCommandLine(args, settings));
    REQUIRE(settings.versionRequested);
}


TEST_CASE("-i input works", "input"){
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};
    
    SECTION("filename provided"){
        std::vector<std::string> args{"", "-i", "helloworld.txt"};
        REQUIRE(processCommandLine(args, settings));
        REQUIRE(!settings.inputFile.empty());
    }
    SECTION("filename not provided"){
        std::vector<std::string> args{"", "-i",};
        REQUIRE(!processCommandLine(args, settings));    
    }
}


TEST_CASE("-o input works", "input"){
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};
    
    SECTION("filename provided"){
        std::vector<std::string> args{"", "-o", "helloworld.txt"};
        REQUIRE(processCommandLine(args, settings));
        REQUIRE(!settings.outputFile.empty());
    }
    SECTION("filename not provided"){
        std::vector<std::string> args{"", "-o",};
        REQUIRE(!processCommandLine(args, settings));    
    }
}


TEST_CASE("-k input works", "input"){
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};
    
    SECTION("key provided"){
        std::vector<std::string> args{"", "-k", "1"};
        REQUIRE(processCommandLine(args, settings));
        REQUIRE(!settings.cipherKey.empty());
    }
    SECTION("key not provided"){
        std::vector<std::string> args{"", "-k",};
        REQUIRE(!processCommandLine(args, settings));    
    }
}


TEST_CASE("encryption input options works", "input"){
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};

    SECTION("--decrypt"){
        std::vector<std::string> args{"", "--decrypt"};
        REQUIRE(processCommandLine(args, settings));
        REQUIRE(settings.mode==CipherMode::Decrypt);
    }
    SECTION("--encrypt"){
        std::vector<std::string> args{"", "--encrypt"};
        REQUIRE(processCommandLine(args, settings));
        REQUIRE(settings.mode==CipherMode::Encrypt);
    }
}

TEST_CASE("invalid input doesn't work", "input"){
    // Not sure how to do this properly as can't test every possible wrong input? 
    // also if the bad input came after a -i or -o or -k it wouldn't need to be rejected?
    // very confused :(
    ProgramSettings settings{ false, false, "", "", "", CipherMode::Encrypt};
    std::vector<std::string> args{"", "xx"};
    REQUIRE(!processCommandLine(args, settings));    
}


    