#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class MiniatureDachshund {
    public:
        int maxMikan(vector<int> mikan, int weight) {
            sort(mikan.begin(), mikan.end());
            int cnt = 0;
            for (int i = 0; i < mikan.size(); ++i) {
                if (weight + mikan[i] > 5000)
                    break;
                cnt++;
                weight += mikan[i];
            }
            return cnt;
        }

        int maxMikan2(vector<int> mikan, int weight) {
            sort(mikan.begin(), mikan.end());
            int cnt = 0;
            for (int i = 0; i < mikan.size(); ++i) {
                weight += mikan[i];
                if (weight > 5000)
                    break;
                cnt++;
            }
            return cnt;
        }
};

int main() {
    MiniatureDachshund test;
    vector<int> testSet1 = {100, 100, 100, 100};
    assert(test.maxMikan(testSet1, 4750) == 2);

    return 0;
}
