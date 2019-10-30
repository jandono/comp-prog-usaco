/*
ID: andonov921
TASK: runround
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
#include <fstream>
#include <cmath>

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
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VC> VVC;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;


ifstream fin("runround.in");
ofstream fout("runround.out");

LL num;
LL best_diff = INT_MAX;
string solution = "";

void read_input(){
    fin >> num;
}

bool is_runround(string s){
    
    int n = s.size();
    VB check(n, 0);
    int cycle = 0;
    for(int i=0;i<n;i++){
        cycle = (cycle + (s[cycle] - '0')) % n;
        if(check[cycle])
            return false;
        check[cycle] = true;
    }

    return true;
}


LL diff(string s){
    stringstream ss(s);
    LL x;
    ss >> x;
    
    if(x - num <= 0)
        return INT_MAX;

    return x - num;
}

void gen_pems(VC curr, VB &visited, int length){

    if(curr.size() == length){
        string tmp = string(curr.begin(), curr.end());

        if(is_runround(tmp)){
            LL tmp_diff = diff(tmp);
            if(tmp_diff < best_diff){
                best_diff = tmp_diff;
                solution = tmp;
            } 
        }
        return;
    }

    for(int i=0;i<9;i++){
        if(!visited[i]){
            curr.push_back(i + 1 + '0');
            visited[i] = true;
            gen_pems(curr, visited, length);
            visited[i] = false;
            curr.pop_back(); 
        }
    }
}

void solve(){

    stringstream ss;
    ss << num;
    string s = ss.str();
    int length = s.size();

    for(int i=length;best_diff==INT_MAX;i++){
        VC curr;
        VB visited(9, false);
        gen_pems(curr, visited, i);
    }

    fout << solution << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
