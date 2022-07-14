#include <bits/stdc++.h> 
#define int long long 
#define mod 1000000007 
using namespace std; 
 
int power(int a, int b){ 
    if(b==0){ 
        return 1; 
    } 
    int res = 1; 
    while(b>0){ 
        if(b&1){ 
            res = (res*a)%mod; 
        } 
        a = (a*a)%mod; 
        b = b/2; 
    } 
    return res; 
} 
 
int gcd(int a,int b){ 
    if(a==0 || b==0){ 
        return a+b; 
    } 
 
    return gcd(b, a%b); 
} 
 
 
void solve(){ 
    int x, n;
    cin >> x >> n;
    set<int> s;
    s.insert(0);
    s.insert(x);
    multiset<int> mul;
    mul.insert(x);
    int q;
    for(int i = 0; i < n; i++){
        cin >> q;
        //Find left and right 
        //delete the diff and add the two differences
        auto it = s.lower_bound( q);
        int x2 = (*it);
        it--;
        int x1 = (*it);
        int gap = x2 - x1;
        it = mul.find(gap);
        mul.erase( it);
        s.insert( q);
        mul.insert( q - x1);
        mul.insert(x2 - q);
        cout << *mul.rbegin() << " ";
    }
} 
 
 
int32_t main(){ 
    int t = 1; 
    // cin >> t; 
    while(t--){ 
        solve(); 
    } 
} 