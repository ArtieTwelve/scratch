//
// Created by smithla on 12/4/20.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>


// Baseline tests that in reality test nothing from the main application
// Two classes Entity and Entity2, exactly the same
// Three fixtures, My MyEntityTest, MyEntityTest2 and Secondary that
// are also similar.


class Entity {
public:
    Entity() {}
    Entity(std::string _id) : id(_id) {}
    std::string Id() { return id;}
    void Increment(int byValue) {
        baseValue += byValue;
    }
    int getValue() {return baseValue;}

private:
    std::string id;
    int baseValue = 100;
};

class Entity2 {
public:
    Entity2() {}
    Entity2(std::string _id) : id(_id) {}
    std::string Id() { return id;}
    void Increment(int byValue) {
        baseValue += byValue;
    }
    int getValue() {return baseValue;}

private:
    std::string id;
    int baseValue = 100;
};

struct MyEntityTest : public testing::Test {
    Entity *e;
    Entity *f;

    void SetUp() {
        std::cout << " Alive \n";
        e = new Entity("ABC");
        f = new Entity("XYZ");
        e->Increment(10);
        f->Increment(20);

    }
    void TearDown() {
        std::cout << " Dead \n";
        delete e;
        delete f;
    }
};

struct MyEntityTest2 : public testing::Test {

    Entity *e;
    Entity *f;

    void SetUp() {
        std::cout << " Alive \n";
        e = new Entity("ABC");
        f = new Entity("XYZ");
        e->Increment(10);
        f->Increment(20);

    }
    void TearDown() {
        std::cout << " Dead \n";
        delete e;
        delete f;
    }
};

class SecondaryTest : public ::testing::Test{
protected:
    virtual void TearDown() {
        std::cout << " Secondary Dead \n";
        delete e;
    }

    virtual void SetUp() {
        std::cout << " Secondary Alive \n";
        e = new Entity2("ABC");
        e->Increment(20);
    }

    Entity2 *e;
};
TEST_F(SecondaryTest,check_id) {
ASSERT_EQ("ABC",e->Id());
EXPECT_EQ(110,e->getValue());
}

TEST_F(MyEntityTest,check_id) {
ASSERT_EQ("ABC",e->Id());
ASSERT_EQ("XYZ",f->Id());
}

TEST_F(MyEntityTest,check_number) {
EXPECT_EQ(110,e->getValue());
EXPECT_EQ(120,f->getValue());
}

TEST_F(MyEntityTest2,check_id) {
ASSERT_EQ("ABC",e->Id());
ASSERT_EQ("XYZ",f->Id());
}

TEST_F(MyEntityTest2,check_number) {
EXPECT_EQ(110,e->getValue());
EXPECT_EQ(120,f->getValue());
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


