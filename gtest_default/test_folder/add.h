#include "../../coding/bin_tree.h"
TEST(Addition_bin_tree,only_one) {
    bin_tree tr;
    tr.add(1);
    EXPECT_TRUE(tr.search(1));
    EXPECT_FALSE(tr.search(0));
    EXPECT_FALSE(tr.search(2));
}

TEST(Addition_bin_tree,only_one_1) {
    bin_tree tr;
    tr.add(99999);
    EXPECT_TRUE(tr.search(99999));
    EXPECT_FALSE(tr.search(88888));
    EXPECT_FALSE(tr.search(99998));
}

TEST(Addition_bin_tree,multiple_2) {
    bin_tree tr;
    std::vector<int> v{2,1,3};
    tr.add(v);
    EXPECT_TRUE(tr.search(2));
    EXPECT_TRUE(tr.search(1));
    EXPECT_TRUE(tr.search(3));
    EXPECT_FALSE(tr.search(4));
}

TEST(Addition_bin_tree,add_then_remove) {
    bin_tree tr;
    tr.add(2);
    EXPECT_TRUE(tr.search(2));
    tr.remove(2);
    EXPECT_FALSE(tr.search(2));
}

TEST(Addition_bin_tree,add_then_remove_2) {
    bin_tree tr;
    tr.add(2);     tr.add(3); 
    EXPECT_TRUE(tr.search(2));
    tr.remove(2);
    EXPECT_FALSE(tr.search(2));

    EXPECT_TRUE(tr.search(3));
    tr.remove(3);
    EXPECT_FALSE(tr.search(3));
}

