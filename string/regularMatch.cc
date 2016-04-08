#include "leet.h"

class Solution{
public:
    bool isMatch(const string &s,const string &p){
        int i = 0;
        int j = 0;

        int star = -1;
        int mark = -1;

        while (i<s.size())
        {
            if(j<p.size()&&(p[j]=='.'||p[j]==s[i])){
                cout<<1<<endl;
                cout<<i<<" "<<j<<" "<<mark<<" "<<star<<endl;
                ++i;
                ++j;
            }else if(p[j]!='*'&&(p[j+1]=='*')&&(p[j+2]==s[i])){
                j += 2;
            }else if(j<p.size()&&p[j]=='*'&&(s[i]==p[j-1]||p[j-1]=='.')){
                cout<<2<<endl;
                cout<<i<<" "<<j<<" "<<mark<<" "<<star<<endl;
                star = j;
                j++;
                mark = i;
            }else if(j<p.size()&&p[j]=='*') {
                cout<<3<<endl;
                cout<<i<<" "<<j<<" "<<mark<<" "<<star<<endl;
                ++j;
            }else if(star!=-1){
                cout<<4<<endl;
                cout<<i<<" "<<j<<" "<<mark<<" "<<star<<endl;
                j = star+1;
                i = ++mark;
            }else {
                cout<<5<<endl;
                cout<<i<<" "<<j<<" "<<mark<<" "<<star<<endl;
                return false;
            }
        }

        while (j < p.length() && p[j] == '*') {
            ++j;
        }
        return j == p.length();
    }
};

int main(){
    string s,p;
    cin>>s>>p;
    Solution solution;
    bool r = solution.isMatch(s,p);
    if(r){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}
