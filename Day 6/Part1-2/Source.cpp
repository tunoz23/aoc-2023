
#include <chrono>
#include <iostream>
struct Timer
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> duration;
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		duration *= 1000.f;
		std::cout << "it took -> " << duration.count() << "ms\n";
	}
};


uint64_t foo(uint64_t time, uint64_t distance)
{
	uint64_t counter = 0;
	bool isItEven = time % 2 == 0;
	//Timer timer = Timer();
	
	uint64_t middle = time / 2;
	uint64_t currentNum = middle;
	while (currentNum * (time - currentNum) > distance)
	{
		currentNum--;
		counter++;
	}
	counter = isItEven ? counter * 2 - 1: counter * 2;
	
	return counter;
	
}
int main()
{
	{
		Timer timer = Timer();
		uint64_t result = 1;
		uint64_t times[4] = { 63,78,94,68 };
		uint64_t distances[4] = { 411,1274,2047,1035 };
		//First part of the puzzle:
		for (int i = 0; i < 4; i++)
		{
			result *= foo(times[i], distances[i]);
		}
		//Second part of the puzzle:

		std::cout << foo(63789468, 411127420471035);

	}
	std::cin.get();
}
