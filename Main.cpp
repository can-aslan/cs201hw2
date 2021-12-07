#include <iostream>
#include <ctime>
using namespace std;

void conductExperiment( int, int);
int linearSearch( int*, int*);

int main() {
    // Parameters
    int n = 100000;
    int m = 1000;

    // Program Code
    for ( int i = 0; i < 2; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            conductExperiment( (j + 1) * n, m);
        }

        m = 10 * m;
    }

    return 0;
}

int linearSearch( int* array1, int array1Size, int* array2, int array2Size ) {
    bool itemFound = false;

    for ( int i = 0; i < array2Size; i++ ) {
        for ( int j = 0; j < array1Size && !itemFound; j++ ) {
            if ( array1[j] == array2[i] ) {
                itemFound = true;
            }
        }

        if ( !itemFound ) {
            return 0;
        }
        else {
            itemFound = false;
        }
    }

    return 1;
}

void conductExperiment( int nInput, int mInput) {
    // ARRAY RANGES ARE [0, nInput);
    // Time Variable(s)
    double duration;
    int k = 10;

    // Parameters
    int n = nInput;
    int m = mInput;
    //int range = 50; // range = from 0 to n/range exclusive (for range = 50, range of numbers = [0, 1999])

    // Arrays
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    // Setting up the arrays
    /*
    for ( int i = 0; i < (n / range); i++ ) {
        for ( int j = (i * range); j < ((i + 1) * range); j++ ) {
            arr1[j] = i;
        }
    }
    */

    for ( int i = 0; i < n; i++ ) {
        arr1[i] = i;
    }

    /*for ( int i = 0; i < n; i++ ) { // For array validation
        cout << i << ": " << arr1[i] << endl;
    }*/

    for ( int i = 0; i < m; i++ ) {
        arr2[i] = i;
    }

    /*for ( int i = 0; i < m; i++ ) { // For array validation
        cout << i << ": " << arr2[i] << endl;
    }*/
    // Setting up the arrays complete

    // Conducting the experiment
    // #####################
    // ### LINEAR SEARCH ###
    // #####################
    clock_t startTime = clock();

    for ( int i = 0; i < k; i++ ) {
        linearSearch(arr1, n, arr2, m);
    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Linear Search(n = " << n << ", m = " << m << "): " << (duration / k) << " milliseconds." << endl;

    // #####################
    // ### BINARY SEARCH ###
    // #####################

    delete [] arr1;
    delete [] arr2;
}