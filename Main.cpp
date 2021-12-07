// Yağız Can Aslan 22001943 CS201-3

#include <iostream>
#include <ctime>
using namespace std;

void conductExperiment( int, int);
int linearSearch( int*, int, int*, int);
int binarySearch( int*, int, int, int);
int binarySearchArray( int*, int, int*, int);
int frequencyTable( int*, int, int*, int);

int main() {
    // Parameters
    int n = 750000;
    int m = 5000;

    // Program Code
    for ( int i = 0; i < 2; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            conductExperiment( (j + 1) * n, m);
        }

        m = 2 * m;
    }

    return 0;
}

int frequencyTable( int* array1, int array1Size, int* array2, int array2Size ) {
    // Find maximum value of Array 1
    int maxArr1 = 0;
    for ( int i = 0; i < array1Size; i++ ) {
        if ( array1[i] > maxArr1 ) {
            maxArr1 = array1[i];
        }
    }

    // Initialize the frequency table
    int* freqTable = new int[maxArr1 + 1];
    
    // Find frequency of each unique element in Array 1
    for ( int i = 0; i < array1Size; i++ ) {
        freqTable[ array1[i]]++;
    }

    // Traverse Array 2 and search for each element of Array 2 in the frequency table of Array 1
    for ( int i = 0; i < array2Size; i++ ) {
        if ( freqTable[ array2[i]] ) {
            freqTable[ array2[i]]--;
        }
        else {
            return 0;
        }
    }

    delete [] freqTable;
    return 1;
}

int binarySearchArray( int* array1, int array1Size, int* array2, int array2Size ) {
    for ( int i = 0; i < array2Size; i++ ) { // For each element in Array 2
        if ( !(1 + binarySearch( array1, 0, array1Size, array2[i])) ) { // Search for the element in Array 1 using Binary Search
            // If the element does not exist, return false (0);
            return 0;
        }
    }

    return 1;
}

int binarySearch( int* arr, int low, int high, int key ) {
    if ( low > high ) {
        return -1;
    }

    int mid = (low + high) / 2;
    
    if ( arr[mid] == key ) {
        return mid;
    }

    if ( arr[mid] > key ) {
        return binarySearch( arr, low, mid - 1, key );
    }

    return binarySearch( arr, mid + 1, high, key );
}

int linearSearch( int* array1, int array1Size, int* array2, int array2Size ) {
    bool itemFound = false;

    for ( int i = 0; i < array2Size; i++ ) { // For each element in Array 2
        for ( int j = 0; j < array1Size && !itemFound; j++ ) { // For each element in Array 1
            if ( array1[j] == array2[i] ) { // Search for the element in Array 1
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
    // ARRAY RANGES ARE [0, 10^6);
    // Time Variable(s)
    clock_t startTime;
    double duration;
    int k = 1000;

    // Parameters
    int n = nInput;
    int m = mInput;

    // Arrays
    int* arr1 = new int[n];
    int* arr2 = new int[m];

    // Setting up the arrays
    for ( int i = 0; i < n; i++ ) {
        arr1[i] = i;
    }

    for ( int i = 0; i < m; i++ ) {
        arr2[i] = arr1[(n - 1) - m + i];
    }
    // Setting up the arrays complete

    // Conducting the experiment
    cout << endl;

    // #####################
    // ### LINEAR SEARCH ###
    // #####################
    startTime = clock();

    linearSearch(arr1, n, arr2, m);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Linear Search(n = " << n << ", m = " << m << "): " << duration << " milliseconds." << endl;

    // #####################
    // ### BINARY SEARCH ###
    // #####################
    startTime = clock();

    for ( int i = 0; i < k; i++ ) {
        binarySearchArray(arr1, n, arr2, m);
    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Binary Search(n = " << n << ", m = " << m << "): " << (duration / k) << " milliseconds." << endl;

    // #######################
    // ### FREQUENCY TABLE ###
    // #######################
    startTime = clock();

    k = 10;
    for ( int i = 0; i < k; i++ ) {
        frequencyTable(arr1, n, arr2, m);
    }

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Frequency Tab(n = " << n << ", m = " << m << "): " << (duration / k) << " milliseconds." << endl;
    
    delete [] arr1;
    delete [] arr2;
}