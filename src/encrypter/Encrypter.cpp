#include <iostream>
#include "../../include/encrypter/Encrypter.hpp"

std::pair<char, char> EncryptStrategy::analyzeInputData(char inputByte, int errorType)
{
    int generatorMatrixRows = 8;
    int generatorMatrixColumns = 16;
    int generatorMatrix[generatorMatrixRows][generatorMatrixColumns] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
            {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    };

    std::bitset<8> inputBitset(inputByte);
    int inputMatrixRows = 1;
    int inputMatrixColumns = inputBitset.size();

    int inputMatrix[inputMatrixRows][inputMatrixColumns];

    for(int i = 0; i < inputMatrixRows; i++)
    {
        for(int j = 0; j < inputMatrixColumns; j++)
        {
            unsigned long temp = inputBitset.to_ulong();
            int value = (int) temp;
            inputMatrix[i][j] = value;
        }
    }

    int codewordMatrix[inputMatrixRows][generatorMatrixColumns];

    for(int i = 0; i < inputMatrixRows; i++)
    {
        for(int j = 0; j < generatorMatrixColumns; j++)
        {
            for(int k = 0; k < generatorMatrixRows; k++)
            {
                for(int l = 0; l < inputMatrixColumns; l++)
                {
                    codewordMatrix[i][j] += inputMatrix[i][l] * generatorMatrix[k][j];
                }
            }

        }
    }


    std::pair<char, char> result;
    result.first = 'a';
    result.second = 'b';
    return result;
}