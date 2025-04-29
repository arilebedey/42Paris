#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void reset_test_file(void)
{
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd > 0)
        close(fd);
}

char *get_file_content(void)
{
    int fd = open("test_output.txt", O_RDONLY);
    if (fd < 0)
        return NULL;
    
    char *buffer = malloc(100);
    if (!buffer)
        return NULL;
    
    int bytes_read = read(fd, buffer, 99);
    if (bytes_read >= 0)
        buffer[bytes_read] = '\0';
    else
        buffer[0] = '\0';
    
    close(fd);
    return buffer;
}

void test_putnbr_fd(int n, char *expected)
{
    static int test_count = 0;
    test_count++;
    
    // Reset test file
    reset_test_file();
    
    // Run the function with test file
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        printf("FAILURE: Test %d - Could not open test file\n", test_count);
        return;
    }
    
    ft_putnbr_fd(n, fd);
    close(fd);
    
    // Get the content written to the file
    char *result = get_file_content();
    if (!result)
    {
        printf("FAILURE: Test %d - Could not read test file\n", test_count);
        return;
    }
    
    // Compare with expected
    if (strcmp(result, expected) == 0)
        printf("SUCCESS: Test %d - Input: %d - Result: %s\n", test_count, n, result);
    else
        printf("FAILURE: Test %d - Input: %d - Expected: %s - Got: %s\n", test_count, n, expected, result);
    
    free(result);
}

int main(void)
{
    printf("ft_putnbr_fd\n");
    
    // Test cases
    test_putnbr_fd(0, "0");                  // Test 1 - Zero
    test_putnbr_fd(42, "42");                // Test 2 - Basic positive number
    test_putnbr_fd(-42, "-42");              // Test 3 - Negative number
    test_putnbr_fd(2147483647, "2147483647"); // Test 4 - INT_MAX
    test_putnbr_fd(-2147483648, "-2147483648"); // Test 5 - INT_MIN
    test_putnbr_fd(123456, "123456");         // Test 6 - Multi-digit positive
    test_putnbr_fd(-987654, "-987654");       // Test 7 - Multi-digit negative
    test_putnbr_fd(9, "9");                  // Test 8 - Single digit
    test_putnbr_fd(-9, "-9");                // Test 9 - Single negative digit
    
    // Remove the test file when done
    if (remove("test_output.txt") == 0)
        printf("\nTest file removed successfully.\n");
    else
        printf("\nFailed to remove test file.\n");
    
    return 0;
}
