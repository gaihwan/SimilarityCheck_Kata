#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

using namespace testing;

class SimilarityCheckerFixture : public Test {
public:
    void checkLength(int expected, string inputA, string inputB) {
        int actual = lsc.getLengthSimilarity(inputA, inputB);
        EXPECT_EQ(expected, actual);
    }
    void checkAlpha(int expected, string inputA, string inputB) {
        int actual = asc.getAlphabetSimilarity(inputA, inputB);
        EXPECT_EQ(expected, actual);
    }

private:
    LengthSimilarityChecker lsc;
    AlphabetSimilarityChecker asc;
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

TEST_F(SimilarityCheckerFixture, AlphabetCheckerTC1_ZeroPoint) {
    checkAlpha(0, "XYZ", "ABC");
}

TEST_F(SimilarityCheckerFixture, AlphabetCheckerTC2_AllTheSame) {
    checkAlpha(40, "AABBCC", "ABC");
}

TEST_F(SimilarityCheckerFixture, AlphabetCheckerTC3_PartialPoint) {
    checkAlpha(30, "ABC", "ABCQ");
    checkAlpha(20, "QFQFQF", "F");
}