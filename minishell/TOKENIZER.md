Here’s a **compact pseudo-code** for the **relevant part** of a tokenizer that correctly handles both single (`'`) and double (`"`) quotes before AST building:

```c
tokens = []
i = 0
while i < len(input):
    skip_spaces()
    if is_operator(input[i]):
        tokens.append(make_token(OPERATOR, input[i]))
        i++
    else:
        buf = ""
        while i < len(input) && !is_space(input[i]) && !is_operator(input[i]):
            if input[i] == '\'':
                buf += read_until('\'', literal_mode=True)
            else if input[i] == '"':
                buf += read_until('"', expand_vars=True)
            else:
                buf += input[i++]
        tokens.append(make_token(WORD, buf))
```

**Key points:**

- **Single quotes** → literal mode (no variable expansion, take text as-is).
- **Double quotes** → allow variable expansion but preserve spaces inside.
- **Operators** (`|`, `<`, `>`, `>>`, `<<`) are always separate tokens.

This ensures the AST builder never sees operators that were inside quotes.

If you want, I can give you a **full C implementation** of this tokenizer that integrates with your `t_token` struct. Would you like me to do that?
