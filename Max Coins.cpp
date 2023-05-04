class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
    sort(ranges.begin(),ranges.end());
        vector<int> temp(n);
        temp[n-1]=ranges[n-1][2];
        
        for(int j=n-2;j>=0;j--)
        {
            temp[j]=max(temp[j+1],ranges[j][2]);
        }
          int answer=INT_MIN;
          
         for(int i=0;i<n;i++){
            int sum = ranges[i][2];
            int low = i+1,high=n-1,mid,t=0;
            while(low<=high){
                mid=(low+high)/2;
                if(ranges[mid][0]>=ranges[i][1]){
                    high=mid-1;
                    t=temp[mid];
                }
                else low=mid+1;
            }
            sum=sum+t;
            answer=max(sum,answer);
      }
       return answer;
  }
};