#include<iostream>

using namespace std;

int partition(int *list, int left, int right){
    int pivot = list[right];
    int i = left;

    for(int j = i; j< right; j++){
        if (list[j] <= pivot){
            swap(list[i], list[j]);
            i ++;
        }  
    }
     swap(list[i], list[right]);
     return i;

}

//quicksort(list, 0, size-1)
void quicksort(int *list, int left, int right){

    if(left < right){
        int pivoitIndex = partition(list, left, right);

        quicksort(list, left, pivoitIndex-1);
        quicksort(list, pivoitIndex +1, right);
    }
}




int main(){

    return 0;
}