#include <stdio.h>
#include <string.h>
#include "logic.h"

int assert_equal_double(double expected, double actual, double tolerance) {
    return (expected - actual < tolerance) && (actual - expected < tolerance);
}

void test_append_to_input() {
    append_to_input("5");
    const char *result = get_current_input();
    if (strcmp(result, "5") != 0) {
        printf("FAIL: test_append_to_input\n");
    } else {
        printf("PASS: test_append_to_input\n");
    }
}

void test_set_operator() {
    append_to_input("10");
    set_operator('+');
    append_to_input("5");
    calculate_result();
    const char *result = get_current_input();
    if (!assert_equal_double(15.0, atof(result), 0.0001)) {
        printf("FAIL: test_set_operator\n");
    } else {
        printf("PASS: test_set_operator\n");
    }
}

void test_clear_all() {
    append_to_input("123");
    clear_all();
    const char *result = get_current_input();
    if (strcmp(result, "") != 0) {
        printf("FAIL: test_clear_all\n");
    } else {
        printf("PASS: test_clear_all\n");
    }
}

void run_tests() {
    printf("Running tests for logic.c\n");
    test_append_to_input();
    test_set_operator();
    test_clear_all();
}

int main() {
    run_tests();
    return 0;
}
