#include "leet.h"

class Solution{
public:
    int getStart(vector<int> &gas,vector<int> &cost){
        if(gas.size()==0||gas.size()!=cost.size())
            return -1;

        int sum = 0;
        int total = 0;
        int start = 0;
        for(int i=0;i<gas.size();++i){
            int diff = gas[i] - cost[i];
            total += diff;
            if(sum<0){
                sum = diff;
                start = i;
            }else{
                sum += diff;
            }
        }

        return (total>=0)?start:-1;
    }
};

int main(){
    int g[] = {3,4,2,1,5,3,7};
    int c[] = {4,4,4,1,2,3,1};
    vector<int> gas(g,g+7);
    vector<int> cost(c,c+7);
    Solution solution;
    int resutl = solution.getStart(gas,cost);
    cout<<resutl<<endl;
}
