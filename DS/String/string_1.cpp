#include<iostream>
#include <cstring>

using namespace std;

int main(){
    string s = "hello";
    cout << s << endl;

    char str1[20] = "world";
    char str2[20] = "!!!";

    strcat(str1, str2);
    cout << "결과" << str1 << str2 <<endl;
    return 0;
}

