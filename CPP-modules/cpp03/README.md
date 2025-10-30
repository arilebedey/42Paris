# C++ Module 03 – Inheritance

### Initialization in C++ Classes

In C++ classes, initialization is the process of properly setting up member variables and base class parts when an object is created. This is done using **constructor initializer lists**, which allow you to directly initialize attributes or call base class constructors before the body of the derived constructor runs. For example, a _derived_ class can call its _base_ constructor with `: BaseClass(arg)` to ensure inherited data is correctly set up. Using initializer lists is more efficient and often necessary for attributes that cannot be assigned after construction (like references or `const` members). Proper initialization ensures predictable object states and clean, well-structured class behavior.
