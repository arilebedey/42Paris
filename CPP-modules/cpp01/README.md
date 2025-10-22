# ex00

### Initializing

```cpp
Zombie::Zombie(const std::string &name) : _name(name) {}
```

is the same as

```cpp
Zombie::Zombie(const std::string &name) {
  _name = name;
}
```

# ex03

### Initializing References in C++ | Benefit of references

In C++, **references must always be initialized when they are declared**, and they cannot be reseated later. This means once a reference is bound to an object, it will always refer to that same object. Because of this behavior, you **cannot assign to a reference inside a constructor body** — it must be set as part of the object’s initialization process.

The correct and only way to initialize a reference member in a class is through the **member initializer list** in the constructor. For example:

```cpp
HumanA::HumanA(std::string name, Weapon &weapon)
    : _name(name), _weapon(weapon) {}
```

Here, `_weapon` is directly bound to the `weapon` argument before the constructor body runs. If you tried to assign it later inside the braces, the compiler would reject it, since by then `_weapon` already exists uninitialized — which is illegal for references.

This design ensures reference members are always valid, making them ideal for mandatory dependencies. If a member might be absent, a pointer (`Weapon*`) or smart pointer (`std::shared_ptr<Weapon>`) should be used instead.

### Initializing Pointers in C++

Pointers in C++ should always be initialized to a known value, typically `nullptr` (modern replacement for `NULL`), to avoid undefined behavior. An uninitialized pointer contains an unpredictable memory address, and dereferencing it can cause serious crashes or data corruption. By initializing a pointer to `nullptr`, you explicitly indicate that it currently points to no valid object, making your intent clear and your code safer. This practice helps you easily check if a pointer is valid before using it, e.g., `if (ptr) { ... }`, ensuring clean and reliable memory handling.
