#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    // Calculate the maximum number of bottles of each size that we can buy
    int max_half_liters = a * 2;
    int max_one_liters = b;
    int max_two_liters = c * 2;
    
    // Initialize the number of ways to buy as 0
    int ways = 0;
    
    // Iterate over all possible numbers of bottles of each size
    for (int i = 0; i <= max_half_liters; i += 2) {
        for (int j = 0; j <= max_one_liters; j++) {
            for (int k = 0; k <= max_two_liters; k += 2) {
                // Calculate the total amount of liters bought
                int total_liters = i / 2 + j + k;
                // If the total is n, count this as a way to buy
                if (total_liters == n) {
                    ways++;
                }
            }
        }
    }
    
    // Print the number of ways, or "O" if impossible
    if (ways > 0) {
        cout << ways << endl;
    } else {
        cout << "O" << endl;
    }
    
    return 0;
}
