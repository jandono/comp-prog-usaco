/*
ID: andonov921
TASK: wormhole
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <fstream>
#include <string>

using namespace std;

/// ********* debug template by Bidhan Roy *********

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const unordered_set< T > &v ) {
    os << "[";
    typename unordered_set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const unordered_map< F, S > &v ) {
    os << "[";
    typename unordered_map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << ": " << it -> second ;
    }
    return os << "]";
}

#define debug(x) cerr << #x << " = " << x << endl;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int check_cycle(vector<int> &paired, vector<int> &next_hole){
    
    int n = paired.size();
    for(int i=0;i<paired.size();i++){
        int pos = i;
        for(int count=0;count<n;count++){
            pos = next_hole[paired[pos]];
            if(pos == INT_MAX) break;
        }

        if(pos != INT_MAX)
            return 1;
    }

    return 0;
}

int solve(vector<int> &paired, vector<int> &next_hole){

    int to_be_paired = -1;
    int n = paired.size();
    for(int i=0;i<n;i++){
        if(paired[i] == i){
            to_be_paired = i;
            break;
        }
    }
    
    if(to_be_paired == -1)
        return check_cycle(paired, next_hole);

    int res = 0;
    for(int j=to_be_paired+1;j<n;j++){

        if(paired[j] == j){
            paired[to_be_paired] = j;
            paired[j] = to_be_paired;
            res += solve(paired, next_hole);
            paired[to_be_paired] = to_be_paired;
            paired[j] = j;
        }
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    
    int n;
    fin >> n;
    LL x, y;
    vector<PLL> wormholes;
    for(int i=0;i<n;i++){
        fin >> x >> y;
        wormholes.push_back({y, x});
    }
    sort(wormholes.begin(), wormholes.end());
    
    vector<int> next_hole(n, INT_MAX);
    for(int i=0;i<n-1;i++){

        if(wormholes[i].first != wormholes[i+1].first) 
            continue;
        
        next_hole[i] = i + 1;
    }

    debug(next_hole);

    vector<int> paired;
    for(int i=0;i<n;i++) paired.push_back(i);

    fout << solve(paired, next_hole) << "\n";

    return 0;
}