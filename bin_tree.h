struct bin_node {
    int value;
    bin_node* left;
    bin_node* right;

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
    bin_node* root;

    void _add(int n);
    void _remove(int n);
public:
    void add(int n) { bin_tree::_add(n);}
    void remove(int n) { bin_tree::_remove(n);}



    bin_tree() {
        root = new bin_node();
    }
    ~bin_tree() {
        delete root;
    }
};


void bin_tree::_add(int n) {
    bin_node *link=root;
    bool toLeft=false;
    while(true) {
        if(n<link->value) toLeft=true;
        else toLeft=false;

        if(toLeft) {
            if(link->left!=nullptr) {
                link=link->left;
            }
            else {
                link->left = new bin_node(n);
                return;
            }
        }
        else {
            if(link->right!=nullptr) {
                link=link->right;
            }
            else {
                link->right = new bin_node(n);
                return;
            }
        }
    }

}

