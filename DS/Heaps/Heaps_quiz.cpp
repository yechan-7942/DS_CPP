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
    name = n;
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
    double sum_heap();       // 전체 score 합계
    double avg_heap();       // 전체 score 평균
    element max_heap();      // 최댓값 반환 (=peek)
    element min_heap();      // 최솟값 반환
    void print_heap();       // 전체 출력
    bool heap_full();
    bool heap_empty();
};

my_heap::my_heap() { csize = 0; }
bool my_heap::heap_empty() { return (csize == 0); }
bool my_heap::heap_full()  { return (csize >= HSIZE - 1); }
int  my_heap::h_size()     { return csize; }

// 끝에 추가 후 sift-up
void my_heap::insert_heap(element t){
    int k;
    csize++;
    k= csize;
    while((k!= 1) && (t.score > h[k/2].score)){
        h[k] = h[k/2];
        k = k/2;
    }
    h[k] =t;
}

// 루트 꺼내고 마지막 노드 sift-down
element my_heap::delete_heap() {
   element t;
   element tmp;
   int parent, child;

   t= h[1];
   tmp = h[csize];
   csize --;

   parent =1;
   child = 2;
   while(child <= csize){
    if((child <csize) && (h[child].score < h[child +1].score)){
        child ++;//right child 선택
    }
    if(tmp.score >= h[child].score){
        break;
    }
    h[parent] = h[child];
    parent = child;
    child = child *2;

   }
   h[parent] = tmp;
   return t;
}



// 전체 score 합산
double my_heap::sum_heap() {
    double sum=0;
    for(int i=1;i<=csize; i++){
        sum += h[i].score;
    } 
    return sum;

}

// 전체 score 평균
double my_heap::avg_heap() {
    return sum_heap()/csize;
}

// 최댓값 반환 (Max-heap에서 루트)
element my_heap::max_heap() {
        return h[1];

}

// 최솟값 반환 (배열 순회)
element my_heap::min_heap() {
    element min = h[1];
    for(int i=2; i <=csize ; i++){
        if(h[i].score < min.score){
            min = h[i];
        }
    }
    return min;
}

// 전체 원소 출력
void my_heap::print_heap() {
    for(int i =1; i <=csize; i++){
        cout << h[i].score << " " << h[i].name << endl;
    }
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

    cout << "=== 전체 출력 ===\n";
    h1.print_heap();

    cout << "\n=== 합계 / 평균 ===\n";
    cout << "합계: " << h1.sum_heap() << "\n";
    cout << "평균: " << h1.avg_heap() << "\n";

    cout << "\n=== 최대 / 최소 ===\n";
    cout << "최대: " << h1.max_heap().name << " : " << h1.max_heap().score << "\n";
    cout << "최소: " << h1.min_heap().name << " : " << h1.min_heap().score << "\n";

    cout << temp.name << " : " << temp.score << "\n";

    cout << "\n=== delete 전체 ===\n";
    while (h1.h_size() > 0) {
        temp = h1.delete_heap();
        cout << temp.name << " : " << temp.score << "\n";
    }

    return 0;
}