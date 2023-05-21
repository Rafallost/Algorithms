#include <iostream>

using namespace std;

int maxProduct(int numbers[], int n) {

    if (n < 3) {
        cout << "Za ma³o elementów w tablicy." << endl;
        return 0;
    }

    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (numbers[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = numbers[i];
        }
        else if (numbers[i] > max2) {
            max3 = max2;
            max2 = numbers[i];
        }
        else if (numbers[i] > max3) {
            max3 = numbers[i];
        }

        if (numbers[i] < min1) {
            min2 = min1;
            min1 = numbers[i];
        }
        else if (numbers[i] < min2) {
            min2 = numbers[i];
        }
    }

    int product1 = max1 * max2 * max3;
    int product2 = max1 * min1 * min2;

    if (product1 > product2)
        return product1;

    return product2;
}

int main() {
    int numbers[] = { -1,-50,-2,70,80 };
    int n = sizeof(numbers) / sizeof(numbers[0]);

    int maxProd = maxProduct(numbers, n);

    cout << "Max product: " << maxProd << endl;

    return 0;
}