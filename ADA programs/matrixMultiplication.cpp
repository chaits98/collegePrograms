#include <iostream>

using namespace std;

void getMatrix(int* mat,int m,int n, const char* name)
{
    cout<<"\n\tEnter "<<name<<" matrix:\n";
    for(int i=0;i<m;i++)
    {
        cout<<"\t";
        for(int j=0;j<n;j++)
        {
            cin>>*(mat + 5*i + j);
        }
    }
}

void printMatrix(int* mat,int m,int n, char* name)
{
    cout<<"\n\t"<<name<<" matrix:\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"\t"<<*(mat + 5*i + j);
        }
        cout<<endl;
    }
}

void multiplyMatrix(int* mat1, int* mat2, int* matResult, int r1, int c1, int r2, int c2)
{
    int iterations = 0;
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            *(matResult + 5*i + j) = 0;
            for(int k=0;k<c1;k++)
            {
                iterations++;
                *(matResult + 5*i + j) += (*(mat1 + 5*i + k) * *(mat2 + 5*k + j));
            }
        }
    }
    cout<<"\n\tExpected iterations for matrix multiplication: "<<(r1*c1*c2);
	cout<<"\n\tActual iterations for matrix multiplication: "<<iterations<<endl;
}

int main()
{
    int a[5][5],b[5][5],c[5][5],m,n,p,q;
    cout<<"\n\tEnter rows and columns of first matrix (max 5, 5): ";
    cin>>m>>n;
    cout<<"\n\tEnter rows and columns of second matrix (max 5, 5): ";
    cin>>p>>q;

    if(n == p)
    {
        getMatrix((int*)a, m, n, (char*) "first");
        getMatrix((int*)b, p, q, (char*) "second");
        printMatrix((int*)a, m, n, (char*) "First");
        printMatrix((int*)b, p, q, (char*) "Second");
        multiplyMatrix((int*)a, (int*)b, (int*)c, m, n, p, q);
        printMatrix((int*)c, m, q, (char*) "New");
    }
    else
        cout<<"\n\tMatrix multiplication is not possible.";
    return 0;
}
