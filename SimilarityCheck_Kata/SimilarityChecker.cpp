#include <iostream>
#include <vector>

using namespace std;

class SimilarityChecker {
public:
    int getLengthSimilarity(const string inputA, const string inputB) const {
        int min = static_cast<int>(std::min(inputA.length(), inputB.length()));
        int max = static_cast<int>(std::max(inputA.length(), inputB.length()));
        int gab = max - min;

        if (isTheSame(max, min)) return MAX_POINT;
        if (is2TimesLonger(max, min)) return MIN_POINT;
        return calcPoint(max, min);
    }


private:
    int calcPoint(int maxVal, int minVal) const { 
        return MAX_POINT - ((maxVal - minVal) * MAX_POINT) / minVal; 
    }
    
    bool isTheSame(int max, int min) const { 
        return max == min; 
    }
    
    bool is2TimesLonger(int lengthA, int lengthB) const {
        return ((lengthA >= lengthB * 2) || (lengthB >= lengthA * 2));
    }

private:
    static const int MAX_POINT = 60;
    static const int MIN_POINT = 0;
};