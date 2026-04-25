#include<iostream>
using namespace std;

int sum(int x){
    if(x <=0){
        return 0;
    }
    
     if( x%2 == 0){
        return (x + sum(x-2));
    }
    else {
        return sum(x-1);
    }
}

int main(){
    int n;
    int result ;
    cout << "숫자를 입력하시오" << endl;
    cin >> n;
    result = sum(n);
    cout << "짝수들의 합: " << result ;
}