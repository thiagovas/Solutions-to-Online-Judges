    #include<iostream>
    using namespace std;
    int main()
    {
        int arr[3][3];
        bool a[3][3]={1,1,1,1,1,1,1,1,1};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            cin>>arr[i][j];
            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                if((arr[i][j]+((i-1<0)?0:arr[i-1][j])+((i+1>2)?0:arr[i+1][j])+((j-1<0)?0:arr[i][j-1])+((j+1>2)?0:arr[i][j+1]))&1)
                    a[i][j]=0;
            }
        for(int i=0;i<3;i++)
        {


            for(int j=0;j<3;j++)



            cout<<a[i][j];


            cout<<"\n";
        }
    }
