#include <iostream>

// --- CLASSES PARENTES ---
class bag {
public:
  virtual ~bag() {}
  virtual void print() const = 0;
};

class searchable_bag : public virtual bag {
public:
  virtual bool has(int val) const = 0;
  virtual void add(int val) = 0;
};

// --- CLASSE CONCRÈTE DE BASE ---
class array_bag : public virtual bag {
protected:
  int *_data;
  int _size;
  int _capacity;

public:
  array_bag() : _data(new int[10]), _size(0), _capacity(10) {}

  virtual ~array_bag() { delete[] _data; }

  void add(int val) {
    if (_size < _capacity)
      _data[_size++] = val;
  }

  void print() const {
    for (int i = 0; i < _size; i++)
      std::cout << _data[i] << " ";
    std::cout << std::endl;
  }
};

// --- CLASSE CONCRÈTE (Héritage multiple) ---
class searchable_array_bag : public array_bag, public searchable_bag {
public:
  bool has(int val) const {
    for (int i = 0; i < _size; i++)
      if (_data[i] == val)
        return true;
    return false;
  }

  void add(int val) { array_bag::add(val); }
};

// --- WRAPPER ---
class set {
private:
  searchable_bag *_inner;

public:
  set(searchable_bag &bag) : _inner(&bag) {}

  searchable_bag &get_bag() const { return *_inner; }

  void add(int val) {
    if (!_inner->has(val))
      _inner->add(val);
  }
};

int main() {
  searchable_array_bag *array = new searchable_array_bag();

  set s(*array);

  s.add(42);
  s.add(42);
  s.add(7);

  s.get_bag().print();

  delete array;
  return 0;
}
