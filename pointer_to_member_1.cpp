#include <cstddef>
#include <iostream>
struct Archer {
    explicit Archer(size_t id) : id_(id) {};
    size_t id_;
};

typedef size_t Archer::* ID;

void test(const Archer* item, ID f) {
    std::cout << f << std::endl;            // 1
    std::cout << item << std::endl;         // 0x7ffd5e9fa770
    std::cout << &(item->*f) << std::endl;  // 0x7ffd5e9fa770
    std::cout << item->*f << std::endl;     // 123
};

int main() {
    Archer a(1);
    ID f = &Archer::id_;
    test(&a, f);
}