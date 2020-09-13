#include "includer.h"

class bin_node;
class bin_tree;

class bin_node {
    int value;
    bin_node* left =nullptr;
    bin_node* right=nullptr;
    bin_node() {}
    bin_node(int n) {
        value=n;
    }
    ~bin_node() {
        delete left;
        delete right;
    }
    friend class bin_tree;
};

class bin_tree {
private: 
    bin_node* root=nullptr;
    bin_node** add(bin_node* &node, int n); // tail recursion 
    bin_node** search(bin_node* &node,int n); // tail recursion 
    void remove(bin_node* &node,int n);
    bin_node**  min(bin_node* &node); // tail recursion 
    void dfs(bin_node* &node);
public:
    bin_tree() {}
    bin_node** add(int n) { return add(root,n); }
    void add(std::vector<int> v) { for(auto i : v) add(i); }
    bin_node** search(int n) { return search(root,n); } // tail recursion 
    void remove(int n) { remove(root,n); } 
    void dfs() { dfs(root); }
    bin_node** min() { return min(root); }
    ~bin_tree() {
        delete root;
    }
};

bin_node** bin_tree::add(bin_node* &node, int n) {
    if(node==nullptr) {
        node = new bin_node(n);
        return &node;
    }
    else if(n < node->value) return add(node->left,n);
    else return add(node->right,n);
}

bin_node** bin_tree::search(bin_node* &node, int n) {
    if(node==nullptr) return nullptr;

    if(node->value==n) return &node;
    else if(n < node->value) return search(node->left,n);
    else return search(node->right,n);
}

bin_node** bin_tree::min(bin_node* &node) {
    if(node->left==nullptr) return &node;
    else return min(node->left);

}
void bin_tree::remove(bin_node* &node,int n) {
    bin_node** link = search(node,n);
    if(!(link)) return;
    else {
        // If node has no children //FIXED
        if((*link)->left==nullptr && (*link)->right==nullptr) {
            delete *link;
            *link=nullptr;
            return;
        }
        // If node has 1 children
        else if(!((*link)->left) || !((*link)->right)) {
            bin_node* temp;
            if((*link)->left) temp=(*link)->left;
            else temp=(*link)->right;
            
            ((*link)->value)=(temp->value);
            ((*link)->left)=(temp->left);
            ((*link)->right)=(temp->right);
            temp->left=nullptr;
            temp->right=nullptr;
            delete temp;
            return;
        }
        // If node has 2 children
        else {
            bin_node** minimum = bin_tree::min((*link)->right);
            (*link)->value = (*minimum)->value;
            remove((*minimum),(*minimum)->value);
        }
    }
}

void bin_tree::dfs(bin_node* &node) {
    if(!node) return;
    if(node->left) dfs(node->left);
    std::cout << node->value << " ";
    if(node->right) dfs(node->right);
}
