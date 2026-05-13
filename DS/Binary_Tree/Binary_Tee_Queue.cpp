#include <iostream>
#include<queue>
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

int my_tree::insert_root(node t) {
    if (root != NULL) return 0;
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count++;
    return 1;
}
int node_insert_left(node *p, string tname, node tnode);
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);
// ──────────────────────

int my_tree::insert_left(string tname, node tnode) {
    int result;
    result = node_insert_left(root, tname, tnode);
    if (result == 1) node_count++;
    return result;
}

int node_insert_left(node *p, string tname, node tnode) {
    if (p == NULL) return 0;
    if (p->name == tname) {
        if (p->left != NULL) return -1;
        node *t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }
    else {
        int result;
        result = node_insert_left(p->left, tname, tnode);
        if (result != 0) return result;
        return node_insert_left(p->right, tname, tnode);
    }
}

int my_tree::insert_right(string tname, node tnode) {
    int result;
    result = node_insert_right(root, tname, tnode);
    if (result == 1) node_count++;
    return result;
}

int node_insert_right(node *p, string tname, node tnode) {
    if (p == NULL) return 0;
    if (p->name == tname) {
        if (p->right != NULL) return -1;
        node *t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }
    else {
        int result;
        result = node_insert_right(p->left, tname, tnode);  // 왼쪽부터
        if (result != 0) return result;
        return node_insert_right(p->right, tname, tnode);
    }
}

double my_tree::score_sum() {
    return sum_allnodes(root);
}

double sum_allnodes(node *p) {
    if (p == NULL) return 0;
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

void my_tree::print_data_levelorder() {
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << current->name << " : " << current->score << endl;

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
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