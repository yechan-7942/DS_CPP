#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    string name;
    double score;
    node *left, *right;
    void set_data(string name, double score);
};

void node::set_data(string s, double n) {
    name = s;
    score = n;
}

class my_tree {
public:
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node tnode);
    int insert_right(string tname, node tnode);
    double score_sum();
    void print_data_levelorder();
};

my_tree::my_tree() {
    node_count = 0;
    root = NULL;
}

// ──────────────────────────────────────────
// [문제 1] insert_root 구현
// - root가 이미 있으면 0 반환
// - 새 노드 동적할당 후 root로 설정
// - 성공 시 node_count++ 후 1 반환
// ──────────────────────────────────────────
int my_tree::insert_root(node t) {
    if(root != NULL){
        return 0;
    }
    node *p;
    p = new node;
    (*p) = t;

    root = p;
    p->left = NULL;
    p->right = NULL;
    node_count ++;
    return 1;

}

int node_insert_left(node *p, string tname, node tnode);
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);

int my_tree::insert_left(string tname, node tnode) {
    int result;
    result = node_insert_left(root, tname, tnode);
    if (result == 1) node_count++;
    return result;
}

// ──────────────────────────────────────────
// [문제 2] node_insert_left 구현
// - p == NULL이면 0 반환
// - p->name == tname이면 왼쪽 자식에 삽입
//   (이미 있으면 -1 반환)
// - 없으면 왼쪽, 오른쪽 서브트리 재귀 탐색
// ──────────────────────────────────────────
int node_insert_left(node *p, string tname, node tnode) {
    if(p== NULL){
        return 0;
    }
    if(p->name == tname){
        if(p->left != NULL){
            return -1;
        }
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else{
     int result = node_insert_left(p->left, tname, tnode);
        if(result !=0){
            return result;
        }
        return node_insert_left(p->right, tname, tnode);
    }
}


int my_tree::insert_right(string tname, node tnode) {
    int result;
    result = node_insert_right(root, tname, tnode);
    if (result == 1) node_count++;
    return result;
}

// ──────────────────────────────────────────
// [문제 3] node_insert_right 구현
// - node_insert_left와 동일한 구조
// - 단, 오른쪽 자식에 삽입
// ──────────────────────────────────────────
int node_insert_right(node *p, string tname, node tnode){
    if(p == NULL){
        return -1;
    }
    if(p->name == tname){
        node *t = new node;
        (*t) = tnode;
        t->left =NULL;
        t->right =NULL;
        p->right = t;
        return 1;
    }
    else{
        int result = node_insert_right(p->left, tname, tnode);

        if(result != 0){
            return result;
        }

        return node_insert_right(p->right, tname, tnode);
    }
}

double my_tree::score_sum() {
    return sum_allnodes(root);
}

// ──────────────────────────────────────────
// [문제 4] sum_allnodes 구현
// - 재귀로 모든 노드의 score 합산
// - p == NULL이면 0 반환
// ──────────────────────────────────────────
double sum_allnodes(node *p) {
    /* TODO */
}

// ──────────────────────────────────────────
// [문제 5] print_data_levelorder 구현
// - queue를 사용한 레벨 순서 출력
// - root가 NULL이면 바로 return
// - 각 노드: cout << name << " : " << score << endl
// ──────────────────────────────────────────
void my_tree::print_data_levelorder() {
    /* TODO */
}

int main() {
    my_tree thetree;
    node n;

    n.set_data("Kim", 8.1);
    thetree.insert_root(n);

    n.set_data("Lee", 6.5);
    thetree.insert_left("Kim", n);

    n.set_data("Park", 8.3);
    thetree.insert_right("Kim", n);

    n.set_data("Choi", 7.2);
    thetree.insert_left("Lee", n);

    n.set_data("Ryu", 9.0);
    thetree.insert_right("Lee", n);

    n.set_data("Cho", 7.7);
    thetree.insert_left("Park", n);

    cout << "Score Sum : " << thetree.score_sum() << "\n";
    cout << "print inorder " << endl;
    thetree.print_data_levelorder();

    return 0;
}