#include<iostream>
#include<vector>
using namespace std;

int cnt=0;
int row_pos[8]={-2,-2,-1,1,-1,1,2,2};
int col_pos[8]={-1,1,-2,-2,2,2,-1,1};

void view(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        cout<<board[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}

int is_safe(vector<vector<int>> &board,int row,int col)
{
    if(row>=0 && row<board.size() && col>=0 && col<board.size() && board[row][col]==-1)
    return 1;

    return 0;
}

void knights_tour(vector<vector<int>> &board,int row,int col,int cur_no)
{
    if(cnt)
    return;

    if(cur_no==board.size()*board.size())
    {
        view(board);
        cnt=1;
        return;
    }

    if(is_safe(board,row,col))
    {
        board[row][col]=cur_no;
        for(int i=0;i<8;i++)
        knights_tour(board,row+row_pos[i],col+col_pos[i],cur_no+1);
        board[row][col]=-1;
    }
}

int main()
{
    int n;
    cout<<"Enter the chess board size: ";
    cin>>n;

    vector<vector<int>> board(n,vector<int>(n,-1));
    knights_tour(board,0,0,0);
}