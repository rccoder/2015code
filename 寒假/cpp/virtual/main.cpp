#include <iostream>
using namespace std;
class A
{
    public:
        A()
        {
            f();
        }
        ~A()
        {
        //……
        }
        virtual void f();
        void g();
        void h()
        {
            f();
            g();
        }

};


class B : public A
{
    public:
        ~B()
        {
        //……
        }
        void g();
        void f();
};

A a;        //调用A::A()和A::f
a.f();      //调用A::f
a.g();      //调用A::g()
a.h();      //调用A::h() A::f() A::g()



B b;        //调用B::B() A::A() A::f()
b.f();      //调用B::f();
b.g();      //调用B::g()
b.h();      //调用A::h  B::f() B::g()


A *p;
p = &a;
p->f()      //调用A::f()
p->g()      //调用A::g()
p->h()      //调用A::h() A::f() A::g()



p = &b;
p->f()      //调用B::f()
p->A::f();  //调用A::f()
p->g()      //调用A::g()   对非虚函数的调用采用静态绑定
