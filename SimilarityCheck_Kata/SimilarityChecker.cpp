#include <iostream>
#include <vector>
#include <set>

using namespace std;

class AlphabetSimilarityChecker {
public:
    int getAlphabetSimilarity(const string inputA, const string inputB) const {
        set<char> stringSetA(inputA.begin(), inputA.end());
        set<char> stringSetB(inputB.begin(), inputB.end());

        int sameCnt = getTheSameCharNumber(stringSetA, stringSetB);
        int totalCnt = getTotalAlphaCount(stringSetA, stringSetB);

        if (isAlltheSame(totalCnt, sameCnt))
            return MAX_ALPHABET_POINT;

        return sameCnt * 40 / totalCnt;
    }

    int getTotalAlphaCount(std::set<char>& stringSetA, std::set<char>& stringSetB) const
    {
        int sameCnt = getTheSameCharNumber(stringSetA, stringSetB);
        return static_cast<int>(stringSetA.size() + stringSetB.size() - sameCnt);
    }

private:
    bool isAlltheSame(int totalCnt, int sameCnt) const
    {
        return totalCnt == sameCnt;
    }

    int getTheSameCharNumber(const set<char>& setCharA, const set<char>& setCharB) const
    {
        int result = 0;
        for (char ch : setCharA) {
            if (setCharB.count(ch)) ++result;
        }
        return result;
    }
private:
    static const int MAX_ALPHABET_POINT = 40;
};

class LengthSimilarityChecker {
public:
    int getLengthSimilarity(const string inputA, const string inputB) const {
        int min = static_cast<int>(std::min(inputA.length(), inputB.length()));
        int max = static_cast<int>(std::max(inputA.length(), inputB.length()));
        int gab = max - min;

        if (isTheSame(max, min)) return MAX_LENGTH_POINT;
        if (is2TimesLonger(max, min)) return MIN_LENGTH_POINT;
        return calcPoint(max, min);
    }

private:

    int calcPoint(int maxVal, int minVal) const { 
        return MAX_LENGTH_POINT - ((maxVal - minVal) * MAX_LENGTH_POINT) / minVal; 
    }
    
    bool isTheSame(int max, int min) const { 
        return max == min; 
    }
    
    bool is2TimesLonger(int lengthA, int lengthB) const {
        return ((lengthA >= lengthB * 2) || (lengthB >= lengthA * 2));
    }

//private:
    static const int MAX_LENGTH_POINT = 60;
    static const int MIN_LENGTH_POINT = 0;
};