#include "gmock/gmock.h"
#include "SimilarityChecker.cpp"

TEST(TS, TC1) {
    SimilarityChecker c;
    EXPECT_EQ(1, 1);
}

TEST(TS, SimilarityCheckerTC1) {
    SimilarityChecker c;
    int expected = 40;
    int actual = c.getLengthSimilarity("ABCD", "ABC");
    EXPECT_EQ(expected, actual);
}

TEST(TS, SimilarityCheckerTC2) {
    SimilarityChecker c;
    int expected = 60;
    int actual = c.getLengthSimilarity("BCD", "ABC");
    EXPECT_EQ(expected, actual);
}

TEST(TS, SimilarityCheckerTC3) {
    SimilarityChecker c;
    int expected = 0;
    int actual = c.getLengthSimilarity("BCDEFG", "ABC");
    EXPECT_EQ(expected, actual);
}

