#include <iostream>
#include <string>
using namespace std;

class bst_node {
public:
    string s_id;
    string name;
    double score;
    bst_node *left, *right;

    bst_node() {
        s_id = "";
        name = "";
        score = 0.0;
        left = right = NULL;
    }

    bst_node(string s1, string s2, double n) {
        s_id = s1;
        name = s2;
        score = n;
        left = right = NULL;
    }

    void set_data(string s1, string s2, double n) {
        s_id = s1;
        name = s2;
        score = n;
    }
};

class bst_tree {
    bst_node *root;
    int csize;

public:
    bst_tree() {
        root = NULL;
        csize = 0;
    }

    void insert_node(bst_node t);
    void show_inorder(bst_node *p);
    bst_node* search(string tid);
    void show_all() { show_inorder(root); }
};

bst_node* bst_tree::search(string tid) {
    bst_node *p = root;
    while (p != NULL) {
        if (p->s_id == tid) return p;
        if (p->s_id < tid) p = p->right;
        else p = p->left;
    }
    cout << "The key " << tid << " does not exist." << endl;
    return NULL;
}

void bst_tree::insert_node(bst_node t) {
    bst_node *p = root;
    bst_node *tmp = new bst_node(t.s_id, t.name, t.score);

    if (root == NULL) {
        root = tmp;
        return;
    }

    while (true) {
        if (p->s_id == t.s_id) {
            cout << "Insertion Failed: the Key " << t.s_id << " already exists." << endl;
            delete tmp;
            return;
        }
        if (p->s_id < t.s_id) {
            if (p->right == NULL) {
                p->right = tmp;
                return;
            }
            p = p->right;
        } else {
            if (p->left == NULL) {
                p->left = tmp;
                return;
            }
            p = p->left;
        }
    }
}

void bst_tree::show_inorder(bst_node *p) {
    if (p == NULL) return;
    show_inorder(p->left);
    cout << p->s_id << " " << p->name << " " << p->score << endl;
    show_inorder(p->right);
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

    cout << "\nInorder Traversal:" << endl;
    t1.show_all();

    // 검색 테스트
    bst_node* found = t1.search("21900136");
    if (found != NULL) {
        cout << "Found: " << found->s_id << " " << found->name << " " << found->score << endl;
    }

    return 0;
}
