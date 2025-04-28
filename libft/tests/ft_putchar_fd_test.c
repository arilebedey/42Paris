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
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
        int fd1 = 1; // stdout
    int fd2 = 2; // stderr
    int test_fd;
    char buffer[2];
    char test_char = 'A';
    int read_bytes;
    
    printf("ft_putchar_fd\n");
    
    // Test 1: Write to stdout (fd 1)
    printf("SUCCESS: Test 1 - Write to stdout - Input: '%c' - Result: ", test_char);
    fflush(stdout);
    ft_putchar_fd(test_char, fd1);
    printf("\n");
    
    // Test 2: Write to stderr (fd 2)
    fprintf(stderr, "SUCCESS: Test 2 - Write to stderr - Input: '%c' - Result: ", test_char);
    fflush(stderr);
    ft_putchar_fd(test_char, fd2);
    fprintf(stderr, "\n");
    
    // Test 3: Write to a file
    test_fd = open("test_file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (test_fd == -1)
    {
        printf("FAILURE: Test 3 - Write to file - Could not create test file\n");
        return (1);
    }
    
    ft_putchar_fd(test_char, test_fd);
    lseek(test_fd, 0, SEEK_SET); // Reset file position to beginning
    
    memset(buffer, 0, sizeof(buffer));
    read_bytes = read(test_fd, buffer, 1);
    
    if (read_bytes == 1 && buffer[0] == test_char)
        printf("SUCCESS: Test 3 - Write to file - Input: '%c' - Result: '%c'\n", test_char, buffer[0]);
    else
        printf("FAILURE: Test 3 - Write to file - Input: '%c' - Expected '%c', Got '%c'\n", 
               test_char, test_char, buffer[0]);
    
    close(test_fd);
    remove("test_file.txt");
    
    return (0);
}
