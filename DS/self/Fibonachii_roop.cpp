#include<iostream>

using namespace std;

int fib(int n){
    if(n <=1){
        return n;
    }
    int pre1 =0 ,pre2=1;
    int curr;
    for(int i=2; i<=n; i++){
        curr = pre1 + pre2;
        pre1= pre2;
        pre2= curr;
    }
    return curr;

}

int main(){

    int n;

    cout << "숫자를 입력하시오: ";
    cin >> n;
    
    cout << n <<"번째 피보나치 수:" << fib(n) << endl;
    return 0;
    
    }