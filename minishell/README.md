### Subject

[EN] https://cdn.intra.42.fr/pdf/pdf/154328/en.subject.pdf

### Others' reference minishell implementations

https://github.com/decilap/groupdev/

https://github.com/ft-palourde/minishell

https://github.com/mli42/at42minishell

### Lexer

A lexer (core minishell concept) (short for lexical analyzer) is a component that takes a raw input string (like a command line) and splits it into a sequence of tokens—atomic pieces such as words, operators (|, >, <), and redirections.

It can be done using the following 2 structs and then fed into the AST builder (learn about AST below)

```c
typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_OUT,
    // etc...
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*text;
	struct s_token	*next;
}					t_token;
```

### Operator precedence

`ls > out.txt | cat` is parsed as `ls > ( out.txt | cat )` not as `( ls > out.txt ) | cat`

When handling operator precedence in minishell, it’s important to also account for quoting rules (' and "), since quotes can prevent operators like | or > from being treated as syntax. For example, echo "a | b" should not create a pipe node in the AST. Proper precedence handling must therefore happen after correct tokenization and quote parsing.

See `build_ast()` in `scr/exec`

### AST (Abstract Syntax Tree)

An AST is a tree data structure used in programming language interpreters, compilers, and shells to represent the hierarchical structure of source code or commands

Each node in the tree is an operation (like a command, a pipe, or a redirection)

![AST for Minishell](https://raw.githubusercontent.com/arilebedey/42Paris/refs/heads/main/minishell/The%20Minishell%20Abstract%20Syntaxt%20Tree.png)

### Heredocs

Advice from 1 group : use forks for heredocs because to correctly handle either signals or correct exit codes
