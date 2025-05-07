#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
    void checkLength(int expected, string inputA, string inputB) {
        int actual = c.getLengthSimilarity(inputA, inputB);
        EXPECT_EQ(expected, actual);
    }

private:
    SimilarityChecker c;
};

TEST_F(SimilarityCheckerFixture, TC1) {
    EXPECT_EQ(1, 1);
}

TEST_F(SimilarityCheckerFixture, SimilarityCheckerTC1) {
    checkLength(40, "ABCD", "ABC");
}

TEST_F(SimilarityCheckerFixture, SimilarityCheckerTC2) {
    checkLength(60, "BCD", "ABC");
}

TEST_F(SimilarityCheckerFixture, SimilarityCheckerTC3) {
    checkLength(0, "BCDEFG", "ABC");
}

