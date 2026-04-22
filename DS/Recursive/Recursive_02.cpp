#include<iostream>
using namespace std;

int sum(int x){
    if(x ==1){
        return 1;
    }
    else{
        return (x +sum(x-1));
    }
}

int main(){
    int n;
    int result ;
    cout << "숫자를 입력하시오" << endl;
    cin >> n;
    result = sum(n);
    cout << "합은 : " << result ;
}