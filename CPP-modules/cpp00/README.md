# ex01

### Allowed functions

The C++ standard library is allowed, thus we can get the get exit() from cstdlib.h

### Coplien form (in french)

(Mandatory above CPP02)

La **forme canonique de Coplien** (ou _Coplien Form_) désigne un ensemble de quatre fonctions membres fondamentales qu’une classe C++ bien conçue doit posséder lorsqu’elle gère des ressources ou définit des comportements de copie spécifiques.

Ces quatre fonctions sont :

1. **Le constructeur par défaut** — initialise un objet vide ou à un état valide.
2. **Le constructeur de copie** — définit comment créer un objet à partir d’un autre du même type.
3. **L’opérateur d’affectation (`operator=`)** — définit comment copier le contenu d’un objet existant vers un autre déjà créé.
4. **Le destructeur** — libère les ressources ou effectue le nettoyage nécessaire à la destruction de l’objet.

### Using const on function declarations to ensure no mutation of the object’s member variables

When you write:

```cpp
std::string getfirstname() const;
```

the `const` at the end means:

> “This function **does not and cannot modify** the object’s member variables (except those marked `mutable`).”

So, inside `getfirstname()` (and the other getters), you’re **only reading** data — not changing anything about the `Contact` object.  
This allows you to call these methods on `const` instances of the class, such as:

```cpp
const Contact c;
c.getfirstname();  // ✅ works, because getfirstname() is const
```

If `getfirstname()` was not marked `const`, the compiler would complain here — because it can’t guarantee that `c` (a read-only object) wouldn’t be modified.

### Differentiating class variables form method params

We can prefix class variables with an underscore (\_) to differentiate them from method parameters.

# ex02

### Arrays vs Vectors in C++

In C++, **arrays** and **vectors** both store sequences of elements, but they differ in flexibility and safety. An **array** has a fixed size determined at compile time (or at allocation for dynamic arrays) and provides no bounds checking; its memory must be managed manually when dynamically allocated. A **`std::vector`**, on the other hand, is part of the Standard Template Library (STL) and handles memory automatically. It can dynamically grow or shrink in size, offers convenient methods like `.push_back()` and `.size()`, and provides safer element access through `.at()`. In general, arrays are preferred for fixed-size, low-level data, while vectors are the go-to choice for dynamic, high-level use cases.

### Account.hpp

#### `acc_int_t` type alias

```cpp
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
```

`acc_int_t` is a **type alias** for a `std::pair` holding two iterators —  
one iterating over a vector of `Account` objects (`accounts_t::iterator`),  
and the other over a vector of integers (`ints_t::iterator`).

It lets you loop through both vectors **in parallel** (e.g., accounts and deposit amounts) using a single variable that keeps both iterators together.

```cpp
for (acc_int_t it(acc_begin, dep_begin);
     it.first != acc_end && it.second != dep_end;
     ++(it.first), ++(it.second))
{
    (*(it.first)).makeDeposit(*(it.second));
}
```

#### amounts_size

```cpp
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
```

It calculates how many elements are in the `amounts` array by dividing its total byte size by the size of one `int`, storing that count as a constant.

#### `ints_t`

```cpp
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
```

`ints_t deposits(d, d + d_size);`  
→ creates a `std::vector<int>` named `deposits`, copying all elements from array `d` in the range `[d, d + d_size)`.

It doesn’t access unallocated memory because `d + d_size` is a pointer **one past the last element**, which is valid as a _range end marker_ in C++ (it’s never dereferenced).

#### iterators

```cpp
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();
```

`ints_t::iterator dep_begin = deposits.begin();`  
→ declares an iterator `dep_begin` (a special pointer-like object) that points to the **first element** of the `deposits` vector.

`ints_t::iterator` specifies the iterator type that belongs to `std::vector<int>` — allowing iteration through its elements safely, just like using a pointer but managed by the container.

Again, it lets you loop through both vectors **in parallel**.

```cpp
for (acc_int_t it(acc_begin, dep_begin);
     it.first != acc_end && it.second != dep_end;
     ++(it.first), ++(it.second))
{
    (*(it.first)).makeDeposit(*(it.second));
}
```

#### `std::for_each`

```cpp
  std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));
```

This line uses `std::for_each` from `<algorithm>` to apply a function to every element in a range — here, from `acc_begin` to `acc_end`, which are iterators over a `std::vector` of `Account` objects. In essence, it visits each account in the container.

The function passed, `std::mem_fun_ref(&Account::displayStatus)`, adapts the `displayStatus()` member function so it can be called for each object reference in the vector. Thus, this line effectively calls `account.displayStatus()` for every `Account` in the vector — the concise equivalent of a manual loop over all accounts.

The adapter `std::mem_fun_ref` bridges that gap by turning the member function pointer into a callable object that `std::for_each` can use, automatically invoking the method on each `Account` in the range.
