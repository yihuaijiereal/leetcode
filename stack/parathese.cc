#include "leet.h"

class Solution{
public:
    bool isvalid(const string &s){
        string left = "([{";
        string right = ")]}";

        stack<char> stk;
        for(auto c:s){
            if(left.find(c)!=string::npos){
                stk.push(c);
            }else{
                if(stk.empty()||stk.top()!=left[right.find(c)]){
                    return false;
                }else{
                    stk.pop();
                }
            }
        }

        return stk.empty();
    }
};

int main(int argc,char **argv){
    string s;
    cin>>s;
    Solution solution;
    cout<<solution.isvalid(s)<<endl;
}
