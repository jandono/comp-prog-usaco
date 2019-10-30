/*
ID: andonov921
TASK: zerosum
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
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int n;
unordered_map<char, int> char_to_mul;
vector<char> options = {'+', '-', ' '};
set<string> solution;

void read_input(){
    fin >> n; // 3 <= n <= 9
}

bool eval(vector<char> &seq){
    
    int res = 0, mul = 1, tmp;
    stringstream curr;
    for(int i=0;i<seq.size();i++){
        if(seq[i] == ' ') continue;

        if(seq[i] == '+' || seq[i] == '-'){
            curr >> tmp;
            res += tmp * mul;
            mul = char_to_mul[seq[i]];
            curr = stringstream();
        }else{
            curr << seq[i];
        }
    }

    curr >> tmp;
    res = res + tmp*mul;
    return res;
}

void gen_seq(vector<char> &seq, int i){
    
    if(i == n + 1){
        if(!eval(seq)){
            solution.insert(string(seq.begin(), seq.end()));
        }
        return;
    }

    seq.push_back(i + '0');
    
    if(i == n){
        gen_seq(seq, i + 1);
    }else{
        for(auto op : options){
            seq.push_back(op);
            gen_seq(seq, i + 1);
            seq.pop_back();
        }   
    }
    seq.pop_back();
}

void solve(){
    char_to_mul['-'] = -1;
    char_to_mul['+'] = 1;
    vector<char> seq;
    gen_seq(seq, 1);
    for(auto sol : solution){
        fout << sol << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
