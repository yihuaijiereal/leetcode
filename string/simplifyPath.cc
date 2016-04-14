#include "leet.h"

class Solution{
public:
    string simplify(const string &path){
        vector<string> dirs;
        for(auto i = path.begin();i!=path.end();){
            ++i;
            auto j = find(i,path.end(),'/');
            auto dir = string(i,j);

            if(!dir.empty()&&dir!="."){
                if(dir == ".."){
                    if(!dirs.empty()){
                        dirs.pop_back();
                    }
                }else{
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        stringstream out;
        if(dirs.empty()){
            out<<"/";
        }else{
            for(auto dir:dirs){
                out<<"/"<<dir;
            }
        }

        return out.str();
    }
};

int main(){
    string path;
    cin>>path;
    Solution solution;
    string spath = solution.simplify(path);
    cout<<spath<<endl;
}
