#include <iostream>
#include <ctime>  
#include <cstdlib> 

using namespace std;

// Función para inicializar
void init(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100 + 1;  // Números aleatorios entre 1 y 100
        }
    }
}

// multiplicar dos matrices A y B, y almacenar el resultado en C
void matrixMultiplication(int** A, int** B, int** C, int size) {
    // Inicializar la matriz C en ceros
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
        }
    }

    // Multiplicación clásica de matrices con tres bucles anidados
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
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
int** creat(int size) {
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }
    return matrix;
}

// Función para liberar la memoria de una matriz dinámica
void deletematrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(0));  // Inicializamos la semilla para números aleatorios

    // Tamaños de matriz que queremos probar: 2x2, 3x3, 4x4, 6x6, y 10x10
    int sizes[] = {2, 3, 4, 6, 10};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    // Probar la multiplicación para cada tamaño de matriz
    for (int s = 0; s < numSizes; s++) {
        int size = sizes[s];

        // Crear matrices A, B y C dinámicamente
        int** A = creat(size);
        int** B = creat(size);
        int** C = creat(size);

        // Inicializar A y B con valores aleatorios
        init(A, size);
        init(B, size);

        // Imprimir las matrices A y B
        cout << "Matriz A (" << size << "x" << size << "):" << endl;
        print(A, size);
        cout << "Matriz B (" << size << "x" << size << "):" << endl;
        print(B, size);

        // Medir el tiempo de inicio
        clock_t start = clock();

        // Realizar la multiplicación de matrices
        matrixMultiplication(A, B, C, size);

        // Medir el tiempo final
        clock_t end = clock();
        double timeTaken = double(end - start) / CLOCKS_PER_SEC;

        // Imprimir la matriz resultante C
        cout << "Matriz C resultante (" << size << "x" << size << "):" << endl;
        print(C, size);

        // Imprimir el tiempo tomado para la multiplicación
        cout << "Tiempo tomado para la multiplicación de una matriz " << size << "x" << size << ": " << timeTaken << " segundos." << endl;
        cout << "---------------------------------------------" << endl;

        // Liberar memoria de las matrices
        deletematrix(A, size);
        deletematrix(B, size);
        deletematrix(C, size);
    }

    return 0;
}
