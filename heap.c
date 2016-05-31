#include <stdio.h>

int heapify (int *array,int n, int root)
{
    int largest, temp;

    if ( ((2*root+1)<n) && (array[(2*root+1)] > array[root]))
    {
        largest=(2*root+1);
    }
    else {
        largest = root;
    }
    if ( ((2*root+2)<n) && (array[(2*root+2)]>array[largest]))
    {
        largest=(2*root+2);
    }
    if (largest!=root)
    {
        temp = array[largest];
        array[largest] = array[root];
        array[root] = temp;
        heapify(array, n, largest);
    }
}

void heap_sort(int *array, int n)
{
    int temp, i;
    int size = n;

    for (i = n/2; i >= 0; i--)
    {
        heapify(array, n, i);
    }

    for (i = n-1; i >= 1; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        size--;
        heapify(array, size, 0);
    }
}

int main()
{
    int a[] = {52, 73, 95, 21, 56, 3, 32 ,5, 12, 321};

	int n =  sizeof(a)/sizeof(a[0]);;

    int i;


	heap_sort(a, n);


	printf("Random niz:\n");
	for(i=0;i<n; i++) { printf ("%d, ", a[i]); }

	return 0;
}
