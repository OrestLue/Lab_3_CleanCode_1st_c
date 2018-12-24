#include <stdio.h>
#include <math.h>
#include <conio.h>

#define N 5

void sort(int array[][N]);                                          // Сортування рядків матриці за спаданням методом вибору
_Bool isGreater(int a, int b);                                      // Порівняння елементів матриці між собою згідно блок-схеми (Рис.2)
double average(int array[][N], int column);                         // Середнє арифметичне значення елементів у N-ному стовпці над допоміжною діагоналлю
double mul(double(*f)(int array[][N], int column), int array[][N]); // Добуток середніх арифметичних значень усіх стовпців над допоміжною діагоналлю

int main()
{
    int array[N][N] = { {33, -5, -9, -20, -11},
                        {0, -42, 86, 83, 71},
                        {-6, -9, 33, 13, 22},
                        {52, -5, -7, 53, 19},
                        {-3, 98, 72, 68, 0} };

    sort(array);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("array[%i][%i] = %i, ", i, j, array[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < N; i++) printf("Average array[][%i] = %.2f\n", i, average(array, i));

    printf("Multiply array[][] = %.2f\n", mul(average, array));

    _getch();

    return 0;
}


void sort(int array[][N]) {

    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N - 1; k++) {
            for (int j = k + 1; j < N; j++) {
                if (isGreater(array[i][j], array[i][k])) {
                    int temp = array[i][k];
                    array[i][k] = array[i][j];
                    array[i][j] = temp;
                }
            }
        }
    }
}

_Bool isGreater(int a, int b) {
    return a > b;
}

double average(int array[][N], int column) {
    int i, sum = 0;

    for (i = 0; i < N - column; i++) sum += array[i][column];

    return (double)sum / (double)i;
}

double mul(double(*f)(int array[][N], int column), int array[][N]) {

    double ress = 1;

    for (int i = 0; i < N; i++) ress *= f(array, i);

    return ress;
}