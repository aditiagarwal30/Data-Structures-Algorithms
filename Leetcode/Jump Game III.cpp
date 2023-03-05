class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<arr.size();i++){
            mp[i].push_back(i+arr[i]);
            mp[i].push_back(i-arr[i]);
        }
        vector<int> vis(arr.size(),0);
        vis[start]=1;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                int node= q.front();
                q.pop();
                if(arr[node]==0) return true;
                for(auto it: mp[node]){
                    if(it>=0 and it<arr.size() and vis[it]==0){
                        q.push(it);
                        vis[it]==1;
                    }
                }
                mp.erase(node);
            }
        }
        return false;
    }
};