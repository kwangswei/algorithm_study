#include <map>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

class BigFatInteger2 {
    public:
        string isDivisible(int A, int B, int C, int D) {
            auto a_facto = factorize(A);
            auto c_facto = factorize(C);

            for (const auto it : c_facto) {
                if ((long long)a_facto[it.first] * B < (long long)it.second * D)
                    return "not divisible";
            }
            return "divisible";
        }

        map<int, int> factorize(int num) {
            map<int, int> result;
            int mul = 2;
            while (num != 1) {
                if (num % mul == 0) {
                    result[mul]++;
                    num /= mul;
                }
                else {
                    mul++;
                }
            }
            return result;
        }
};

int main() {
    BigFatInteger2 test;
    assert(test.isDivisible(1000000000, 1000000000, 1000000000, 200000000) == "divisible");
    assert(test.isDivisible(6, 1, 2, 1) == "divisible");
    assert(test.isDivisible(2, 1, 6, 1) == "not divisible");
    assert(test.isDivisible(8, 100, 4, 200) == "not divisible");
    assert(test.isDivisible(2, 2, 4, 1) == "divisible");

    return 0;
}
