#include "includer.h"
struct bin_node {
    int value;
    bin_node* left=nullptr;
    bin_node* right=nullptr;

    bin_node() {}
    bin_node(int value) {
         this->value = value;
    }
    ~bin_node() {
        delete left;
        delete right;
    }
};


class bin_tree {
private:


    void _add(int n);
    void _remove(bin_node* node, int n);
    bin_node* _search(int n);
    void _dfs_print(bin_node* node);
    bin_node* min(bin_node* node);
    bin_node* max(bin_node* node);

public:
    bin_node* root;
    void add(int n) {bin_tree::_add(n);}
    void add(std::vector<int> v) {
        for(auto i : v) {
            _add(i);
        }
    }
    void remove(int n) { bin_tree::_remove(root,n); }
    bin_node* search(int n) { return bin_tree::_search(n); }
    void dfs_print();
    
    bin_node* min() { return bin_tree::min(root); }
    bin_node* max() { return bin_tree::max(root); }

    bin_node* parent_min(bin_node* node);
    bin_node* parent_max(bin_node* node);
    bin_node* parent_value(bin_node* node, int v);
    bin_tree() {
        root = nullptr;
    }
    ~bin_tree() {
        delete root;
    }
};

bin_node* bin_tree::_search(int n) {
    bin_node *link=root;
    if(root==nullptr) {
        root = new bin_node(n);
        return root;
    }
    bool toLeft=false;
    while(true) {
        if(n==link->value) return link;
        if(n<link->value) toLeft=true;
        else toLeft=false;

        if(toLeft) {
            if(link->left!=nullptr) link=link->left;
            else return nullptr;
        }
        else {
            if(link->right!=nullptr) link=link->right;
            else return nullptr;
        }
    }
}
void bin_tree::_add(int n) {
    bin_node *link=root;
    if(root==nullptr) {
        root = new bin_node(n);
        return;
    }
    while(link) {
        if(n<link->value) link=link->left;
        else link=link->right;
    }
    link=new bin_node(n);
    return;
}


bin_node* bin_tree::min(bin_node* node) {
    bin_node* link= node;
    if(link==nullptr) return nullptr;
    while(true) {
        if(link->left!=nullptr) link=link->left;
        else return link;
    }
}

bin_node* bin_tree::max(bin_node* node) {
    bin_node* link= node;
    if(link==nullptr) return nullptr;
    while(true) {
        if(link->right!=nullptr) link=link->right;
        else return link;
    }  
}
void bin_tree::dfs_print() {
    bin_node* link = root;
    if(link!=nullptr) {
        std::cout << link->value << " ";
        bin_tree::_dfs_print(link);
    }
    else return;
}
void bin_tree::_dfs_print(bin_node* link) {
    if(link->left!=nullptr) {
        std::cout << link->left->value << " ";
        _dfs_print(link->left);

    }
    if(link->right!=nullptr) {
        std::cout << link->right->value << " ";
        _dfs_print(link->right);
    }
}

bin_node* bin_tree::parent_min(bin_node* node) {
    bin_node* link = node;
    bin_node* prev = link;
    if(link==nullptr) return nullptr;
    while(true) {
        if(link->left!=nullptr) {
            prev=link;
            link=link->left;
        }
        else return prev;
    }
}
bin_node* bin_tree::parent_max(bin_node* node) {
    bin_node* link = node;
    bin_node* prev = link;
    if(link==nullptr) return nullptr;
    while(true) {
        if(link->right!=nullptr) {
            prev=link;
            link=link->right;
        }
        else return prev;
    }
}
bin_node* bin_tree::parent_value(bin_node* node, int n) {
    bin_node* link=node;
    bin_node* prev=link;
    if(node==nullptr) {
        return nullptr;
    }
    bool toLeft=false;
    while(true) {
        if(n==link->value) return prev;
        if(n<link->value) toLeft=true;
        else toLeft=false;


        if(toLeft) {
            if(link->left!=nullptr) {
                prev=link;
                link=link->left;
            }
            else return nullptr;
        }
        else {
            if(link->right!=nullptr) {
                prev=link;
                link=link->right;
            }
            else return nullptr;
        }
    }
}


void bin_tree::_remove(bin_node* node, int n) {
    // CASE 1 : NODE HAS NO CHILDREN
    // CASE 2 : NODE HAS 1 CHILD
    // CASE 3 : NODE HAS 2 CHILDREN

    bin_node* link=parent_value(node,n);
    if(link==nullptr) return;
    bin_node* child;

    bool toLeft=false;
    if(link->left && link->left->value==n) {
        child=link->left;
        toLeft=true;
    }
    else child=link->right;

    if(child->left==nullptr && child->right==nullptr) {
        if(toLeft) link->left=nullptr;
        else link->right=nullptr;
        delete child;
    }
    else if(child->left==nullptr || child->right==nullptr) {
        if(toLeft) {
            if(child->left) link->left=child->left;
            else link->left=child->right;
        }
        else {
            if(child->left) link->right=child->left;
            else link->right=child->right;
        }
        if(child->left) child->left=nullptr;
        else child->right=nullptr;
        delete child;
    }
    else {
        bin_node* c = bin_tree::parent_min(child);
        bin_node* c_child = c->left;
        
        c_child->left=child->left;
        c_child->right=child->right;
        child->left=nullptr;
        child->right=nullptr;
        if(toLeft) {
            link->left=c_child;
        }
        else link->right=c_child;
        c->left=nullptr;
        delete child;
    }
}