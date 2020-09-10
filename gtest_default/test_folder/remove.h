TEST(Wrong_remove,wrong_remove) {
    bin_tree tr;
    tr.remove(0);
}
TEST(No_child,remove_non_child) {
    bin_tree tr;
    tr.add(1);
    EXPECT_TRUE(tr.search(1));
    tr.remove(1);
    EXPECT_FALSE(tr.search(1));
}

TEST(Left,remove_left) {
    bin_tree tr;
    tr.add(2); tr.add(1);
    EXPECT_TRUE(tr.search(1));
    tr.remove(1);
    EXPECT_FALSE(tr.search(1));
}

TEST(Left,remove_left_1) {
    bin_tree tr;
    tr.add(2); tr.add(1); tr.add(0);
    EXPECT_TRUE(tr.search(1));
    tr.remove(1);
    EXPECT_FALSE(tr.search(1));
    EXPECT_TRUE(tr.search(0));
}

TEST(Right,remove_right) {
    bin_tree tr;
    tr.add(1); tr.add(2);
    EXPECT_TRUE(tr.search(2));
    tr.remove(2);
    EXPECT_FALSE(tr.search(2));
}

TEST(Right,remove_right_1) {
    bin_tree tr;
    tr.add(0); tr.add(1); tr.add(2);
    EXPECT_TRUE(tr.search(1));
    tr.remove(1);
    EXPECT_FALSE(tr.search(1));
    EXPECT_TRUE(tr.search(0));
    EXPECT_TRUE(tr.search(2));
}

TEST(Center,remove_center) {
    bin_tree tr;
    tr.add(2); tr.add(1); tr.add(3);
    EXPECT_TRUE(tr.search(2));
    tr.remove(2);
    EXPECT_FALSE(tr.search(2));
}

TEST(Center,remove_center_1) {
    bin_tree tr;
    std::vector<int> v{2,1,3,4};
    tr.add(v);
    EXPECT_TRUE(tr.search(2));
    EXPECT_TRUE(tr.search(3));
    EXPECT_TRUE(tr.search(4));

    tr.remove(3);
    EXPECT_TRUE(tr.search(2));
    EXPECT_FALSE(tr.search(3));
    EXPECT_TRUE(tr.search(4));
    
}

TEST(Removal_bin_tree,remove_center_2) {
    bin_tree tr;
    std::vector<int> v{2,1,6,9,7,10};
    tr.add(v);
    EXPECT_TRUE(tr.search(6));
    tr.remove(6);
    EXPECT_FALSE(tr.search(6));
}

TEST(Address_test,node_and_left_child) {
    bin_tree tr;
    std::vector<int> v{2,1};
    tr.add(v);
    bin_node* temp1=*(tr.search(2));
    tr.remove(2);
    bin_node* temp2=*(tr.search(1));
    EXPECT_EQ(temp1,temp2);
}

TEST(Address_test,node_and_right_child) {
    bin_tree tr;
    std::vector<int> v{1,2};
    tr.add(v);
    bin_node* temp1=*(tr.search(1));
    tr.remove(1);
    bin_node* temp2=*(tr.search(2));
    EXPECT_EQ(temp1,temp2);
}

TEST(Address_test,node_and_right_child_2) {
    bin_tree tr;
    std::vector<int> v{2,1,3};
    tr.add(v);
    bin_node* temp1=*(tr.search(2));
    tr.remove(2);
    bin_node* temp2=*(tr.search(3));
    EXPECT_EQ(temp1,temp2);
}