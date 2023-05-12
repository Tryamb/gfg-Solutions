class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        int ans=0,l=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
            {
                if(l!=0)
                  ans++;
                l=0;
            }
            else
              l++;
        }
        if(l==n)return -1;
        if(l)ans++;
        return ans;
    }
};
