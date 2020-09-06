

#include "gtest/gtest.h"
#include "test_folder/test1.h"
// BELOW IS TESTS


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}
