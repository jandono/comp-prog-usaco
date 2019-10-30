/*
ID: andonov921
TASK: hamming
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
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<vector<LL>> VVL;

ifstream fin("hamming.in");
ofstream fout("hamming.out");

int N, B, D;
VI solution;
VVI dist;

void read_input(){
    fin >> N >> B >> D; // 1 <= N <= 64, 1 <= B <= 8, 1 <= D <=7
}

int diff(int x, int y){
    int tmp = x ^ y;
    int count = 0;
    for(int i=0;i<B;i++){
        if(tmp & (1 << i))
            count++;
    }
    return count;
}

bool eval(int j){
    for(auto sol : solution){
        if(dist[j][sol] < D)
            return false;
    }
    return true;
}

void solve(){
    int limit = 1 << B;
    dist.resize(limit, VI(limit, 0));
    for(int i=0;i<limit;i++){
        for(int j=i+1;j<limit;j++){
            dist[i][j] = diff(i, j);
            dist[j][i] = dist[i][j];
        }
    }
    
    while(solution.size() != N){
        int start = (solution.size() > 0) ? solution.back() : 0;
        for(int j=start;j<limit;j++){
            if(eval(j)){
                solution.push_back(j);
                break;
            }
        }
    }

    for(int i=0;i<N;i++){
        if((i + 1) % 10 == 0 || i == N-1)
            fout << solution[i] << "\n";
        else
            fout << solution[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
