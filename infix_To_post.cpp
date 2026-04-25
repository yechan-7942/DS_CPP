#include <iostream>
using namespace std;

class op_stack {
    char s[100];   // 배열 이름을 s로統一
    int top;
public:
    op_stack();
    void push(char x);
    bool empty();
    char top_element();
};

op_stack::op_stack() {
    top = 0;
}

void op_stack::push(char x) {
    s[top] = x;   // 세미콜론 추가
    top++;
}

bool op_stack::empty() {
    return (top == 0);
}

char op_stack::top_element() {
    return s[top - 1];   // 올바른 배열 접근
}

int main() {
    op_stack st;
    st.push('A');
    st.push('B');
    cout << st.top_element() << endl; // 출력: B
}
