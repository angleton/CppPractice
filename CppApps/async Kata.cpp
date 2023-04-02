#include <iostream> // std::cout
#include <Windows.h> // Need this for Sleep and not sleep() in Windows. 
#include <future>
#include <gtest/gtest.h>

class testClass2 {
public:
	auto doLongStuff() -> int
	{
		auto repetitions = 10;
		while (repetitions-- > 0){
			Sleep(10); // Simulate doing something. 
		}
		std::cout << "Task 1 Start on thread " << std::this_thread::get_id 
			<< std::endl << std::flush; // Don't buffer
		return 0;
	}
	auto doOtherStuff() {
		std::cout << "Task 2 Start on thread " << std::this_thread::get_id 
			<< std::endl << std::flush; // Don't buffer. 
		return 0;
	}
	auto doAnotherLongStuff(const std::string& param) -> int
	{
		Sleep(10); // Simulate doing something. 
		std::cout << "Task 3 Start on thread " << std::this_thread::get_id 
			<< " with param=" << param << std::endl << std::flush; // Don't buffer. 
		return 0;
	}
	auto useForEach(const std::string& param) -> int
	{
		int arr[] = { 1,2,3,4,5 };	// array initialization
		std::cout << "Task 4 Start on thread " << std::this_thread::get_id 
			<< " with array elements ";
		for (int i : arr)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl << std::flush; // Don't buffer.;
		return 0; 
	}
};

int main(int argc, char* argv[])
{
	//testing::InitGoogleTest(&argc, argv);
	//RUN_ALL_TESTS();

	auto repetitions = 5;
	while (repetitions-- > 0)
	{
		Sleep(3); // Simulate diong something. 
	}

	Sleep(3); // Give a time to open Task Manager. 
	testClass2 app;

	auto thread1 = std::async(std::launch::async, &testClass2::doLongStuff, &app);
	auto thread2 = std::async(std::launch::async, &testClass2::doOtherStuff, &app);
	auto thread3 = std::async(std::launch::async, &testClass2::doAnotherLongStuff, &app, "Hello World!");
	auto thread4 = std::async(std::launch::async, &testClass2::useForEach, &app, "Use New C++ Foreach");
	if (thread1.get() == 0) std::cout << "Task 1 success" << std::endl;
	if (thread2.get() == 0) std::cout << "Task 2 success" << std::endl;
	if (thread3.get() == 0) std::cout << "Task 3 success" << std::endl;
	if (thread4.get() == 0) std::cout << "Task 4 success" << std::endl;
}