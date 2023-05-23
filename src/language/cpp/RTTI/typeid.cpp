/**
 * @file  typeid.cpp
 * @author Yuting Xie (xyt@bupt.cn)
 * @brief evaluate the basic functionalities of typeid
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <typeinfo>
#include <iostream>

class A {
    private:
        int a = 0;
    public:
        virtual void func() {
            std::cout << "A::func()" << std::endl;
        }
        virtual ~A() {}
};

class B1 : public A {
    private:
        int b1 = 1;
    public:
        virtual void func() {
            std::cout << "B1::func()" << std::endl;
        }
        virtual ~B1() {}
};

class B2 : public A {
    private:
        int b2 = 3;
    public:
        virtual void func() {
            std::cout << "B2::func()" << std::endl;
        }
        virtual ~B2() {}
};

class C : public B1, public B2 {
    private:
        int c = 2;
    public:
        virtual void func() {
            std::cout << "C::func()" << std::endl;
        }
        virtual ~C() {}
};

int main() {
    A a;
    B1 b1;
    B2 b2;
    C c;

    std::cout << "typeid(a).name(): " << typeid(a).name() << std::endl;
    std::cout << "typeid(b1).name(): " << typeid(b1).name() << std::endl;
    std::cout << "typeid(b2).name(): " << typeid(b2).name() << std::endl;
    std::cout << "typeid(c).name(): " << typeid(c).name() << std::endl;

    B1 *pb1 = &c;
    B2 *pb2 = &c;
    std::cout << "typeid(*pb1).name(): " << typeid(*pb1).name() << std::endl;
    std::cout << "typeid(*pb2).name(): " << typeid(*pb2).name() << std::endl;

    return 0;
}

