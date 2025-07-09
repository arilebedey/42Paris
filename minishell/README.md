https://github.com/decilap/groupdev/

https://medium.com/@mostafa.omrane/mes-conseils-si-je-devais-recommencer-minishell-a9783c51ba1b

https://cdn.intra.42.fr/pdf/pdf/154328/en.subject.pdf

https://github.com/ft-palourde/minishell

use forks for heredocs because to correctly handle either signals or correct exit codes

### fork() allows us to redirect the FDs of each command separately through dup2()

For `cat file | grep foo | wc -l`:

- The shell does:
  1.  fork() for cat, set its output to pipe1
  2.  fork() for grep, set its input to pipe1, output to pipe2
  3.  fork() for wc, set its input to pipe2
