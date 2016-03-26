#include "leet.h"

class Solution{
public:
	vector<vector<int> > sum3(vector<int> &nums){
		vector<vector<int> > result;
		if(nums.size()<3) return result;
		sort(nums.begin(),nums.end());
		const int target =0;

		auto last = nums.end();
		for(auto i=nums.begin();i<last-2;++i){
			auto j = i+1;
			if(i>nums.begin()&&*i==*(i-1)) continue;
			auto k = last-1;
			while(j<k){
				if(*i+*k+*j<target){
					++j;
					while(*j==*(j-1)&&j<k)
						++j;
				}else if(*i+*j+*k>target){
					--k;
					while(*k==*(k+1)&&j<k)
						--k;
				}else{
					vector<int> oneResult;
					oneResult.push_back(*i);
					oneResult.push_back(*j);
					oneResult.push_back(*k);
					result.push_back(oneResult);
					++j;
					--k;
					while(*j==*(j-1)&&*k==*(k+1)&&j<k)
						++j;
				}
			}
		}
		return result;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		int result = 0;
        int min_gap = INT_MAX;
        sort(nums.begin(), nums.end());

        for(auto a=nums.begin();a!=prev(nums.end(),2);++a){
        	auto b = next(a);
        	auto c = prev(nums.end());

        	while(b<c){
        		const int sum = *a+*b+*c;
        		const int gap = abs(sum-target);

        		if(gap<min_gap){
        			result=sum;
        			min_gap=gap;
        		}

        		if(sum<target)
        			++b;
        		else
        			--c;
        	}
        }
        return result;
	}
};

int main(){
	int a[] = {1,3,-1,1,2,-2,4,6,-7,0};
	vector<int> v(a,a+10);
	Solution solution;
	auto result = solution.sum3(v);
	for(auto i=result.begin();i!=result.end();++i){
		//vector<int> oneResult = *i;
		//cout<<oneResult[0]<<oneResult[1]<<oneResult[2]<<endl;
		cout<<(*i)[0]<<(*i)[1]<<(*i)[2]<<endl;
	}

	int min_result = solution.threeSumClosest(v,15);
	cout<<min_result<<endl;
	return 0;
}

