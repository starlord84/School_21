#include "print_module.h"
#include "documentation_module.h"

int main() {
    #ifdef Q1
    #define FUNC
    print_log(*print_char, Module_load_success_message);
    #endif
    #ifdef Q2
    #define FUNC
    int *availability_mask = check_available_documentation_module(validate, Documents_count, Documents);
    output(availability_mask, Documents_count, Documents);
    free(availability_mask);
    #endif
    FUNC
    return 0;
}

