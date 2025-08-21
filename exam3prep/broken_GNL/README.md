To debug a segmentation fault in your C binary (`a.out`) when it’s run with input piped from a file (`cat infile | ./a.out`).

```bash
gdb ./a.out
```

Then inside gdb:

```gdb
run < infile
```
