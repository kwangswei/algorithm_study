#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string s, int l, int r) {
    if (l > r || l == r)
        return true;
    return s[l] == s[r] ? is_palindrome(s, l+1, r-1) : false;
}

int find(string s) {
    for (int i = 0; i < s.size(); ++i)
        if (is_palindrome(s, i, s.size()-1))
            return s.size() + i;
    return s.size() * 2;
}


int main() {
    cout << find("abab") << endl;
    cout << find("abacaba") << endl;
    cout << find("qwerty") << endl;
    cout << find("abdfhdyrbdbsdfghjkllkjhgfds") << endl;
    return 0;
}
