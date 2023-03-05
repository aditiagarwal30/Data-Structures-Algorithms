class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        vector<int> vis(arr.size(), 0);
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        int jump=0;
        queue<int> q;
        q.push(0);
        vis[0]=1;

        while(!q.empty()){
            int sz= q.size();
            while(sz--){
                int ind= q.front();
                q.pop();
                if(ind== arr.size()-1) return jump;
                mp[arr[ind]].push_back(ind-1);
                mp[arr[ind]].push_back(ind+1);

                for(auto it: mp[arr[ind]]){
                    if(it>=0 and it< arr.size() and vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
                mp.erase(arr[ind]);
            }
            jump++;
        }
        return jump;
    }
};