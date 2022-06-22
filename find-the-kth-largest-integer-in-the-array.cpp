class Solution {
public:
    
    struct cmp{
        bool operator()(const string &a , const string &b){
            if( a.size() == b.size() ){
                int n=a.size();
                for(int i=0;i<n;i++){
                    if( a[i]!=b[i] ) return a[i] > b[i];
                }
            }
            
            return a.size() > b.size();
        }  
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue< string , vector< string > ,cmp > pq;
        
        for(const string &i : nums ){
            pq.push( i );
            if( pq.size() > k ) pq.pop();
        }
        
        return pq.top();
    }
};