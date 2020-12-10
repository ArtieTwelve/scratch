//
// Created by smithla on 12/4/20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../entity/Entity.h"


TEST(Blank,check_number) {
EXPECT_EQ(true,true);
}
// main method is not needed at this point but useful if running outside of the IDE.
// Haiving this here might limit some of the IDE functionality. Not sure about that, but
// I read it somewhere.
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc,argv);
    std::cout << " In Main of SampleAppTests"  << " Argc = " << argc << std::endl;
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argv: " << argv[i] << std::endl;

    }
    return RUN_ALL_TESTS();
}


