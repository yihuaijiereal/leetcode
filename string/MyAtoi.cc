#include "leet.h"

class Solution{
public:
    int myAtoi(const string &str){
        int num = 0;
        int sign = 1;
        const int n = str.length();
        int i = 0;

        while (str[i] == ' ' && i < n) i++;

        if (str[i] == '+') {
              i++;
          } else if (str[i] == '-') {
              sign = -1;
              i++;
          }

         for (; i < n; i++) {
              if (str[i] < '0' || str[i] > '9')
                  break;
              if (num > INT_MAX / 10 ||
                              (num == INT_MAX / 10 &&
                                      (str[i] - '0') > INT_MAX % 10)) {
                  return sign == -1 ? INT_MIN : INT_MAX;
              }
              num = num * 10 + str[i] - '0';
          }
          return num * sign;
    }
};

int main(int argc,char **argv){
    string str = argv[1];
    Solution solution;
    int r = solution.myAtoi(str);
    cout<<r<<endl;
}
