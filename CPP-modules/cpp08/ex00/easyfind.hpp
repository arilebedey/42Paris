#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
public:
  const char *what() const throw() {
    return "The value was not found in the container";
  }
};

template <typename T> typename T::iterator easyfind(T &container, int val) {
  typename T::iterator i = std::find(container.begin(), container.end(), val);
  if (i == container.end()) {
    throw ValueNotFoundException();
  }
  return i;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int val) {
  typename T::const_iterator i =
      std::find(container.begin(), container.end(), val);
  if (i == container.end())
    throw ValueNotFoundException();
  return i;
}
