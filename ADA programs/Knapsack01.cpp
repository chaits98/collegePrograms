#include<iostream>
#include<cmath>

using namespace std;

int iterations;

int max(int a, int b)
{
    return (a > b)? a : b;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int knapsack(int W, float *wt, float *val, int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i == 0 || w == 0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
           {
                iterations++;
                K[i][w] = max(val[i-1] + K[i-1][w-(int)wt[i-1]], K[i-1][w]);
           }
           else
            {
                K[i][w] = K[i-1][w];
            }
       }
   }
   return K[n][W];
}

float fracknapsack(int n, float *wt, float *val, float W)
{
    float x[20], tp = 0.0;
    int i, j, u;
    u = W;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++)
    {
        if (wt[i] > u)
	        break;
      
        else 
        {
            iterations++;
	        x[i] = 1.0;
	        tp = tp + val[i];
	        u = u - wt[i];
        }       
    }

    if (i < n)
        x[i] = u / wt[i];

    tp = tp + (x[i] * val[i]);

    cout << "\nThe resultant vector is: ";
    for (i = 0; i < n; i++)
    {
        cout << "\t" << "("<< val[i] <<", "<< wt[i] <<"): " << x[i];
    }

    return tp;
}

int main()
{
    float *val, *wt, *ratio, W, profit;
    int i, j, size;

    cout<<"Enter size of array: ";
	cin>>size;

    cout<<"Enter total weight allowed: ";
	cin>>W;

    val = new float[size];
    wt = new float[size];
    ratio = new float[size];

	for(i=0; i<size; i++)
    {
        cout<<"Enter value of element "<<i<<": ";
        cin>>val[i];
        cout<<"Enter weight of element "<<i<<": ";
        cin>>wt[i];
    }

    for (i=0; i<size; i++)
    {
        ratio[i] = val[i] / wt[i];
    }

    for (i=0; i<size; i++) 
    {
        for (j = i+1; j<size; j++) 
        {
		    if (ratio[i] < ratio[j]) 
            {
                swap(ratio[i], ratio[j]);
                swap(wt[i], wt[j]);
                swap(val[i], val[j]);
		    }
        }
    }

    iterations = 0;
    profit = knapsack(W, wt, val, size);

    cout<<"\n\nMaximum profit by 0-1 knapsack is: "<<profit;
    cout<<"\nActual iterations for 0-1 knapsack: "<<iterations;
    cout<<"\nExpected iterations for 0-1 knapsack: "<<size*W;

    iterations = 0;
    profit = fracknapsack(size, wt, val, W);

    cout<<"\n\nMaximum profit by fractional knapsack is: "<<profit;
    cout<<"\nActual iterations for fractional knapsack: "<<iterations;
    cout<<"\nExpected iterations for fractional knapsack: "<<size*log2(size);

    return 0;
}
