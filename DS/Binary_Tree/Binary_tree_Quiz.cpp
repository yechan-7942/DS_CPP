#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// ========================
// Node 구조체
// ========================
struct node {
    string name;
    double score;
    node *left, *right;

    void set_data(string n, double s) {
        name = n;
        score = s;
        left = right = NULL;
    }
};

// ========================
// my_tree 클래스
// ========================
class my_tree {
public:
    int node_count;
    node *root;

    my_tree() {
        node_count = 0;
        root = NULL;
    }

    // ========================
    // 네가 채워야 할 함수들
    // ========================

    // root에 노드 삽입
    int insert_root(node t) {
        if(root != NULL){
            return 0;
        }

        node *p = new node;
        (*p)= t;
        p->left = NULL;
        p->right = NULL;
        root = p;
        node_count ++;
        return 1;
    }

    // tname 노드의 왼쪽에 삽입
    int insert_left(string tname, node t) {
        int result;
        result = node_insert_left(root, tname, t);
        if(result ==1){
            node_count++;
        }
        return result;
    }

    int node_insert_left(node *p,string tname,node tnode){
        if(p == NULL){
            return 0;
        }
        if(p->name == tname){
            if(p->left !=NULL){
                return -1;
            }
            node *t = new node;
            (*t) = tnode;
            t->left = NULL;
            t->right = NULL;
            p->left = t;
            return 1;
        }
        else{
            int result;
            result = node_insert_left(p->left, tname, tnode);
            if(result !=0){
                return result;
            }
            return node_insert_left(p->right, tname, tnode);
        }

    }

    // tname 노드의 오른쪽에 삽입
    int insert_right(string tname, node t) {
        int result;
        result = node_insert_right(root, tname, t);
        if(result =1){
            node_count++;
        }
        return result;
    }
    
    int node_insert_right(node *p, string tname, node tnode){
        if(p == NULL){
            return 0;
        }
        if(p->name == tname){
        node *t = new node;
        *t = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t; 
        return 1;
        }
        else{
            int result;
            result = node_insert_right(p->left ,tname, tnode);
            if(result !=0){
                return result;
            }
            return node_insert_right(p->right, tname, tnode);
        }
    }

    // tname 노드 삭제
    void delete_node(string tname) {
        // TODO
    }

    // 모든 노드 score 합
    double score_sum() {
        // TODO
    }

    // 모든 노드 score 평균
    double score_average() {
        // TODO
    }

    // ========================
    // 이미 구현된 함수들 (PDF 기반)
    // ========================

    // non-recursive inorder
    void nonrecursive_inorder() {
        stack<node*> s1;
        node *t = root;
        while (1) {
            while (t != NULL) {
                s1.push(t);
                t = t->left;
            }
            if (s1.empty()) return;
            t = s1.top(); s1.pop();
            cout << t->name << " : " << t->score << endl;
            t = t->right;
        }
    }

    // level-order traversal
    void print_data_levelorder() {
        queue<node*> q;
        if (root == NULL) return;
        q.push(root);
        while (1) {
            if (q.empty()) return;
            node *t = q.front(); q.pop();
            cout << t->name << " : " << t->score << endl;
            if (t->left != NULL) q.push(t->left);
            if (t->right != NULL) q.push(t->right);
        }
    }
};

// ========================
// Tree Copy
// ========================
node* make_copy(node *p) {
    if (p == NULL) return NULL;
    node *t = new node;
    *t = *p;
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);
    return t;
}

void copy_tree(my_tree &t1, my_tree t2) {
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}

// ========================
// Equality Test
// ========================
bool equal_test(node *p1, node *p2) {
    if (p1 == NULL && p2 == NULL) return true;
    if (p1 == NULL || p2 == NULL) return false;
    if (p1->name != p2->name) return false;
    if (p1->score != p2->score) return false;
    return equal_test(p1->left, p2->left) && equal_test(p1->right, p2->right);
}

bool equal_tree(my_tree t1, my_tree t2) {
    if (t1.node_count != t2.node_count) return false;
    return equal_test(t1.root, t2.root);
}

// ========================
// main
// ========================
int main() {
    my_tree thetree;
    node tmp;

    // 트리 구성 테스트
    tmp.set_data("Kim", 8.1);
    thetree.insert_root(tmp);

    tmp.set_data("Lee", 6.5);
    thetree.insert_left("Kim", tmp);

    tmp.set_data("Park", 8.3);
    thetree.insert_right("Kim", tmp);

    cout << "\nNon-recursive Inorder:\n";
    thetree.nonrecursive_inorder();

    cout << "\nLevel-Order:\n";
    thetree.print_data_levelorder();

    return 0;
}