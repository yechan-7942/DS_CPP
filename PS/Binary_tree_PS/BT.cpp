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
    }


    return root;
}

void clearTree(){}
void inorderprint(){}

int main(){

    return 0;
}