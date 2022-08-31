#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>

export module Anagram;

export namespace Anagram
{
	bool isAnagram(std::string s, std::string t)
	{
		if (s.length() != t.length()) return false;

		std::sort(s.begin(), s.end());
		std::sort(t.begin(), t.end());

		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] != t[i])
				return false;
		}

		return true;
	}

	consteval bool isAnagramArray(std::string const &s, std::string const &t)
	{
		if (s.length() != t.length()) return false;

		constexpr int alphabetSize = 26;
		int arr[alphabetSize] = {};

		for (int i = 0; i < s.size(); ++i)
		{
			++arr[s[i] - 'a'];
			--arr[t[i] - 'a'];
		}

		for (int i = 0; i < alphabetSize; ++i)
		{
			if (arr[i])
				return false;
		}

		return true;
	}

	bool isAnagramArrayVar(std::string const& s, std::string const& t)
	{
		if (s.length() != t.length()) return false;

		constexpr int alphabetSize = 26;
		int arr[alphabetSize] = {};

		auto size = s.size();
		for (int i = 0; i < size; ++i)
		{
			++arr[s[i] - 'a'];
			--arr[t[i] - 'a'];
		}

		for (int i = 0; i < alphabetSize; ++i)
		{
			if (arr[i])
				return false;
		}

		return true;
	}	

	void testDef()
	{
		auto start = std::chrono::high_resolution_clock::now();
		assert(isAnagramArray("anagram", "nagaram") == true);
		assert(isAnagramArray("rat", "car") == false);
		assert(isAnagramArray("a", "b") == false);
		assert(isAnagramArray("aa", "bb") == false);
		assert(isAnagramArray("a", "ab") == false);
		auto end = std::chrono::high_resolution_clock::now();

		double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Def: " << time_taken << "\n";
	}

	void testVar()
	{
		auto start = std::chrono::high_resolution_clock::now();
		assert(isAnagramArrayVar("anagram", "nagaram") == true);
		assert(isAnagramArrayVar("rat", "car") == false);
		assert(isAnagramArrayVar("a", "b") == false);
		assert(isAnagramArrayVar("aa", "bb") == false);
		assert(isAnagramArrayVar("a", "ab") == false);
		auto end = std::chrono::high_resolution_clock::now();

		double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
		std::cout << "Var: " << time_taken << "\n";
	}

	void test()
	{
		for (int i = 0; i < 10; ++i)
		{
			testDef();
			testVar();
		}
	}
}