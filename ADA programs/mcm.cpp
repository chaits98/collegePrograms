#include <iostream>

using namespace std;

int iterations = 0;

void getarray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "p[" << i << "]: ";
        cin >> arr[i];
    }
}

int mcm(int p[], int n)
{
    int cost[n][n];
    for(int i = 1; i < n; i++)
    {
        cost[i][i] = 0;
    }
//	Comment by Sanuj
    for(int l = 2; l < n; l++)
    {
        iterations++;
        for(int i = 1; i < (n - l + 1); i++)
        {
            iterations++;
            int j, min;
            j = i + l - 1;
            cost[i][j] = cost[i][i] + cost[i+1][j] + p[i-1]*p[i]*p[j];
            for(int k = i+1; k < j; k++)
            {
                iterations++;
                min = cost[i][k] + cost[k+1][j] + p[i-1]*p[k]*p[j];
                if(min < cost[i][j])
                {
                    cost[i][j] = min;
                }
            }
        }
    }
    return cost[1][n-1];
}

int main()
{
    int n;
    cout << "\nEnter number of matrices: ";
    cin >> n;

    int p[n+1];
    cout << "Enter dimensions: " << endl;
    getarray(p, n+1);

    cout << "\nMinimum cost for multiplication of entered matrices: " << mcm(p, n+1) << endl;
    cout << "Expected number of iterations made to calculate the minimum cost: " << n*n*n << endl;
    cout << "Actual number of iterations made to calculate the minimum cost: " << iterations << endl;
        
    return 0;
}
