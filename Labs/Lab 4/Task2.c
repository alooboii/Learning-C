#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    int max_of_rest = findMax(arr, n-1);
    if (arr[n-1] > max_of_rest) {
        return arr[n-1];
    }
    else {
        return max_of_rest;
    }
}

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

bool isPalindrome(const char *str, int length) {
    if (length == 0 || length == 1) {
        return true;
    }
    if (str[0] != str[length - 1]) {
        return false;
    }
    return isPalindrome(str+1,length-2);
}

//TESTING FUNCTIONS // DO NOT CHANGE
int testFindMax() {
    int score = 0;

    int testArray1[] = {1, 2, 3, 4, 5};
    int expected1 = 5;
    int actual1 = findMax(testArray1, 5);
    if (actual1 == expected1) {
        printf("Test Find Max 1 Passed\n");
        score += 10;
    } else {
        printf("Test Find Max 1 Failed\n");
    }

    int testArray2[] = {10, 20, 30, 40, 50, 60};
    int expected2 = 60;
    int actual2 = findMax(testArray2, 6);
    if (actual2 == expected2) {
        printf("Test Find Max 2 Passed\n");
        score += 10;
    } else {
        printf("Test Find Max 2 Failed\n");
    }

    return score;
}

int testPalindrome() {
    int score = 0;

    if (isPalindrome("tattarrattat", 12)) {
        printf("Test Palindrome 1 Passed\n");
    } else {
        printf("Test Palindrome Failed\n");
        return 0;
    }

    if (!isPalindrome("salutations", 5)) {
        printf("Test Palindrome 2 Passed\n");
    } else {
        printf("Test Palindrome Failed\n");
        return 0;
    }

    if (isPalindrome("a", 1)) {
        printf("Test Palindrome 3 Passed\n");
    } else {
        printf("Test Palindrome Failed\n");
        return 0;
    }

    score += 20;
    return score;
}

int testGCD() {
    int score = 0;

    int result1 = gcd(25, 15);
    if (result1 == 5) {
        printf("Test GCD of 25 and 15 Passed\n");
        score += 4;
    } else {
        printf("Test GCD of 25 and 15 Failed\n");
    }

    int result2 = gcd(88, 36);
    if (result2 == 4) {
        printf("Test GCD of 88 and 36 Passed\n");
        score += 4;
    } else {
        printf("Test GCD of 88 and 36 Failed\n");
    }

    int result3 = gcd(12, 15);
    if (result3 == 3) {
        printf("Test GCD of 12 and 15 Passed\n");
        score += 4;
    } else {
        printf("Test GCD of 12 and 15 Failed\n");
    }

    int result4 = gcd(100, 50);
    if (result4 == 50) {
        printf("Test GCD of 100 and 50 Passed\n");
        score += 4;
    } else {
        printf("Test GCD of 100 and 50 Failed\n");
    }

    int result5 = gcd(17, 13);
    if (result5 == 1) {
        printf("Test GCD of 17 and 13 Passed\n");
        score += 4;
    } else {
        printf("Test GCD of 17 and 13 Failed\n");
    }

    return score;
}

int main() 
{
    int score = 0;

    score += testFindMax();
    printf("\n");
    score += testPalindrome();
    printf("\n");
    score += testGCD();
    printf("\n");
    printf("Your total score is %d/60\n", score);

    return 0;
}