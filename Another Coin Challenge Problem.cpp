class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
       vector<vector<bool>> dpCoin(K+1,vector<bool>(target+1,false));
        dpCoin[0][0]=true;
        for(int i=0;i<N;i++){
            for(int j=1;j<=K;j++){
                for(int l=1;l<=target;l++){
                    if(coins[i]<=l and dpCoin[j][l]==false){
                        dpCoin[j][l]=dpCoin[j-1][l-coins[i]];
                    }
                }
            }
        }
        return dpCoin[K][target];
    }
};