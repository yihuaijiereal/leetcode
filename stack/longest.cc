#include "leet.h"

class Solution{
public:
    int longest(const string &s){
        int max_len = 0, last = -1;
        stack<int> lefts;

        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                lefts.push(i);
            }else{
                if(lefts.empty()){
                    last = i;
                }else{
                    lefts.pop();
                    if(lefts.empty()){
                        max_len = max(max_len,i-last);
                    }else{
                        max_len = max(max_len,i-lefts.top());
                    }
                }
            }
        }
        return max_len;
    }

    int longest2(const string &s){
        std::vector<int> f(s.size(),0);
        int ret;
        for(int i = s.size()-2;i>=0;--i){
            int match = i+f[i+1]+1;
            if(s[i]=='('&&match<s.size()&&s[match]==')'){
                f[i] = f[i+1]+2;
                if(match+1<s.size()){
                    f[i]+=f[match+1];
                }
            }
            ret = max(ret,f[i]);
        }

        return ret;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solution;
    cout<<solution.longest(s)<<" "<<solution.longest2(s)<<endl;
}
