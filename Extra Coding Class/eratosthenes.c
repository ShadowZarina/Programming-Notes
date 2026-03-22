#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define SieveOfEratosthenes function
void SieveOfEratosthenes(int n)
{
    // Allocate memory for prime array and initialize all
    // elements as true
    bool* prime = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++)
        prime[i] = true;

    // 0 and 1 are not prime numbers
    prime[0] = prime[1] = false;

    // For each number from 2 to sqrt(n)
    for (int p = 2; p <= sqrt(n); p++) {
        // If p is prime
        if (prime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers up to n
    printf("Prime numbers up to %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");

    // Free allocated memory
    free(prime);
}

// Define main function
int main()
{
    // Declare variable to hold maximum number
    int n;
    // Prompt user to enter the maximum number
    printf("Enter the maximum number to find primes: ");
    // Read user input
    scanf("%d", &n);
    // Call SieveOfEratosthenes function with user input
    SieveOfEratosthenes(n);
    return 0;
}
