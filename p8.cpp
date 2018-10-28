#include <iostream>
using namespace std;
void aswap(int* a, int* b)
{
     int t = *a;
     *a = *b;
     *b = t;
}
int qpartition (int a[], int small, int large)
{
     int pivot = a[large];
     int i = (small - 1);
     for (int j = small; j <= large- 1; j++)
     {
      if (a[j] <= pivot)
      {
       i++;
       aswap(&a[i], &a[j]);
      }
     }
     aswap(&a[i + 1], &a[large]);
     return (i + 1);
}
void quickSort(int a[], int small, int large)
{
     if (small < large)
     {
      int pi = qpartition(a, small, large);
      quickSort(a, small, pi - 1);
      quickSort(a, pi + 1, large);
     }
}
void disp(int a[], int s)
{
     for (int i=0; i < s; i++)
      cout<<a[i]<<"\t";
     cout<<"\n";
}
int main()
{
     int n,i;
     cout<<"Enter the no. of Elements for array :- ";
     cin>>n;
     int arr[n];
     cout<<"Enter the array :- ";
     for(i=0;i<n;i++)
        cin>>arr[i];

     cout<<"\n";
     quickSort(arr, 0, n-1);
     cout<<"Sorted array: \n";
     disp(arr, n);
     return 0;
}
