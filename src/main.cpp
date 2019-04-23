#include <iostream>
#include <bitset>

int main()
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

    std::bitset<8> inputBitset('a');
    int inputMatrixRows = 1;
    int inputMatrixColumns = inputBitset.size();

    int inputMatrix[inputMatrixRows][inputMatrixColumns];

    for(int i = 0; i < inputMatrixRows; i++)
    {
        for(int j = 0; j < inputMatrixColumns; j++)
        {
            inputMatrix[i][j] = inputBitset.operator[](j);

            std::cout<<inputMatrix[i][j]<<std::endl;
            std::cout<<inputBitset<<std::endl;

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

    for (int i = 0; i < inputMatrixRows; i++) {
        for (int j = 0; j < inputMatrixColumns; j++) {
            std::cout<<inputMatrix[i][j]<<"  ";
        }
        std::cout<<std::endl;
    }


    return 0;
}