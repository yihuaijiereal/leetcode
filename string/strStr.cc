#include "leet.h"

class Solution{
public:
    int strStr(string &haystack,string &needle){
        if(needle.empty()) return 0;

        const int N = haystack.size()-needle.size()+1;
        for(int i=0;i<N;++i){
            int j=i;
            int k=0;
            while(j<haystack.size()&&k<needle.size()&&haystack[j]==needle[k]){
                ++j;
                ++k;
            }
            if(k==needle.size()){
                return i;
            }
        }
        return -1;
    }

    int kmp(const string &haystack,const string &needle){
        int i;
        int j=-1;
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) {
            return 0;
        }

        int *next = (int*)malloc(m*sizeof(int));

        for(i=0;i<n;++i){
            while(j>-1&&needle[j+1]!=haystack[i]){
                j = next[j];
            }
            if(haystack[i]==needle[j+1]){
                ++j;
            }
            if(j==m-1){
                free(next);
                return i-j;
            }
        }
        free(next);
        return -1;
    }
private:
    void getNext(const string &needle,int next[]){
        int i;
        int j=-1;
        next[0]=j;
        const int m = needle.size();

        for(int i=0;i<m;++i){
            if(j>-1&&needle[j+1]!=needle[i]){
                j = next[j];
            }
            if(needle[j+1]==needle[i]){
                ++j;
            }
            next[i] = j;
        }
    }
};

int main(int argc,char *argv[]){
    if(argc!=3){
        cout<<"usage: "<<"strStr haystack needle"<<endl;
    }
    string haystack = argv[1];
    string needle = argv[2];
    Solution solution;
    int r = solution.strStr(haystack,needle);
    int r2 = solution.kmp(haystack,needle);
    cout<<r<<" "<<r2<<endl;
    return 0;
}
