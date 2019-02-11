#include <iostream>

using namespace std;

class Node {
   public:
    int key;

    Node* parent;
    Node* left;
    Node* right;

    Node(int key) : key(key), parent(NULL), left(NULL), right(NULL) {}
};

Node* minimum(Node* root) {
    if (root == NULL)
        return NULL;

    Node* node = root;
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* maximum(Node* root) {
    if (root == NULL)
        return NULL;

    Node* node = root;
    while (node->right != NULL)
        node = node->right;
    return node;
}

Node* find_node(Node* node, int key) {
    if (node == NULL)
        return NULL;

    Node* tmp = node;
    while (tmp != NULL) {
        if (tmp->key == key)
            return tmp;
        else if (tmp->key > key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return NULL;
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << ' ' << root->key;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << ' ' << root->key;
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << ' ' << root->key;
}

Node* successor(Node* node) {
    if (node == NULL)
        return NULL;

    if (node->right != NULL)
        return minimum(node->right);

    Node* target = node->parent;
    Node* tmp = node;
    while (target != NULL && target->right == tmp) {
        tmp = tmp->parent;
        target = target->parent;
    }
    return target;
}

Node* predecessor(Node* node) {
    if (node == NULL)
        return NULL;

    if (node->left != NULL)
        return maximum(node->left);

    Node* target = node->parent;
    Node* tmp = node;
    while (target != NULL && target->left == tmp) {
        tmp = tmp->parent;
        target = target->parent;
    }
    return target;
}

void insert_node(Node** root, int key) {
    Node* new_node = new Node(key);

    if (*root == NULL) {  // tree is empty
        *root = new_node;
        return;
    }

    Node* parent = NULL;
    Node* node = *root;
    while (node != NULL) {
        parent = node;
        if (new_node->key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    new_node->parent = parent;
    if (new_node->key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
}

void _delete_node(Node* target) {
    if (target->left == NULL && target->right == NULL) {
        if (target->parent->left == target)
            target->parent->left = NULL;
        else
            target->parent->right = NULL;

        delete target;
    } else if (target->left != NULL && target->right != NULL) {
        Node* node = successor(target);
        target->key = node->key;
        _delete_node(node);
    } else {
        Node* parent = target->parent;
        Node* child;

        if (target->left != NULL)
            child = target->left;
        else
            child = target->right;

        child->parent = parent;
        if (parent->left == target)
            parent->left = child;
        else
            parent->right = child;

        delete target;
    }
}

void delete_node(Node** root, int key) {
    if (*root == NULL)
        return;

    Node* target = find_node(*root, key);
    if (target == NULL)
        return;

    _delete_node(target);
}

int main() {
    Node* root = NULL;

    insert_node(&root, 6);
    insert_node(&root, 2);
    insert_node(&root, 8);
    insert_node(&root, 1);
    insert_node(&root, 4);
    insert_node(&root, 3);
    insert_node(&root, 5);

    Node* min = minimum(root);
    Node* max = maximum(root);
    cout << "min: " << min->key << '\n';
    cout << "max: " << max->key << '\n';

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << "\n\n";

    delete_node(&root, 2);
    min = minimum(root);
    max = maximum(root);

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
}

