#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_from_file(const char *file_name) {
   FILE *file = fopen(file_name, "r");
   
   int file_number;
   
   fscanf(file, "%d", &file_number);
   fclose(file);

   return file_number;
}

int fibonacci_recursive_function (int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_recursive_function(n - 1) + fibonacci_recursive_function (n - 2);
    }
}

int fibonacci_iterative_function(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}


int main(int argc, char *argv[]) {
    int interger_agrument = atoi(argv[1]);
    char function_wanted = argv[2][0];
    const char *filename = argv[3];
    int ending_number;

    int file_number = read_from_file(*filename);

    int Nth_term_wanted = interger_agrument + file_number;

    if (function_wanted == 'r') {
        ending_number = fibonacci_recursive_function(Nth_term_wanted);
    } else if (function_wanted == 'i') {
        ending_number= fibonacci_iterative_function(Nth_term_wanted);
    }
    printf("%d\n", ending_number);
    
    return 0;
}
