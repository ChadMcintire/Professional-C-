#include <iostream>
#include <vector>
#include <memory>

struct Vec3
{
    int x, y, z;
    // following constructor is no longer needed since C++20
    Vec3(int x = 0, int y = 0, int z = 0) noexcept : x(x), y(y), z(z) { }
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v)
    {
        return os << '{' << "x:" << v.x << " y:" << v.y << " z:" << v.z  << '}';
    }
};

int main() {
    std::cout << "print this" << std::endl;
    //auto vectorptr = make_unique<vector<int>>();
    auto v1 = std::make_unique<Vec3>();
    std::cout << "make_unique<Vec3>():      " << *v1 << '\n';


    std::vector<int> vect;

    vect.push_back(10);
    vect.push_back(20);
    for (int x : vect)
    std::cout << x << std::endl;

    v1.reset(); //Free resource and set to null;
    return 0;

}
