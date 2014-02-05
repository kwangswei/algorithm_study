#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

class CuttingBitString {
    public:
        int getmin(string s);
    private:
        void makeFiveSet();
        string convertNumToBits(unsigned long long num);
        vector<string> fiveset;
};

void CuttingBitString::makeFiveSet() {
    if (fiveset.size() != 0)
        return;

    unsigned long long num = 1;
    unsigned long long end = pow(2, 50) + 1;

    while (num < end) {
        string s = convertNumToBits(num);
        fiveset.push_back(s);
        num *= 5;
    }
}

string CuttingBitString::convertNumToBits(unsigned long long num) {
    string result;

    while (num != 0) {
        result += num % 2 + '0';
        num /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

int CuttingBitString::getmin(string s) {
    if (s.size() == 0)
        return 0;

    if (s[0] == '0')
        return -1;

    makeFiveSet();

    int answer = numeric_limits<int>::max();
    for (const auto c : fiveset) {
        if (c.size() > s.size())
            break;
        if (c == s.substr(0, c.size())) {
            auto result = getmin(s.substr(c.size()));
            if (result == -1)
                continue;
            answer = min(answer, result);
        }
    }

    if (answer == numeric_limits<int>::max())
        return -1;

    return answer + 1; 
}

int main() {
    CuttingBitString test;
    cout << test.getmin("101101101") << endl;
    cout << test.getmin("1111101") << endl;
    cout << test.getmin("00000") << endl;
    cout << test.getmin("110011011") << endl;
    cout << test.getmin("1000101011") << endl;
    cout << test.getmin("111011100110101100101110111") << endl;
    cout << test.getmin("1") << endl;

    
    return 0;
}
