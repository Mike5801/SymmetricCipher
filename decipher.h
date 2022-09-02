#include "matrixOperations.h"

void inverseRubiksCubeAlgorithm(vector<vector<char> > &matrix, int sizeMatrix) {
    rotateMatrixRows(matrix, 0, sizeMatrix, 3);
    rotateMatrixCol(matrix, 3, sizeMatrix, 3);
    rotateMatrixRows(matrix, 0, sizeMatrix, 1);
    rotateMatrixCol(matrix, 3, sizeMatrix, 1);
}

void inverseMoveMessageRows(vector<vector<char> > &matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        switch(i) {
            case 0:
                rotateMatrixRows(matrix, i, sizeMatrix, 3);
                break;
            case 1:
                rotateMatrixRows(matrix, i, sizeMatrix, 2);
                break;
            case 2:
                rotateMatrixRows(matrix, i, sizeMatrix, 1);
                break;
            case 3:
                rotateMatrixRows(matrix, i, sizeMatrix, 3);
                break;
            default:
                break;
        }
    }
}

void inverseMoveMessageColumns(vector<vector<char> > &matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        switch(i) {
            case 0:
                rotateMatrixCol(matrix, i, sizeMatrix, 3);
                break;
            case 1:
                rotateMatrixCol(matrix, i, sizeMatrix, 1);
                break;
            case 2:
                rotateMatrixCol(matrix, i, sizeMatrix, 3);
                break;
            case 3:
                rotateMatrixCol(matrix, i, sizeMatrix, 1);
                break;
        }
    }
}

void inverseMessageSubstitution(vector<vector<char> > &matrix, int sizeMatrix) {
    map <char, char> alphabet;
    map <char, char> alphabet2;

    alphabet['a'] = 'k';
    alphabet['b'] = 's';
    alphabet['c'] = 'x';
    alphabet['d'] = 'm';
    alphabet['e'] = 'g';
    alphabet['f'] = 'o';
    alphabet['g'] = 'z';
    alphabet['h'] = 'a';
    alphabet['i'] = 'j';
    alphabet['j'] = 'd';
    alphabet['k'] = 'e';
    alphabet['l'] = 'n';
    alphabet['m'] = 'c';
    alphabet['n'] = 'y';
    alphabet['o'] = 'p';
    alphabet['p'] = 'v';
    alphabet['q'] = 'r';
    alphabet['r'] = 'u';
    alphabet['s'] = 'b';
    alphabet['t'] = 'w';
    alphabet['u'] = 'f';
    alphabet['v'] = 'l';
    alphabet['w'] = 'h';
    alphabet['x'] = 't';
    alphabet['y'] = 'i';
    alphabet['z'] = 'q';
    //UpperCase
    alphabet['A'] = 'K';
    alphabet['B'] = 'S';
    alphabet['C'] = 'X';
    alphabet['D'] = 'M';
    alphabet['E'] = 'G';
    alphabet['F'] = 'O';
    alphabet['G'] = 'Z';
    alphabet['H'] = 'A';
    alphabet['I'] = 'J';
    alphabet['J'] = 'D';
    alphabet['K'] = 'E';
    alphabet['L'] = 'N';
    alphabet['M'] = 'C';
    alphabet['N'] = 'Y';
    alphabet['O'] = 'P';
    alphabet['P'] = 'V';
    alphabet['Q'] = 'R';
    alphabet['R'] = 'U';
    alphabet['S'] = 'B';
    alphabet['T'] = 'W';
    alphabet['U'] = 'F';
    alphabet['V'] = 'L';
    alphabet['W'] = 'H';
    alphabet['X'] = 'T';
    alphabet['Y'] = 'I';
    alphabet['Z'] = 'Q';


    alphabet2['a'] = 'q';
    alphabet2['b'] = 'z';
    alphabet2['c'] = 't';
    alphabet2['d'] = 'm';
    alphabet2['e'] = 'o';
    alphabet2['f'] = 'b';
    alphabet2['g'] = 'r';
    alphabet2['h'] = 'l';
    alphabet2['i'] = 'w';
    alphabet2['j'] = 'x';
    alphabet2['k'] = 'j';
    alphabet2['l'] = 'u';
    alphabet2['m'] = 'y';
    alphabet2['n'] = 'c';
    alphabet2['o'] = 'a';
    alphabet2['p'] = 'i';
    alphabet2['q'] = 'v';
    alphabet2['r'] = 'k';
    alphabet2['s'] = 'd';
    alphabet2['t'] = 'f';
    alphabet2['u'] = 'p';
    alphabet2['v'] = 'e';
    alphabet2['w'] = 'h';
    alphabet2['x'] = 's';
    alphabet2['y'] = 'g';
    alphabet2['z'] = 'n';
    //-----UpperCase
    alphabet2['A'] = 'Q';
    alphabet2['B'] = 'Z';
    alphabet2['C'] = 'T';
    alphabet2['D'] = 'M';
    alphabet2['E'] = 'O';
    alphabet2['F'] = 'B';
    alphabet2['G'] = 'R';
    alphabet2['H'] = 'L';
    alphabet2['I'] = 'W';
    alphabet2['J'] = 'X';
    alphabet2['K'] = 'J';
    alphabet2['L'] = 'U';
    alphabet2['M'] = 'Y';
    alphabet2['N'] = 'C';
    alphabet2['O'] = 'A';
    alphabet2['P'] = 'I';
    alphabet2['Q'] = 'V';
    alphabet2['R'] = 'K';
    alphabet2['S'] = 'D';
    alphabet2['T'] = 'F';
    alphabet2['U'] = 'P';
    alphabet2['V'] = 'E';
    alphabet2['W'] = 'H';
    alphabet2['X'] = 'S';
    alphabet2['Y'] = 'G';
    alphabet2['Z'] = 'N';

    for (int i = 0; i < sizeMatrix; i++) {
        for (int j = 0; j < sizeMatrix; j++) {
            if (j % 2 == 0) {
                for (auto k : alphabet) {
                    if (k.second == matrix[i][j]) {
                        matrix[i][j] = k.first;
                        break;
                    }
                }
            } else {
                for (auto k : alphabet2) {
                    if (k.second == matrix[i][j]) {
                        matrix[i][j] = k.first;
                        break;
                    }
                }
            }
        }
    }
}


void decipher(vector<vector<char> > &messageMatrix, vector<vector<char> > &privateKeyMatrix, int sizeMatrix) {
    bitset<8> auxBit(1);

    vector<vector<bitset<8> > > messageBinAux {
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit}
    };

    vector<vector<bitset<8> > > privateKeyBinAux {
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit}
    };

    inverseRubiksCubeAlgorithm(privateKeyMatrix, sizeMatrix);
    messageBinAux = getBinaryMatrix(messageMatrix, sizeMatrix);
    privateKeyBinAux = getBinaryMatrix(privateKeyMatrix, sizeMatrix);
    // cout << "Private key binary: " << endl;
    // printBinaryMatrix(privateKeyBinAux, sizeMatrix);
    xorBinaryMatrixes(messageBinAux, privateKeyBinAux, sizeMatrix);
    // cout << "Binary inverse XOR: " << endl;
    // printBinaryMatrix(messageBinAux, sizeMatrix);
    messageMatrix = getCharMatrix(messageBinAux, sizeMatrix);
    // cout << "Inverse XOR: " << endl;
    // printMatrix(messageMatrix, sizeMatrix);
    inverseMessageSubstitution(messageMatrix, sizeMatrix);
    // cout << "Inverse substitution: " << endl;
    // printMatrix(messageMatrix, sizeMatrix);
    inverseMoveMessageColumns(messageMatrix, sizeMatrix);
    // cout << "Inverse move columns: " << endl;
    // printMatrix(messageMatrix, sizeMatrix);
    inverseMoveMessageRows(messageMatrix, sizeMatrix);
    // cout << "Inverse move rows:" << endl;
    // printMatrix(messageMatrix, sizeMatrix);
    printMatrixAsString(messageMatrix, sizeMatrix);
}