#include "includer.h"
template<typename T>
struct bin_node {
        T value;
        bin_node* left=nullptr;
        bin_node* right=nullptr;

        bin_node() {}
        bin_node(T t) {
            value=t;
        }
        ~bin_node() {
            delete left;
            delete right;
        }
    };

template<typename T>
class bin_tree {
private:
    
    bin_node<T>* root=nullptr;
    bin_node<T>* _add(T t);
public:
    bin_tree() {}
    ~bin_tree() {
        delete root;
    }
    bin_node<T>* add(T t) { return bin_tree<T>::add(t); }

};

template<typename T>
bin_node<T>* bin_tree<T>::_add(T t) {
    bin_node<T>* link=root;
    if(root==nullptr) {
        root = new bin_node<T>(t);
        return root;
    }
    else {
        bool toLeft=false;
        while(true) {
            if(t<link->value) toLeft=true;
            else toLeft=false;

            if(toLeft) {
                if(link->left!=nullptr) link=link->left;
                else {
                    link->left = new bin_node<T>(t);
                    return link->left;
                }
            }
            else {
                if(link->right!=nullptr) link=link->right;
                else {
                    link->right = new bin_node<T>(t);
                    return link->right;
                }
            }
        }
    }
}

