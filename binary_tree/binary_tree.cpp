#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int id;
    int value;
    node *left;
    node *right;
    node *parent;

    node(int id, int value)
    {
        this->id = id;
        this->value = value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

class BinaryTree {
public:
    node *root;    

    node *create_new_node(int id, int value)
    {
        node *new_node = new node(id, value);
        return new_node;
    }

    void Insertion(int id, int value)
    {
        node *new_node = create_new_node(id, value);
        if (root == NULL) {
            root = new_node;
            return;
        }
        queue<node *> q;
        q.push(root);
        while(!q.empty()) {
            node *a = q.front();
            q.pop();
            if (a->left != NULL) {
                q.push(a->left);
            } else {
                a->left = new_node;
                new_node->parent = a;
                return;
            }
            if (a->right != NULL) {
                q.push(a->right);
            } else {
                a->right = new_node;
                new_node->parent = a;
                return;
            }
        }
    }

    void BFS()
    {
        if (root == NULL) {
            return;
        }
        queue<node *>q;
        q.push(root);

        while (!q.empty()) {
            node *a = q.front();
            q.pop();
            int p = -1, l = -1, r = -1;
            if (a->left != NULL) {
                l = a->left->id;
                q.push(a->left);
            }
            if (a->right != NULL) {
                r = a->right->id;
                q.push(a->right);
            }
            if (a->parent != NULL) {
                p = a->parent->id;
            }
            cout << "Node: " << a->id << " Left child: " << l << " Right child: " << r << " Parent: " << p << "\n";
        }
    }
};

int main()
{
    BinaryTree bt;
    bt.Insertion(1, 5);
    bt.Insertion(2, 4);
    bt.Insertion(3, 5);
    bt.Insertion(5, 6);
    bt.Insertion(7, 10);
    bt.Insertion(8, 10);
    bt.Insertion(9, 10);
    bt.BFS();

    return 0;
}
