#include<bits/stdc++.h>
using namespace std;

int f(int T, vector<int> &A){
    if(T == 0) return 1;
    if(T < 0 ) return 0;
    int result = 0;
    for(auto a : A){
        result = result || f(T - a, A);
    }
    return result;
}
int f1(int T, vector<int> &A){ // number of solutions
    if(T == 0) return 1;
    if(T < 0) return 0;
    int ans = 0;
    for(auto a : A){
        ans = ans + f1(T-a, A); 
    }
    return ans;
}

int f2(int T, vector<int> &A){ // minimum number of entities in solution
    if(T == 0 ) return 0;
    if(T < 0 ) return 1e9;
    int ans = 1e9;
    for(auto a : A){
        ans = min(ans, f2(T-a, A)+1);
    }
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int testcases;
    cin>>testcases;
    while(testcases--){
        vector<int> A;
        int n;
        int T;
        cout<<"TestCase:"<<testcases+1<<"\n";
        cin>>T;
        cin>>n;
        for(int i = 0 ; i<n ; i++){
            int e;
            cin>>e;
            A.push_back(e);
        }
       int ans1 = f(T, A);
       cout<<ans1<<"\n";
       if(ans1){
        int ans2 = f1(T, A);
        cout<<ans2<<"\n";
        int ans3 = f2(T, A);
        cout<<ans3<<"\n";
       }
       else
       cout<<0<<"\n"<<0<<"\n";
    }
}