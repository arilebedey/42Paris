### Instructions

1. Add this folder (get_next_line_tests) to you get_next_line program folder
2. `cd get_next_line_tests`
3. `make test`

### Additional test

Look at the Makefile for tests with different BUFFER_SIZE assignments
Place `test_stdin_manual_compilation.c` into your GNL folder and compile everything together to test standard input

### Leakage test
```bash
cc -g get_next_line.c get_next_line_utils.c test_stdin_manual_compilation.c -o gnl_test
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl_test

```
### Questions
- Why does it work with different buffer sizes?
- Why did you use a static variable? What is a static variable?
- Do you check for invalid FDs? Did you think of optimizing the check? What is an invalid FD?
- Why do we pass an FD to read()?
- Do you zero-terminate buffer?
- Do you read line-by-line?
