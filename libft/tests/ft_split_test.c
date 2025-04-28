#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_delimiter(char c, char *charset);
int count_words(char *str, char *charset);
char *extract_word(char *str, char *charset, int *i);
char **allocate_result(char *str, char *charset);
char **ft_split(char *str, char *charset);

int compare_arrays(char **expected, char **result) {
    int i = 0;
    
    if (!expected && !result)
        return (1);
    if (!expected || !result)
        return (0);
        
    while (expected[i] && result[i]) {
        if (strcmp(expected[i], result[i]) != 0)
            return (0);
        i++;
    }
    
    if (expected[i] != result[i])  // Check if both arrays end at the same point
        return (0);
        
    return (1);
}

void print_array(char **arr) {
    int i = 0;
    printf("[");
    while (arr && arr[i]) {
        printf("\"%s\"", arr[i]);
        if (arr[i + 1])
            printf(", ");
        i++;
    }
    printf("]");
}

void free_array(char **arr) {
    int i = 0;
    if (!arr)
        return;
    while (arr[i]) {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void test_split(char *str, char *charset, char **expected, int test_num, char *description) {
    char **result = ft_split(str, charset);
    int success = compare_arrays(expected, result);
    
    if (success)
        printf("SUCCESS: Test %d - %s - Input: \"%s\", Charset: \"%s\" - Result: ", test_num, description, str, charset);
    else
        printf("FAILURE: Test %d - %s - Input: \"%s\", Charset: \"%s\" - Result: ", test_num, description, str, charset);
    
    print_array(result);
    printf(" | Expected: ");
    print_array(expected);
    printf("\n");
    
    free_array(result);
}

char **create_expected(char **strings) {
    int i = 0;
    while (strings[i])
        i++;
    
    char **expected = (char **)malloc(sizeof(char *) * (i + 1));
    if (!expected)
        return NULL;
    
    for (i = 0; strings[i]; i++) {
        expected[i] = strdup(strings[i]);
        if (!expected[i]) {
            free_array(expected);
            return NULL;
        }
    }
    expected[i] = NULL;
    
    return expected;
}

int main(void) {
    printf("ft_split\n");
    
    // Test 1: Basic split with space delimiter
    {
        char *strings[] = {"Hello", "World", NULL};
        char **expected = create_expected(strings);
        test_split("Hello World", " ", expected, 1, "Basic split with space");
        free_array(expected);
    }
    
    // Test 2: Multiple consecutive delimiters
    {
        char *strings[] = {"Hello", "World", NULL};
        char **expected = create_expected(strings);
        test_split("Hello   World", " ", expected, 2, "Multiple consecutive spaces");
        free_array(expected);
    }
    
    // Test 3: Multiple different delimiters
    {
        char *strings[] = {"Hello", "World", NULL};
        char **expected = create_expected(strings);
        test_split("Hello,;World", ",;", expected, 3, "Multiple different delimiters");
        free_array(expected);
    }
    
    // Test 4: Empty string
    {
        char *strings[] = {NULL};
        char **expected = create_expected(strings);
        test_split("", " ", expected, 4, "Empty string");
        free_array(expected);
    }
    
    // Test 5: String with only delimiters
    {
        char *strings[] = {NULL};
        char **expected = create_expected(strings);
        test_split("   ", " ", expected, 5, "String with only delimiters");
        free_array(expected);
    }
    
    // Test 6: String with delimiters at start and end
    {
        char *strings[] = {"middle", NULL};
        char **expected = create_expected(strings);
        test_split(" middle ", " ", expected, 6, "Delimiters at start and end");
        free_array(expected);
    }
    
    // Test 7: Multiple words
    {
        char *strings[] = {"This", "is", "a", "test", "string", NULL};
        char **expected = create_expected(strings);
        test_split("This is a test string", " ", expected, 7, "Multiple words");
        free_array(expected);
    }
    
    // Test 9: NULL string
    test_split(NULL, " ", NULL, 8, "NULL string");
    
    return 0;
}
