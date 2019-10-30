/*
ID: andonov921
TASK: holstein
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

ifstream fin("holstein.in");
ofstream fout("holstein.out");

int V, G;
VI requirements;
VVI foods;
VI solution;

void read_input(){
    fin >> V; // 1 <= V <= 25
    requirements.resize(V);
    for(int i=0;i<V;i++){
        fin >> requirements[i]; // 1 <= each <= 1000
    }

    fin >> G; // 1 <= G <= 15
    foods.resize(G, VI(V));
    for(int i=0;i<G;i++){
        for(int j=0;j<V;j++){
            fin >> foods[i][j]; // 0 <= each <= 1000
        }
    }
}

void subtract(int i){
    for(int j=0;j<V;j++){
        requirements[j] -= foods[i][j];
    }
}

void add(int i){
    for(int j=0;j<V;j++){
        requirements[j] += foods[i][j];
    }
}

bool check(){
    for(int i=0;i<V;i++){
        if(requirements[i] > 0)
            return false;
    }
    return true;
}

void recur(int i, VI &curr_solution){

    if(check()){
        if(!solution.size() || curr_solution.size() < solution.size()){
            solution = curr_solution;
        }
        return;
    }

    if(i >= G)
        return;

    subtract(i);
    curr_solution.push_back(i);
    recur(i + 1, curr_solution);
    curr_solution.pop_back();
    add(i);
    recur(i + 1, curr_solution);
}

void solve(){
    VI curr_solution;
    recur(0, curr_solution);
    
    fout << solution.size();
    for(auto el : solution){
        fout << " " << el + 1;
    }
    fout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
