class Solution {
  public:
    int bitMagic(int n, vector<int> &a) {
        int ans=0,i=0,j=n-1;
        while(i<j){
            if(a[i]!=a[j])ans++;
            i++;
            j--;
        }
        return ans/2 + ans%2;
    }
};