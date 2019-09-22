#include <thread>
#include <memory>
#include <vector>
#include <iostream>
#include <mutex>

using namespace std;

std::mutex g_lock;

void func() {
	//g_lock.lock();
	cout << "entered thread" << std::this_thread::get_id() << endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << "leave thread" << std::this_thread::get_id() << endl;
	//g_lock.unlock();
}

int main() {
	std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}
