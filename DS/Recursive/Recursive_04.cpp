#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;        // 종료 조건
    return gcd(b, a % b);        // 재귀 호출
}

int main() {
    int x, y;
    cout << "두 정수를 입력하세요: ";
    cin >> x >> y;

    cout << x << "와 " << y << "의 최대공약수: " << gcd(x, y) << endl;
    return 0;
}
