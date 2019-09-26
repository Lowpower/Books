#include <list>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>

using namespace std;

template<typename T>
class SyncQueue {
	public:
		SyncQueue(int maxSize) : mMaxSize(maxSize), mNeedStop(false) {};
		void Put(const T& x){
			Add(x);
		}

		void Put(T&& x) {
			Add(std::forward<T>(x));
		}

		void Take(std::list<T>& list) {
			std::unique_lock<std::mutex> locker(m_mutex);
			m_notEmpty.wait(locker, [this]{return mNeedStop || NotEmpty();});
			if(mNeedStop) {
				return;
			}
			list = std::move(m_queue);
			m_notFull.notify_one();
		}

		void Take(T& t) {
			std::unique_lock<std::mutex> locker(m_mutex);
			m_notEmpty.wait(locker, [this]{return mNeedStop || NotEmpty();});
			if(mNeedStop) {
				return;
			}
			t = m_queue.front();
			m_queue.pop_front();
			m_notFull.notify_one();
		}

		void Stop() {
			{
				std::lock_guard<std::mutex> locker(m_mutex);
				mNeedStop = true;
			}
			m_notFull.notify_all();
			m_notEmpty.notify_all();
		}

		bool Empty() {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.empty();
		}

		bool Full () {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.size() == mMaxSize;;
		}

		size_t Size() {
			std::lock_guard<std::mutex> locker(m_mutex);
			return m_queue.size();
		}

		int Count() {
			return m_queue.size();
		}

	private:
		bool NotFull() const {
			bool full = m_queue.size() >= mMaxSize;
			if (full) {
				cout << "缓冲区满了，需要等待" << endl;
			}
			return !full;
		}

		bool NotEmpty() const {
			bool empty = m_queue.empty();
			if (empty) {
				cout << "缓冲区空了，需要等待。。。异步层的线程Id：" << this_thread::get_id() << endl;
			}
			return !empty;
		}
		
		template<typename F>
		void Add(F&& x) {
			std::unique_lock<std::mutex> locker(m_mutex);
			m_notFull.wait(locker, [this]{return mNeedStop || NotFull();});
			if(mNeedStop) {
				return;
			}
			m_queue.push_back(std::forward<F>(x));
			m_notEmpty.notify_one();
		}

	private:
		std::list<T> m_queue;		// 缓冲区
		std::mutex m_mutex;			// 互斥量和条件变量结合起来使用
		std::condition_variable m_notEmpty; // 不为空的条件变量
		std::condition_variable m_notFull;	// 没有满的条件变量
		int mMaxSize;
		bool mNeedStop;	// 停止标志
};
