## TLDR

The virtual keyword in the base class destructor tells the compiler to look for a vtable entry for a destructor in the derived class and call that

Compiler will warn if class has at least one virtual function and no virtual destructor

## 🧩 1. What the Virtual Table (vtable) Actually Is

- The **vtable** is per‑class, not per‑object.
- Each **polymorphic class** (a class with at least one `virtual` function) has its own static table of function pointers.
- Every polymorphic **object** stores a hidden pointer called the **vptr**, which points to that class’s vtable at runtime.

## 🧠 The Core of the Error

When compiling, the compiler produces the following message:

```sh
main.cpp:27:3: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
   27 |   delete generic;
      |   ^
main.cpp:28:3: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
   28 |   delete doggy;
      |   ^
main.cpp:29:3: error: delete called on non-final 'Animal' that has virtual functions but non-virtual destructor [-Werror,-Wdelete-non-abstract-non-virtual-dtor]
   29 |   delete kitty;
      |   ^
3 errors generated.
make: *** [obj/main.o] Error 1
```

This means the compiler detected that you are deleting a pointer to a **polymorphic** class (`Animal`) — it has virtual functions — but that class’s destructor is **not virtual**.  
That situation is inherently unsafe, because deleting derived objects through such a base pointer would lead to **undefined behavior**.

## 🔍 Why Polymorphism Triggers This

When you declare _any_ function in a class as `virtual` (e.g. `makeSound()`),  
that class becomes **polymorphic** — it gains a _vtable_ (virtual table) for dynamic dispatch.

So when you call:

```cpp
delete basePtr;
```

where `basePtr` actually points to a _derived object_ (like `Dog` or `Cat`),  
the compiler has to decide **which destructor to run first** — the derived one or the base one.

---

## ⚠️ The Problem

If the base class destructor (`Animal::~Animal()`) is **not virtual**,  
the deletion will only call the _base_ part of the object — the `Animal` destructor —  
and skip the `Dog` or `Cat` destructor entirely.

That means:

- The derived part of the object never gets destroyed.
- Any resources held there (heap-allocated memory, open files, etc.) will **leak**.
- Formally, the C++ standard calls this **undefined behavior**.

---

### 💬 In short:

Your compiler _detected a potentially catastrophic bug_ at compile time —  
you tried to destroy a polymorphic object (`Animal` → `Dog`/`Cat`)  
through a non-virtual base destructor.

The **correct polymorphic pattern** is always:

```cpp
class Animal {
public:
  virtual ~Animal() {}
  virtual void makeSound() const;
};
```

Now, `Animal`’s destructor is part of the virtual table —  
so when you `delete` through an `Animal*`,  
C++ will look up the _actual_ object type in the vtable and call the correct destructor chain:
👉 `Dog::~Dog()` → `Animal::~Animal()`

No leaks, no undefined behavior, and no compiler error.
