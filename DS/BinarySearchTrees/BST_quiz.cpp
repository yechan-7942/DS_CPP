#include <iostream>
using namespace std;

class bst_node {
public:
    string phone;    // key (전화번호)
    string name;
    string birthday;
    bst_node* left, * right;
    bst_node() { left = NULL; right = NULL; }
    void set_data(string p, string n, string b) {
        phone = p; name = n; birthday = b;
    }
};

class bst_tree {
    bst_node* root;
    int csize;
public:
    bst_tree() { root = NULL; csize = 0; }
    void insert_node(bst_node t);
    bst_node search(string tid);
    void show_inorder();
    int size() { return csize; }
    bool empty() { return root == NULL; }
};

void bst_tree :: insert_node(bst_node t){
    bst_node *p;
    bst_node *tmp;

    tmp = new bst_node;
    *tmp = t;
    tmp ->left = NULL;
    tmp ->right = NULL;
    if(root == NULL){
        root = tmp;
        return ;
    }
    p = root;
    while(1){
        
    }
}


int main() {
    bst_tree t1;
    bst_node temp;
    int choice;
    string phone, name, birthday;

    while (1) {
        cout << "\n===== 전화번호부 메뉴 =====" << endl;
        cout << "1. 새로운 원소 추가" << endl;
        cout << "2. 원소 조회" << endl;
        cout << "3. 전체 목록 보기" << endl;
        cout << "4. 종료" << endl;
        cout << "명령 선택 : ";
        cin >> choice;

        if (choice == 1) {
            // ⬜ (1) 전화번호, 이름, 생일 입력받고 insert
        

        }
        else if (choice == 2) {
            // ⬜ (2) 전화번호 입력받고 search 후 결과 출력

        }
        else if (choice == 3) {
            // ⬜ (3) 전체 목록 출력

        }
        else if (choice == 4) {
            // ⬜ (4) 종료 메시지 출력 후 종료

        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }
    }
    return 0;
}