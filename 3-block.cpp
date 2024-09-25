#include <iostream>
#include <ctime>  
#include <cstdlib> 

using namespace std;

// inicializar una matriz con valores aleatorios
void init(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100 + 1;  // Números aleatorios entre 1 y 100
        }
    }
}

// Función para multiplicar dos matrices clásicamente
void matrixMultiplication(int** A, int** B, int** C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplicación clásica de matrices 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Función para multiplicar dos matrices por bloques
void matrixMultiplicationByBlocks(int** A, int** B, int** C, int size, int blockSize) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplicación por bloques usando seis bucles anidados
    for (int ii = 0; ii < size; ii += blockSize) {
        for (int jj = 0; jj < size; jj += blockSize) {
            for (int kk = 0; kk < size; kk += blockSize) {
                for (int i = ii; i < min(ii + blockSize, size); i++) {
                    for (int j = jj; j < min(jj + blockSize, size); j++) {
                        for (int k = kk; k < min(kk + blockSize, size); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

// Función para imprimir una matriz
void print(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Función para crear una matriz dinámica de tamaño `size`
int** create(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

// Función para liberar la memoria de una matriz dinámica
void deleteMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(0));  //  semilla para números aleatorios
    // Tamaños de matriz que queremos probar: 2x2, 3x3, 4x4, 6x6, y 10x10
    int sizes[] = {2, 3, 4, 6, 10};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Bloque de tamaño fijo para la multiplicación por bloques
    int blockSize = 2;  // Puedes ajustarlo según el tamaño de las matrices y la caché

    // Probar la multiplicación para cada tamaño de matriz
    for (int s = 0; s < numSizes; s++) {
        int size = sizes[s];

        // Crear matrices A, B y C dinámicamente
        int** A = create(size);
        int** B = create(size);
        int** C_classic = create(size);
        int** C_block = create(size);

        // Inicializar A y B con valores aleatorios
        init(A, size);
        init(B, size);

        

        // Medir el tiempo de la multiplicación clásica
        clock_t startClassic = clock();
        matrixMultiplication(A, B, C_classic, size);
        clock_t endClassic = clock();
        double timeClassic = double(endClassic - startClassic) / CLOCKS_PER_SEC;

        // Medir el tiempo de la multiplicación por bloques
        clock_t startBlock = clock();
        matrixMultiplicationByBlocks(A, B, C_block, size, blockSize);
        clock_t endBlock = clock();
        double timeBlock = double(endBlock - startBlock) / CLOCKS_PER_SEC;

        // Imprimir los resultados
        cout << "Multiplicación para matriz " << size << "x" << size << ":" << endl;
        cout << "Tiempo (clásica): " << timeClassic << " segundos." << endl;
        cout << "Tiempo (por bloques): " << timeBlock << " segundos." << endl;
        cout << "---------------------------------------------" << endl;

        // Liberar memoria de las matrices
        deleteMatrix(A, size);
        deleteMatrix(B, size);
        deleteMatrix(C_classic, size);
        deleteMatrix(C_block, size);
    }

    return 0;
}
