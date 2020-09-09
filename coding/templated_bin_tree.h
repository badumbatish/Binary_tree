#include "includer.h"
template<class T>
struct bin_node {
    T value;
    bin_node<T>* left =nullptr;
    bin_node<T>* right=nullptr;
    bin_node() {}
    bin_node(T n) {
        value=n;
    }
    ~bin_node() {
        delete left;
        delete right;
    }
};

template<class T>
class bin_tree {
private: 
    bin_node<T>* root=nullptr;

    bin_node<T>** _add(bin_node<T>* &node, T n); // tail recursion 
    bin_node<T>** _search(bin_node<T>* &node,T n); // tail recursion 
    void _remove(T n);
    bin_node<T>**  min(bin_node<T>* &node); // tail recursion 
    void _dfs(bin_node<T>* &node);
public:
    bin_tree() {}
    bin_node<T>** add(T n) { return _add(root,n); }
    void add(std::vector<T> v) { for(auto i : v) add(i); }
    bin_node<T>** search(T n) { return _search(root,n); } // tail recursion 
    void remove(T n) { _remove(n); } 
    void dfs() { _dfs(root); }
    bin_node<T>** min() { return min(root); }
    ~bin_tree() {
        delete root;
    }
};

template<class T>
bin_node<T>** bin_tree<T>::_add(bin_node<T>* &node, T n) {
    if(node==nullptr) {
        node = new bin_node<T>(n);
        return &node;
    }
    else if(n < node->value) return _add(node->left,n);
    else return _add(node->right,n);
}

template<class T>
bin_node<T>** bin_tree<T>::_search(bin_node<T>* &node, T n) {
    if(node==nullptr) return nullptr;

    if(node->value==n) return &node;
    else if(n < node->value) return _search(node->left,n);
    else return _search(node->right,n);
}

template<class T>
bin_node<T>** bin_tree<T>::min(bin_node<T>* &node) {
    if(node->left==nullptr) return &node;
    else return min(node->left);

}

template<class T>
void bin_tree<T>::_remove(T n) {
    bin_node<T>** link = search(n);
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
            bin_node<T>* temp=((*link)->left);
            ((*link)->left)=nullptr;
            delete *link;
            (*link)=temp;
        }
        // CASE 1: right child
        else if((*link)->right && !((*link)->left)) {
            bin_node<T>* temp=((*link)->right);
            ((*link)->right)=nullptr;
            delete *link;
            (*link)=temp;
        }

        // If node has 2 children
        else {
            bin_node<T>** minimum = bin_tree<T>::min((*link)->right);
            (*minimum)->left=(*link)->left;

            if((*minimum)==(*link)->right) { (*minimum)->right=nullptr; }
            else {
                (*minimum)->right=(*link)->right;
            }

            (*link)->left=nullptr;
            (*link)->right=nullptr;
            delete *link;
            (*link)=*minimum;
        }
    }
}

template<class T>
void bin_tree<T>::_dfs(bin_node<T>* &node) {
    if(!node) return;
    if(node->left) _dfs(node->left);
    std::cout << node->value << " ";
    if(node->right) _dfs(node->right);
}