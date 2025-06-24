#include <bits/stdc++.h>
using namespace std;
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
       int n=adj.size();
       vector<int>ans(n,INT_MAX);
       ans[src]=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>s;
       s.push({0,src});
       while(s.size())
       {
           auto it=s.top();
           int node=it.second;
           int wt=it.first;
           s.pop();
           for(auto itt:adj[node])
           {
              int wtt=itt.second;
              int adjnode=itt.first;
              if(wt+wtt<ans[adjnode])
              {
                  ans[adjnode]=wt+wtt;
                  s.push({ans[adjnode],adjnode});
              }
           }
       }
      return ans;
    }

