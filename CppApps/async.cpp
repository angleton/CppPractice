/**
* async multi-threading with C++
* flag : -pthread -std=c++0x
*/

#include <iostream> // std::cout
#include <Windows.h> // Need this for Sleep and not "sleep()" in Windows. 
#include <future>

class testClass {
public:
	auto doLongStuff() -> int
	{
		for (int i = 0; i < 10; ++i) {
			Sleep(10); // Simulate doing something. 
		}
		std::cout << "1" << std::endl << std::flush; // Don't buffer
		return 0;
	}
	auto doOtherStuff() -> int
	{
		std::cout << "2" << std::endl << std::flush; // Don't buffer.
		return 0;
	}
	auto doAnotherLongStuff(const std::string& param) -> int
	{
		Sleep(10); // Simulate doing something. 
		std::cout << "3" << std::endl << std::flush; // Don't buffer. 
		return 0;
	}	
	auto useForEach(const std::string& param) -> int
	{
		int arr[] = { 1,2,3,4,5 };   //array initialization
		std::cout << "4.  The elements are: ";
		for (auto i : arr)
		{
			std::cout << i << " ";
		}
		return 0;
	}
};

int main(int argc, char* argv[])
{
	//for (int n : a)
	auto repetitions = 10;
	while ((repetitions--) > 0) {
		Sleep(1); // Simulate doing something. 
	}
	//for (int i = 0; i < 10; ++i) {
	//    Sleep(1); // Simulate doing something. 
	//}

	Sleep(3); // Give a time to open Task Manager. 
	testClass app;

	auto thread1 = std::async(std::launch::async, &testClass::doLongStuff, &app);
	auto thread2 = std::async(std::launch::async, &testClass::doOtherStuff, &app);
	auto thread3 = std::async(std::launch::async, &testClass::doAnotherLongStuff, &app, "Hello World!");
	auto thread4 = std::async(std::launch::async, &testClass::useForEach, &app, "Use New C++ Foreach");
	if (thread1.get() == 0) std::cout << "thread 1 success" << std::endl;
	if (thread2.get() == 0) std::cout << "thread 2 success" << std::endl;
	if (thread3.get() == 0) std::cout << "thread 3 success" << std::endl;
	if (thread4.get() == 0) std::cout << "thread 4 success" << std::endl;
}