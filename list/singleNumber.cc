#include "leet.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums){
        const int width = sizeof(int)*8;
        vector<int> w(width,0);
        int result = 0;
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<width;++j){
                w[j] += (nums[i]>>j)&1;
                w[j] %=3;
            }
        }

        for(int i=0;i<width;++i){
            result += (w[i]<<i);
        }

        return result;
    }

    int singleNumber2(vector<int> &nums){
        int one = 0;
        int two = 0;
        int _three = 0;
        for(int i=0;i<nums.size();++i){
            two |= (one & nums[i]);
            one ^= nums[i];
            _three = ~(one & two);
            one &= _three;
            two &= _three;
        }

        return one;
    }
};

int main(){
    int a[] = {3,3,3,4,4,288,4,5,6,5,6,5,6};
    vector<int> nums(a,a+13);
    Solution sution;
    int r = sution.singleNumber(nums);
    int r2 = sution.singleNumber2(nums);
    cout<<r<<" "<<r2<<endl;
}
