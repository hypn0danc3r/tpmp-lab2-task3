#include "task3.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <размер_массива>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Размер должен быть положительным\n");
        return 1;
    }

    srand(time(NULL));
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Исходный массив из %d чисел:\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // числа 0..999
        printf("%d ", arr[i]);
    }
    printf("\n");
    printPerfectSquares(arr, n);
    free(arr);

    NOTE1 block[BLOCK_SIZE];
    inputNotes(block, BLOCK_SIZE);

    sortNotesByName(block, BLOCK_SIZE);

    printf("\nОтсортированный список (по фамилии и инициалам):\n");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%d. %s, тел: %s, рожд: %02d.%02d.%d\n",
               i+1, block[i].name, block[i].tele,
               block[i].birth.day, block[i].birth.month, block[i].birth.year);
    }

    int month;
    printf("\nВведите номер месяца (1-12): ");
    scanf("%d", &month);
    printNotesByMonth(block, BLOCK_SIZE, month);

    return 0;
}