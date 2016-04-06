#include "leet.h"

class Solution
{
public:
    string add(const string &a,const string &b){
        string result;
        const int n = (a.length()>b.length()) ? a.length() : b.length();
        int carry = 0;
        for(int i=0;i<n;++i){
            int ai = (i<a.size())?a[a.size()-1-i]-'0':0;
            int bi = (i<b.size())?b[b.size()-1-i]-'0':0;
            int temp = (ai+bi+carry)%2;
            cout<<ai<<" "<<bi<<" "<<temp<<endl;
            carry = (ai+bi+carry)/2;
            result.insert(result.begin(),temp+'0');
        }
        if(carry==1){
            result.insert(result.begin(),carry+'0');
        }

        return result;
    }
};

int main(int argc, char** argv){
    Solution solution;
    string s = solution.add(argv[1],argv[2]);
    cout<<s<<endl;
}
