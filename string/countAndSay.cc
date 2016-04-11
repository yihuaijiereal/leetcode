#include "leet.h"
#include <sstream>

class Solution{
public:
    string say(int n){
        string s("1");
        while(--n){
            cout<<s<<endl;
            s = getNext(s);
        }

        cout<<s<<endl;
        return s;
    }
private:
    string getNext(const string &s){
        std::stringstream ss;

        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(std::not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }

        return ss.str();
    }
};

int main(int argc,char **argv){
    int m = atoi(argv[1]);
    Solution solution;
    string s = solution.say(m);
}
