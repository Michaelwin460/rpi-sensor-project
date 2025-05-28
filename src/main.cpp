#include "../include/sensor.h"
#include <spdlog/spdlog.h>
#include <thread>
#include <chrono>

int main()
{
	Sensor s;
	spdlog::info("Starting sensor monitoring...");
	for (int i = 0; i < 10; ++i)
	{
		double val = s.read();
		spdlog::info("Sensor reading {}", val);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	spdlog::info("finish monitoring");
	
	return 0;
}