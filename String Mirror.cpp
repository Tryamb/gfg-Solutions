class Solution{
public:
    string stringMirror(string str){
        // Code here
        string ans;
        int val0=str[0]-'a';
        int tillIndex=0;
        int n=str.length();
        for(int i=1;i<n;i++){
           int val=str[i]-'a';
           if(val<val0)
           {
              val0=val;
              tillIndex=i;
           }
           else if(val0==val and i!=1){
              val0=val;
              tillIndex=i;
           }
           else{
               break;
           }
          
        }
        ans=str.substr(0,tillIndex+1);
        string org=ans;
        reverse(ans.begin(), ans.end());
     return org+ans;
        
    }
    
};