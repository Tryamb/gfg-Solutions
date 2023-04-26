bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int c=0;
        for(int i=0;i<m;i++){
            if(seats[i]==0){
                if(i==0){
                    if(seats[1]==0){
                        c++;
                        seats[i]=1;
                    }
                }
                else if(i==m-1){
                    if(seats[i-1]==0){
                        c++;
                        seats[i]=1;
                    }
                }
                else{
                    if(seats[i-1]==0 && seats[i+1]==0){
                        c++;
                        seats[i]=1;
                    }
                }
            }
        }
        return c>=n;
    }