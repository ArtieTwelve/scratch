#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "../entity/Entity.h"



TEST(Entity,check1) {
    ASSERT_EQ(true,true);
}

TEST(Entity,check2) {
    ASSERT_EQ(true,false);
}

