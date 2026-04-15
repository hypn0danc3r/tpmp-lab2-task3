#include "task3.h"

int isPerfectSquare(int num) {
    if (num < 0) return 0;
    int root = (int)round(sqrt(num));
    return (root * root == num);
}

void printPerfectSquares(int *arr, int n) {
    printf("Числа, являющиеся полными квадратами:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (isPerfectSquare(arr[i])) {
            printf("%d ", arr[i]);
            found = 1;
        }
    }
    if (!found) printf("отсутствуют");
    printf("\n");
}

void inputNotes(NOTE1 *block, int size) {
    printf("Введите данные для %d записей:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Запись %d\n", i+1);
        printf("  Фамилия и инициалы: ");
        fgets(block[i].name, MAX_NAME, stdin);
        block[i].name[strcspn(block[i].name, "\n")] = 0; // убрать \n
        printf("  Номер телефона: ");
        fgets(block[i].tele, MAX_TELE, stdin);
        block[i].tele[strcspn(block[i].tele, "\n")] = 0;
        printf("  Дата рождения (год месяц день): ");
        scanf("%d %d %d", &block[i].birth.year, &block[i].birth.month, &block[i].birth.day);
        while (getchar() != '\n'); // очистка буфера
    }
}

static int compareByName(const void *a, const void *b) {
    const NOTE1 *na = (const NOTE1 *)a;
    const NOTE1 *nb = (const NOTE1 *)b;
    return strcmp(na->name, nb->name);
}

void sortNotesByName(NOTE1 *block, int size) {
    qsort(block, size, sizeof(NOTE1), compareByName);
}

void printNotesByMonth(const NOTE1 *block, int size, int month) {
    printf("\nЛюди, родившиеся в %d месяце:\n", month);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (block[i].birth.month == month) {
            printf("  %s, тел: %s, дата: %02d.%02d.%d\n",
                   block[i].name, block[i].tele,
                   block[i].birth.day, block[i].birth.month, block[i].birth.year);
            found = 1;
        }
    }
    if (!found) {
        printf("  Нет таких людей.\n");
    }
}