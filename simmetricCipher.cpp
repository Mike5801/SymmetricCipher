/* Integrantes
Halim Abraham Hamanoiel Galindo
Alejandro Ruíz García Rojas
Miguel Weiping Tang Feng
*/
#include <iostream>
#include <fstream>
#include "cipher.h"
#include "decipher.h"

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
        cout << "---------------------------------------- BLOCK " << stringLimit << " --------------------------------------------" << endl;
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
                    cout << cipheredMatrixes[i][j][k] << flush;
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
                        cout << decipheredMatrixes[i][j][k] << flush;
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
        cout << endl;
    }

    return 0;
}
