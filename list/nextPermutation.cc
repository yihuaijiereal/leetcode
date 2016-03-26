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

	string getPermutation(int n,int k){
		string s(n,'0');
		string result;
		for(int i=0;i<n;i++){
			s[i]+=i+1;
		}
		return kth_permutation(s,k);
	}

private:
	int factorial(int n){
		if(n==1)
			return 1;
		else
			return n*factorial(n-1);
	}

	template<typename Sequence>
	Sequence kth_permutation(const Sequence &seq,int k){
		const int n = seq.size();
		Sequence S(seq);
		Sequence result;

		int base = factorial(n-1);
		--k;

		for(int i=n-1;i>0;k%=base,base/=i,--i){
			auto a = std::next(S.begin(),k/base);
			result.push_back(*a);
			S.erase(a);
		}
		result.push_back(S[0]);
		return result;
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
	string s = solution.getPermutation(8,410);
	cout<<s<<endl;
}