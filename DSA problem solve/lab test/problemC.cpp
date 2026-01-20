#include <iostream>
#include <string>
#include <vector>

int getCode(char c) {
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return 1;
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return 2;
    if (c == 'D' || c == 'T') return 3;
    if (c == 'L') return 4;
    if (c == 'M' || c == 'N') return 5;
    if (c == 'R') return 6;
    return 0;
}

int main() {
    std::string word;
    
    while (std::cin >> word) {
        std::string result;
        int prev_code = 0;
        
        for (char c : word) {
            int code = getCode(c);
            
            if (code > 0 && code != prev_code) {
                result += (code + '0');
            }
            
            if (code > 0) {
                prev_code = code;
            }
        }
        
        std::cout << result << std::endl;
    }
    
    return 0;
}