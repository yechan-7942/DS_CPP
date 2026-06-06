#include<iostream>
#include <vector>//push_back(),pop_back()

using namespace std;

class MaxHeap{
    vector<int> v1;
    int parent(int i){
        return (i-1)/2;
    }
    int leftchild(int i){
        return 2*i +1;
    }
    int rightchild(int i){
        return 2*i +2;
    }

    public:
    void insert(int v);
    void removeRoot();
    int top();
    void print();

};

 void MaxHeap ::insert(int v){


 }
    void MaxHeap :: removeRoot(){
        if(heap.empty()) return;
        
    }
    int MaxHeap :: top(){
    
    }
    void MaxHeap :: print(){

    }







int main(){

    return 0;
}

