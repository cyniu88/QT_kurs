#include <iostream>


class A{
    public:
   virtual ~A() = default;
};

class B : public A{
    //int r = 2;
    public:
    void print(){

        std::cout <<"jestem w B "<<  std::endl;
    }
};
class C : public A{

};

int main()
{
    A* a = new A();

    B* b = dynamic_cast<B*>(a);

    b->print();
    delete a;
    return 0;
}
