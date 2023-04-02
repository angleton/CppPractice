/**
 * async multi threading with c++
 * flag : -pthread -std=c++0x
 */

#include <iostream> // std::cout
#include <Windows.h> // Need this for Sleep() not sleep() in Windows.
#include <future> // std::async

class MyClass {
public:
    auto doStuffSoLong() -> int
    {
        std::cout << "1" << std::endl << std::flush; //dont buffer
        return 0;
    }
    auto doAnotherStuff() -> int
    {
        std::cout << "2" << std::endl << std::flush; //dont buffer
        return 0;
    }
    auto doAnotherLongStuff(const std::string& param) -> int
    {
        Sleep(3); // Simulate doing something. 
        std::cout << "3" << std::endl << std::flush; //dont buffer
        return 0;
    }
};

int main()
{
    //for (int n : a)
    auto repetitions = 10;
    while ((repetitions--) > 0) {
        Sleep(1); // Simulate doing something. 
    }
    //for (int i = 0; i < 10; ++i) {
    //    Sleep(1); // Simulate doing something. 
    //}

    Sleep(3); // give a time to open task manager
    MyClass app;

    auto thread1 = std::async(std::launch::async, &MyClass::doStuffSoLong, &app);
    auto thread2 = std::async(std::launch::async, &MyClass::doAnotherStuff, &app);
    auto thread3 = std::async(std::launch::async, &MyClass::doAnotherLongStuff, &app, "hello world");
    if (thread1.get() == 0) std::cout << "thread 1 succes" << std::endl;
    if (thread2.get() == 0) std::cout << "thread 2 succes" << std::endl;
    if (thread3.get() == 0) std::cout << "thread 3 succes" << std::endl;
}