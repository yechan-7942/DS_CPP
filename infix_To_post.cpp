#include<iostream>
using namespace std;

class op_stack{
    char SIZE[100];
    int top;
    public:
    op_stack();
    void push(char x);
    bool empty();
    char top_element();


};
op_stack :: op_stack(){
    top =0;
}

void op_stack :: push(char x){
    s[top] = x
    top++;
}


bool op_stack :: empty(){
    return (top==0);
}

char op_stack :: top_element(){
    return s([top-1]);
}

int main(){

}