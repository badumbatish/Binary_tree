#include <iostream>
#include "bin_tree.h"
int main()
{
    bin_tree tr;
    std::vector<int> v {2,1};
    tr.add(v);
    bin_node** temp1=(tr.search(2));
    tr.remove(2);
    bin_node** temp2=(tr.search(1));
    IC((*temp1)==(*temp2));
    return 0;
}
