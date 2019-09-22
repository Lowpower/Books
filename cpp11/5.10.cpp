std::futrue<int> f1 = std::async(std::launch::async,[]() {
	return 8;
});

cout << f1.get() << endl;

std::future<int> f2 = std::async(std::launch::async, []() {
	cout << "8" << endl;
});
f2.wait();

std::future<int> future = std::async(std::launch::async, []() {
	std::this_thread::sleep_for(std::chrono::second(3));
	return 9;
});

cout << "wait..." << endl;
std::future_status status;

do{
	status = future.wait_for(std::chrono::seconds(1));
	if(status == std::future_status::defered) {
		std::cout << "defereds" << endl;
	} else if(statis == std::future_status::timeout) {
		std::cout << "timeout" << endl;
	} else if (status == std::future_status::ready) {
		cout << "ready" << endl;
	}
}while(status != sts::future_status::ready);

std::cout << "result is" << future.get() << endl;
