/* Integrantes
Halim Abraham Hamanoiel Galindo
Alejandro Ruíz García Rojas
Miguel Weiping Tang Feng
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

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


int main (int argc, char* argv[]) {
    unordered_map <char,char> alphabet;

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

    string privateKey = "X4n17Az365lIjk8m";
    vector<vector<char> > privateKeyMatrix {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    int const sizeMatrix = 4;
    int limitMatrixRows = 0;
    int limitMatrixColumns = 0;

    for (int k = 0; k < privateKey.length(); k++) {
        if ((k + 1) % 4 == 0) {
            privateKeyMatrix[limitMatrixRows][limitMatrixColumns] = privateKey[k];
            limitMatrixRows++;
            limitMatrixColumns = 0;
        } else {
            privateKeyMatrix[limitMatrixRows][limitMatrixColumns] = privateKey[k];
            limitMatrixColumns++;
        }
    }

    vector<vector<char> > privateKeyMatrixCopy = privateKeyMatrix;

    string message;
    vector<vector<char> > messageMatrix {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}
    };

    getline(cin, message);

    if (message.length() > 16) {
        //add code if message is larger than 16 characters
    } else {
        if (message.length() < 16) {
            while (message.length() < 16) {
                message += " ";
            }
        }

        limitMatrixRows = 0;
        limitMatrixColumns = 0;

        for (int k = 0; k < message.length(); k++) {
            if ((k + 1) % 4 == 0) {
                messageMatrix[limitMatrixRows][limitMatrixColumns] = message[k];
                limitMatrixRows++;
                limitMatrixColumns = 0;
            } else {
                messageMatrix[limitMatrixRows][limitMatrixColumns] = message[k];
                limitMatrixColumns++;
            }
        }
        //printMatrix(messageMatrix, sizeMatrix);
    }




   return 0;

}
