#include<bits/stdc++.h>
using namespace std;

void k_sum_subsets(int i, int n, int k, vector<int> &A, set<int> &dp, vector<set<int>> &sets){
    if(k == 0){
        sets.push_back(dp);
        return;
    }
    if(i == n) return;
    if(A[i] <= k){
        dp.insert(A[i]);
        k_sum_subsets(i+1, n, k-A[i], A, dp, sets);
        dp.erase(A[i]);
    }
    k_sum_subsets(i+1, n, k, A, dp, sets);
}

void f(int i, vector<set<int>> &sets, map<int, set<int>> &G, int n, vector<map<int,set<int>>> &Ans){
    if(i == n+1){
        Ans.push_back(G);
        return;
    }
    for(auto s : sets){
        if(s.count(i))
            continue;
        
        int flag = 1;
        for(auto e : s){
            if(G.find(e) == G.end())
                continue;
            if(!G[e].count(i)){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            G[i] = s;
            f(i+1, sets, G, n, Ans);
            G.erase(i);
        }
    }
}

void printGraph(vector<map<int,set<int>>> &Ans){
    int count = 1;
    for(auto g : Ans){
            cout<<"Graph "<<count<<" :\n";
            for(auto m : g){
                cout<<m.first<<"\t";
                for (auto it = m.second.begin(); it != m.second.end(); ++it)
                    cout<< *it<<" ";
                cout<<"\n";
            }
            count++;
        }
}
void construct_all_graphs(int n, int k){
    vector<int> A(n);
    iota(A.begin(), A.end(), 1);
    vector<set<int>> sets;
    set<int> dp;
    k_sum_subsets(0, n, k, A, dp, sets);
    //vector<set<int>> sets = {{2,3,5},{1,5,4},{1,2,3,4}}; //{{1,2,5,6,7},{3,5,6,7},{1,3,4,6,7},{2,3,4,5,7},{1,2,3,4,5,6}};//
    map<int, set<int>> G;
    vector<map<int,set<int>>> Ans;
    f(1, sets, G, n, Ans);

    // Print all graphs
    if(Ans.empty()){
        cout<<"NO Graph is Possible\n";
    }
    else{
        printGraph(Ans);
    }
}


int main(){
    // Just supply n and k values as inputs and get all possible graphs.
    int n = 10;
    int k = 20;
    construct_all_graphs(n,k);
}