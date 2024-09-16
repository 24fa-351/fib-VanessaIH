#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_MEMORY 100000

unsigned long long int memo[MAX_SIZE_MEMORY];

void initalizing_memory_table() {
    for (size_t i = 0; i < MAX_SIZE_MEMORY; i++) {
        memo[i] = (unsigned long long int) - 1;
    }
}
unsigned long long int read_from_file(const char *file_name) {
   FILE *file = fopen(file_name, "r");
   
   unsigned long long int file_number;
   
   fscanf(file, "%llu", &file_number);
   fclose(file);

   return file_number;
}
unsigned long long int fibonacci_recursive_function_og(unsigned long long int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_recursive_function_og(n - 1) + fibonacci_recursive_function_og(n - 2);
    }
}

unsigned long long int fibonacci_iterative_function_og(unsigned long long int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    unsigned long long int a = 0;
    unsigned long long int b = 1;
    unsigned long long int c;
    for (unsigned long long int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

unsigned long long int fibonacci_recursive_memory_function(unsigned long long int n) {
    if (n <= 1) {
        return n;
    } else if (n >= MAX_SIZE_MEMORY) {
        exit(EXIT_FAILURE);
    }
    if (memo[n] != (unsigned long long int) - 1) {
        return memo[n];
    }
    return fibonacci_recursive_memory_function(n - 1) + fibonacci_recursive_memory_function(n - 2);
}

unsigned long long int fibonacci_function_wrapper(unsigned long long int n, unsigned long long int 
                                                 (*fibonacci_function)(unsigned long long int)) {
    return fibonacci_function(n);
}

int main(int argc, char *argv[]) {
    unsigned long long int interger_agrument = atoi(argv[1]);
    char function_wanted = argv[2][0];
    const char *filename = argv[3];
    unsigned long long int ending_number;

    unsigned long long int file_number = read_from_file(filename);

    unsigned long long int Nth_term_wanted = interger_agrument + file_number - 1;

    initalizing_memory_table();
    memo[0] = 0;
    memo[1] = 1;

    if (function_wanted == 'r') {
        ending_number = fibonacci_function_wrapper(Nth_term_wanted, fibonacci_recursive_memory_function);
    } else if (function_wanted == 'i') {
        ending_number= fibonacci_function_wrapper(Nth_term_wanted, fibonacci_iterative_function_og);
    }
    printf("%llu\n", ending_number);
    
    return EXIT_SUCCESS;
}