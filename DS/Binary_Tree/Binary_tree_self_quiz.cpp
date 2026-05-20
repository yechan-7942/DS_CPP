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
    int node_count=0;
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
        if(root !=NULL){
            return 0;
        }
        node *p = new node;
        (*p) = t;
        p->left = NULL;
        p->right = NULL;
        root = p;
        node_count ++;
        return 1;
    }

    // tname 노드의 왼쪽에 삽입
    int insert_left(string tname, node tnode) {
       int result;
       result = insert_left_node(root, tname, tnode);
       if(result ==1){
        node_count ++;
       }
        return result;
       
    }

    int insert_left_node(node *p, string tname, node tnode){
        if(p == NULL){
            return 0;
        }
        if(p->name == tname){
            if(p ->left != NULL){
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
        result = insert_left_node(p->left, tname, tnode);
        if(result !=0){
            return result;
        }
        return insert_left_node(p->right , tname, tnode);
        }
    }

    

    // tname 노드의 오른쪽에 삽입
    int insert_right(string tname, node tnode) {
        int result; 
        result = insert_right_node(root , tname, tnode);
        if(result == 1){
            node_count ++;
        }
        return result;
        
    }

    int insert_right_node(node *p, string tname, node tnode){
       if(p==NULL){
        return 0;
       }
       if(p->name == tname){
        if(p->right != NULL){
            return -1;
        }
        node *t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
       }
       else{
        int result;
        result = insert_right_node(p->left, tname, tnode);
        if(result != 0){
            return result;
        }
        return insert_right_node(p->right, tname, tnode);
       }
    }
    
    

    // tname 노드 삭제
      int delete_node(node* p, string tname) {
    if (p == NULL) return 0;

    if (p->left && p->left->name == tname) {
        if (p->left->left == NULL && p->left->right == NULL) {
            delete p->left;
            p->left = NULL;
            return 1;
        }
        return -1; // 자식 있으면 아직 처리 안 함
    }
    if (p->right && p->right->name == tname) {
        if (p->right->left == NULL && p->right->right == NULL) {
            delete p->right;
            p->right = NULL;
            return 1;
        }
        return -1;
    }

    int result = delete_node(p->left, tname);
    if (result != 0) return result;
    return delete_node(p->right, tname);
}
  

    // 모든 노드 score 합
    double score_sum() {
       return  sum_allnodes(root);
    }

   
    
    double sum_allnodes(node *p){
         if(p== NULL){
            return 0;
        }
        return sum_allnodes(p->right) + sum_allnodes(p->left) + p->score;
    }

    // 모든 노드 score 평균
    double score_average() {
        return score_sum() / node_count ;
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

    // 특정 점수 이상인 노드 출력
void print_above_score(double threshold) {
    search_above(root, threshold);
}

void search_above(node *p, double threshold) {
    if (p == NULL) return;
    if (p->score >= threshold) {
        cout << p->name << " : " << p->score << endl;
    }
    search_above(p->left, threshold);
    search_above(p->right, threshold);
}

// 특정 점수 이상인 노드 개수
int count_above_score(double threshold) {
    return count_above(root, threshold);
}

int count_above(node *p, double threshold) {
    if(p==NULL){
        return 0;
    }
    int count =0;
    if(p->score >= threshold){
        count ++;
    }
    return count + (p->right,threshold) + count_above(p->left, threshold);
}

double average_above_score(double threshold) {
    int cnt = count_above_score(threshold);
    if (cnt == 0) return 0;
    return sum_above(root, threshold) / cnt;
}

double sum_above(node *p, double threshold) {
    if (p == NULL) return 0;
    double s = 0;
    if (p->score >= threshold) {
        s = p->score;
    }
    return s + sum_above(p->left, threshold) + sum_above(p->right, threshold);
}
};

/*
queue<node *> q;
if(root == NULL){
return ;
}
q.push(root);
if(q.emty()){
return ;
}
node *t = q.front();
q.pop();
cout << t->name << "  :  "  << t->score << endl;
if(t->left != NULL){
q.push(t->left)
}
if(t->right == NULl){
q.push(t->right);
}
}
*/

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


// ========================
// main
// ========================
int main() {
    my_tree thetree;
    node tmp;

    // 트리 구성 테스트
    tmp.set_data("Kim", 81);
    thetree.insert_root(tmp);

    tmp.set_data("Lee", 65);
    thetree.insert_left("Kim", tmp);

    tmp.set_data("Park", 83);
    thetree.insert_right("Kim", tmp);


    cout << "score : " << thetree.score_sum() << "  average : " << thetree.score_average() << endl;

    cout << "\nNon-recursive Inorder:\n";
    thetree.nonrecursive_inorder();

    cout << "\nLevel-Order:\n";
    thetree.print_data_levelorder();

    cout << "80점 이상:\n";
thetree.print_above_score(80.0);

cout << "80점 이상 인원수: " << thetree.count_above_score(80.0) << endl;
cout << "80점 이상 평균: " << thetree.average_above_score(80.0) << endl;

    return 0;
}