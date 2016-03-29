#include "leet.h"
#include <numeric>

class Solution
{
public:
    int totalCandy(vector<int> &rating){
        const int n = rating.size();
        if(n<=0) return -1;
        vector<int> increment(n);

        for(int i=1,inc=1;i<n;++i){
            if(rating[i]>rating[i-1]){
                increment[i] = max(inc++,increment[i]);
            }else{
                inc = 1;
            }
        }

        for(int i=n-2,inc=1;i>=0;--i){
            if(rating[i]>rating[i+1]){
                increment[i] = max(inc++,increment[i]);
            }else{
                inc = 1;
            }
        }

        return std::accumulate(increment.begin(),increment.end(),n);
    }

    int rTotalCandy(vector<int> &rating){
        const int n = rating.size();
        if(n<=0) return -1;
        vector<int> f(n);
        int sum =0;
        for (int i = 0; i < n; ++i)
            sum += solve(rating, f, i);
        return sum;

    }
private:
    int solve(vector<int> &ratings,vector<int> &f,int i){
        if(f[i]==0){
            f[i] = 1;
            if(i > 0 && ratings[i] > ratings[i - 1]){
                f[i] = max(f[i], solve(ratings, f, i - 1) + 1);
            }
            if(i < ratings.size() - 1 && ratings[i] > ratings[i + 1]){
                f[i] = max(f[i], solve(ratings, f, i + 1) + 1);
            }
        }
        return f[i];
    }
};

int main(){
    int r[] = {1,3,4,2,2,1,4,5,5,4,6,7};
    vector<int> rating(r,r+12);
    Solution solution;
    int result = solution.totalCandy(rating);
    int r2 = solution.rTotalCandy(rating);
    cout<<result<<" "<<r2<<endl;
}
