#include "includer.h"

struct bin_node {
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
};

class bin_tree {
private: 
    bin_node* root=nullptr;
    bin_node** _add(bin_node* &node, int n); // tail recursion 
    bin_node** _search(bin_node* &node,int n); // tail recursion 
    void _remove(bin_node* &node,int n);
    bin_node**  min(bin_node* &node); // tail recursion 
    void _dfs(bin_node* &node);
public:
    bin_tree() {}
    bin_node** add(int n) { return _add(root,n); }
    void add(std::vector<int> v) { for(auto i : v) add(i); }
    bin_node** search(int n) { return _search(root,n); } // tail recursion 
    void remove(int n) { _remove(root,n); } 
    void dfs() { _dfs(root); }
    bin_node** min() { return min(root); }
    ~bin_tree() {
        delete root;
    }
};

bin_node** bin_tree::_add(bin_node* &node, int n) {
    if(node==nullptr) {
        node = new bin_node(n);
        return &node;
    }
    else if(n < node->value) return _add(node->left,n);
    else return _add(node->right,n);
}

bin_node** bin_tree::_search(bin_node* &node, int n) {
    if(node==nullptr) return nullptr;

    if(node->value==n) return &node;
    else if(n < node->value) return _search(node->left,n);
    else return _search(node->right,n);
}

bin_node** bin_tree::min(bin_node* &node) {
    if(node->left==nullptr) return &node;
    else return min(node->left);

}
void bin_tree::_remove(bin_node* &node,int n) {
    bin_node** link = _search(node,n);
    if(!(link)) return;
    else {
        // If node has no children //FIXED
        if((*link)->left==nullptr && (*link)->right==nullptr) {
            delete *link;
            *link=nullptr;
        }
        // If node has 1 children
        // CASE 0: left child
        else if((*link)->left && !((*link)->right)) {
            bin_node* temp=((*link)->left);
            ((*link)->left)=nullptr;
            delete *link;
            (*link)=temp;
        }
        // CASE 1: right child
        else if((*link)->right && !((*link)->left)) {
            bin_node* temp=((*link)->right);
            ((*link)->right)=nullptr;
            delete *link;
            (*link)=temp;
        }
        // If node has 2 children
        else {
            bin_node** minimum = bin_tree::min((*link)->right);
            (*link)->value = (*minimum)->value;
            _remove((*minimum),(*minimum)->value);
        }
    }
}

void bin_tree::_dfs(bin_node* &node) {
    if(!node) return;
    if(node->left) _dfs(node->left);
    std::cout << node->value << " ";
    if(node->right) _dfs(node->right);
}