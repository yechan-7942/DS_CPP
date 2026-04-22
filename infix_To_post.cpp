#include <iostream>
#include <string>
using namespace std;

#define EOS '$'

// ===== 스택 클래스 정의 =====
class op_stack {
    char s[100];
    int top;
public:
    op_stack() { top = 0; }
    void push(char x) { s[top++] = x; }
    char pop() {
        if (top == 0) return '\0';
        return s[--top];
    }
    bool empty() const { return (top == 0); }
    char top_element() const {
        if (top == 0) return '\0';
        return s[top - 1];
    }
};

// ===== 피연산자 판별 =====
bool is_operand(char ch) {
    if ( (ch == '(') || (ch == ')') || (ch == '+') || 
         (ch == '-') || (ch == '*') || (ch == '/') || 
         (ch == '%') || (ch == '$') ) return false;
    else return true;
}

// ===== 연산자 우선순위 =====
int get_precedence(char op) { 
    if ( (op =='$') || (op == '(' ) ) return 0; 
    if ( (op =='+') || (op == '-' ) ) return 1; 
    if ( (op =='*') || (op == '/' ) || (op == '%' ) ) return 2; 
    return -1;
}

// ===== 변환 로직 =====
string infix_to_postfix(string input) {
    op_stack stack1;
    string output = "";
    
    input += EOS;       // 입력 끝에 EOS 추가
    stack1.push(EOS);   // 스택 바닥에 EOS 추가
    
    for (int i = 0; i < input.size(); i++) {
        char token = input[i];
        
        if ( is_operand(token) ) {
            output += token; // 피연산자는 그대로 출력
        } 
        else if (token == '(') {
            stack1.push(token);
        }
        else if (token == ')') {
            while (stack1.top_element() != '(') {
                output += stack1.pop();
            }
            stack1.pop(); // '(' 제거
        }
        else { // 연산자 처리
            while (get_precedence(stack1.top_element()) >= get_precedence(token)) {
                if (stack1.top_element() == EOS) break;
                output += stack1.pop();
            }
            stack1.push(token);
        }
    }
    
    // 스택에 남은 연산자 모두 출력
    while (!stack1.empty() && stack1.top_element() != EOS) {
        output += stack1.pop();
    }
    
    return output;
}

// ===== 테스트 =====
int main() {
    string expr;
    cout << "중위표기식을 입력하세요: ";
    cin >> expr;

    string postfix = infix_to_postfix(expr);
    cout << "후위표기식: " << postfix << endl;

    return 0;
}
