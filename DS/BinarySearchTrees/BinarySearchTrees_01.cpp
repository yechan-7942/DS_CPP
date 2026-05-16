#include<iostream>
using namespace std;

class bst_node{
    public :
    string s_id;
    string name;
     double score;
     bst_node *left, *right;
     bst_node();
     bst_node(string s1, string s2, double n);
     void set_data(string s1, string s2, double n);
};

class bst_tree{
    bst_node *root;
    int csize;

    public :
    bst_tree();
    void insert_node(bst_node t);
    void show_inorder();
    bst_node search(string tid);
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
        if(p->s_id == t.s_id){
            cout << "Insertion Failde : the Key " << t.s_id << "already exists." <<endl;
            return ;

        }
        if(p->s_id <t.s_id){
            if(p->right == NULL){
                p->right = tmp;
                return ;
            }
            else{
                p= p->right;
            }
        }
        else{
            if(p->left == NULL){
                p->left = tmp;
                return;
            }
        
            else p = p->left;
            
        
    }
}
}

int main() {
    bst_node temp;
    bst_tree t1;

    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);

    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);

    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);

    // 중복 key 테스트
    temp.set_data("21900013", "Hong", 5.0);
    t1.insert_node(temp);

    return 0;
}