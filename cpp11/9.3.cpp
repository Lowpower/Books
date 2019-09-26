#include <iostream>
#include <thread>
#include <chrono>
#include "9.2.cpp"

using namespace std;

int main() {
	ThreadPool pool;
	pool.Start(2);
	std::thread thd1([&pool]{
		for (int i = 0; i < 10; i++) {
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId] {
				cout << "同步线程1的线程id：" << thdId << endl;
			});
		}
	});
	std::thread thd2([&pool]{
		for(int i =  0; i < 10; i ++) {
			auto thdId = this_thread::get_id();
			pool.AddTask([thdId] {
				cout << "同步线程2的线程id：" << thdId << endl;
			});
		}
	});
	this_thread::sleep_for(std::chrono::seconds(100));
	pool.Stop();
	thd1.join();
	thd2.join();
	return 0;
}
