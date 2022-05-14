#define Dist first
#define Node second
#define To first
#define Wt second
#define pii pair<int,int>
class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector< vector< pii> > G(n+1);
        vector<int> Dis(n+1 , 1e9 ) ;
        bitset<105> vis;
        
        for(const auto &e:edges){
            
            G[ e[0] ].push_back( { e[1] , e[2] } );
        }
        
        int Total = n*(n+1)/2 , ans = 1e9;
        
        priority_queue< pii , vector< pii > ,greater<pii> > pq; // 
        
        pq.push( {0,k} );
        Dis[k] = 0;
        
        while( pq.size() ){
            int st = pq.top().Node ; 
            pq.pop();
            
            if( !vis[ st ] ){
                vis[ st ] = 1;
                Total -= st ;
            }
            else continue ;
            
            for(const auto &e : G[ st ] ){
                if( Dis[st]+e.Wt < Dis[ e.To ] ){
                    Dis[ e.To ] = Dis[st]+e.Wt;
                    
                    pq.push( { Dis[e.To] , e.To } );
                }
            }
        }
        
        return (Total ? -1: *max_element( Dis.begin()+1 ,Dis.end()) );
    }
};