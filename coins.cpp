int totalTime(int n, vector<int> &arr, vector<int> &time) {
    map<int,int>mp;
        int count=0;
        mp[arr[0]] = 1;
        //int counter=0;
         for(int i=1;i<n;i++)
         {
             if(mp.find(arr[i])==mp.end()){
              mp.insert({arr[i],1});
              count+=1;
            
             }
             else{
                 count+=time[arr[i]-1];
                 
             }
         }
         return count;
    }