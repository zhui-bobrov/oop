#include "stdafx.h"
#include "CHttpUrl.h"

int main()
{
	std::string url;

	while (std::getline(std::cin, url))
	{
		try
		{
			CHttpUrl httpUrl(url);
			httpUrl.PrintUrl();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}