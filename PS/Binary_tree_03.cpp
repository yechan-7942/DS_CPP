#include <iostream>
using namespace std;

// 노드 구조체 정의
struct Node {
    int data;
    Node* left;
    Node* right;

    // 생성자
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// 트리에 노드 삽입 (BST 방식)
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// 중위 순회 (Inorder Traversal)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// 전위 순회 (Preorder Traversal)
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회 (Postorder Traversal)
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    // 트리에 값 삽입
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "중위 순회: ";
    inorder(root);
    cout << endl;

    cout << "전위 순회: ";
    preorder(root);
    cout << endl;

    cout << "후위 순회: ";
    postorder(root);
    cout << endl;

    return 0;
}
