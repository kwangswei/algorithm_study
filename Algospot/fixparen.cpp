#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string get_closes(string opens) {
    string closes = opens;
    closes.replace(opens.find("{"), 1, "}");
    closes.replace(opens.find("<"), 1, ">");
    closes.replace(opens.find("["), 1, "]");
    closes.replace(opens.find("("), 1, ")");
    return closes;
}

string solve(string input_str, string opens, string closes) {
    string parens = input_str;
    stack<char> s;

    for (int i = 0; i < parens.size(); ++i) {
        if (opens.find(parens[i]) != string::npos) {
            s.push(i);
            continue;
        }

        char& open_char = parens[s.top()];
        char& close_char = parens[i];

        int open_priority = opens.find(open_char);
        int close_priority = closes.find(close_char);

        if (open_priority > close_priority)
            close_char = closes[open_priority];
        else if (open_priority < close_priority)
            open_char = opens[close_priority];

        s.pop();
    }

    return parens;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        string str, opens;
        cin >> str >> opens;

        reverse(opens.begin(), opens.end());
        cout << solve(str, opens, get_closes(opens)) << endl;
    }
    return 0;
}
