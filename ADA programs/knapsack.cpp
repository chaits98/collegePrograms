#include<iostream>
#include<math.h>

using namespace std;

void knapsack(int n, float wt[], float pft[], float cap)
{
    float x[20], tp = 0;
    int i, j, u;
    u = cap;

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
	        x[i] = 1.0;
	        tp = tp + pft[i];
	        u = u - wt[i];
        }       
    }

    if (i < n)
        x[i] = u / wt[i];

    tp = tp + (x[i] * pft[i]);

    cout << "\nThe resultant vector is: ";
    
    for (i = 0; i < n; i++)
    {
        cout << "\t" << x[i];
    }

    cout << "\nMaximum proft is: " <<  tp;
}

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
}

int fracknapsack(float W, float wt[], float val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    
    if (wt[n-1] > W)
        return fracknapsack(W, wt, val, n-1);

    else
        return max(val[n-1] + fracknapsack(W-wt[n-1], wt, val, n-1), fracknapsack(W, wt, val, n-1));
}

int main() 
{
    float wt[20], pft[20], cap;
    int no, m, n;
    float ratio[20], temp;

    cout << "\nEnter the no. of objects: ";
    cin >> no;
    cout << "\nEnter the weights and profits of each object: ";
    
    for (m = 0; m < no; m++) 
    {
        cout << "\nWeight of object " << m+1 << ": ";
        cin >> wt[m];
        cout << "\nProfit of object " << m+1 << ": ";
        cin >> pft[m];
    }

    cout << "\nEnter the cap of knapsack: ";

    cin >> cap;
    
    cout << fracknapsack(cap, wt, pft, no);

    for (m = 0; m < no; m++)
    {
        ratio[m] = pft[m] / wt[m];
    }

    for (m = 0; m < no; m++) 
    {
        for (n = m + 1; n < no; n++) 
        {
		    if (ratio[m] < ratio[n]) 
            {
 	            temp = ratio[n];
	            ratio[n] = ratio[m];
	   	        ratio[m] = temp;
		        temp = wt[n];
		        wt[n] = wt[m];
	            wt[m] = temp;
	    	    temp = pft[n];
	    	    pft[n] = pft[m];
		        pft[m] = temp;
		    }
        }
    }

    knapsack(no, wt, pft, cap);
    cout << "\nTime complexity of 0-1 knapsack is O(2^n) = O(" << pow(2,no) << ")";
    cout << "\nTime complexity of Fractional knapsack problem is O(nlogn) = O(" << no*log(no) << ")";
    return(0);
}
