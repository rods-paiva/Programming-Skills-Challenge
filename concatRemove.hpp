#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool isValidString(const string& str) {
    return regex_match(str, regex("^[a-z]+$"));
}



string ConcatRemove(const string& s, const string& t, int k) {

    if (!isValidString(s) || !isValidString(t)) {
        return "s and t must be lowercase letters of the Portuguese alphabet, ascii [a-z]";
    }

    int commonLength = 0;
    int sLength = s.length();
    int tLength = t.length();

    // Find the length of strings s and t
    while (commonLength < sLength && commonLength < tLength && s[commonLength] == t[commonLength]) {
        commonLength++;
    }

    int minMoves = sLength + tLength - 2 * commonLength;

    // Check if it's possible to obtain the desired string 
    if (k >= minMoves && (k - minMoves) % 2 == 0) {
        return "yes";
    } else if (k >= sLength + tLength) {
        return "yes";
    } else {
        return "no";
    }
}
