Here’s a concise, creative, and resourceful summary of the **features your shell parser must support for 42 Minishell** (mandatory part):

---

## **Shell Parser Features Required**

### 1. **Tokenization**

- Split input into tokens: words, operators (`|`, `<`, `>`, `<<`, `>>`), and quoted strings.
- Correctly handle whitespace and special characters.

### 2. **Quoting**

- **Single quotes `'...'`**: treat everything inside as literal (no expansion, no splitting).
- **Double quotes `"..."`**: treat as literal except for `$` (variable expansion allowed inside).

### 3. **Variable Expansion**

- Expand `$VAR` and `$?` (last exit status) in unquoted and double-quoted contexts.

### 4. **Redirections**

- Support:
  - **Input**: `<`
  - **Output**: `>`
  - **Append**: `>>`
  - **Heredoc**: `<<` (read until delimiter line)
- Correctly associate filenames and delimiters with their operators.

### 5. **Pipes**

- Support `|` to connect commands in a pipeline.
- Build a structure (AST or similar) to represent the pipeline.

### 6. **Command Separation**

- Parse commands and arguments, including those with quotes and expansions.

### 7. **Built-in Commands**

- Recognize and handle: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

### 8. **Error Handling**

- Detect and report syntax errors (e.g., unclosed quotes, missing filenames).
- Do not crash on malformed input.

### 9. **Signal Handling**

- Respond to `Ctrl-C`, `Ctrl-D`, and `Ctrl-\` as specified.

### 10. **Environment**

- Pass environment variables to child processes.
- Update environment for built-ins like `export` and `unset`.

### 11. **History**

- Integrate with `readline` for command history.

---

## **Summary Table**

| Feature            | Details                                       |
| ------------------ | --------------------------------------------- | ------------------------------ |
| Tokenization       | Words, operators, quotes                      |
| Quoting            | Single/double quotes, literal/expansion rules |
| Variable Expansion | `$VAR`, `$?`                                  |
| Redirections       | `<`, `>`, `>>`, `<<`                          |
| Pipes              | `                                             | ` operator, pipeline structure |
| Command Separation | Arguments, quoted strings                     |
| Built-ins          | echo, cd, pwd, export, unset, env, exit       |
| Error Handling     | Syntax errors, unclosed quotes, missing files |
| Signal Handling    | Ctrl-C, Ctrl-D, Ctrl-\                        |
| Environment        | Pass/update env variables                     |
| History            | Use readline, add_history                     |

---

**In short:**  
Your parser must handle quoting, variable expansion, redirections, pipes, built-ins, and error/signal handling—just like a real shell, but limited to the features required by the subject.
