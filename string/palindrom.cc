#include "leet.h"

class Solution
{
public:
    bool isPalindrome(string s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
              if (!::isalnum(*left))  ++left;
              else if (!::isalnum(*right)) --right;
              else if (*left != *right) return false;
              else { left++, right--; }
        }
        return true;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solution;
    if(solution.isPalindrome(s)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
