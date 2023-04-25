int goodSubsets(vector<int> &arr, int n){
        int a[31]={0};
        a[2] = 1;
        a[3] = 2;
        a[5] = 4;
        a[6] = 3;
        a[7] = 8;
        a[10] = 5;
        a[11] = 16;
        a[13] = 32;
        a[14] = 9;
        a[15] = 6;
        a[17] = 64;
        a[19] = 128;
        a[21] = 10;
        a[22] = 17;
        a[23] = 256;
        a[26] = 33;
        a[29] = 512;
        a[30] = 7;
        unordered_map<int,int> f;
        int c=0;
        for(auto x:arr){
            if(x==1)c++;
            else f[x]++;
        }
        long long int dp[1024]={0};
        int mod = 1e9+7;
        dp[0]=1;
        for(auto x:f){
            if(a[x.first]!=0){
                for(int i=0;i<1024;i++){
                    if((a[x.first]&i)==0){
                        dp[(a[x.first]|i)]+=(x.second*dp[i]);
                        dp[(a[x.first]|i)]%=mod;
                    }
                }
            }
        }
        long long int sol=0;
        for(int i=1;i<1024;i++){
            sol+=dp[i];
            sol%=mod;
        }
        while(c--){
            sol*=2;
            sol%=mod;
        }
        return sol;

    }