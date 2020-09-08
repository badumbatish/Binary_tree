#include <iostream>
#include "bin_tree.h"
int main()
{
    bin_tree tr;
    tr.add(2);
    IC(tr.search(2));
    tr.remove(2);
    return 0;
}
