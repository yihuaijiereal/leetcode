#include "leet.h"

class Solution{
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for (auto a = nums.begin(); a < last- 3; ++a) {
            for (auto b = a+1; b < last -2; ++b) {
                auto c = b+1;
                auto d = last-1;
                while (c < d) {
                	if(*a+*b+*c+*d<target){
                		++c;
                	}else if(*a+*b+*c+*d>target){
                		--d;
                	}else{
                		//cout<<*a+*b+*c+*d<<endl;
                		int arr[] = {*a,*b,*c,*d};
                		vector<int> v(arr,arr+4);
                		result.push_back(v);
                		++c;
                		--d;
                	}
                }
            } 
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
	}

};

int main(){
	int a[] = {1,2,3,-1,-2,-3,4,5,6,7,-4,-5,-6,-7,0,8,9,10};
	vector<int> v(a,a+sizeof(a)/sizeof(*a));
	Solution solution;
	vector<vector<int> > result;
	result = solution.fourSum(v,6);
	for(auto i=result.begin();i!=result.end();++i){
		cout<<(*i)[0]<<" "<<(*i)[1]<<" "<<(*i)[2]<<" "<<(*i)[3]<<endl;
	}
	cout<<endl;

	return 0;
}