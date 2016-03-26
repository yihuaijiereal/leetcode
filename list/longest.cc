#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution{
public:
	int longestConsecutive(const std::vector<int> &nums){
		std::unordered_map<int,bool> used;

		for(auto i:nums)
			used[i] = false;
		int longest = 0;

		for(auto i:nums){
			if(used[i])
				continue;
			int length = 1;
			used[i] = true;

			for(int j=i+1;used.find(j)!=used.end();++j){
				used[j] = true;
				++length;
			}

			for(int j=i-1;used.find(j)!=used.end();--j){
				used[j] = true;
				++length;
			}
			longest = std::max(longest,length);
		}
		return longest;
	}
};

class Solution2 {
  public:
      int longestConsecutive(std::vector<int> &nums) {
          std::unordered_map<int, int> map;
          int size = nums.size();
          int l = 1;
          for (int i = 0; i < size; i++) {
              if (map.find(nums[i]) != map.end()) continue;
              map[nums[i]] = 1;
              if (map.find(nums[i] - 1) != map.end()) {
                  l = std::max(l, mergeCluster(map, nums[i] - 1, nums[i]));
              }
              if (map.find(nums[i] + 1) != map.end()) {
                  l = std::max(l, mergeCluster(map, nums[i], nums[i] + 1));
} }
          return size == 0 ? 0 : l;
      }
  private:
      int mergeCluster(std::unordered_map<int, int> &map, int left, int right) {
          int upper = right + map[right] - 1;
          int lower = left - map[left] + 1;
          int length = upper - lower + 1;
          map[upper] = length;
          map[lower] = length;
          return length;
      }
};

int main(){
	int a[] = {1,2,4,5,3,6,7,8,10};
	std::vector<int> v(a,a+8);
	Solution solution;
	Solution2 solution2;
	int result = solution.longestConsecutive(v);
	int result2 = solution2.longestConsecutive(v);
	std::cout<<result<<std::endl;
	std::cout<<result2<<std::endl;
	return 0;
}