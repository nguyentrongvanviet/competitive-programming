for(int i = 3;i<=n;i++)
    {
        for(int j=2 ;j<=i-1;j++)
        {
            int pos = np1(1,j-1,a[i].l-a[j].l);
            if(pos==j)continue;
            res=(res+j-pos)%sm ;
        }
    }   