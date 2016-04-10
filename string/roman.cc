#include "leet.h"

class Solution{
public:
    string intToRoman(int num){
        const int radix[] = {1000, 900, 500, 400, 100, 90,
                  50, 40, 10, 9, 5, 4, 1};
        const string symbol[] = {"M", "CM", "D", "CD", "C", "XC",
                  "L", "XL", "X", "IX", "V", "IV", "I"};

        string roman;
        for (size_t i = 0; num > 0; ++i) {
              int count = num / radix[i];
              num %= radix[i];
              for (; count > 0; --count) roman += symbol[i];
        }
        return roman;
    }

    int romanToInt(const string &s){
        int result = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (i > 0 && map(s[i]) > map(s[i - 1])) {
                result += (map(s[i]) - 2 * map(s[i - 1]));
            } else {
                result += map(s[i]);
            }
        }
        return result;
    }
private:
    inline int map(const char c) {
          switch (c) {
          case 'I': return 1;
          case 'V': return 5;
          case 'X': return 10;
          case 'L': return 50;
          case 'C': return 100;
          case 'D': return 500;
          case 'M': return 1000;
          default: return 0;
          }
      }
};

int main(){
    int m;
    cin>>m;
    Solution solution;
    string s = solution.intToRoman(m);
    int r = solution.romanToInt(s);
    cout<<s<<" "<<r<<endl;
}
