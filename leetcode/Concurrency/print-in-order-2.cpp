#include<iostream>
#include<thread>
#include<future>
#include<vector>
#include<numeric>
#include<chrono>

void printFirst() {
	std::cout << "First" << std::endl;
}

void printSecond() {
	std::cout << "Second" << std::endl;
}

void printThird() {
	std::cout << "Third" << std::endl;
}

class Foo {
	int foo;
public:
    Foo() {
			foo = 0;
		}

    void first(std::function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
				foo += 1;
    }

    void second(std::function<void()> printSecond) {
				while (foo < 1) {}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
				foo += 1;
    }

    void third(std::function<void()> printThird) {
				while (foo < 2) {}
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
				foo += 1;
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
