/*
ID: andonov921
TASK: ttwo
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
typedef vector<PII> VPII;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");

char field[10][10];
PII farmer, cow;
VPII ori_to_delta = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void read_input(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fin >> field[i][j];
            if(field[i][j] == 'F'){
                farmer = {i, j};
            }

            if(field[i][j] == 'C'){
                cow = {i, j};
            }
        }
    }
}

bool bad(int x, int y){
    if(x < 0 || x >= 10) return true;
    if(y < 0 || y >= 10) return true;
    return false;
}

void move(PII &el, int &ori){

    int el_i = el.first + ori_to_delta[ori].first;
    int el_j = el.second + ori_to_delta[ori].second;

    if(bad(el_i, el_j) || field[el_i][el_j] == '*'){
        ori++;
        ori %= 4;
    }else{
        el = {el_i, el_j};
    }
}

void solve(){
    int ori_farmer = 0, ori_cow = 0;
    int farmer_i, farmer_j, cow_i, cow_j;
    int max_confs = 400 * 400;

    for(int t=1;t<=max_confs;t++){

        move(farmer, ori_farmer);
        move(cow, ori_cow);

        if(cow == farmer){
            fout << t << "\n";
            return;
        }
    }
    fout << "0\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
