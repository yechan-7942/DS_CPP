#include <iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *left, *right;
    void set_data(string name, double score);
};

void node :: set_data(string s, double n){
    name =s;
    score = n;
}

class my_tree{
    public :
    int node_count;
    node *root;
    my_tree();
    int insert_root(node t);
    int insert_left(string tname, node tnode);
};

my_tree :: my_tree(){
    node_count =0;
    root = NULL;
}


int my_tree :: insert_root(node t){
    if(root != NULL){
        return 0;
    }
    node *p;
    p = new node;
    (*p) =t;
    p ->left = NULL;
    p ->right = NULL;
    root = p;
    node_count++;
    return 1;
}

int my_tree :: insert_left(string tname, node tnode){
    int result;
    result = node_insert_left(root,tname,tnode);
    if(result ==1){
        node_count++;
    }
    return result;

}

int node_insert_left(node *p,string tname, node tnode){
    if(p==NULL){
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
        p->left =t;
        return 1;
    }
    else{
        int result;
        result = node_insert_left(p->left, tname, tnode);
        if(result != 0){
            return result;
        }
        return node_insert_left(p->right, tname, tnode);
        }
    }



int main(){

}


