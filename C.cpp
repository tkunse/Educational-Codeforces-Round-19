#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

void input(std::string* s) {
    std::getline(std::cin, *s);
    std::reverse(s->begin(), s->end());
}

std::string minimalString(std::string& string) {
    // Количество вхождений символов в строку
    int entriesOfLetters[256] = {0};
    std::string t, u;
    
    for (auto ch : string) {
        entriesOfLetters[ch] += 1;
    }
    
    for (uint8_t currCh = 'a'; currCh <= 'z' || !string.empty(); ++currCh) {
        while (!t.empty()) {
            const char lastExtractedCh = t.back();
            while (currCh < lastExtractedCh && !entriesOfLetters[currCh]) {
                currCh += 1;
            }
            // Выходим если в string существует символ младше текущего 
            if (lastExtractedCh > currCh) {
                break;
            }
            t.pop_back();
            u.push_back(lastExtractedCh);
        }
        
        while (entriesOfLetters[currCh]) {
            const char lastExtractedCh = string.back();
            string.pop_back();
            
            lastExtractedCh == currCh ? u.push_back(lastExtractedCh) : t.push_back(lastExtractedCh);
            entriesOfLetters[lastExtractedCh] -= 1;
        }
    }
    return u;
}

void output(const std::string& minimalString) {
    std::cout << minimalString << std::endl;
}

int main(int argc, char** argv) {
    std::string s;
    input(&s);
    output(minimalString(s));
    return 0;
}
