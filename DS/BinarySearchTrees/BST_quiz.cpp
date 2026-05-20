#include <iostream>
using namespace std;

class bst_node {
public:
    string s_id;
    string name;
    double score;
    bst_node* left, * right;
    bst_node() { left = NULL; right = NULL; }
    bst_node(string s1, string s2, double n) {
        s_id = s1; name = s2; score = n;
        left = NULL; right = NULL;
    }
    void set_data(string s1, string s2, double n) {
        s_id = s1; name = s2; score = n;
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
};

// ============================================
// 문제 1 : insert_node 구현
// ============================================
void bst_tree::insert_node(bst_node t) {
    bst_node *p;
    bst_node *tmp = new bst_node;
    (*tmp) = t;
    tmp->left = NULL;
    tmp ->right = NULL;
     if(root == NULL){
        root = tmp;
        return;
     }
      p = root;
      while(1){
        if(p->s_id == t.s_id){
            cout << "오류";
            return ;
        }
        if(p->s_id < t.s_id){
            if( p->right == NULL){
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
                    return ;
                }
                else{
                    p= p->left;
                }
            }
        
      }
}

// ============================================
// 문제 2 : search 구현
// ============================================
bst_node bst_tree::search(string tid) {
    bst_node *p;
    p=root;
    if(root == NULL){
        bst_node tmp;
        tmp.s_id = "00000";
        tmp.name = "none";
        tmp.score = -1;
        return tmp;
    }
    while(1){
        if(p->s_id == tid){
            return (*p);
        }
        if(p->s_id < tid){
            if(p->right == NULL){
                cout << "존재 X"<< endl;
                bst_node tmp;
                tmp.set_data("00000" , "NONe", -1);
                return tmp;
            }
            else{
                p= p->right;
            }
        }
        else{
            if(p->left == NULL){
                bst_node tmp;
                tmp.set_data("0000", "None" ,-1);
                return tmp;
            }
            else{
                p= p->left;
            }
        }
    }
}

// ============================================
// show_inorder (완성된 코드 - 문제 아님)
// ============================================
void inorder_helper(bst_node* p) {
    if (p == NULL) return;
    inorder_helper(p->left);
    cout << p->s_id << " : " << p->name << " : " << p->score << endl;
    inorder_helper(p->right);
}
void bst_tree::show_inorder() {
    inorder_helper(root);
}

// ============================================
// main
// ============================================
int main() {
    bst_node temp;
    bst_tree t1;

    temp.set_data("21900013", "Kim", 6.5);
    t1.insert_node(temp);
    temp.set_data("21900136", "Lee", 8.8);
    t1.insert_node(temp);
    temp.set_data("21900333", "Park", 9.2);
    t1.insert_node(temp);
    temp.set_data("21800442", "Choi", 7.1);
    t1.insert_node(temp);
    temp.set_data("21900375", "Ryu", 5.4);
    t1.insert_node(temp);
    temp.set_data("21700248", "Cho", 6.3);
    t1.insert_node(temp);

    cout << "\n\n Node List : inorder sequence \n";
    t1.show_inorder();

    string s_key = "21800442";
    temp = t1.search(s_key);
    cout << "\n -- " << s_key << "'s record ---" << endl;
    cout << " Student ID : " << temp.s_id << endl;
    cout << " Student Name : " << temp.name << endl;
    cout << " Score : " << temp.score << endl;

    return 0;
}