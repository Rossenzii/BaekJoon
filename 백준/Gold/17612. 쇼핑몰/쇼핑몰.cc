#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct checkout{
    int num;
    int waiting;
};
struct customer{
    int id;
    int checkout_num;
    int exit_time;
};

struct checkout_cmp
{
   bool operator()(checkout &a, checkout &b)
    {
       if(a.waiting==b.waiting) return a.num>b.num;
       return a.waiting>b.waiting;
   }
};
struct customer_cmp
{
    bool operator()(customer &a, customer &b)
    {
        if(a.exit_time == b.exit_time) return a.checkout_num<b.checkout_num;
        return a.exit_time > b.exit_time;
    }
};

int n,k,id,w,t,c_num,coeff=1;
long long ans;
priority_queue<checkout, vector<checkout>, checkout_cmp> pq_in;
priority_queue<customer, vector<customer>, customer_cmp> pq_out;


int main(){
    fastio;
    cin>>n>>k;
    for(int i=1; i<=k; i++){
        pq_in.push({i,0});
    }
    for(int i=0; i<n; i++){
        cin>>id>>w;
        t=pq_in.top().waiting+w;
        c_num=pq_in.top().num;
        
        pq_in.pop();
        pq_in.push({c_num,t});
        pq_out.push({id, c_num, t});
    }
    while(!pq_out.empty()){
        ans+=(long long) coeff*pq_out.top().id;
        coeff++;
        pq_out.pop();
    }
    cout<<ans;
    return 0;
}
