class Solution {
public:
    vector<int> sz , p;
    
    int Find(int x){
        return (p[x] == x ? x:p[x] = Find(p[x]) );
    }

    void Union(int a,int b){
        a = Find(a);
        b = Find(b);

        if( sz[b] > sz[a] ){
            swap(a,b);
        }

        sz[a]+=sz[b];
        p[b] = a;
    }

    int validSubarraySize(vector<int>& nums, int threshold) {
        // init dsu
        int n = nums.size();
        sz.resize(n,1);
        p.resize(n,-1);

        vector<int> idx(n);
        for(int i=0;i<n;i++){
            idx[i]=i;
        }

        sort(idx.begin(),idx.end(),[&](const int a,const int b){
            return nums[a]>nums[b];
        });

        for(int i : idx){
            p[i] = i;
            // left
            if( i-1>=0 && p[i-1] != -1 ){
                Union(i,i-1);
            }
            // right
            if( i+1<n && p[i+1] != -1 ){
                Union(i,i+1);
            }

            long long curSize = sz[Find(i)];
            if( curSize*nums[i] > threshold ){
                return curSize;
            }
        }

        return -1;
    }
};

