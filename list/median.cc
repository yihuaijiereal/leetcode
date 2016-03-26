#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
	double findMedian(const std::vector<int> &A,const std::vector<int> B){
		const int m = A.size();
		const int n = B.size();
		int total = m+n;
		if(total & 0x1){
			return findKth(A.begin(),m,B.begin(),n,total/2+1);
		}else{
			return (findKth(A.begin(),m,B.begin(),n,total/2)+findKth(A.begin(),m,B.begin(),n,total/2+1))/2.0;
		}
	}
private:
	int findKth(std::vector<int>::const_iterator A,int m,
	std::vector<int>::const_iterator B,int n,int k){
		if(m>n) return findKth(B,n,A,m,k);
		if(m==0) return *(B+k-1);
		if(k==1) return std::min(*A,*B);

		int ia = std::min(k/2,m),ib=k-ia;
		if(*(A+ia-1)<*(B+ib-1))
			return findKth(A+ia,m-ia,B,n,k-ia);
		else if(*(A+ia-1)>*(B+ib-1))
			return findKth(A,m,B+ib,n-ib,k-ib);
		else
			return A[ia-1];
	}
};

int main(){
	int a[] = {1,3,5,7,9};
	int b[] = {2,4,6,8,10};
	std::vector<int> A(a,a+5);
	std::vector<int> B(b,b+5);
	Solution solution;
	double median = solution.findMedian(A,B);
	std::cout<<median<<std::endl;
	return 0;
}

