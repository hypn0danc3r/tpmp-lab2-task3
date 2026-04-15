#ifndef TASK3_H
#define TASK3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int isPerfectSquare(int num);
void printPerfectSquares(int *arr, int n);

#define MAX_NAME 50
#define MAX_TELE 20
#define BLOCK_SIZE 9

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[MAX_NAME];
    char tele[MAX_TELE];
    Date birth;
} NOTE1;

void inputNotes(NOTE1 *block, int size);
void sortNotesByName(NOTE1 *block, int size);
void printNotesByMonth(const NOTE1 *block, int size, int month);

#endif