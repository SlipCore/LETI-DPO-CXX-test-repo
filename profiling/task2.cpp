#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}
void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}
int** multiplyMatrices(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = createMatrix(rowsA, colsB);
    
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0));
    int rowsA = 3, colsA = 4;
    int rowsB = 4, colsB = 3;
    int** A = createMatrix(rowsA, colsA);
    int** B = createMatrix(rowsB, colsB);
    fillMatrix(A, rowsA, colsA);
    fillMatrix(B, rowsB, colsB);
    
    cout << "Matrix A:" << endl;
    printMatrix(A, rowsA, colsA);
    
    cout << "\nMatrix B:" << endl;
    printMatrix(B, rowsB, colsB);
    int** C = multiplyMatrices(A, B, rowsA, colsA, colsB);
    
    cout << "\nResult matrix C:" << endl;
    printMatrix(C, rowsB, colsB);
    int** temp = createMatrix(2, 2); 
    fillMatrix(temp, 2, 2);
    for (int i = 0; i < 3; i++) {
        int** leakyMatrix = createMatrix(2, 2);
    }
    
    cout << "\nProgram finished. Check for memory leaks with valgrind!" << endl;
    delete[] A;
    delete[] B;
    delete[] C;
    
    return 0;
}
