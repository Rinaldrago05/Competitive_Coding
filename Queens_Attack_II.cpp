#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,k,rq,cq,r,c,cnt=0;
    cin>>n>>k>>rq>>cq;

    vector<vector<int>> arr(8,vector<int>(2,0));

    /** o--> row
        1--> col
    **/

    /** 0 --> top
        1 --> right up
        2 --> right
        3 --> right down
        4 --> bottom
        5 --> left down
        6 --> left
        7 --> left up
    **/

    for(int i=0;i<k;i++)
    {
        cin>>r>>c;

        if(r>n ||c>n)
        continue;
        
        // vertical
        if(cq==c)
        {
            // top
            if(rq<r && (r<arr[0][0] || !arr[0][0]))
            {
                arr[0][0]=r;
                arr[0][1]=c;
            }

            // bottom
            else if(rq>r && (r>arr[4][0] || !arr[4][0]))
            {
                arr[4][0]=r;
                arr[4][1]=c;
            }
        }
        
        // horizontal
        else if(rq==r)
        {
            // left
            if(cq>c && (c>arr[6][1] || !arr[6][1]))
            {
                arr[6][0]=r;
                arr[6][1]=c;
            }

            // right
            else if(cq<c && (c<arr[2][1] || !arr[2][1]))
            {
                arr[2][0]=r;
                arr[2][1]=c;
            }
        }

        // right diagonal.
        else if(rq-r==cq-c)
        {
            // right up
            if(rq<r && (r<arr[1][0] || !arr[1][0]))
            {
                arr[1][0]=r;
                arr[1][1]=c;
            }

            // left down
            else if(rq>r && (r>arr[5][0] || !arr[5][0]))
            {
                arr[5][0]=r;
                arr[5][1]=c;
            }
        }

        // left diagonal
        else if(rq-r==c-cq)
        {
            // left up
            if(rq<r && (r<arr[7][0] || !arr[7][0]))
            {
                arr[7][0]=r;
                arr[7][1]=c;
            }

            // right down
            else if(rq>r && (r>arr[3][0] || !arr[3][0]))
            {
                arr[3][0]=r;
                arr[3][1]=c;
            }
        }
    }

    // top
    cnt+=(arr[0][0])?(arr[0][0]-rq-1):(n-rq);

    // bottom
    cnt+=(arr[4][0])?(rq-arr[4][0]-1):(rq-1);

    // right
    cnt+=(arr[2][1])?(arr[2][1]-cq-1):(n-cq);

    // left
    cnt+=(arr[6][1])?(cq-arr[6][1]-1):(cq-1);

    // right up 
    cnt+=(arr[1][0])?(arr[1][0]-rq-1):min(n-rq,n-cq);

    // right down
    cnt+=(arr[3][0])?(rq-arr[3][0]-1):min(n-cq,rq-1);

    // left up
    cnt+=(arr[7][0])?(arr[7][0]-rq-1):min(n-rq,cq-1);

    // left down
    cnt+=(arr[5][0])?(rq-arr[5][0]-1):min(cq-1,rq-1);

    /*
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[i].size();j++)
        cout<<arr[i][j]<<' ';
        cout<<endl;
    }
    */
   
    cout<<cnt;
}