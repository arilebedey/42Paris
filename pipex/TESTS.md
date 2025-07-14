## **Test 14: The program uses the environment list [KO]**

**Tester command:**

```bash
PATH=$PWD/assets:$PATH VAR1="hello" VAR2="world" ../pipex/pipex "/dev/null" "env_var" "cat" "outs/test-14.txt"
```

**Reference output:**

```bash
VAR1="hello" VAR2="world" ./assets/env_var > outs/test-14-original.txt
```

**Manual steps:**

1. Run your program:
   ```bash
   PATH=$PWD/assets:$PATH VAR1="hello" VAR2="world" ../pipex/pipex "/dev/null" "env_var" "cat" "outs/test-14.txt"
   ```
2. Run the reference:
   ```bash
   VAR1="hello" VAR2="world" ./assets/env_var > outs/test-14-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-14.txt outs/test-14-original.txt
   ```

---

## **Test 15: The program handles the command [KO]**

## **Test 16: The output of the command is correct [KO]**

**Tester command:**

```bash
../pipex/pipex "assets/deepthought.txt" "cat" "hostname" "outs/test-15.txt"
```

**Reference output:**

```bash
< assets/deepthought.txt cat | hostname > outs/test-16-original.txt
```

**Manual steps:**

1. Run your program:
   ```bash
   ../pipex/pipex "assets/deepthought.txt" "cat" "hostname" "outs/test-15.txt"
   ```
2. Run the reference:
   ```bash
   < assets/deepthought.txt cat | hostname > outs/test-16-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-15.txt outs/test-16-original.txt
   ```

---

## **Test 17: The program handles the command [KO]**

## **Test 18: The output of the command is correct [KO]**

**Tester command:**

```bash
../pipex/pipex "assets/deepthought.txt" "grep Now" "head -2" "outs/test-17.txt"
```

**Reference output:**

```bash
< assets/deepthought.txt grep Now | head -2 > outs/test-18-original.txt
```

**Manual steps:**

1. Run your program:
   ```bash
   ../pipex/pipex "assets/deepthought.txt" "grep Now" "head -2" "outs/test-17.txt"
   ```
2. Run the reference:
   ```bash
   < assets/deepthought.txt grep Now | head -2 > outs/test-18-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-17.txt outs/test-18-original.txt
   ```

---

## **Test 19: The program handles the command [KO]**

## **Test 20: The output of the command is correct [KO]**

**Tester command:**

```bash
../pipex/pipex "assets/deepthought.txt" "grep Now" "wc -w" "outs/test-19.txt"
```

**Reference output:**

```bash
< assets/deepthought.txt grep Now | wc -w > outs/test-20-original.txt
```

**Manual steps:**

1. Run your program:
   ```bash
   ../pipex/pipex "assets/deepthought.txt" "grep Now" "wc -w" "outs/test-19.txt"
   ```
2. Run the reference:
   ```bash
   < assets/deepthought.txt grep Now | wc -w > outs/test-20-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-19.txt outs/test-20-original.txt
   ```

---

## **Test 21: The program handles the command [KO]**

## **Test 22: The output of the command is correct [KO]**

**Tester command:**

```bash
../pipex/pipex "assets/deepthought.txt" "grep Now" "cat" "outs/test-21.txt"
../pipex/pipex "assets/deepthought.txt" "wc -w" "cat" "outs/test-21.txt"
```

**Reference output:**

```bash
< assets/deepthought.txt grep Now | cat > outs/test-22-original.txt
< assets/deepthought.txt wc -w | cat > outs/test-22-original.txt
```

**Manual steps:**

1. Run your program (twice, as in the script):
   ```bash
   ../pipex/pipex "assets/deepthought.txt" "grep Now" "cat" "outs/test-21.txt"
   ../pipex/pipex "assets/deepthought.txt" "wc -w" "cat" "outs/test-21.txt"
   ```
2. Run the reference (twice, output to the same file):
   ```bash
   < assets/deepthought.txt grep Now | cat > outs/test-22-original.txt
   < assets/deepthought.txt wc -w | cat > outs/test-22-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-21.txt outs/test-22-original.txt
   ```

---

## **Test 25: The output of the command is correct [KO]**

**Tester command:**

```bash
../pipex/pipex "assets/deepthought.txt" "notexisting" "wc" "outs/test-25.txt"
```

**Reference output:**

```bash
< /dev/null cat | wc > outs/test-25-original.txt
```

**Manual steps:**

1. Run your program:
   ```bash
   ../pipex/pipex "assets/deepthought.txt" "notexisting" "wc" "outs/test-25.txt"
   ```
2. Run the reference:
   ```bash
   < /dev/null cat | wc > outs/test-25-original.txt
   ```
3. Compare outputs:
   ```bash
   diff outs/test-25.txt outs/test-25-original.txt
   ```

---

## **Test 31: The program does not timeout [KO]**

**Tester command:**

```bash
../pipex/pipex "/dev/urandom" "cat" "head -1" "outs/test-31.txt"
```

**Reference output:**
Not directly compared, but the test expects your program to **not hang** and to exit.

**Manual step:**

1. Run your program and see if it finishes:
   ```bash
   ../pipex/pipex "/dev/urandom" "cat" "head -1" "outs/test-31.txt"
   ```
   - If it hangs, your program is not closing the write end of the pipe in the parent, so `head -1` never sees EOF.

---

## **Summary Table**

| Test | Command to Run | Reference Command | Compare |
| ---- | -------------- | ----------------- | ------- |
| 14   | see above      | see above         | diff    |
| 15   | see above      | see above         | diff    |
| 16   | see above      | see above         | diff    |
| 17   | see above      | see above         | diff    |
| 18   | see above      | see above         | diff    |
| 19   | see above      | see above         | diff    |
| 20   | see above      | see above         | diff    |
| 21   | see above      | see above         | diff    |
| 22   | see above      | see above         | diff    |
| 25   | see above      | see above         | diff    |
| 31   | see above      | N/A               | N/A     |

---

**Tip:**  
If you want to see the actual output differences, use `diff -u` for a unified diff.

Let me know if you want a script to automate these manual checks!
