#include<iostream>
using namespace std;

class node{
    public : 
    string name;
    double score;
    node *left , *right;
    void set_data(string s, double n);

};
void node :: set_data(string s, double n){
    name = s;
    score = n;
}

class my_tree{
    public : 
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(node *p , string tname , node t);
    int insert_right(node *p , string tname , node t);

    double score_sum();
    double score_average();
    void print_data_inorder(); //inorder순서로 모든 node의 값 출력
    void print_data_preorder();
    void print_data_postorder();
};

my_tree :: my_tree(){
    node_count = 0;
    root = NULL;
}

int my_tree::insert_left(node *p, string tname, node tnode) {
    if (p == NULL) return 0; // 탐색 실패

    if (p->name == tname) {
        if (p->left != NULL) return -1; // 이미 왼쪽 자식이 있으면 실패

        node *newNode = new node;
        *newNode = tnode; // 값 복사
        newNode->left = NULL;
        newNode->right = NULL;
        p->left = newNode;
        node_count++;
        return 1; // 성공
    }
    else {
        // 왼쪽 서브트리 탐색
        int result = insert_left(p->left, tname, tnode);
        if (result != 0) return result;

        // 오른쪽 서브트리 탐색
        return insert_left(p->right, tname, tnode);
    }
}

int my_tree::insert_right(node *p, string tname, node tnode) {
    if (p == NULL) return 0; // 탐색 실패

    if (p->name == tname) {
        if (p->right != NULL) return -1; // 이미 왼쪽 자식이 있으면 실패

        node *newNode = new node;
        *newNode = tnode; // 값 복사
        newNode->right = NULL;
        newNode->left = NULL;
        p-> right = newNode;
        node_count++;
        return 1; // 성공
    }
    else {
        // 왼쪽 서브트리 탐색
        int result = insert_left(p->right, tname, tnode);
        if (result != 0) return result;

        // 오른쪽 서브트리 탐색
        return insert_right(p->left, tname, tnode);
    }
}

double my_tree :: score_sum(){
    return sum_allnodes(root);
}
double sum_allnodes(node *p){
    if( p == NULL){
        return 0;
    }
    return sum_allnodes(p ->left) + sum_allnodes(p->right) + p->score;
}


