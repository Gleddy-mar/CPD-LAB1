#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000  

// inicializando la matriz y el vector con valores aleatorios entre 1 y 100
void init(int A[MAX][MAX], int x[MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            A[i][j] = rand() % 100 + 1;  // Números aleatorios entre 1 y 100
        }
        x[i] = rand() % 100 + 1;  // Números aleatorios entre 1 y 100
    }
}

// Primera  multiplicación loop 
void loop1(int A[MAX][MAX], int x[MAX], int y[MAX]) {

    // Multiplicación de matriz 
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

// Segunda multiplicación 
void loop2(int A[MAX][MAX], int x[MAX], int y[MAX]) {

    // Multiplicación de matriz
    for (int j = 0; j < MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

// Función para imprimir el vector y
void printy(int y[MAX]) {
    printf("Vector y:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");
}

int main() {
    int A[MAX][MAX];  // Matriz A
    int x[MAX];       // Vector x
    int y[MAX];       // Vector y para almacenar el resultado

    // Inicializamos la semilla de números aleatorios
    srand(time(0));

    // Inicializamos la matriz y el vector con valores aleatorios
    init(A, x);
    // Inicializamos el vector y a 0
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    // Variables para medir el tiempo
    clock_t start, end;
    double time_loop1, time_loop2;

    // Multiplicación 
    start = clock();
    loop1(A, x, y);
    end = clock();
    time_loop1 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Imprimimos el resultado del vector y
    printf("Resultado con :\n");
    printy(y);

    // Inicializamos el vector y a 0
    for (int i = 0; i < MAX; i++) {
        y[i] = 0;
    }

    // Multiplicación 
    start = clock();
    loop2(A, x, y);
    end = clock();
    time_loop2 = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Imprimimos el resultado del vector y
    printf("Resultado con :\n");
    printy(y);

    // Imprimimos el tiempo que tomó cada multiplicación
    printf("Tiempo para realizar la multiplicación con : %f segundos\n", time_loop1);
    printf("Tiempo para realizar la multiplicación con : %f segundos\n", time_loop2);

    return 0;
}
