#include "blocking_queue.h"
#include "../variable.h"
	
template<typename T>
void BlockingQueue<T>::Put(const T& task){
	std::unique_lock<std::mutex> lock(mtx);
    if (queue_.size() > capacity_ - 2){
        qDebug("za duzo w kolejce!!!!!");
        return;
    }
	full_.wait(lock, [this]{return (queue_.size() < capacity_);} );
    //assert(queue_.size() < capacity_);
	queue_.push(task);
	empty_.notify_all(); 
}

template<typename T>
T BlockingQueue<T>::Take(){
	std::unique_lock<std::mutex> lock(mtx);
	empty_.wait(lock, [this]{return !queue_.empty();} );
	assert(!queue_.empty());
	T front(queue_.front());
	queue_.pop();
	full_.notify_all();
	return front;
}

template<typename T>
size_t BlockingQueue<T>::Size(){
	std::lock_guard<std::mutex> lock(mtx);
	return queue_.size();
}

template<typename T>
T BlockingQueue<T>::Front(){
	std::unique_lock<std::mutex> lock(mtx);
	empty_.wait(lock, [this]{return !queue_.empty();} );
	assert(!queue_.empty());
	T front(queue_.front());
	return front;
}

template<typename T>
T BlockingQueue<T>::Back(){
	std::unique_lock<std::mutex> lock(mtx);
	empty_.wait(lock, [this]{return !queue_.empty();} );
	assert(!queue_.empty());
	T back(queue_.back());
	return back;
}

template<typename T>
bool BlockingQueue<T>::Empty(){
	std::unique_lock<std::mutex> lock(mtx);
	return queue_.empty();
}

template<typename T>
void BlockingQueue<T>::SetCapacity(const size_t capacity){
	capacity_ = (capacity > 0 ? capacity : MAX_CAPACITY);
}
	
template class BlockingQueue<int>;
template class BlockingQueue<float>;
template class BlockingQueue<double>;
template class BlockingQueue<ADRESS_WHAT>;
