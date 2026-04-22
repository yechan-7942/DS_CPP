#include<iostream>
using namespace std;

int fac(int n){
    if(n==0){
        return 1;
    }
    else{
        return (n*(fac(n-1)));
    }
}

int main(){
    int k;
    cout << "숫자를 입력하시오" << endl;
    cin >> k;
   int result = fac(k);
    cout << result << endl ;
}