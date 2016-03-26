#include <iostream>
#include <vector>

class Solution{
public:
	int search(const std::vector<int> &nums,int target){
		int first = 0;
		int last = nums.size();
		while(first!=last){
			const int mid = first + (last-first)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[first]<=nums[mid]){
				if(nums[first]<=target&&nums[mid]>target)
					last = mid;
				else
					first = mid+1;
			}else{
				if(nums[mid]<target&&target<=nums[last-1])
					first = mid+1;
				else
					last = mid;
			}
			std::cout<<first<<" "<<last<<std::endl;
		}
		return -1;
	}
};

int main(){
	int a[] = {4,5,6,7,8,9,0,1,2,3};
	std::vector<int> v(a,a+10);
	int target = 0;
	std::cin>>target;
	std::cout<<target<<std::endl;
	Solution solution;
	int result = solution.search(v,target);
	if(result!=-1)
		std::cout<<result<<std::endl;
	return 0;
}