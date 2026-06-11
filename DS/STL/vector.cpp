#include<iostream>
#include<vector>

using namespace std;

int main(){

    // 기본 생성 및 push_back
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // size, capacity
    cout << "size: " << v1.size() << endl;
    cout << "capacity: " << v1.capacity() << endl;

    // 인덱스 접근
    cout << "v1[0]: " << v1[0] << endl;
    cout << "v1.at(1): " << v1.at(1) << endl;

    // front, back
    cout << "front: " << v1.front() << endl;
    cout << "back: " << v1.back() << endl;

    // 반복문으로 출력
    cout << "모든 원소: ";
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }
    cout << endl;

    // 범위 기반 for 루프
    cout << "range-based for: ";
    for(int x : v1){
        cout << x << " ";
    }
    cout << endl;

    // pop_back
    v1.pop_back();
    cout << "pop_back 후 size: " << v1.size() << endl;

    // insert (인덱스 1 위치에 99 삽입)
    v1.insert(v1.begin() + 1, 99);
    cout << "insert 후: ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    // erase (인덱스 0 삭제)
    v1.erase(v1.begin());
    cout << "erase 후: ";
    for(int x : v1) cout << x << " ";
    cout << endl;

    // clear
    v1.clear();
    cout << "clear 후 size: " << v1.size() << endl;
    cout << "empty: " << v1.empty() << endl;

    // 초기값으로 생성
    vector<int> v2(5, 7); // 크기 5, 모두 7로 초기화
    cout << "v2: ";
    for(int x : v2) cout << x << " ";
    cout << endl;

    return 0;
}
