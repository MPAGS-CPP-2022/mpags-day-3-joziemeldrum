#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"

struct ProgramSettings{
    bool helpRequested;
    bool versionRequested;
    std::string inputFile;
    std::string outputFile;
    std::string cipherKey;
    CipherMode mode;
};

bool processCommandLine(const std::vector<std::string>& cmdLineArgs,
                        ProgramSettings& settings);




#endif    // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP