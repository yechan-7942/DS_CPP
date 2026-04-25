#include <iostream>
using namespace std;

bool isPalindrome(char str[], int len) {
    char stk[1000];  // 배열 스택
    int top = -1;
    int mid = len / 2;
    
    // 앞 절반 push
    for (int i = 0; i < mid; i++) {
        stk[++top] = str[i];
    }
    
    // 홀수 중간 스킵
    if (len % 2 == 1) mid++;
    
    // 뒤 절반 pop 비교
    for (int i = mid; i < len; i++) {
        if (top == -1 || str[i] != stk[top--]) {
            return false;
        }
    }
    return true;
}


int main() {
    char input[1000];
    cout << "문자열 입력: ";
    cin.getline(input, 1000);  // <iostream>에 있음
    
    int len = 0;
    while (input[len] != '\0') len++;
    
    if (isPalindrome(input, len)) {
        cout << "회문입니다." << endl;
    } else {
        cout << "회문이 아닙니다." << endl;
    }
    return 0;
}
