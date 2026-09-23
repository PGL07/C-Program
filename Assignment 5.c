#include <stdio.h>
#include <stdlib.h>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
long long factorial(int n);
int isPrime(int n);

int main() {
    int choice;
    double num1, num2, result;
    int intNum;

    while (1) {
        // Display Menu
        printf("\n===================================\n");
        printf("         MENU-DRIVEN PROGRAM       \n");
        printf("===================================\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Find Factorial\n");
        printf("6. Check Prime Number\n");
        printf("7. Exit\n");
        printf("===================================\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case 5:
                printf("Enter a non-negative integer: ");
                scanf("%d", &intNum);
                if (intNum < 0) {
                    printf("Error: Factorial of a negative number doesn't exist.\n");
                } else {
                    printf("Result: %d! = %lld\n", intNum, factorial(intNum));
                }
                break;

            case 6:
                printf("Enter an integer: ");
                scanf("%d", &intNum);
                if (isPrime(intNum)) {
                    printf("Result: %d is a Prime number.\n", intNum);
                } else {
                    printf("Result: %d is NOT a Prime number.\n", intNum);
                }
                break;

            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select an option between 1 and 7.\n");
        }
    }

    return 0;
}

// Function definitions

// 1. Addition: Takes two doubles, returns their sum
double add(double a, double b) {
    return a + b;
}

// 2. Subtraction: Takes two doubles, returns their difference
double subtract(double a, double b) {
    return a - b;
}

// 3. Multiplication: Takes two doubles, returns their product
double multiply(double a, double b) {
    return a * b;
}

// 4. Division: Takes two doubles, returns their quotient
double divide(double a, double b) {
    return a / b;
}

// 5. Factorial: Takes an int, returns a long long to handle larger values
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// 6. Prime Checking: Takes an int, returns 1 (true) if prime, 0 (false) if not
int isPrime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0; // Found a factor, not prime
        }
    }
    return 1; // No factors found, it is prime
}

