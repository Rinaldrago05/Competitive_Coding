#include<iostream>
#include<vector>
using namespace std;
void input(vector<int> &arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
}

int fnc(vector<int> &vec,vector<int> &temp)
{
    int left_ind=temp[0],right_ind=temp.back();    
    int left_val=vec[left_ind],right_val=vec[right_ind];
    int truth_value=1;
    
    //Inward checking if need to do.
    //No need to check when the two comsidered indeces are next adjacent indeces.
    if(right_ind-left_ind!=1)
    {
        if(right_val<vec[left_ind+1] && left_val>vec[right_ind-1])
        truth_value=1;
        else
        return 0;
        //truth_value=0;
    }
    
    //Outward check if need to do.
    //If there is something to be checked on the left of the leftmost considered index.
    if(left_ind>0)
    {
        if(right_val>vec[left_ind-1])
        truth_value=1;    
        else
        return 0;
    }
    //If there is something to be checked on the right of the rightmost considered inedx.
    if(right_ind<vec.size()-1)
    {
        if(left_val<vec[right_ind+1])
        truth_value=1;
        else
        return 0;
    }
    return truth_value;    
}

void check(vector<int> &vec)
{
    vector<int> temp;
    int cnt=0;
    string trend="up";
    for(int i=1;i<vec.size();i++)
    {
        if(cnt<=2)
        {
            if(trend=="up" && vec[i]<vec[i-1])
            {
                trend="down";
                temp.push_back(i-1);
                cnt++;
            }
            else if(trend=="down" && vec[i]>vec[i-1])
            {        
                trend="up";
                temp.push_back(i-1);
            }
        }
        else
        {
            cout<<"no";
            return;
        }
    }
    
    if(temp.size()%2!=0)
    temp.push_back(vec.size()-1);
    
    //Either reverse or swap can only occur when cnt is greater than 0, i.e. there is atleast
    //1 dip and they satisfy the checking condition.
    if(cnt>0 && fnc(vec,temp))
    {
        //Reverse will only occur when cnt is 1 and there are elements between the two 
        //considered indeces.
        if(cnt==1 && temp.back()-temp[0]>1)
        cout<<"yes\nreverse "<<temp[0]+1<<" "<<temp.back()+1;
        else
        cout<<"yes\nswap "<<temp[0]+1<<" "<<temp.back()+1;
    }
    else
    cout<<"no";
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    input(vec,n);
    check(vec);
} 

