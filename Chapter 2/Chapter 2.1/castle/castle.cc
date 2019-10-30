/*
ID: andonov921
TASK: castle
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <queue>
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
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<vector<int>> VVI;
typedef vector<vector<LL>> VVL;

ifstream fin("castle.in");
ofstream fout("castle.out");

int n, m;
VVI mat, components;
unordered_map<int, int> component_to_size;
int ii[4] = {-1, +1, 0, 0};
int jj[4] = {0, 0, -1, +1};

int dir(int k){
    if(k == 0) return 2;
    if(k == 1) return 8;
    if(k == 2) return 1;
    return 4;
}

void read_input(){
    fin >> m >> n; // 1 <= M, N <=50
    mat.resize(n, VI(m, -1));
    components.resize(n, VI(m, -1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fin >> mat[i][j];
        }
    }
}

int fill(int start_i, int start_j, int comp){
    int size = 1;
    queue<PII> q;
    q.push({start_i, start_j});
    int i, j;
    while(!q.empty()){
        tie(i, j) = q.front(); q.pop();

        for(int k=0;k<4;k++){
            int new_i = i + ii[k];
            int new_j = j + jj[k];
            int direction = dir(k);
            if(new_i < 0 || new_i >= n) continue;
            if(new_j < 0 || new_j >=m ) continue;
            if(components[new_i][new_j] != -1) continue;
            
            if(!(mat[i][j] & direction)){
                components[new_i][new_j] = comp;
                size++;
                q.push({new_i, new_j});
            }
        }
    }

    return size;
}

void solve(){
    int comp = 0;
    int max_size_room = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(components[i][j] != -1) continue;

            components[i][j] = comp;
            component_to_size[comp] = fill(i, j, comp);
            max_size_room = max(max_size_room, component_to_size[comp]);
            comp++;
        }
    }
    fout << comp << "\n";
    fout << max_size_room << "\n";

    int best_i, best_j;
    string wall;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int c_ij = components[i][j];

            if(j + 1 < m){
                int c_right = components[i][j + 1];
                int direction = 4;
                int new_val_right = component_to_size[c_ij] + component_to_size[c_right];
                if(c_ij != c_right && (mat[i][j] & direction) && new_val_right >= max_size_room){
                    if(new_val_right == max_size_room && j > best_j) continue;
                    best_i = i;
                    best_j = j;
                    wall = "E";
                    max_size_room = component_to_size[c_ij] + component_to_size[c_right];
                }
            }

            if(i - 1 >= 0){
                int c_up = components[i-1][j];
                int direction = 2;
                int new_val_up = component_to_size[c_ij] + component_to_size[c_up];
                if(c_ij != c_up && (mat[i][j] & direction) && new_val_up >= max_size_room){
                    if(new_val_up == max_size_room && j > best_j) continue;
                    best_i = i;
                    best_j = j;
                    wall = "N";
                    max_size_room = component_to_size[c_ij] + component_to_size[c_up];
                }
            }
        }
    }
    fout << max_size_room << "\n";
    fout << best_i + 1 << " " << best_j + 1 << " " << wall << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
