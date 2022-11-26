#include "_VirtualMap.h"

void _VirtualMap::LoadMapFromVariable(int arr[29][41])
{
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void _VirtualMap::LoadStartingMapFromTxt(std::string mapname)
{
	int x, y; int pixel;
	std::ifstream read(mapname);
	read >> x >> y;
	std::cout << x << " " << y << std::endl;

	for (int row = 0; row < x; row++)
	{
		for (int column = 0; column < y; column++)
		{
			read >> pixel;
			map[row][column] = pixel;
			std::cout << pixel << " ";
		}
		std::cout << std::endl;
	}
	read.close();
}

void _VirtualMap::ExportMapToTxt(std::string name)
{
	std::ofstream write(name);
	write << 29 << " " << 41 << std::endl;

	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			write << map[row][column] << " ";
		}
		write << std::endl;
	}
	write.close();
}
