 vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        stack<int> st;
        int left[n],right[n];
        vector<int> ans(n);

      
        for(int i=0;i<n;i++){
            while(st.size() && arr[st.top()]>=arr[i])st.pop();
            if(st.size())left[i]=st.top();
            else left[i]=-1;
            st.push(i);
        }

        while(st.size())st.pop();

       
        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[st.top()]>=arr[i])st.pop();
            if(st.size())right[i]=st.top();
            else right[i]=-1;
            st.push(i);
        }

        for(int i=0;i<n;i++){
            if(left[i]==right[i])ans[i]=-1;
            else if(left[i]==-1)ans[i]=right[i];
            else if(right[i]==-1)ans[i]=left[i];
            else if(i-left[i]<right[i]-i)ans[i]=left[i];
            else if(i-left[i]>right[i]-i)ans[i]=right[i];
            else if(arr[right[i]]<arr[left[i]])ans[i]=right[i];
            else ans[i]=left[i];
        }
        return ans;
    }