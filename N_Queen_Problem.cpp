#include<iostream>
#include<vector>
using namespace std;

void view(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        cout<<board[i][j]<<"  ";
        cout<<endl;
    }

    cout<<endl;
}

int is_safe(vector<vector<int>> &board,int row,int col)
{
    for(int i=0;i<row;i++)
    if(board[i][col])
    return 0;

    for(int i=0;i<col;i++)
    if(board[row][i])
    return 0;

    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    if(board[i][j])
    return 0;

    for(int i=row-1,j=col+1;i>=0 && j<board[row].size();i--,j++)
    if(board[i][j])
    return 0;

    return 1;
}

void solve_n_queen(vector<vector<int>> &board,int row,int col,int n,int cur_queen)
{
    if(cur_queen==n)
    {
        view(board);
        return;
    }

    if(row==board.size())
    return;

    if(col==board[0].size())
    {
        row++;
        col=0;
    }

    if(is_safe(board,row,col))
    {
        board[row][col]=1;
        solve_n_queen(board,row,col+1,n,cur_queen+1);
        board[row][col]=0;
    }

    solve_n_queen(board,row,col+1,n,cur_queen);
}

int main()
{
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,0));
    
    solve_n_queen(board,0,0,n,0);
}