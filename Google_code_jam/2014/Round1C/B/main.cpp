#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

using namespace std;

#define DIVIDOR 1000000007

int N;
vector<string> words;

string preprocess(string);
int fact(int n);
void init();

long long answer = 1;

vector<string> get_uniq(vector<string>& words) {
    map<string, int> freq;

    for (const auto str :words)
        freq[str]++;

    vector<string> uniq;
    for (const auto f : freq) {
        if (f.second > 1 && f.first.size() > 1)
            answer = 0;
        answer = (answer * fact(f.second)) % DIVIDOR;
        uniq.push_back(f.first);
    }

    return uniq;
}

bool is_connected(string one, string two) {
    return one[one.size()-1] == two[0];
}

string attach(string one, string two) {
    return one + two.substr(1);
}

vector<string> get_connected(vector<string>& uniq) {
    vector<string> connected;

    for (int i = 0; i < uniq.size(); ++i) {
        bool attached = false;
        for (int j = i+1; j < uniq.size(); ++j) {
            if (is_connected(uniq[i], uniq[j])) {
                uniq[j] = attach(uniq[i], uniq[j]);
                attached = true;
                break;
            }
            else if (is_connected(uniq[j], uniq[i])) {
                uniq[j] = attach(uniq[j], uniq[i]);
                attached = true;
                break;
            }
        }

        if (!attached)
            connected.push_back(uniq[i]);
    }

    return connected;
}

bool is_uniq(vector<string>& connected) {
    map<char, bool> existed;
    for (const auto& str : connected) {
        for (const auto& c : str) {
            if (existed[c])
                return false;
            existed[c] = true;
        }
    }
    return true;
}

int solve() {
    auto uniq = get_uniq(words);
    auto connected = get_connected(uniq);

    if (!is_uniq(connected))
        return 0;

    answer = (answer * fact(connected.size())) % DIVIDOR;
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        init();

        cin >> N;
        words = vector<string>(N);

        for (int i = 0; i < N; ++i) {
            string s; cin >> s;
            words[i] = preprocess(s);
        }

        printf("Case #%d: %d\n", test, solve());
    }

    return 0;
}

void init() {
    answer = 1;
}

string preprocess(string s) {
    string result;
    result.push_back(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i-1])
            continue;
        result.push_back(s[i]);
    }
    return result;
}

int fact(int n) {
    long long answer = 1;
    for (int i = 1; i <= n; ++i)
        answer = (answer * i) % 1000000007;
    return answer;
}


