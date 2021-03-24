#pragma once
#include <random>

class rng
{
public:
	static int rdm_int(int min, int max)
	{
		auto rdm = std::mt19937(std::random_device()());
		return std::uniform_int_distribution<int>(min, max)(rdm);
	}
	static float rdm_float(float min, float max)
	{
		auto rdm = std::mt19937(std::random_device()());
		return std::uniform_real_distribution<float>(min, max)(rdm);
	}
	static bool rdm_bool(float true_chance)
	{
		return rdm_float(0.0f, 100.0f) <= true_chance;
	}
};