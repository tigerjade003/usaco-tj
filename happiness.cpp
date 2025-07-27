#include <iostream>
using namespace std;

int smallestNumberOfPackages(int happiness, int numPackages) {
    int minPackages = INT_MAX;

    // Iterate through each type of package
    for (int i = 1; i <= numPackages; ++i) {
        int packageSize = i;

        // Calculate the number of packages needed for this type
        int numPackagesNeeded = happiness / packageSize;

        // Update the minimum number of packages if needed
        minPackages = min(minPackages, numPackagesNeeded);
    }

    return minPackages;
}

int main() {
    int happiness, numPackages;
    cin >> happiness >> numPackages;

    // Call the function and print the result
    cout << smallestNumberOfPackages(happiness, numPackages) << endl;

    return 0;
}
