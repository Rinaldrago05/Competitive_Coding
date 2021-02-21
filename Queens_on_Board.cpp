#include<iostream>
#include<vector>
#include<string>
using namespace std;

void view(vector<string> &board,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        cout<<board[i][j]<<"  ";
        cout<<endl;
    }

    cout<<endl;
}

int is_safe(vector<string> &board,int row,int col,int n,int m)
{
    for(int i=0;i<row;i++)
    if(board[i][col]=='1')
    return 0;

    for(int i=0;i<col;i++)
    if(board[row][i]='1')
    return 0;

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    if(board[i][j]='1')
    return 0;

    for(int i=row-1,j=col+1;i>=0 && j<m;i--,j++)
    if(board[i][j]='1')
    return 0;

    return 1;
}

void solve_n_queen(vector<string> &board,int row,int col,int no_queen,int cur_queen,int n,int m)
{
    if(cur_queen==no_queen)
    {
        view(board,n,m);
        return;
    }

    if(row==n)
    return;

    if(col==m)
    {
        row++;
        col=0;
    }

    if(is_safe(board,row,col,n,m))
    {
        board[row][col]='1';
        solve_n_queen(board,row,col+1,no_queen,cur_queen+1,n,m);
        board[row][col]='0';
    }

    solve_n_queen(board,row,col+1,no_queen,cur_queen,n,m);
}

int main()
{
    int t,n,m;
    cin>>t;

    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        vector<string> board;
        string str;
        for(int j=0;j<n;j++)
        {
            cin.clear();
            fflush(stdin);
            getline(cin,str);
            board.push_back(str);
        }
        view(board,n,m);
        
        for(int j=1;j<=n;j++)
        solve_n_queen(board,0,0,j,0,n,m);   
    }
}