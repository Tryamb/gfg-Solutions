    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
    map<int,int> mm;
        for(auto i:intervals){
            mm[i[0]]++;
            mm[i[1]+1]--;
        }
        int temp=0,ans=-1;
        for(auto j:mm){
            if(temp>=k and j.second<0)ans=j.first-1;
            temp+=j.second;
            if(temp>=k)ans=j.first;
        }
        return ans;
    }