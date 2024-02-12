#include <iostream>
using namespace std;


// ������� ��� ���������� ����� ��������� ���������� 3x3
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
    cout << "������� ���������� ����� � �������� (�� ����� 20): ";
    cin >> n >> m;

    // �������� �� ������������ �������� �������
    if (n < 3 || m < 3 || n > 20 || m > 20) {
        cout << "������������ ������� �������!";
        return 0;
    }

    int arr[20][20];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand()%100;
        }
    }
    cout << "���������� ������" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // �������������� ������������ ����� ��������� ������� ����������
    int maxSum = sumSubarray(arr, 0, 0);
    int maxRow = 0, maxCol = 0;

    // �������� �� ���� ����������� 3x3 � ���� ������������ �����
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

    // ������� ��������� ��������� � ��� �����
    cout << "��������� � ������������ ������:" << endl;
    for (int i = maxRow; i < maxRow + 3; ++i) {
        for (int j = maxCol; j < maxCol + 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "������������ �����: " << maxSum << endl;

    return 0;
}
