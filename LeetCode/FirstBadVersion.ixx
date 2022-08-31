#include <iostream>

export module FirstBadVersion;

export
namespace FirstBadVersion
{
	bool isBadVersion(int version)
	{
		return version >= 1;
	}

	int firstBadVersion(int right)
	{
		long left = 1;
		while (left <= right)
		{
			const long mid = (left + right) >> 1;
			if (isBadVersion(mid))
				right = mid - 1;
			else
				left = mid + 1;
		}

		return left;
	}

	void test()
	{
		std::cout << firstBadVersion(5) << "\n";
		std::cout << firstBadVersion(11) << "\n";
	}
}