#include <iostream>
using std::cin; using std::cout;
#include <vector>
using std::vector;

int removeDup(vector<int> &nums){
	if (nums.empty()) return 0;
	int index = 0;

	for(int i=1;i<nums.size();i++){
		if(nums[index]!=nums[i])
			nums[++index] = nums[i];
	}
	return index+1;
}

int main(){
	int aivec[]={1,2,2,3,4,6,7,8,9,9};
	vector<int> ivec(aivec,aivec+10);
	//std::vector<int> ivec = {1,2,2,3,4,6,7,8,9,9};
	int new_size=removeDup(ivec);
	cout<<new_size;
	return 0;
}
