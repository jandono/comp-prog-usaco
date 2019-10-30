/*
ID: andonov921
TASK: maze1
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
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VS> VVS;

ifstream fin("maze1.in");
ofstream fout("maze1.out");

int W, H, n, m;
vector<PII> exits;
VVI dist;
VVB visited;
VS maze;
int ii[4] = {-1, 1, 0, 0};
int jj[4] = {0, 0, -1, 1};

void read_input(){
    fin >> W >> H;
    n = 2*H + 1;
    m = 2*W + 1;
    maze.resize(n);

    string newline;
    getline(fin, newline);

    for(int i=0;i<n;i++){
        getline(fin, maze[i]);
        for(int j=0;j<m;j++){
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && maze[i][j] == ' ')
                exits.push_back({i, j});
        }
    }
}

void bfs(PII start){
    
    int curr_i, curr_j, level;
    queue<pair<PII, int>> q;

    visited[start.first][start.second] = true;
    dist[start.first][start.second] = 0;
    q.push({start, 0});
    while(!q.empty()){
        auto curr = q.front(); q.pop();
        tie(curr_i, curr_j) = curr.first;
        level = curr.second;
        
        for(int k=0;k<4;k++){
            int new_i = curr_i + ii[k];
            int new_j = curr_j + jj[k];

            if(new_i < 0 || new_i >= n) continue;
            if(new_j < 0 || new_j >= m) continue;
            if(visited[new_i][new_j]) continue;
            if(maze[new_i][new_j] != ' ') continue;

            visited[new_i][new_j] = true;
            dist[new_i][new_j] = min(dist[new_i][new_j], level + 1);
            q.push({{new_i, new_j}, level + 1});
        }
    }
}

void solve(){
    
    dist.resize(n, VI(m, INT_MAX));
    for(auto exit : exits){
        visited = VVB(n, VB(m, false));
        bfs(exit);
    }

    int max_dist = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == ' ')
                max_dist = max(max_dist, dist[i][j]);
        }
    }

    fout << (max_dist + 1) / 2  << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
