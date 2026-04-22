#include<iostream>
using namespace std;

#include <string>
#define SIZE 100
#define EOS '$'

//Infix expression을 Postfix expression으로 변환하는 프로그램을 작성하시오.

class op_stack{
    char s[SIZE];
    int top;
    
    public:
    op_stack();
    void push(char x);
    char pop();
    bool emtpy();
    char top_element();
};

op_stack::op_stack(){
    top =0;

}

void op_stack::push(char x){
    s[top] =x ;
    top ++ ;
}

char op_stack::pop(){
    top --;
    return(s[top]);
}

bool op_stack::emtpy(){
    return (top ==0);
}
char op_stack::top_element(){
    return (s[top-1]);
}

bool is_operand(char ch){
if ( (ch == '(') || (ch == ')') ||
(ch == '+') || (ch == '-') ||
(ch == '*') || (ch == '/') ||
(ch == '%') || (ch == '$') )
return false;
else
return true;
}

int get_precedence(char op)
{
if ((op =='$') || (op == '(' ) )
return(0);
if ( (op =='+') || (op == '-' ) )
return(1);
if ((op =='*') || (op == '/' ) || (op == '%' ) )
return(2);
return(-1);
}

int main(){
    string input , output;
    op_stack stack1;
    cout << "Input an infix expression to convert :";
    cin >> input;
    input += EOS;
    stack1.push(EOS);
    for(int i=0; i< input.size(); i++){
        char token = input[i];
        if (is_operand(token)) {
            output += token;
        } else if (token == '(') {
            stack1.push(token);
        } else if (token == ')') {
            while (stack1.top_element() != '(') {
                output += stack1.pop();
            }
            stack1.pop(); // '(' 제거
        } else {
            while (!stack1.emtpy() &&
                   get_precedence(stack1.top_element()) >= get_precedence(token)) {
                output += stack1.pop();
            }
            stack1.push(token);
        }
    }
    while (!stack1.emtpy()) {
        char c = stack1.pop();
        if (c != EOS)
            output +=c ;
    }

    cout << output;

}