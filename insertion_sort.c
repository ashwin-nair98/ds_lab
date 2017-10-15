#include<stdio.h>

int main() {
	int n, i, j, k, temp, arr[100];
	printf ( "Enter the size of the array: " );
	scanf ( "%d", &n );
	for ( i = 0; i < n; i ++ ) 
		scanf ( "%d", &arr[i] );


	for ( j = 1; j < n; j ++ ) {
		for ( k = j; k > 0; k -- ) {
			if ( arr[k - 1] > arr[k] ) {
				temp = arr[k - 1];
				arr[k - 1] = arr[k];
				arr[k] = temp;
			}
		}
	}

	printf ( "\nSorted array: \n" );
	for ( i = 0; i < n; i ++ ) {
		printf ( "%d\t", arr[i] );
	}
	printf ( "\n" );
	return 0;
}
