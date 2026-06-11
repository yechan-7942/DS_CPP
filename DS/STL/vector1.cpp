#include <iostream>
#include <vector>
#include <algorithm> // sort, find, reverse 등
using namespace std;

int main() {

    // ── 1. 선언 및 초기화 ──────────────────────────────────────
    vector<int> v1;                     // 빈 벡터
    vector<int> v2(5);                  // 크기 5, 기본값 0
    vector<int> v3(5, 10);             // 크기 5, 모두 10으로 초기화
    vector<int> v4 = {1, 2, 3, 4, 5}; // 초기화 리스트

    // ── 2. 삽입 ───────────────────────────────────────────────
    v1.push_back(10); // 맨 뒤에 추가
    v1.push_back(20);
    v1.push_back(30);
    // v1 = {10, 20, 30}

    v1.insert(v1.begin() + 1, 15); // 인덱스 1 위치에 15 삽입
    // v1 = {10, 15, 20, 30}

    // ── 3. 접근 ───────────────────────────────────────────────
    cout << "v1[0] = " << v1[0] << "\n";       // 인덱스 접근 (범위 검사 없음)
    cout << "v1.at(1) = " << v1.at(1) << "\n"; // at() 사용 (범위 초과 시 예외 발생)
    cout << "front = " << v1.front() << "\n";  // 첫 번째 원소
    cout << "back  = " << v1.back() << "\n";   // 마지막 원소

    // ── 4. 크기 관련 ──────────────────────────────────────────
    cout << "size     = " << v1.size() << "\n";     // 현재 원소 수
    cout << "capacity = " << v1.capacity() << "\n"; // 할당된 메모리 크기
    cout << "empty?   = " << v1.empty() << "\n";    // 비어 있으면 1

    // ── 5. 삭제 ───────────────────────────────────────────────
    v1.pop_back(); // 맨 뒤 원소 제거
    // v1 = {10, 15, 20}

    v1.erase(v1.begin() + 1); // 인덱스 1 원소 제거
    // v1 = {10, 20}

    // ── 6. 순회 ───────────────────────────────────────────────
    vector<int> v5 = {3, 1, 4, 1, 5, 9, 2, 6};

    // 범위 기반 for문
    cout << "v5: ";
    for (int x : v5) cout << x << " ";
    cout << "\n";

    // 이터레이터 사용
    cout << "iterator: ";
    for (auto it = v5.begin(); it != v5.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    // ── 7. 정렬 / 탐색 ────────────────────────────────────────
    sort(v5.begin(), v5.end());                  // 오름차순 정렬
    sort(v5.begin(), v5.end(), greater<int>());  // 내림차순 정렬

    // 값 탐색 (find)
    auto it = find(v5.begin(), v5.end(), 5);
    if (it != v5.end())
        cout << "5 found at index: " << (it - v5.begin()) << "\n";

    // ── 8. 기타 ───────────────────────────────────────────────
    reverse(v5.begin(), v5.end()); // 뒤집기

    v5.resize(3); // 크기를 3으로 줄임 (남은 원소 삭제)
    v5.clear();   // 모든 원소 제거 (size=0, capacity 유지)

    // 2차원 벡터
    vector<vector<int>> matrix(3, vector<int>(3, 0)); // 3x3 행렬, 0으로 초기화
    matrix[1][1] = 7;

    cout << "matrix[1][1] = " << matrix[1][1] << "\n";

    return 0;
}
