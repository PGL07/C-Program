#include <stdio.h>
#include <math.h>

// Function to reverse the digits of a number
long long reverseNumber(int n) {
    long long rev = 0;
    int num = (n < 0) ? -n : n; // handle negative numbers
    while (num != 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }
    return rev;
}

// Function to calculate sum of digits
int sumOfDigits(int n) {
    int sum = 0;
    int num = (n < 0) ? -n : n;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Function to check palindrome
int isPalindrome(int n) {
    if (n < 0) return 0; // negative numbers not considered palindrome here
    return (n == reverseNumber(n));
}

// Function to check prime number
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; (long)i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to count digits
int countDigits(int n) {
    int count = 0;
    int num = (n < 0) ? -n : n;
    if (num == 0) return 1;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to check Armstrong number
int isArmstrong(int n) {
    if (n < 0) return 0;
    int digits = countDigits(n);
    int num = n, sum = 0;
    while (num != 0) {
        int digit = num % 10;
        sum += (int)round(pow(digit, digits));
        num /= 10;
    }
    return (sum == n);
}

// Function to check perfect number
int isPerfect(int n) {
    if (n <= 1) return 0;
    int sum = 1; // 1 is always a divisor for n > 1
    for (int i = 2; (long)i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i)
                sum += n / i;
        }
    }
    return (sum == n);
}

int main() {
    int n;

    printf("Enter an integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    printf("\n----- Digit-Based Analysis for %d -----\n", n);

    // Reverse of the number
    long long rev = reverseNumber(n);
    if (n < 0)
        printf("Reverse of the number     : -%lld\n", rev);
    else
        printf("Reverse of the number     : %lld\n", rev);

    // Sum of digits
    printf("Sum of digits             : %d\n", sumOfDigits(n));

    // Palindrome check
    if (isPalindrome(n))
        printf("Palindrome check          : %d is a Palindrome number.\n", n);
    else
        printf("Palindrome check          : %d is NOT a Palindrome number.\n", n);

    // Prime, Armstrong, Perfect checks
    printf("\n----- Special Number Category -----\n");

    int foundCategory = 0;

    if (isPrime(n)) {
        printf("%d is a PRIME number.\n", n);
        foundCategory = 1;
    }
    if (isArmstrong(n)) {
        printf("%d is an ARMSTRONG number.\n", n);
        foundCategory = 1;
    }
    if (isPerfect(n)) {
        printf("%d is a PERFECT number.\n", n);
        foundCategory = 1;
    }

    if (!foundCategory) {
        printf("%d is NOT Prime, Armstrong, or Perfect.\n", n);
    }

    return 0;
}