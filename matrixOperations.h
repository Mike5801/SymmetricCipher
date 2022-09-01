#ifndef matrixOperations
#define matrixOperations

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

void printMatrixAsString(vector<vector<char> > matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            cout << matrix[i][j];
        }
    }
    cout << endl;
}

void printMatrix(vector<vector<char> > matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void printBinaryMatrix(vector<vector<bitset<8> > > matrix, int sizeMatrix) {
        for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void insertStringToMatrix(vector<vector<char> > &matrix, int sizeMatrix, string s) {
    int limitMatrixRows = 0;
    int limitMatrixColumns = 0;
     if (s.length() < 16) {
        while (s.length() < 16) {
            s += "_";
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if ((i + 1) % 4 == 0) {
            matrix[limitMatrixRows][limitMatrixColumns] = s[i];
            limitMatrixRows++;
            limitMatrixColumns = 0;
        } else {
            matrix[limitMatrixRows][limitMatrixColumns] = s[i];
            limitMatrixColumns++;
        }
    }
}

void rotateMatrixRows(vector<vector<char> > &matrix, int rowRotating, int sizeMatrix, int numRotations) {
    vector<char> auxRow;

    for (int i = 0; i < sizeMatrix; i++) {
        auxRow.push_back(matrix[rowRotating][i]);
    }

    for (int i = 0; i < numRotations; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            if (j == sizeMatrix - 1) {
                matrix[rowRotating][0] = auxRow[j]; 
            } else {
                matrix[rowRotating][j + 1] = auxRow[j];
            }
        }
        for (int j = 0; j < sizeMatrix; j++) {
            auxRow[j] = matrix[rowRotating][j];
        }
    }
}

void rotateMatrixCol(vector<vector<char> > &matrix, int colRotating, int sizeMatrix, int numRotations) {
    vector<char> auxCol;

    for (int i = 0; i < sizeMatrix; i++) {
        auxCol.push_back(matrix[i][colRotating]);
    }

    for (int i = 0; i < numRotations; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            if (j == sizeMatrix - 1) {
                matrix[0][colRotating] = auxCol[j]; 
            } else {
                matrix[j + 1][colRotating] = auxCol[j];
            }
        }
        for (int j = 0; j < sizeMatrix; j++) {
            auxCol[j] = matrix[j][colRotating];
        }
    }
}

vector<vector<bitset<8> > > getBinaryMatrix(vector<vector<char> > matrix, int sizeMatrix) {
    bitset<8> auxBit(1); 
    vector<vector<bitset<8> > > matrixBitset {
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit} 
    };
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            bitset<8> bits = matrix[i][j];
            matrixBitset[i][j] = bits;
        }
    }
    return matrixBitset;
}

vector<vector<char> > getCharMatrix(vector<vector<bitset<8> > > matrix, int sizeMatrix) {
    vector<vector<char> > matrixChar {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            matrixChar[i][j] = static_cast<char>(std::bitset<8>(matrix[i][j].to_string()).to_ulong());;
        }
    }
    return matrixChar; 
}

void xorBinaryMatrixes(vector<vector<bitset<8> > > &messageMatrix, vector<vector<bitset<8> > >  privateKeyMatrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            bitset<8> auxbit = messageMatrix[i][j] ^ privateKeyMatrix[i][j];
            messageMatrix[i][j] = auxbit;
        }
    }
}

string charMatrixToString(vector<vector<char> > matrix, int sizeMatrix) {
    string result = "";
    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            result += matrix[i][j];
        }
    }
    return result;
}

#endif