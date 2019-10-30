/*
ID: andonov921
TASK: milk3
LANG: C++                 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <fstream>
#include <string>

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

ifstream fin("milk3.in");
ofstream fout("milk3.out");

bool configs[21][21][21];
set<int> solution;
vector<int> capacities(3);
vector<int> buckets(3, 0);

void read_input(){
    for(int i=0;i<3;i++)
        // cin >> capacities[i];
        fin >> capacities[i];

    buckets[2] = capacities[2];
}

void recur(vector<int> &buckets){
    
    if(buckets[0] == 0){
        solution.insert(buckets[2]);
    }
    
    for(int i=0;i<3;i++){
        
        if(buckets[i] == 0) continue;

        for(int j=0;j<3;j++){
            
            if(i == j) continue;
            int pour = min(buckets[i], capacities[j] - buckets[j]);
            buckets[i] -= pour;
            buckets[j] += pour;
            if(!configs[buckets[0]][buckets[1]][buckets[2]]){
                configs[buckets[0]][buckets[1]][buckets[2]] = true;
                recur(buckets);
            }
            buckets[i] += pour;
            buckets[j] -= pour;
        }
    }
}

void solve(){

    recur(buckets);
    for(auto el : solution){
        
        if(el == *solution.rbegin())
            // cout << el << "\n";
            fout << el << "\n";
        else
            // cout << el << " ";
            fout << el << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read_input();
    solve();
    return 0;
}