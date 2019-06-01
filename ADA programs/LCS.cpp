#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
int iterations = 0;

void lcsfn( char *X, char *Y, char* z, int m, int n )
{
  int L[m+1][n+1];

  for (int i=0; i<=m; i++)
  {
    for (int j=0; j<=n; j++)
    {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (X[i-1] == Y[j-1])
        L[i][j] = L[i-1][j-1] + 1;
      else
        L[i][j] = max(L[i-1][j], L[i][j-1]);
    }
  }

  int index = L[m][n];

  char lcs[index+1];
  int i = m, j = n;

  while (i > 0 && j > 0)
  {
    iterations++;
    if (X[i-1] == Y[j-1])
    {
      lcs[index-1] = X[i-1];
      i--;
      j--;
      index--;
    }
    else if (L[i-1][j] > L[i][j-1])
      i--;
    else
      j--;
  }

  strcpy(z, lcs);
}

int main()
{
  char x[20], y[20], z[20];

  cout<<"\nEnter the first string: ";
  cin>>x;
  cout<<"Enter the second string: ";
  cin>>y;

  int m = strlen(x);
  int n = strlen(y);
  lcsfn(x, y, z, m, n);
  cout<<"\nThe longest common subsequence is: "<<z;
  cout<<"\nExpected number of iterations: "<<m*n;
  cout<<"\nActual number of iterations: "<<iterations;

  
  return 0;
}
