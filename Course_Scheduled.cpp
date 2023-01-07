class Solution {
public:
     bool dfscheck(int node,vector<int> &vis,vector<int> &dfsvis,vector<int> adj[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(dfscheck(it,vis,dfsvis,adj))
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(dfscheck(i,vis,dfsvis,adj))
                    return false;
            }
        }
        return true;
    }
};




