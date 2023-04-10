class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int> mp;
        for(auto line:lines){
            int st=line[0];
            int en=line[1];
            mp[st]++;
            mp[en+1]--;
        }
        int maxi=1;
        int presum=0;
        for(auto it:mp){
            presum+=it.second;
            maxi=max(maxi,presum);
        }
            
        return maxi;
    }
};
