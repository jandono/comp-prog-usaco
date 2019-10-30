/*
ID: andonov921
TASK: comehome
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
typedef pair<double, double> PDD;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<LL> VLL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VB> VVB;
typedef vector<VI> VVI;
typedef vector<VC> VVC;
typedef vector<VLL> VVLL;
typedef vector<VD> VVD;
typedef vector<VS> VVS;

ifstream fin("comehome.in");
ofstream fout("comehome.out");

#define cin fin
#define cout fout

int n, weight;
string from, to;
unordered_map<string, int> s2i;
unordered_map<int, string> i2s;

vector<vector<PII>> g;
VI distances;
VB visited;

void read_input(){
    cin >> n; // 1 <= n <= 10000
    
    string newline;
    getline(cin, newline);
    
    int curr = 0;
    for(int i=0;i<n;i++){
        cin >> from >> to >> weight;
        
        if(!s2i.count(from)){
            s2i[from] = curr;
            i2s[curr] = from;
            curr++;
            g.push_back(vector<PII>());
        }

        if(!s2i.count(to)){
            s2i[to] = curr;
            i2s[curr] = to;
            curr++;
            g.push_back(vector<PII>());
        }

        g[s2i[from]].push_back({s2i[to], weight});
        g[s2i[to]].push_back({s2i[from], weight});
    }
}

void dijkstra(){

    priority_queue<PII, vector<PII>, greater<PII>> pq;

    int curr = s2i["Z"];
    int curr_dist = 0;
    pq.push({curr_dist, curr});
    while(!pq.empty()){
        
        tie(curr_dist, curr) = pq.top(); pq.pop();
        if(visited[curr]) continue;

        visited[curr] = true;
        distances[curr] = curr_dist;

        for(auto neighbor : g[curr]){
            int to = neighbor.first;
            int weight = neighbor.second;
            if(!visited[to] && distances[to] > distances[curr] + weight){
                distances[to] = distances[curr] + weight;
                pq.push({distances[to], to});
            }
        }
    }
}

void solve(){

    int p = g.size();
    distances.resize(p, INT_MAX);
    visited.resize(p, false);
    dijkstra();

    int min_dist = INT_MAX;
    int min_idx = -1;
    for(int i=0;i<p;i++){
        
        if(i2s[i][0] >= 'Z') continue;

        if(distances[i] < min_dist){
            min_dist = distances[i];
            min_idx = i;
        }
    }

    cout << i2s[min_idx] << " " << min_dist << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_input();
    solve();
    return 0;
}
