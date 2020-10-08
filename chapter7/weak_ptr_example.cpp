#include <memory>
#include <iostream>

using namespace std;

class Simple
{
    public:
        Simple() { cout << "Simple constructor called!" << endl; }
        ~Simple() { cout << "Simple destructor called!" << endl; }
};

void useResource(weak_ptr<Simple>& weakSimple)
{
    auto resource = weakSimple.lock();
    if (resource) {
        cout << "Resource still alive." << endl;
    } else {
        cout << "Resource has been freed!" << endl;
    }
}

int main()
{
    auto sharedSimple = make_shared<Simple>();
    shared_ptr<Simple> smartPtr2(sharedSimple);
    weak_ptr<Simple> weakSimple(sharedSimple);

    // Try to use the weak_ptr.
    useResource(weakSimple);

    // Reset the shared_ptr.
    // Still alive because smarPtr2 is around
    sharedSimple.reset();

    // Try to use the weak_ptr a second time.
    // still alive
    useResource(weakSimple);

    // kill the last reference
    // will be freed and set to null;
    smartPtr2.reset();

    // Should report freed
    useResource(weakSimple);

    return 0;
}
