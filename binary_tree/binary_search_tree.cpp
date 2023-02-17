#include <bits/stdc++.h>
using namespace std;

class node {
public:    
    int value;
    node *left;
    node *right;

    node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    node *root;

    BST()
    {
        root = NULL;
    }

    node* create_new_node(int value)
    {
        node* new_node = new node(value);
        return new_node;
    }

    void BFS()
    {
        if (root == NULL) {
            return;
        }
        queue<node*> q;
        q.push(root);

        while(!q.empty()) {
            node* a = q.front();
            q.pop();
            int l = -1, r = -1;
            if (a->left != NULL) {
                l = a->left->value;
                q.push(a->left);
            }
            if(a->right != NULL) {
                r = a->right->value;
                q.push(a->right);
            }
            cout << "Node value: " << a->value << " Left child: " << l << " Right child: " << r << "\n";
        }
    }

    void Insert(int value)
    {
        node *new_node = create_new_node(value);

        if (root == NULL) {
            root = new_node;
            return;
        }

        node *current = root;
        node *parent = NULL;

        while (current != NULL) {
            if (new_node->value > current->value) {
                parent = current;
                current = current->right;
            }
            else {
                parent = current;
                current = current->left;
            }
        }

        if (new_node->value > parent->value) {
            parent->right = new_node;
        }
        else {
            parent->left = new_node;
        }
    }

    bool Search(int value)
    {
        node *current = root;

        while (current != NULL) {
            if (value > current->value) {
                current = current->right;
            }
            else if (value < current->value) {
                current = current->left;
            }
            else {
                return true;
            }
        }

        return false;
    }

    void Delete(int value)
    {
        node *current = root;
        node *parent = NULL;

        while (current != NULL) {
            if (value > current->value) {
                parent = current;
                current = current->right;
            }
            else if (value < current->value) {
                parent = current;
                current = current->left;
            }
            else {
                break;
            }
        }

        if (current == NULL) {
            cout << "Value is not present in BST\n";
            return;
        }

        // case 1 both child is NULL
        if (current->left == NULL && current->right == NULL) {
            if (parent->left != NULL && parent->left->value == current->value) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
            delete current;
            return;
        }

        // case 2 node has only one child
        if (current->left == NULL && current->right != NULL) {
            if (parent->left != NULL && parent->left->value == current->value) {
                parent->left = current->right;
            }
            else {
                parent->right = current->right;
            }
            delete current;
            return;
        }
        if (current->left != NULL && current->right == NULL) {
            if (parent->left != NULL && parent->left->value == current->value) {
                parent->left = current->left;
            }
            else {
                parent->right = current->left;
            }
            delete current;
            return;
        }

        // case 3 node has two child
        node *temp = current->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        int saved = temp->value;
        Delete(saved);
        current->value = saved;
    }
};

int main()
{
    BST bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);

    //Case 1
//    bst.Delete(8);
//    bst.BFS();

    //Case 2
//    bst.Delete(7);
//    bst.BFS();

    //Case 3
    bst.Delete(6);
    bst.BFS();

    return 0;
}