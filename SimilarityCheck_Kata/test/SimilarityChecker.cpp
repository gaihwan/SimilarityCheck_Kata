#include <iostream>
#include <vector>

using namespace std;

class SimilarityChecker {
public:
    static const int MAX_POINT = 60;

    int getLengthSimilarity(const string inputA, const string inputB) const {
        int lengthA = inputA.length();
        int lengthB = inputB.length();
        int gab = inputA.length() - inputB.length();

        if (gab == 0) return MAX_POINT;
        if (is2TimesLonger(lengthA, lengthB)) return 0;
        if (gab > 0) return MAX_POINT - (gab * MAX_POINT) / lengthB;
        else return MAX_POINT + (gab * MAX_POINT) / lengthA;
    }
    bool is2TimesLonger(int lengthA, int lengthB) const {
        return ((lengthA >= lengthB * 2) || (lengthB >= lengthA * 2));
    }
};