#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define NO_OF_CHARS 256

// Preprocessing: Create the Bad Character Table
void badCharHeuristic(const std::string& str, int size, int badchar[NO_OF_CHARS]) {
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (int i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(const std::string& txt, const std::string& pat) {
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is the shift of the pattern with respect to text
    while (s <= (n - m)) {
        int j = m - 1;

        // Keep reducing index j of pattern while characters of 
        // pattern and text are matching at this shift s
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // If the pattern is present at current shift, then index j 
        // will become -1 after the loop
        if (j < 0) {
            std::cout << "Pattern occurs at shift = " << s << std::endl;
            
            // Shift the pattern so that the next character in text 
            // aligns with the last occurrence of it in pattern.
            s += (s + m < n) ? m - badchar[(unsigned char)txt[s + m]] : 1;
        } else {
            // Shift the pattern so that the bad character in text 
            // aligns with the last occurrence of it in pattern.
            s += std::max(1, j - badchar[(unsigned char)txt[s + j]]);
        }
    }
}

int main() {
    std::string txt = "ABAAABCDABC";
    std::string pat = "ABC";
    search(txt, pat);
    return 0;
}
