/*
** PRINTF VS FPRINTF
**
** printf:
** - Outputs formatted text to standard output (stdout)
** - Prototype: int printf(const char *format, ...)
** - Always writes to stdout
** - Example: printf("Hello %s\n", name);
**
** fprintf:
** - Outputs formatted text to a specified file stream
** - Prototype: int fprintf(FILE *stream, const char *format, ...)
** - Can write to stdout, stderr, or any opened file
** - Example: fprintf(stderr, "Error: %s\n", error_message);
**
** Both functions handle the same format specifiers (%d, %s, %c...)
** but fprintf gives more control over the destination.
**
** OPEN FUNCTION ARGUMENTS
**
** open("test_file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
**
** 1st arg: File path to open or create
**
** 2nd arg: Flags (combined with bitwise OR)
**   - O_RDWR: Open for reading and writing
**   - O_CREAT: Create file if it doesn't exist
**   - O_TRUNC: If file exists, truncate to length 0
**
** 3rd arg: File permissions (when creating new file)
**   - 0644 in octal means:
**     - Owner: read + write (6 = 4+2)
**     - Group: read only (4)
**     - Others: read only (4)
**
** LSEEK FUNCTION
**
** lseek(test_fd, 0, SEEK_SET);
**
** Purpose: Repositions the file offset (read/write position)
**
** 1st arg: File descriptor
** 2nd arg: Offset (how many bytes to move)
** 3rd arg: Reference point
**   - SEEK_SET: Relative to beginning of file
**   - SEEK_CUR: Relative to current position
**   - SEEK_END: Relative to end of file
**
** FFLUSH FUNCTION
**
** fflush(stdout);
**
** Purpose: Forces a write of all buffered data for the output stream
**
** Why needed: Output functions like printf buffer their output for
** efficiency. fflush ensures everything is written immediately.
**
** Common use: Ensuring output appears in expected order when mixing
** different output functions or when immediate display is required.
*/
#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define TEST_FILE "putendl_test.txt"

void test_putendl_fd(char *test_name, char *input)
{
    int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        printf("FAILURE: %s - Could not open test file\n", test_name);
        return;
    }

    // Write to file using ft_putendl_fd
    ft_putendl_fd(input, fd);
    close(fd);

    // Read back the contents
    fd = open(TEST_FILE, O_RDONLY);
    if (fd < 0)
    {
        printf("FAILURE: %s - Could not reopen test file\n", test_name);
        return;
    }

    // Calculate expected result (input string + newline)
    char *expected = malloc(strlen(input) + 2);
    if (!expected)
    {
        printf("FAILURE: %s - Memory allocation failed\n", test_name);
        close(fd);
        return;
    }
    
    strcpy(expected, input);
    strcat(expected, "\n");
    int expected_len = strlen(expected);

    // Read the file content
    char *result = malloc(expected_len + 1);
    if (!result)
    {
        printf("FAILURE: %s - Memory allocation failed\n", test_name);
        free(expected);
        close(fd);
        return;
    }
    
    int bytes_read = read(fd, result, expected_len);
    result[bytes_read] = '\0';
    close(fd);

    // Compare and print the test result
    if (strcmp(result, expected) == 0)
        printf("SUCCESS: %s - Input: \"%s\"\n", test_name, input);
    else
        printf("FAILURE: %s - Input: \"%s\" - Expected: \"%s\" - Got: \"%s\"\n", 
               test_name, input, expected, result);

    free(expected);
    free(result);
}

int main(void)
{
    printf("ft_putendl_fd\n");
    
    test_putendl_fd("Test 1 - Basic string", "Hello, world!");
    test_putendl_fd("Test 2 - Empty string", "");
    test_putendl_fd("Test 3 - String with spaces", "  Spaces  in  the  string  ");
    test_putendl_fd("Test 4 - String with special characters", "!@#$%^&*()_+");
    test_putendl_fd("Test 5 - Long string", "This is a longer string to test the function with more characters than the previous tests");
    
    // Cleanup the test file
    unlink(TEST_FILE);
    
    return (0);
}
