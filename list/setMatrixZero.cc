#include "leet.h"

class Solution
{
public:
    void setZeros(std::vector<std::vector<int> > &matrix){
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        bool row_has_zeros = false;
        bool col_has_zeros = false;

        for(size_t i=0;i<n;++i){
            if(matrix[0][i]==0){
                row_has_zeros = true;
                break;
            }
        }

        for(size_t i=0;i<m;++i){
            if(matrix[i][0]==0){
                col_has_zeros = true;
                break;
            }
        }

        for(size_t i=0;i<m;++i){
            for(size_t j=i;j<n;++j){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }

        for(size_t i=1;i<m;++i){
            for(size_t j=1;j<n;++j){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(row_has_zeros){
            for(size_t j=1;j<n;++j){
                matrix[0][j] = 0;
            }
        }

        if(col_has_zeros){
            for(size_t j=1;j<m;++j){
                matrix[j][0] = 0;
            }
        }
    }
};
