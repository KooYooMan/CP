#include<iostream>
#include<thread>
#include<future>
#include<vector>
#include<numeric>
#include<chrono>

static void printFirst() {
	std::cout << "First" << std::endl;
}

static void printSecond() {
	std::cout << "Second" << std::endl;
}

static void printThird() {
static void printThird() {
	std::cout << "Third" << std::endl;
}

class Foo {
		std::promise<void> promiseFirst, promiseSecond;
public:
    Foo() {}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
				promiseFirst.set_value();
    }

    void second(std::function<void()> printSecond) {
				promiseFirst.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
				promiseSecond.set_value();
    }

    void third(std::function<void()> printThird) {
				promiseSecond.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

int main() {
	
	Foo foo = Foo();

	std::thread t1 = (foo.second, printSecond);
	std::thread t2 = (foo.third, printThird);
	std::thread t3 = (foo.first, printFirst);

	t1.join();
	t2.join();
	t3.join();

	std::cout << "Done!!!" << std::endl;

	return 0;
}
