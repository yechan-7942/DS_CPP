#include <iostream>
using namespace std;

// 배열의 앞쪽 n개 원소의 합을 재귀로 구하는 함수
int sum_array(int arr[], int n) {
    if (n <= 0) { // 종료 조건
        return 0;
    }
    return arr[n-1] + sum_array(arr, n-1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n;

    cout << "몇 개의 원소를 더할까요? ";
    cin >> n;

    int result = sum_array(arr, n);
    cout << "앞쪽 " << n << "개 원소의 합: " << result << endl;

    return 0;
}
