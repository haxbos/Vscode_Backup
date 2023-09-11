#include <iostream>
#include <memory>
#include <cassert>
using namespace std;

class Foo {
 public:
  std::shared_ptr<Foo> GetSPtr() {
    return std::shared_ptr<Foo>(this);
  }
};

class Foo2 : public std::enable_shared_from_this<Foo2> {
public:
    std::shared_ptr<Foo2> GetSPtr() {
        return shared_from_this();
    }
};

//不能直接指向this,必须继承enable_shared_from_this
void testSharedThis(){
    auto sptr1 = std::make_shared<Foo>();
    assert(sptr1.use_count() == 1);
    auto sptr2 = sptr1->GetSPtr();
    assert(sptr1.use_count() == 1);
    assert(sptr2.use_count() == 1);
}

void testEnableSharedFromThis(){
    auto sptr1 = std::make_shared<Foo2>();
    assert(sptr1.use_count() == 1);
    auto sptr2 = sptr1->GetSPtr();
    assert(sptr1.use_count() == 2);
    assert(sptr2.use_count() == 2);
}

int main(){
    testSharedThis();
    cout << "----------------1" << endl;
    testEnableSharedFromThis();
    cout << "----------------2" << endl;
    return 0;
}
