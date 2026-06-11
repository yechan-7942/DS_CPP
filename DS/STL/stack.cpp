#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack <int> s1;
    s1.push(3);
    s1.push(4);
    s1.push(8);
    
    int n1 = s1.top();
    cout << n1<< endl;
    int n2 = s1.size();
    cout << n2;
    return 0;
}