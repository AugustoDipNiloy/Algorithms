#include<bits/stdc++.h>
using namespace std;
#define mx 1000
#define eps 1e-6
double mat[mx][mx+1];

void gauss_elimination(int n)
{
   double swap_variable,factor;
   int det=0;
   // det 0 means there is only a solution
   // det 1 means there is no solution
   // det 2 means there is infinite solutions
   for(int i=0;i<n;i++)
   {
      int id=i;
      for(int j=i+1;j<n;j++)
      {
         if(fabs(mat[j][i])>fabs(mat[id][i]))
            id=j;
      }
      if(id!=i)
      {
         for(int j=i;j<=n;j++)
         {
            swap_variable=mat[i][j];
            mat[i][j]=mat[id][j];
            mat[id][j]=swap_variable;
         }
      }
      if(mat[i][i]!=1 && mat[i][i]!=0)
      {
         for(int j=i+1;j<=n;j++)
            mat[i][j]/=mat[i][i];
         mat[i][i]=1;
      }
      for(int j=0;j<n;j++)
      {
         if(j!=i && mat[i][i]!=0)
         {
            factor=mat[j][i]/mat[i][i];
            mat[j][i]=0;
            for(int k=i+1;k<=n;k++)
               mat[j][k]-=factor*mat[i][k];
         }
      }
   }
   for(int i=0;i<n && det<2;i++)
   {
      if(mat[i][i]!=1)
      {
         det=1;
         if(fabs(mat[i][n])<eps)
            det=2;
      }
   }
   if(det==0)
      {
         cout << "Unique Solution\n";
          for(int i=0;i<n;i++)
      {
      cout << mat[i][n] << " ";
   cout << "\n";
   }
      }
   else if(det==1)
      cout << "No solution\n";
   else cout << "Infinite Solution\n";
}

int main()
{
   int n;
      cout << "Input number of equations: ";
         cin >> n;
         cout << "Insert Augmented Matrix of the equations:\n";
   for(int i=0;i<n;i++)
      for(int j=0;j<=n;j++)
      cin >> mat[i][j];
   gauss_elimination(n);
   cout << "\n";
}
