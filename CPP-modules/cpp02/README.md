### Floating Point: Accuracy vs. Precision

**English:**  
Floating point numbers excel in precision but often lack perfect accuracy. They can represent very small differences and fractional values, giving programmers the ability to model continuous quantities. However, many decimal fractions cannot be represented exactly in binary form—this leads to slight rounding errors. As a result, while floating point calculations can produce very fine distinctions, they may still differ subtly from the mathematically exact result. Understanding this tradeoff helps avoid bugs and unexpected behavior in numerical computations.

**Français :**  
Les nombres à virgule flottante offrent une grande précision mais une exactitude limitée. Ils peuvent représenter des différences très fines et des valeurs fractionnaires, ce qui permet de modéliser des grandeurs continues. Cependant, beaucoup de fractions décimales ne peuvent pas être représentées exactement en binaire, provoquant de légères erreurs d’arrondi. Ainsi, bien que les calculs en virgule flottante permettent une distinction très détaillée, ils peuvent s’écarter légèrement du résultat mathématiquement exact. Comprendre ce compromis permet d’éviter des erreurs et des comportements inattendus dans les programmes numériques.

### Fixed-point numbers benefit

Used in:

- **Computer graphics** — rendering, textures, transformations
- **Audio processing** — sound synthesis, effects
- **Scientific programming** — precise calculations
- **Embedded systems** — microcontrollers with limited resources
- **Digital Signal Processing (DSP)** — real-time audio/signal analysis

**Why Use Them:**

1. **Speed**: Integer arithmetic is significantly faster than floating-point math, especially on older CPUs or embedded systems without dedicated floating-point hardware

2. **Predictable Precision**: You always know exactly what precision you have (with 8 bits: ±1/256 ≈ ±0.00390625). Floating-point precision varies and can be unpredictable

3. **Determinism**: Perfect for real-time systems (games, audio, control systems) where you need consistent, predictable behavior—no floating-point rounding surprises

4. **Memory Efficiency**: Often uses less memory than floats while maintaining adequate precision for the application

### int to float

The int is automatically promoted to float because of hierarchy:

double < float < int

```cpp
float Fixed::toFloat(void) const {
  return static_cast<float>(this->_rawBits) / (1 << _fractionalBits);
}
```

### Why min() & max() declared as `static`

**Static** means they belong to the **class itself**, not individual instances. You call them like:

```cpp
Fixed::max(a, b)  // not a.max(b)
```
