#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
	std::vector<int> sum2(std::vector<int> &nums,int target){
		std::unordered_map<int,int> map_int;
		std::vector<int> result;

		for(int i=0;i<nums.size();++i){
			map_int[nums[i]] = i;
		} 

		for (int i = 0; i < nums.size(); ++i)
		{
			/* code */
			const int gap = target-nums[i];
			if(map_int.find(gap)!=map_int.end()&&map_int[gap]>i){
				result.push_back(i+1);
				result.push_back(map_int[gap]+1);
				break;
			}
		}
		return result;
	}
};

int main(){
	std::vector<int> result;
	int a[]={1,2,3,5,4,6,8,7,9,10};
	std::vector<int> v(a,a+10);
	Solution solution;
	result = solution.sum2(v,8);
	std::cout<<result[0]<<" "<<result[1]<<std::endl;
}