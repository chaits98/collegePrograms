#include <iostream>
#include <climits>

using namespace std;
int iterations;

int add(int f[], int i, int j)
{
    int sum = 0;
    for (int k=i; k<=j; k++)
    {
       sum += f[k];
    }
    return sum;
}

int OBSTfn(int keys[], int f[], int x)
{
    int cost[x][x];
    iterations = 0;
    for (int i = 0; i < x; i++)
    {
        cost[i][i] = f[i];
    }

    for (int len=2; len<=x; len++)
    {
        for (int i=0; i<=x-len+1; i++)
        {
            int j = i + len - 1;
            cost[i][j] = INT_MAX;

            for (int r=i; r<=j; r++)
            {
                iterations++;
                int c = ((r > i) ? cost[i][r-1] : 0) + ((r < j) ? cost[r+1][j] : 0) + add(f, i, j);

                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                }
            }
        }
    }

    return cost[0][x-1];
}

int main()
{
    int keys[20], f[20], n, cost;

    cout<<"\nEnter number of elements: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter key of element "<<i<<": ";
        cin>>keys[i];
        cout<<"Enter frequency of element "<<i<<": ";
        cin>>f[i];
        cout<<endl;
    }

    cost = OBSTfn(keys, f, n);
    
    cout<<"\nCost for the given set of values: "<<cost;
    cout<<"\nExpected number of iterations: "<<n*n*n;
    cout<<"\nActual number of iterations: "<<iterations;

    return 0;
}