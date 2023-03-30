#include <bits/stdc++.h>
#include <fstream>
using namespace std;

const int N = 100;
const int Max = 100000000;
int a[N];
int dp[N][N];

int matrix_chain_multiplication(int i, int j)
{
    if(i==j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = Max;

    for(int k = i; k<j;k++)
    {
        dp[i][j] = min(dp[i][j], matrix_chain_multiplication(i, k) + matrix_chain_multiplication(k+1, j) + a[i-1]*a[k]*a[j]);
    }

    return dp[i][j];
}

int main()
{
    
    ifstream myfile;
    myfile.open("poly_sides.data");

    int d;
    int i =0;
    int count_vertices = 3;
    int count = 0;
    for (i = 0; i < 4948; i++)
    {
        d = 0;
        myfile >> d;
        a[count] = d;

        count++;
        if(count == count_vertices)
        {
            int n = count;
            count = 0;
            count_vertices += 1;
            
            
            memset(dp, -1, sizeof dp);
            cout<<"for vertices "<<n<<" = "<<matrix_chain_multiplication(1, n-1)/1000<<endl;
            memset(a, 0, sizeof a);
        }
        
    }
    cout<< "total = "<<i<<endl;
    myfile.close();

    return 0;
}