/* Integrantes
Halim Abraham Hamanoiel Galindo
Alejandro Ruíz García Rojas
Miguel Weiping Tang Feng
*/
#include <iostream>
#include "cipher.h"
#include "decipher.h"

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
    // cout << "Move rows:" << endl; 
    // printMatrix(messageMatrix, sizeMatrix);
    moveMessageColumns(messageMatrix, sizeMatrix);
    // cout << "Move columns:" << endl; 
    // printMatrix(messageMatrix, sizeMatrix);
    messageSubstitution(messageMatrix, sizeMatrix);
    // cout << "Substitute matrix" << endl; 
    // printMatrix(messageMatrix, sizeMatrix);
    privateKeyBinaryMatrix = getBinaryMatrix(privateKeyMatrix, sizeMatrix);
    // cout << "Binary private key" << endl; 
    // printBinaryMatrix(privateKeyBinaryMatrix, sizeMatrix);
    messageBinaryMatrix = getBinaryMatrix(messageMatrix, sizeMatrix);
    // cout << "Binary message:" << endl; 
    // printBinaryMatrix(messageBinaryMatrix, sizeMatrix);
    xorBinaryMatrixes(messageBinaryMatrix, privateKeyBinaryMatrix, sizeMatrix);
    // cout << "Binary XOR:" << endl; 
    // printBinaryMatrix(messageBinaryMatrix, sizeMatrix);
    messageMatrix = getCharMatrix(messageBinaryMatrix, sizeMatrix);
    // cout << "Cipher message matrix:" << endl; 
    printMatrixAsString(messageMatrix, sizeMatrix);
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
    // printMatrix(privateKeyMatrix, sizeMatrix);
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
    
    string auxMessage;
    int rounds = 6;

    cout << "\nORIGINAL MESSAGE: " << message << endl;

    cout << "\nPRIVATE KEY MATRIX: " << endl;
    printMatrix(privateKeyMatrix, sizeMatrix);

    cout << "************************************************************** CIPHER **************************************************************" << endl << endl;
    if (message.length() > 16) {
        //add code if message is larger than 16 characters
        vector<vector<vector<char> > > cipheredMatrixes;
        vector<vector<vector<char> > > decipheredMatrixes;

        int stringLimit = message.length() / 16;
        int remainingChars = (16 * stringLimit);
        string messageTrim;

        for (int i = 0; i < stringLimit; i++) {
            messageTrim = message.substr(16 * i, 16);
            insertStringToMatrix(messageMatrix, sizeMatrix, messageTrim);
            cout << "---------------------------------------- BLOCK " << i << " --------------------------------------------" << endl;
            for(int j = 0; j < rounds; j++) {
                cout << ".................. ROUND " << j << " .................." << endl;
                cout << "Cipher result: " << endl;
                cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);
            }
            cipheredMatrixes.push_back(messageMatrix);
        }

        messageTrim = message.substr(remainingChars, message.length());
        insertStringToMatrix(messageMatrix, sizeMatrix, messageTrim);
        cout << "---------------------------------------- BLOCK " << stringLimit + 1 << "--------------------------------------------" << endl;
        for (int i = 0; i < rounds; i++) {
            cout << ".................. ROUND " << i << " .................." << endl;
            cout << "Cipher result: " << endl;
            cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);
        }
        cipheredMatrixes.push_back(messageMatrix);

        cout << "\nCIPHERED MESSAGE: ";
        for (int i = 0; i < cipheredMatrixes.size(); i++) {
            for (int j = 0; j < sizeMatrix; j++) {
                for (int k = 0; k < sizeMatrix; k++) {
                    cout << cipheredMatrixes[i][j][k];
                }
            }
        }

        cout << endl << endl;

        cout << "************************************************************** DECIPHER **************************************************************" << endl << endl;
        for (int i = 0; i < cipheredMatrixes.size(); i++) {
            cout << "---------------------------------------- BLOCK " << i << " --------------------------------------------" << endl;
            for (int j = 0; j < rounds; j++) {
                cout << ".................. ROUND " << j << " .................." << endl;
                cout << "Decipher result: " << endl;
                decipher(cipheredMatrixes[i], copyPrivateKeyMatrixDecipher, sizeMatrix);
            }
            decipheredMatrixes.push_back(cipheredMatrixes[i]);
        }


        cout << endl;

        cout << "DECIPHERED MESSAGE: ";
        for (int i = 0; i < decipheredMatrixes.size(); i++) {
            for (int j = 0; j < sizeMatrix; j++) {
                for (int k = 0; k < sizeMatrix; k++) {
                    if (decipheredMatrixes[i][j][k] != '_') {
                        cout << decipheredMatrixes[i][j][k];
                    }
                }
            }
        }
        cout << endl;

    } else {
        insertStringToMatrix(messageMatrix, sizeMatrix, message);
        for (int i = 0; i < rounds; i++) {
            cout << ".................. ROUND " << i << " .................." << endl;
            cout << "Cipher result: " << endl;
            cipher(messageMatrix, copyPrivateKeyMatrixCipher, sizeMatrix);

        }
        
        cout << "\nCIPHERED MESSAGE: ";
        printMatrixAsString(messageMatrix, sizeMatrix);
        cout << endl;

        cout << "************************************************************** DECIPHER **************************************************************" << endl << endl;
        for (int i = 0; i < rounds; i++) {
            cout << ".................. ROUND " << i << " .................." << endl;
            cout << "Decipher result: " << endl;
            decipher(messageMatrix, copyPrivateKeyMatrixDecipher, sizeMatrix);
        }

        cout << "\nDECIPHERED MESSAGE: ";
        for (int i = 0; i < sizeMatrix; i++) {
            for (int j = 0; j < sizeMatrix; j++) {
                if (messageMatrix[i][j] != '_') {
                    cout << messageMatrix[i][j];
                }
            }
        }
        //printMatrixAsString(messageMatrix, sizeMatrix);
        cout << endl;
    }

    return 0;
}
