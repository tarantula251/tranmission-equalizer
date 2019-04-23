#ifndef TRANMISSION_EQUALIZER_ENCRYPTER_HPP
#define TRANMISSION_EQUALIZER_ENCRYPTER_HPP

#include <bitset>

class EncryptStrategy
{
public:
    void getInputData();

    std::pair<char, char> analyzeInputData(char inputByte, int errorType);
};


#endif //TRANMISSION_EQUALIZER_ENCRYPTER_HPP
