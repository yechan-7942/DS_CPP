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
    if (heap_full()) return;

    int i = ++csize;
    // 부모보다 크면 위로 올림
    while (i > 1 && h[i / 2].score < t.score) {
        h[i] = h[i / 2];
        i /= 2;
    }
    h[i] = t;
}

// ✅ delete 구현 (sift-down)
element my_heap::delete_heap() {
    element root = h[1];      // 루트(최댓값) 저장
    element last = h[csize--]; // 마지막 원소 꺼내고 size 줄임

    int i = 1, child;
    while (i * 2 <= csize) {
        child = i * 2; // left child

        // 오른쪽 자식이 더 크면 선택
        if (child < csize && h[child].score < h[child + 1].score)
            child++;

        if (last.score >= h[child].score) break;

        h[i] = h[child];
        i = child;
    }
    h[i] = last;

    return root;
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