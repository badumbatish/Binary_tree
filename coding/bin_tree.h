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

    void _add(bin_node* &node, int n);
    bin_node** _search(bin_node* &node,int n);
    void _remove(int n);
    bin_node**  min(bin_node* &node);
    void _dfs(bin_node* &node);
    bin_node** _parent_search(bin_node* &node, int n);
    bin_node** parent_search(int n) { return _parent_search(root,n); }
public:
    bin_tree() {}
    void add(int n) { _add(root,n); }
    void add(std::vector<int> v) {
        for(auto i : v) {
            add(i);
        }
    }
    bin_node** search(int n) {return _search(root,n); }
    void remove(int n) { _remove(n); }
    void dfs() { _dfs(root); }
    bin_node** min() { return min(root); }
    ~bin_tree() {
        delete root;
    }

};

void bin_tree::_add(bin_node* &node, int n) {
    if(node==nullptr) {
        node = new bin_node(n);
        return;
    }
    else if(n < node->value) _add(node->left,n);
    else _add(node->right,n);
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
void bin_tree::_remove(int n) {
    bin_node** parent = parent_search(n);
    if(!(parent)) return;
    bin_node** link;
    if(((*parent)->left) && ((*parent)->left->value)==(*parent)->value) link=&((*parent)->left);
    else if(((*parent)->right) && ((*parent)->right->value)==(*parent)->value) link=&((*parent)->right);
    else link=parent;

    if(!(*link)) return;
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
        else {
            bin_node** minimum = bin_tree::min((*link)->right);
            if((*minimum)==(*link)->right) {
                bin_node* temp=((*link)->right);
                temp->left=(*link)->left;
                ((*link)->left)=nullptr;
                ((*link)->right)=nullptr;
                delete *link;
                (*link)=temp;
            }
            else
            {
                (*minimum)->left=(*link)->left;
                (*minimum)->right=(*link)->right;
                (*link)->left=nullptr;
                (*link)->right=nullptr;
                delete *link;
                (*link)=*minimum;
            }

        }
    }
}

bin_node** bin_tree::_parent_search(bin_node* &node, int n) {
    if(node==nullptr) return nullptr;

    if(node->value==n || (node->left && node->left->value==n) || (node->right && node->right->value == n)) return &node;
    else if(n < node->value) return _parent_search(node->left,n);
    else return _parent_search(node->right,n);
}
void bin_tree::_dfs(bin_node* &node) {
    if(!node) return;
    if(node->left) _dfs(node->left);
    std::cout << node->value << " ";
    if(node->right) _dfs(node->right);
}