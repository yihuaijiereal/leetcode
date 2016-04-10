#include "leet.h"

class Solution{
public:
    bool isNumber(const string &s){
        enum InputType{
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXPONENT,
            NUM_INPUTS
        };

        const int transitionTable[][NUM_INPUTS] = {
            -1, 0, 3, 1, 2, -1, // next states for state 0
            -1, 8, -1, 1, 4, 5,// next states for state 1
            -1, -1, -1, 4, -1, -1,
            -1, -1, -1, 1, 2, -1,
            -1, 8, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1,
            -1, -1, -1, 7, -1, -1,
            -1, 8, -1, 7, -1, -1,
            -1, 8, -1, -1, -1, -1,
        };

        int state = 0;
        for (auto ch : s) {
            InputType inputType = INVALID;
            if (isspace(ch))
                  inputType = SPACE;
              else if (ch == '+' || ch == '-')
                  inputType = SIGN;
              else if (isdigit(ch))
                  inputType = DIGIT;
              else if (ch == '.')
                  inputType = DOT;
              else if (ch == 'e' || ch == 'E')
                  inputType = EXPONENT;
              // Get next state from current state and input symbol
              state = transitionTable[state][inputType];
              // Invalid input
              if (state == -1) return false;
          }
          return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

int main(int argc,char **argv){
    Solution solution;
    cout<<solution.isNumber(argv[1])<<endl;
}
