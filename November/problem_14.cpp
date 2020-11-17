 int rot = minutesToTest/minutesToDie;
    int i=0;
    int sum=0;
    
    
    if(rot==0)
        return 0;
    
    while(sum<buckets){
        sum = pow(rot+1,i);
        if(sum<buckets)
            i++;
        else
            break;
    }
    return i;
