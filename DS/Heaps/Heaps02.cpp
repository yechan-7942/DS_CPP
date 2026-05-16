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
    csize++;
    k = csize ;

    while((k!=1) && (t.score > h[k/2].score)){
        h[k] = h[k/2];//부모 노도를 내 자리(k)로 복사해서 내려옴 > 내가 올라갈 자리를 비우는 작업
        k/=2;//나(k)를 부모 위치로 이동 > 다음 루프에서 그 위 부모랑 비교하기 위해 
    }
    h[k]= t;
}

// ✅ delete 구현 (sift-down)
element my_heap::delete_heap() {
    
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