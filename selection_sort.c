#include<stdio.h>

int main() {
	int n, i, j, k, temp, arr[100];
	printf ( "Enter the size of the array: " );
	scanf ( "%d", &n );
	for ( i = 0; i < n; i ++ )		scanf ( "%d", &arr[i] );

	for ( j = 0; j < n - 1; j ++ ) {
		for ( k = j + 1; k < n; k ++ ) {
			if ( arr[j] > arr[k] ) {
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}

	printf ( "Sorted array: \n" );
	for ( i = 0; i < n; i ++ ) {
		printf ( "%d\t", arr[i] );
	}
	printf ( "\n" );
	return 0;
}
