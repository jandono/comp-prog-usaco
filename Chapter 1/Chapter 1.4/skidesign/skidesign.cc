/*
ID: andonov921
TASK: skidesign
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
typedef pair<int, int> II;
typedef vector<int> VI;

int solve(vector<int> &hills, int mini, int maxi){
    
    const int LIMIT = 17;
    int res = INT_MAX;
    for(int i=mini;i<=maxi;i++){
        int tmp_res = 0;
        for(auto hill : hills){
            if(hill < i)
                tmp_res += (i - hill) * (i - hill);
            else
            if(hill > i + LIMIT)
                tmp_res += (hill - i - LIMIT) * (hill - i - LIMIT);
        }
        
        res = min(res, tmp_res);
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int n;
    fin >> n;
    // cin >> n;
    vector<int> hills(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        fin >> hills[i];
        // cin >> hills[i];
        mini = min(mini, hills[i]);
        maxi = max(maxi, hills[i]);
    }

    int res = solve(hills, mini, maxi);
    fout << res << "\n";
    // cout << res << "\n";
    return 0;
}