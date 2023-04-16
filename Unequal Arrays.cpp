long long solve(int n, vector<int> &a, vector<int> &b) {
        long long opr=0,sum=0;
        vector<int>a_even;
        vector<int>a_odd;
        vector<int>b_even;
        vector<int>b_odd;
         sort(a.begin(),a.end());
         sort(b.begin(),b.end());
        
         for(int i=0;i<n;i++){
             sum+=a[i]-b[i];
             if(a[i]%2==0){
                 a_even.push_back(a[i]);
             }
              if(a[i]%2!=0){
                 a_odd.push_back(a[i]);
             }
              if(b[i]%2==0){
                 b_even.push_back(b[i]);
             }
              if(b[i]%2!=0){
                 b_odd.push_back(b[i]);
             }
         }
         if(sum==0 and a_even.size()==b_even.size() and a_odd.size()==b_odd.size()){
            for(int i=0;i<a_even.size();i++){
                opr+=abs(a_even[i]-b_even[i])/2;
            }
            for(int i=0;i<a_odd.size();i++){
             opr+=abs(a_odd[i]-b_odd[i])/2;
            }
            return opr/2;
         }
        else
          return -1;
    }