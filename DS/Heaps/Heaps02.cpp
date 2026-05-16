#include <iostream>
using namespace std;

#define HSIZE 100

class element {
public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element::set_data(string n, double s) {
    name = n;   // ✅ 수정
    score = s;
}

class my_heap {
    element h[HSIZE];
    int csize;
public:
    my_heap();
    int h_size();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};

my_heap::my_heap() { csize = 0; }

bool my_heap::heap_empty() { return (csize == 0); }
bool my_heap::heap_full()  { return (csize >= HSIZE - 1); }
int  my_heap::h_size()     { return csize; }

// ✅ insert 구현 (sift-up)
void my_heap::insert_heap(element t) {
    int k;
    csize ++;
    k=csize;

    while((k!=1) && t.score > h[k/2].score){
        h[k] = h[k/2];
        k/=2;
    }
    h[k] = t; 
}

// ✅ delete 구현 (sift-down)
element my_heap::delete_heap() {
    element t;//꺼낼 루트값 저장
    element temp;//마지막 노드 저장

    int parent, child;

    t= h[1];
    temp = h[csize];
    csize -- ;
    parent =1;
    child =2;

    while(child <= csize){
        if((child <csize) && (h[child].score <h[child +1].score)){
            child ++;
        }
        if(temp.score >= h[child].score){
            break;
        }
        h[parent] = h[child];
        parent = child;
        child *=2;
    }
    h[parent] = temp;
    return t;
}

int main() {
    my_heap h1;
    element temp;

    temp.set_data("Kim", 88);  h1.insert_heap(temp);
    temp.set_data("Lee", 77);  h1.insert_heap(temp);
    temp.set_data("Park", 98); h1.insert_heap(temp);
    temp.set_data("Choi", 74); h1.insert_heap(temp);
    temp.set_data("Ryu", 94);  h1.insert_heap(temp);
    temp.set_data("Cho", 85);  h1.insert_heap(temp);

    cout << "현재 원소 수: " << h1.h_size() << "\n\n";

    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}