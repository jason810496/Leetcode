#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        bool End=0;
        node* child[26];
        node(){
            for(int i=0;i<26;i++){
                child[i]=nullptr;
            }
        }
    };

    node* root = new node;
    vector< vector<string> > ans;
    vector< string > row;

    void Add(string &str){
        node* rt = root;
        for(char c : str){
            int id = c-'a';
            if( rt->child[id]==nullptr ){
                rt->child[id] = new node;
            }
            rt = rt->child[id];
        }

        rt->End = 1;
    }

    void Search(string &str){
        node* rt = root;
        for(char c : str ){
            int id = c-'a';
            if( rt->child[id]==nullptr ){
                ans.push_back( {} );
                return ;
            }
            rt = rt->child[id];
        }

        row.clear();
        Get(rt,str);
        ans.push_back( row );
    }

    void Get(node* rt,string &str){
        if( row.size()==3 ) return;
        if( rt->End ){
            row.push_back( str );
        }
        for(int i=0;i<26;i++){
            if( rt->child[i] ){
                str.push_back( char(i+'a') );
                Get( rt->child[i] , str );
                str.pop_back();
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(string &str : products ){
            Add(str);
        }

        for(int l=1;l<=searchWord.size();l++){
            string str = searchWord.substr(0,l);
            Search( str );
        }

        return ans;
    }
};