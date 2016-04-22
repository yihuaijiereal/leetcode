#include "leet.h"

class Solution{
public:
    int lagestRectangle(vector<int> &height){
        stack<int> s;
        height.push_back(0);
        int result = 0;
        for(int i=0;i<height.size();){
            if(s.empty()||height[i]>height[s.top()]){
                s.push(i++);
            }else{
                int tmp = s.top();
                s.pop();
                result = max(result,
                            height[tmp]*(s.empty()?i:i-s.top()-1));
            }
        }

        return result;
    }
};

int main(){
    int a[] = {1,2,3,4,2,5,6,2,3,1};
    std::vector<int> height(a,a+10);
    Solution solution;
    cout<<solution.lagestRectangle(height)<<endl;
}
