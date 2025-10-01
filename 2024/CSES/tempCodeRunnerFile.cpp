assert(numOfDigits!=1) ; 
        long long rank =  n-sumNumOfDigits ;
        cout<<rank<<endl;
        long long num =  pow(10,numOfDigits-1) + rank/numOfDigits + (rank%numOfDigits!=0) - 1 ; 
        cout<<num<<endl;
        int order =  rank%numOfDigits+ (rank%numOfDigits==0)*numOfDigits ;
        //  int order =  rank - (num-pow(10,numOfDigits-1))*numOfDigits ; 
        assert(order<=numOfDigits) ;
        auto getTheDigit = [](long long num , int order ) -> int 
        {
            string s = to_string(num) ; 
            return s[order-1] -'0' ; 
        } ; 
        cout<<order<<endl;
        cout<<getTheDigit(num,order)<<endl; 