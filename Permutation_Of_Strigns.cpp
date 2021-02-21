#include<iostream>
#include<string>
using namespace std;

string swap(string str,int left,int right)
{
    char s;
    s=str[left];
    str[left]=str[right];
    str[right]=s;

    return str;
}

void find_permutations(string str,int left,int right)
{
    if(left==right)
    {
        cout<<str<<endl;
        return;
    }

    for(int i=left;i<=right;i++)
    find_permutations(swap(str,left,i),left+1,right);
}

int main()
{
    string str;
    getline(cin,str);
    find_permutations(str,0,str.length()-1);
}