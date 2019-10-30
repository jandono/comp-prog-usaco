/*
ID: andonov921
TASK: cowtour
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
#include <iomanip>

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

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");

#define cin fin
#define cout fout

int n;
VS g;
vector<PDD> locs;
VVD dist;
VD furthest;
double diff = 1000000.0;
double INF = sqrt(diff * diff + diff * diff);

void read_input(){
    cin >> n; // 1 <= n <= 150
    locs.resize(n);
    for(int i=0;i<n;i++){
        cin >> locs[i].first >> locs[i].second;
    }
    string newline;
    getline(cin, newline);

    g.resize(n);
    for(int i=0;i<n;i++){
        getline(cin, g[i]);
    }
}

double distance(int i, int j){
    
    if(i == j) return 0;

    double a = (locs[i].first - locs[j].first);
    double b = (locs[i].second - locs[j].second); 
    return sqrt(a*a + b*b);
}

void solve_furthest(int source){

    for(int i=0;i<n;i++){
        if(dist[source][i] == INF) continue;
        furthest[source] = max(furthest[source], dist[source][i]);
    }
}

void solve(){
    dist.resize(n, VD(n, INF));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j] = (g[i][j] == '0') ? INF : distance(i, j);
        }
        dist[i][i] = 0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    furthest.resize(n, 0);
    for(int i=0;i<n;i++){
        solve_furthest(i);
    }

    double result = LLONG_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(dist[i][j] != INF || i == j) continue;

            result = min(result, furthest[i] + furthest[j] + distance(i, j));
        }
    }

    for(int i=0;i<n;i++){
        result = max(result, furthest[i]);
    }

    cout << fixed << setprecision(6) << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << fixed << setprecision(6) << INF << "\n";
    read_input();
    solve();
    return 0;
}
