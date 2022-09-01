/* Integrantes
Halim Abraham Hamanoiel Galindo
Alejandro Ruíz García Rojas
Miguel Weiping Tang Feng
*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bitset>

using namespace std;


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
            s += "!";
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

void rubiksCubeAlgorithm(vector<vector<char> > &matrix, int sizeMatrix) {
    rotateMatrixCol(matrix, 3, sizeMatrix, 3);
    rotateMatrixRows(matrix, 0, sizeMatrix, 3);
    rotateMatrixCol(matrix, 3, sizeMatrix, 1);
    rotateMatrixRows(matrix, 0, sizeMatrix, 1);
}

void inverseRubiksCubeAlgorithm(vector<vector<char> > &matrix, int sizeMatrix) {
    rotateMatrixRows(matrix, 0, sizeMatrix, 3);
    rotateMatrixCol(matrix, 3, sizeMatrix, 3);
    rotateMatrixRows(matrix, 0, sizeMatrix, 1);
    rotateMatrixCol(matrix, 3, sizeMatrix, 1);
}

void moveMessageRows(vector<vector<char> > &matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        switch(i) {
            case 0:
                rotateMatrixRows(matrix, i, sizeMatrix, 1);
                break;
            case 1:
                rotateMatrixRows(matrix, i, sizeMatrix, 2);
                break;
            case 2:
                rotateMatrixRows(matrix, i, sizeMatrix, 3);
                break;
            case 3:
                rotateMatrixRows(matrix, i, sizeMatrix, 1);
                break;
            default:
                break;
        }
    }
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

void moveMessageColumns(vector<vector<char> > &matrix, int sizeMatrix) {
    for (int i = 0; i < sizeMatrix; i++) {
        switch(i) {
            case 0:
                rotateMatrixCol(matrix, i, sizeMatrix, 1);
                break;
            case 1:
                rotateMatrixCol(matrix, i, sizeMatrix, 3);
                break;
            case 2:
                rotateMatrixCol(matrix, i, sizeMatrix, 1);
                break;
            case 3:
                rotateMatrixCol(matrix, i, sizeMatrix, 3);
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

void messageSubstitution(vector<vector<char> > &matrix, int sizeMatrix) {
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
                if (alphabet.find(matrix[i][j]) != alphabet.end()) {
                    matrix[i][j] = alphabet[matrix[i][j]];
                }
            } else {
                if (alphabet2.find(matrix[i][j]) != alphabet2.end()) {
                    matrix[i][j] = alphabet2[matrix[i][j]];
                }
            }
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

void cipher(vector<vector<char> > &messageMatrix, vector<vector<char> > &privateKeyMatrix, int sizeMatrix) {
    bitset<8> auxBit(1);

    vector<vector<bitset<8> > > privateKeyBinaryMatrix {
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit}
    };

    vector<vector<bitset<8> > > messageBinaryMatrix {
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit},
        {auxBit, auxBit, auxBit, auxBit}
    };

    moveMessageRows(messageMatrix, sizeMatrix);
    cout << "Move rows:" << endl; 
    printMatrix(messageMatrix, sizeMatrix);
    moveMessageColumns(messageMatrix, sizeMatrix);
    cout << "Move columns:" << endl; 
    printMatrix(messageMatrix, sizeMatrix);
    messageSubstitution(messageMatrix, sizeMatrix);
    cout << "Substitute matrix" << endl; 
    printMatrix(messageMatrix, sizeMatrix);
    privateKeyBinaryMatrix = getBinaryMatrix(privateKeyMatrix, sizeMatrix);
    cout << "Binary private key" << endl; 
    printBinaryMatrix(privateKeyBinaryMatrix, sizeMatrix);
    messageBinaryMatrix = getBinaryMatrix(messageMatrix, sizeMatrix);
    cout << "Binary message:" << endl; 
    printBinaryMatrix(messageBinaryMatrix, sizeMatrix);
    xorBinaryMatrixes(messageBinaryMatrix, privateKeyBinaryMatrix, sizeMatrix);
    cout << "Binary XOR:" << endl; 
    printBinaryMatrix(messageBinaryMatrix, sizeMatrix);
    messageMatrix = getCharMatrix(messageBinaryMatrix, sizeMatrix);
    cout << "Cipher message matrix:" << endl; 
    printMatrix(messageMatrix, sizeMatrix);
    privateKeyMatrix = getCharMatrix(privateKeyBinaryMatrix, sizeMatrix);
    rubiksCubeAlgorithm(privateKeyMatrix, sizeMatrix);

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
    printMatrix(privateKeyMatrix, sizeMatrix);
    messageBinAux = getBinaryMatrix(messageMatrix, sizeMatrix);
    privateKeyBinAux = getBinaryMatrix(privateKeyMatrix, sizeMatrix);
    cout << "Private key binary: " << endl;
    printBinaryMatrix(privateKeyBinAux, sizeMatrix);
    xorBinaryMatrixes(messageBinAux, privateKeyBinAux, sizeMatrix);
    cout << "Binary inverse XOR: " << endl;
    printBinaryMatrix(messageBinAux, sizeMatrix);
    messageMatrix = getCharMatrix(messageBinAux, sizeMatrix);
    cout << "Inverse XOR: " << endl;
    printMatrix(messageMatrix, sizeMatrix);
    inverseMessageSubstitution(messageMatrix, sizeMatrix);
    cout << "Inverse substitution: " << endl;
    printMatrix(messageMatrix, sizeMatrix);
    inverseMoveMessageColumns(messageMatrix, sizeMatrix);
    cout << "Inverse move columns: " << endl;
    printMatrix(messageMatrix, sizeMatrix);
    inverseMoveMessageRows(messageMatrix, sizeMatrix);
    cout << "Inverse move rows:" << endl;
    printMatrix(messageMatrix, sizeMatrix);

}

int main (int argc, char* argv[]) {
    //string privateKey = "X4n17Az365lIjk8m";
    string privateKey;
    cout << "Enter the private key: ";
    getline(cin, privateKey);
    vector<vector<char> > privateKeyMatrix {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    vector<vector<char> > copyPrivateKeyMatrixCipher {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    vector<vector<char> > copyPrivateKeyMatrixDecipher {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    int const sizeMatrix = 4;

    insertStringToMatrix(privateKeyMatrix, sizeMatrix, privateKey);
    insertStringToMatrix(copyPrivateKeyMatrixCipher, sizeMatrix, privateKey);
    insertStringToMatrix(copyPrivateKeyMatrixDecipher, sizeMatrix, privateKey);
    //printMatrix(privateKeyMatrix, sizeMatrix);
    
    string message;

    vector<vector<char> > messageMatrix {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    cout << "Enter the message: ";
    getline(cin, message);

    printMatrix(privateKeyMatrix, sizeMatrix);
    
    string auxMessage;
    int rounds = 6;


    cout << "-----------------------------Cipher-------------------------" << endl;
    if (message.length() > 16) {
        //add code if message is larger than 16 characters
        vector<vector<vector<char> > > cipheredMatrixes;
        vector<vector<vector<char> > > decipheredMatrixes;


        int stringLimit = message.length() / 16;
        int remainingChars = (16 * stringLimit);
        string messageTrim;

        for (int i = 0; i < stringLimit; i++) {
            messageTrim = message.substr(16 * i, 16);
            cout << messageTrim << endl; 
            insertStringToMatrix(messageMatrix, sizeMatrix, messageTrim);
            for(int j = 0; j < rounds; j++) {
                cout << "-------------- ROUND " << i << "----------------" << endl;
                cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);
            }
            cipheredMatrixes.push_back(messageMatrix);
        }

        messageTrim = message.substr(remainingChars, message.length());
        insertStringToMatrix(messageMatrix, sizeMatrix, messageTrim);
        for (int i = 0; i < rounds; i++) {
            cout << "-------------- ROUND " << i << "----------------" << endl;
            cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);
        }
        cipheredMatrixes.push_back(messageMatrix);

        cout << "-----------------------------Decipher-------------------------" << endl;
        for (int i = 0; i < cipheredMatrixes.size(); i++) {
            cout << "-------------- ROUND " << i << "----------------" << endl;
            for (int j = 0; j < rounds; j++) {
                decipher(cipheredMatrixes[i], copyPrivateKeyMatrixDecipher, sizeMatrix);
            }
            decipheredMatrixes.push_back(cipheredMatrixes[i]);
        }

        cout << "Original message: " << message << endl;
        cout << "Deciphered message: " << endl;
        for (int i = 0; i < decipheredMatrixes.size(); i++) {
            for (int j = 0; j < sizeMatrix; j++) {
                for (int k = 0; k < sizeMatrix; k++) {
                    cout << decipheredMatrixes[i][j][k];
                }
            }
        }
        cout << endl;

    } else {
        insertStringToMatrix(messageMatrix, sizeMatrix, message);

        printMatrix(messageMatrix, sizeMatrix);
        for (int i = 0; i < rounds; i++) {
            cout << "-------------- ROUND " << i << "----------------" << endl;
            cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);

        }

        auxMessage = charMatrixToString(messageMatrix, sizeMatrix);
        cout << auxMessage << endl;


        cout << "-----------------------------Decipher-------------------------" << endl;
        for (int i = 0; i < rounds; i++) {
            cout << "-------------- ROUND " << i << "----------------" << endl;
            decipher(messageMatrix, copyPrivateKeyMatrixDecipher, sizeMatrix);
        }

        cout << "Original message: " << message << endl;
        cout << "Deciphered message: " << endl;
        

        for (int i = 0; i < sizeMatrix; i++) {
            for (int j = 0; j < sizeMatrix; j++) {
                cout << messageMatrix[i][j];
            }
        }
        cout << endl;
    }



    return 0;
}
