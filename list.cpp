#include<iostream>
using namespace std;

void my_sort(int arr[],int n);
int main(){
    int list[10]= {22,11,14,8,18,33,7,14,19,21};
    int i;
    my_sort(list,10);
    for(i=0;i<10; i++){
        cout<<list[i]<<"\n";
    }
           return 0;

}
void my_sort(int arr[],int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
