#include<bits/stdc++.h>
using namespace std;

#define ll long long 
class NumMatrix {
public:
    vector< vector< ll > > prefix;
    int n , m;
    NumMatrix(vector<vector<int>>& matrix) {
        n= matrix.size();
        m= matrix[0].size();

        prefix.resize( n+1 , vector<ll>(m+1) );

        for(int i=1;i<=n;i++){
            for(int j=1,sum=0;j<=m;j++){
                sum+=matrix[i-1][j-1];
                prefix[i][j] = prefix[i-1][j] + sum;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<prefix[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return (prefix[row2][col2]+prefix[row1][col1]-prefix[row1][col2]-prefix[row2][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */