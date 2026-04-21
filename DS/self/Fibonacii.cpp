#include<iostream>

using namespace std;


int cal(int n){
    if(n<=1){
        return n;
    }
    return cal(n -1) + cal(n-2);
}

int main(){
    int n;
    cout << "수를 입력하시오 : ";
   cin >> n;

   cout << n << "번째 피보나치 수열" << cal(n);
   return 0;
}
