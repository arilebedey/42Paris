### Links

https://github.com/decilap/groupdev/

https://medium.com/@mostafa.omrane/mes-conseils-si-je-devais-recommencer-minishell-a9783c51ba1b

https://cdn.intra.42.fr/pdf/pdf/154328/en.subject.pdf

https://github.com/ft-palourde/minishell

### Heredocs

use forks for heredocs because to correctly handle either signals or correct exit codes

### Regress testing

Do tests for each functionality at the moment of writing it, because regress error can happen very easily on minishell

### AST (Abstract Syntax Tree)

An AST is a tree data structure used in programming language interpreters, compilers, and shells to represent the hierarchical structure of source code or commands

Each node in the tree is an operation (like a command, a pipe, or a redirection)

### Lexer

A lexer (short for lexical analyzer) is a component that takes a raw input string (like a command line) and splits it into a sequence of tokens—atomic pieces such as words, operators (|, >, <), and redirections.
