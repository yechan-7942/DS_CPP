#include<iostream>
#include<queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* makeTree(int *list ,int s){
    if(s ==0){
        return nullptr;
    }
    queue <Node *> q;
    Node *root = new Node(list[0]);

    q.push(root);

    int i = 1;
    while(i<s){
        Node *cur = q.front();
        q.pop();
        if(i<s){
            cur ->left = new Node(list[i]);
            q.push(cur->left);
            i++;
        }
        if(i<s){
            cur ->right = new Node(list[i]);
            q.push(cur->right);
            i++;
        }
    }
    return root;
}

void clearTree(Node *root){
    if(root == nullptr){
        return ;
    }
    clearTree(root ->left);
    clearTree(root ->right);
    delete root;
}

void inorderprint(Node *root){
    if(root== nullptr){
        return;
    }
    inorderprint(root ->left);
    cout << root ->data << " ";
    inorderprint(root ->right);
}

int main(){
    int s;
    cin >> s;
    int *list = new int[s];
    
    return 0;
}