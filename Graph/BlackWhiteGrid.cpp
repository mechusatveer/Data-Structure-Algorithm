/* 

You have a grid on mxn size, each cell of this grid is either black or white.
You can choose any cell and flip it, once u flip it color of this cell get opposite.
you need to flip around cell too,
It mean if you choose a cell at x,y position then
x-1,y
x,y-1
x+1,y
x,y+1 position cells if present they also get fliped.

How many min iteration we need so whole grid become black

*/


#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<memory>
using namespace std;
 
const int HEIGHT=4;
const int WIDTH=5;
//the final state, all cells are black
const int END = (1<<20)-1;
int visited[END+10];
int step[END+10];
 
 
void Roll(int x,int y,int& grid)
{
     
    if (x < 0||x >= HEIGHT||y < 0||y >= WIDTH) return;
     
    int position = (x * WIDTH) + y;
    //flip the bit
    grid = grid ^ (1<<position);
}

int Click(int x,int y,int grid)
{
    int a[] = {0, -1, 1, 0, 0};
    int b[] = {0, 0, 0, -1, 1};
    //five cells
    for (int i = 0; i < 5; i++)
    {
        Roll(x + a[i],y + b[i], grid);
    }
    return grid;
}
 
int Init(vector<string> board)
{
    int k = 0;
    int grid = 0;
    for (int i = 0; i<4; i++)
    {
        string s = board[i];
        for (int j=0; j<5; j++)
        {
            grid |= (s[j] - '0')<<k;
            k++;
        }
    }
    return grid;
}
 
int BlackWriteReverse(vector<string> board)
{
  int grid = Init(board);
  queue<int> Q;
  Q.push(grid);
  memset(visited, 0, sizeof(visited));
  visited[grid] = 1;
  memset(step, 0, sizeof(step));
  while (!Q.empty())
  {
  int now = Q.front();
  Q.pop();
  if (now == END) {
  return step[now];
  }
  for (int x = 0; x < 4;x++)
  {
  for (int y = 0; y < 5;y++)
  {
  int state = Click(x, y, now);
   
  if (!visited[state])
  {
  visited[state] = 1;
  step[state] = step[now] + 1;
  Q.push(state);
  }
  }
  }
  }
  return 0;
}
int main()
{
  vector<string> board;
  board.push_back("00111");
  board.push_back("01111");
  board.push_back("11110");
  board.push_back("11100");
  int result = BlackWriteReverse(board);
  cout <<result<<endl;
  return 0;
} 
