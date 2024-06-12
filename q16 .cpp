// Example IR (simplified):
// Assume we have an IR with three-address code like:
//   t1 = a + b
//   t2 = t1 * c
//   result = t2

#include <stdio.h>

// Generate C code for the given IR
void generate_code() {
    printf("int main() {\n");
    printf("    int a = 10;\n");
    printf("    int b = 20;\n");
    printf("    int c = 5;\n");
    printf("    int t1 = a + b;\n");
    printf("    int t2 = t1 * c;\n");
    printf("    int result = t2;\n");
    printf("    printf(\"Result: %d\\n\", result);\n");
    printf("    return 0;\n");
    printf("}\n");
}

int main() {
    generate_code();
    return 0;
}

