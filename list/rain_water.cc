#include "leet.h"
#include <stack>
using std::pair;

class Solution
{
public:
    int trap(const std::vector<int> &A){
        const int n = A.size();
        int *max_left = new int[n]();
        int *max_right = new int[n]();

        for(int i=1;i<n;i++){
            max_left[i] = max(max_left[i-1],A[i-1]);
            max_right[n-1-i] = max(max_right[n-i],A[n-i]);
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            int height = min(max_right[i],max_left[i]);
            if(height>A[i]){
                sum += height - A[i];
            }
        }

        delete[] max_right;
        delete[] max_left;
        return sum;
    }

    int trap2(const std::vector<int> &A){
        const int n = A.size();

        int max = 0;
        for(int i=0;i<n;++i){
            if(A[i]>A[max])
                max = i;
        }

        int water = 0;
        for(int i=0,peak = 0;i<max;++i){
            if(A[i]>peak)
                peak = A[i];
            else
                water += peak - A[i];
        }
        for(int i=n-1,top = 0;i>max;--i){
            if(A[i]>top)
                top = A[i];
            else
                water += top - A[i];
        }

        return water;
    }

    int trap3(std::vector<int> &A){
        const int n = A.size();
        std::stack<pair<int,int> > s;
        int water = 0;

        for(int i = 0;i<n;++i){
            int height = 0;
            while(!s.empty()){
                int bar = s.top().first;
                int pos = s.top().second;
                water += (min(bar,A[i])-height)*(i-pos-1);
                height = bar;

                if(A[i]<bar)
                    break;
                else
                    s.pop();
            }
            s.push(std::make_pair(A[i],i));
        }

        return water;
    }
};

int main(){
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> A(a,a+12);
    Solution solution;
    int result = solution.trap(A);
    int result2 = solution.trap2(A);
    int result3 = solution.trap3(A);
    cout<<result<<" "<<result2<<" "<<result3<<endl;
}
