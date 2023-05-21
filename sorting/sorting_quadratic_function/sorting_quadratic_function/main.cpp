#include <iostream>

void merge(int tab[], int left, int middle, int right) {
    int tabOne = middle - left + 1;
    int tabTwo = right - middle;

    int* L = new int[tabOne];
    int* R = new int[tabTwo];

    for (int i = 0; i < tabOne; i++) {
        L[i] = tab[left + i];
    }
    for (int j = 0; j < tabTwo; j++) {
        R[j] = tab[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < tabOne && j < tabTwo) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < tabOne) {
        tab[k] = L[i];
        i++;
        k++;
    }

    while (j < tabTwo) {
        tab[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int tab[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(tab, left, middle);
        mergeSort(tab, middle + 1, right);

        merge(tab, left, middle, right);
    }
}

int* sortFunctiontab(int arguments[], int size, int A, int B, int C) {

    int* functiontab = new int[size];

    for (int i = 0; i < size; i++) {
        int functionValue = A * arguments[i] * arguments[i] + B * arguments[i] + C;
        functiontab[i] = functionValue;
    }

    mergeSort(functiontab, 0, size - 1);

    return functiontab;
}

int main() {
    int arguments[] = { -10000, -900,-232, 0, 12, 23323 };
    int size = sizeof(arguments) / sizeof(arguments[0]);
    int A = -1, B = 2, C = 3;

    int* sortedtab = sortFunctiontab(arguments, size, A, B, C);
    std::cout << "Sorted values:";

    for (int i = 0; i < size; i++) {
        std::cout << " " << sortedtab[i];
    }
    std::cout << "\n";

    delete[] sortedtab;

    return 0;
}