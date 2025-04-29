#include "../libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void reset_test_file(const char *filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd > 0)
        close(fd);
}

char *get_file_content(const char *filename)
{
    int fd = open(filename, O_RDONLY);
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

void test_putnbr_fd(int n, char *expected, int custom_fd, const char *filename, const char *test_desc)
{
    static int test_count = 0;
    test_count++;
    
    // Reset test file
    reset_test_file(filename);
    
    // Run the function with the provided file descriptor
    int fd;
    if (custom_fd >= 0) {
        fd = custom_fd;
    } else {
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    }
    
    if (fd < 0)
    {
        printf("FAILURE: Test %d - Could not open test file\n", test_count);
        return;
    }
    
    ft_putnbr_fd(n, fd);
    
    // Only close if we opened it (not stdin/stdout/stderr)
    if (custom_fd < 0 || custom_fd > 2) {
        close(fd);
    }
    
    // Get the content written to the file (if using a regular file)
    char *result = NULL;
    if (custom_fd < 0 || custom_fd > 2) {
        result = get_file_content(filename);
        if (!result)
        {
            printf("FAILURE: Test %d - Could not read test file\n", test_count);
            return;
        }
        
        // Compare with expected
        if (strcmp(result, expected) == 0)
            printf("SUCCESS: Test %d - %s - Input: %d - FD: %d - Result: %s\n", 
                   test_count, test_desc, n, (custom_fd >= 0) ? custom_fd : fd, result);
        else
            printf("FAILURE: Test %d - %s - Input: %d - FD: %d - Expected: %s - Got: %s\n", 
                   test_count, test_desc, n, (custom_fd >= 0) ? custom_fd : fd, expected, result);
        
        free(result);
    } else {
        // For standard file descriptors, we can't easily capture the output
        printf("SUCCESS: Test %d - %s - Input: %d - FD: %d (Check the console output)\n", 
               test_count, test_desc, n, custom_fd);
    }
}

int main(void)
{
    printf("ft_putnbr_fd\n");
    
    // Basic test cases with a regular file
    test_putnbr_fd(0, "0", -1, "test_output1.txt", "Zero");
    test_putnbr_fd(42, "42", -1, "test_output2.txt", "Basic positive number");
    test_putnbr_fd(-42, "-42", -1, "test_output3.txt", "Negative number");
    test_putnbr_fd(2147483647, "2147483647", -1, "test_output4.txt", "INT_MAX");
    test_putnbr_fd(-2147483648, "-2147483648", -1, "test_output5.txt", "INT_MIN");
    
    // Test cases with different file descriptors
    int custom_fd = open("test_output_custom.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (custom_fd > 0) {
        test_putnbr_fd(123456, "123456", custom_fd, "test_output_custom.txt", "Custom file descriptor");
        close(custom_fd);
    }
    
    // Test with standard file descriptors - these will output to the console/terminal
    printf("\n--- Testing with stdout (FD 1) - Output should be '987654': ");
    test_putnbr_fd(987654, "987654", 1, NULL, "Standard output");
    
    printf("\n--- Testing with stderr (FD 2) - Output should be '-9': ");
    test_putnbr_fd(-9, "-9", 2, NULL, "Standard error");
    
    // Test with different files
    test_putnbr_fd(9, "9", -1, "test_output_final.txt", "Single digit");
    
    return 0;
}
