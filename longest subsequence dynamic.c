#include<stdio.h>
#include<stdlib.h>

int lis( int arr[], int n )
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    for (i = 0; i < n; i++ )
        lis[i] = 1;
    for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
    free(lis);
    return max;
}
int main()
{   int num,i;
    printf("Input size:");
    scanf("%d",&num);
    int arr[num];
    printf("\n");
    for (i=0;i<num;i++)
        scanf("%d",&arr[i]);
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of longest increasing subsequence is %d\n", lis( arr, n ) );
    return 0;
}
