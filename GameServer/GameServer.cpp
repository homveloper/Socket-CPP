#include "pch.h"
#include "CorePch.h"
#include <mutex>

std::vector<int32> Vector;
std::mutex VectorLock;

void Push()
{
	VectorLock.lock();
	for (int32 i = 0; i < 10'000; i++) {
		Vector.push_back(i);
	}
	VectorLock.unlock();
}

int main()
{
	std::thread t1(Push);
	std::thread t2(Push);

	t1.join();
	t2.join();

	std::cout<< Vector.size() << std::endl;
}