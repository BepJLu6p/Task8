#include <stdio.h>
#include <string.h>


unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}


unsigned long long count_anagrams(char *word) {
    int length = strlen(word);
    int letter_counts[256] = {0};


    for (int i = 0; i < length; i++) {
        letter_counts[(int)word[i]]++;
    }


    unsigned long long n_fact = factorial(length);


    unsigned long long denom = 1;
    for (int i = 0; i < 256; i++) {
        if (letter_counts[i] > 0) {
            denom *= factorial(letter_counts[i]);
        }
    }


    return n_fact / denom;
}

int main() {
    char word[15];
    printf("Enter word: ");
    scanf("%14s", word);


    unsigned long long anagrams = count_anagrams(word);
    printf("\nKilkist anagram: %llu\n", anagrams);

    return 0;
}
