/*
ID: andonov921
TASK: ariprog
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

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

bool check(int a, int b, int n, const int LIMIT, vector<bool> &s){

    for(int i=a;i<=LIMIT;i+=b){
        if(!s[i])
            return false;

        n--;
        if(!n)
            return true;
    }

    return false;
}

void solve(int n, int m){

    vector<II> solution;
    const int LIMIT = m*m + m*m;
    vector<bool> s(LIMIT+ 1, false);
    vector<int> v;
    for(int i=0;i<=m;i++){
        for(int j=i;j<=m;j++){
            int el = i*i + j*j;
            if(!s[el]){
                v.push_back(el);
                s[el] = true;
            }
        }
    }
    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){

            int a = v[i];
            int b = v[j] - v[i];
            if(check(a, b, n, LIMIT, s)){
                solution.push_back({a, b});
            }
        }
    }

    auto lambda = [](auto &lhs, auto &rhs){
        if(lhs.second == rhs.second)
            return lhs.first < rhs.first;

        return lhs.second < rhs.second;
    };

    sort(solution.begin(), solution.end(), lambda);
    if(!solution.size()){
        // cout << "NONE\n";
        fout << "NONE\n";
        return;
    }

    for(auto el : solution){
        // cout << el.first << " " << el.second << "\n";
        fout << el.first << " " << el.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    // cin >> n >> m;
    fin >> n >> m;
    solve(n, m);
    return 0;
}