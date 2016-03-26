#include "leet.h"

class Solution{
public:
	void nextPermutation(vector<int> &nums){
		next_permutation(nums.begin(),nums.end());
	}

	template<typename BidiIt>
	bool next_permutation(BidiIt first,BidiIt last){
		const auto rfirst = std::reverse_iterator<BidiIt>(last);
		const auto rlast = std::reverse_iterator<BidiIt>(first);

		auto pivot = next(rfirst);
		while(pivot!=rlast&&*pivot>=*prev(pivot))
			++pivot;

		if(pivot==rlast){
			std::reverse(rfirst,rlast);
			return false;
		}

		auto change = find_if(rfirst,pivot,bind1st(std::less<int>(),*pivot));
		std::swap(*change,*pivot);
		std::reverse(rfirst,pivot);

		return true;
	}
};

int main(){
	int a[] = {3,5,6,8,4,1,3};
	vector<int> v(a,a+7);
	Solution solution;
	for(auto vi:v){
		cout<<vi<<" ";
	}
	cout<<endl;
	solution.nextPermutation(v);
	for(auto vi:v){
		cout<<vi<<" ";
	}
	cout<<endl;
}