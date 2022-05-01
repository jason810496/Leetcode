#include<bits/stdc++.h>
using namespace std;


#define F first
#define S second
#define ll long long 
#define all(x) x.begin(),x.end()
#define MEM(x,i) memset(x,i,sizeof(x))
#define rep(i,n) for(int i=0;i<n;++i)
#define REP(i,st,n) for(int i=st;i<=n;++i)
#define PB push_back
typedef pair<int,int> pii;
const int MAX_N = 100005;
const int INF = 1e9;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size() , m=nums2.size() ,half;
        half=(m+n)/2;

        priority_queue<int,vector<int> , greater<int> > Min_pq;
        priority_queue<int,vector<int> > Max_pq;

        int i=0,j=0;

        while( i<n&&j<m){
            if( nums1[i] < nums2[j]){
                Min_pq.push( nums1[i] );
                Max_pq.push( nums1[i] );
                i++;
            }
            else{
                Min_pq.push( nums1[j] );
                Max_pq.push( nums1[j] );
                j++;
            }
            if( Min_pq.size() > half ) Min_pq.pop();
            if( Max_pq.size() > half ) Max_pq.pop();
        }

        while(i<n){
            Min_pq.push( nums1[i] );
            Max_pq.push( nums1[i] );
            i++;
            if( Min_pq.size() > half ) Min_pq.pop();
            if( Max_pq.size() > half ) Max_pq.pop();
        }

        while(j<m){
            Min_pq.push( nums1[j] );
            Max_pq.push( nums1[j] );
            j++; 
            if( Min_pq.size() > half ) Min_pq.pop();
            if( Max_pq.size() > half ) Max_pq.pop();   
        }

        return ( Min_pq.top()+Max_pq.top() )/2;
    }
};