#include<stdio.h>

int main() {
	int n, i, j, k, temp, arr[100];
	printf ( "Enter the size of the array: " );
	scanf ( "%d", &n );
	printf ( "Enter the array elements: ");
	for ( i = 0; i < n; i ++ ) {
		scanf ( "%d", &arr[i] );
	}
	for ( j = n-1; j > 0; j -- ) {
		for ( k = 0; k < j; k ++ ) {
			if ( arr[k] > arr[k + 1] ) {
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}

	printf ( "Sorted array: \n" );
	for ( i = 0; i < n; i ++ ) {
		printf ( "%d\t", arr[i]);
	}
	printf ( "\n" );
	return 0;
}
