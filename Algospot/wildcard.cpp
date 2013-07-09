#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

string pattern;
string file;

int cache[101][101];

bool solve(int p_idx, int f_idx) {
    if (p_idx == pattern.size()) {
        if (f_idx < file.size())
            return false;
        return true;
    }

   if (cache[p_idx][f_idx] != -1)
        return cache[p_idx][f_idx];

   int& result = cache[p_idx][f_idx];
   result = 0;

    if (f_idx == file.size()) {
        if (p_idx <  pattern.size() && pattern[p_idx] == '*')
            return (result=solve(p_idx+1, f_idx));
        return false;
    }

     if (pattern[p_idx] == '?' || pattern[p_idx] == file[f_idx])
        return (result=solve(p_idx+1, f_idx+1));
    else if (pattern[p_idx] == '*')
        return (result=solve(p_idx, f_idx+1) || solve(p_idx+1, f_idx));
    return false;
}

void init() {
    memset(cache, -1, sizeof(cache));
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        cin >> pattern;
        int n;
        cin >> n;
        set<string> result;
        for (int i = 0; i < n; ++i) {
            cin >> file;
            init();
            if (solve(0,0))
                result.insert(file);
        }

        for(set<string>::iterator it = result.begin(); it != result.end(); ++it) {
            cout << *it << endl;
        }
    }
    return 0;
}
