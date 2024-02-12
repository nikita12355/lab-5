#include <iostream>
using namespace std;


// Функция для вычисления суммы элементов подмассива 3x3
int sumSubarray(int arr[20][20], int n, int m) {
    int sum = 0;
    for (int i = n; i < n + 3; ++i) {
        for (int j = m; j < m + 3; ++j) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, m;
    cout << "Введите количество строк и столбцов (не более 20): ";
    cin >> n >> m;

    // Проверка на корректность размеров массива
    if (n < 3 || m < 3 || n > 20 || m > 20) {
        cout << "Некорректные размеры массива!";
        return 0;
    }

    int arr[20][20];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand()%100;
        }
    }
    cout << "Полученный массив" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Инициализируем максимальную сумму значением первого подмассива
    int maxSum = sumSubarray(arr, 0, 0);
    int maxRow = 0, maxCol = 0;

    // Проходим по всем подмассивам 3x3 и ищем максимальную сумму
    for (int i = 0; i <= n - 3; ++i) {
        for (int j = 0; j <= m - 3; ++j) {
            int currentSum = sumSubarray(arr, i, j);
            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Выводим найденный подмассив и его сумму
    cout << "Подмассив с максимальной суммой:" << endl;
    for (int i = maxRow; i < maxRow + 3; ++i) {
        for (int j = maxCol; j < maxCol + 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Максимальная сумма: " << maxSum << endl;

    return 0;
}
