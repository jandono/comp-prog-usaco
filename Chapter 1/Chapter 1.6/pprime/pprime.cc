/*
ID: andonov921
TASK: pprime
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
#include <cmath>
#include <cassert>
#include <sstream>

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
typedef vector<int> VI;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

int a, b;
set<int> solution;

void read_input(){
    // cin >> a >> b;
    fin >> a >> b; // 5 <= a < b <= 100,000,000
}

bool prime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

bool pal(int x){
    int tmp_x = x;
    int rev_x = 0;
    while(tmp_x){
        rev_x = rev_x*10 + tmp_x%10;
        tmp_x /= 10;
    }
    return rev_x == x;
}

void gen_palindromes(string &curr){

    int x;
    stringstream ss(curr);

    if(curr.size() > 11)
        return;

    if(curr.size()){
        ss >> x;
        
        if(x > b)
            return;
        
        if(x >= a && pal(x) && prime(x)){
            solution.insert(x);
        }
    }

    for(int i=0;i<10;i++){
        string tmp = curr;
        curr = string(1, '0' + i) + curr + string(1, '0' + i);
        gen_palindromes(curr);
        curr = tmp;
    }
}

void solve(){

    if(11 >= a && 11 <= b)
        solution.insert(11);

    for(int i=0;i<10;i++){
        string s = string(1, '0' + i);
        gen_palindromes(s);
    }

    for(auto el : solution){

        // cout << el << "\n";
        fout << el << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}