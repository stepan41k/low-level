#include <iostream>

using namespace std;

template <typename T> class Named {
public:
  Named(const T &value) : value_(value) {}
  const T &getValue() const { return value_; }

private:
  T value_;
};

int main() {
  Named<int> num(10);
  Named<double> num2(3.14);

  cout << num.getValue() << " " << num2.getValue() << endl;
}
