#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int(*validate) (char*), int document_count, ...) {
    va_list argptr;
    va_start(argptr, document_count);
    int *p = (int*)malloc(document_count * sizeof(int));
    for (int i = 0; i <document_count; i++) {
        p[i] = validate(va_arg(argptr, char*));
    }
    va_end(argptr);
    return p;
}

void output(const int *data, int document_count, ...) {
    va_list argptr;
    va_start(argptr, document_count);
        for (int i = 0; i <document_count; i++) {
            if (data[i] == 0) {
                if (i != document_count - 1)
                    printf("%-15s : unavaliable\n", va_arg(argptr, char*));
                else
                    printf("[%-15s : unavaliable", va_arg(argptr, char*));
            }
            if (data[i] == 1) {
                if (i != document_count - 1)
                    printf("%-15s : avaliable\n", va_arg(argptr, char*));
                else
                    printf("%-15s : avaliable", va_arg(argptr, char*));
            }
        }
    va_end(argptr);
}
