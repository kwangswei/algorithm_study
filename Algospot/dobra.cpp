#include <iostream>
#include <string>

using namespace std;

long long solve(string str, int idx, int vowels, int consonants, bool included);
bool is_invalid(int vowels, int consonants);
bool is_vowel(char c);
bool is_consonant(char c);

int main() {
    string input_str;
    cin >> input_str;

    cout << solve(input_str, 0, 0, 0, false) << endl;

    return 0;
}

long long solve(string str, int idx, int vowels, int consonants, bool included) {
    if (is_invalid(vowels, consonants))
        return 0;

    if (str.size() == idx)
        return included ? 1 : 0;

    long long result = 0;

    if (is_vowel(str[idx])) {
        if (str[idx] == 'L')
            included = true;
        result += solve(str, idx+1, vowels+1, 0, included);
    }
    else if (is_consonant(str[idx])) {
        result += solve(str, idx+1, 0, consonants+1, included);
    }
    else {
        // try to put vowels
        if (included)
            result += solve(str, idx+1, vowels+1, 0, included) * 21;
        else
            result += solve(str, idx+1, vowels+1, 0, included) * 20 + solve(str, idx+1, vowels+1, 0, true);

        // try to put consonant
        result += solve(str, idx+1, 0, consonants+1, included) * 5;
    }

    return result;
}

bool is_invalid(int vowels, int consonants) {
    return vowels >= 3 || consonants >=3;
}

bool is_vowel(char c) {
    return !is_consonant(c) && c != '_';
}

bool is_consonant(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

