// link to problem: https://www.codechef.com/MAY21C/problems/TCTCTOE
#include <bits/stdc++.h>
#include <array>
using namespace std;

//valid code's referred from geeks for geeks
int win[8][3] = {{0, 1, 2}, // Check first row.
                {3, 4, 5}, // Check second Row
                {6, 7, 8}, // Check third Row
                {0, 3, 6}, // Check first column
                {1, 4, 7}, // Check second Column
                {2, 5, 8}, // Check third Column
                {0, 4, 8}, // Check first Diagonal
                {2, 4, 6}}; // Check second Diagonal

bool isCWin(char *a, char c)
{
    // Check all possible winning combinations
    for (int i=0; i<8; i++)
        if (a[win[i][0]] == c &&
            a[win[i][1]] == c &&
            a[win[i][2]] == c )
            return true;
    return false;
}


bool isValid(char a[9],int xCount,int oCount)
{
    if (xCount==oCount || xCount==oCount+1)
    {
        if (isCWin(a, 'O'))
        {
            if (isCWin(a, 'X'))
                return false;
            return (xCount == oCount);
        }
        if (isCWin(a, 'X') && xCount != oCount + 1)
        return false; 
        
        return true;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t {};
    cin >> t;
    while(t--)
    {
        int oCount=0,xCount=0, dCount=0;
        char a[9]={};
        for(int i=0;i<9;i++)
        {
            cin>>a[i];
            if(a[i]=='X')
            xCount++;
            else if(a[i]=='O')
            oCount++;
            else 
            dCount++;
        }
        if(isValid(a,xCount,oCount)==1)
        {
            if(isCWin(a,'X')==1 or isCWin(a,'O')==1 or (isCWin(a,'X')==0 && isCWin(a,'O')==0 && dCount==0))
            cout<<1<<"\n";
            else if(dCount!=0)
            cout<<2<<"\n";
        }
        else 
        cout<<3<<"\n";
    }
}

  


  
