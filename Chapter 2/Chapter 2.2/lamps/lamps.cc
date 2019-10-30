/*
ID: andonov921
TASK: lamps
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

ifstream fin("lamps.in");
ofstream fout("lamps.out");

int num_lamps, button_presses, x;
bool solved = false;
VI final_conf(6, -1); // -1 = whatever, 1 = on, 0 = off

void read_input(){
    fin >> num_lamps; // 10 <= num_lamps <= 100
    fin >> button_presses; // 0 <= button_presses <= 10000
    
    while(fin >> x && x != -1){
        final_conf[(x-1) % 6] = 1;
    }

    while(fin >> x && x != -1){
        if(final_conf[(x-1) % 6] == 1){
            solved = true;
            fout << "IMPOSSIBLE\n";
            return;
        }
        final_conf[(x-1) % 6] = 0;
    }
}

bool check(VI &conf){

    for(int i=0;i<final_conf.size();i++){
        if(final_conf[i] != -1 && final_conf[i] != conf[i])
            return false;
    }

    return true;
}

void update(VI &conf, int option){
    int start, inc;

    if(option == 0){
        start = 0;
        inc = 1;
    }else
    if(option == 1){
        start = 0;
        inc = 2;
    }else
    if(option == 2){
        start = 1;
        inc = 2;
    }else{
        start = 0;
        inc = 3;
    }

    for(int i=start;i<conf.size();i+=inc){
        conf[i] = (conf[i]) ? 0 : 1;
    }
}

void print(VI &conf){

    for(int i=0;i<num_lamps;i++){
        fout << conf[i % 6];
    }
    fout << "\n";
}

void solve(){
    
    if(solved)
        return;

    set<VI> solution;

    int limit = 1 << 4;
    for(int i=0;i<limit;i++){
        VI conf(6, 1);
        int ones = 0;
        for(int j=0;j<4;j++){
            if(i & (1 << j)){
                ones++;
                update(conf, j);
            }
        }
        
        if(button_presses == 0 && ones != 0) continue;
        if(button_presses == 1 && ones != 1) continue;

        if(check(conf)){
            solution.insert(conf);
        }
    }

    if(!solution.size()){
        fout << "IMPOSSIBLE\n";
        return;
    }

    for(auto conf : solution){
        print(conf);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
