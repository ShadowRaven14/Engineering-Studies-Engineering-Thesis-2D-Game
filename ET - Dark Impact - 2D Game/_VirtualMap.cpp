#include "_VirtualMap.h"

void _VirtualMap::LoadMap(int arr[29][41])
{
	for (int row = 0; row < 29; row++)
	{
		for (int column = 0; column < 41; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}

void _VirtualMap::DrawMap(int arr[29][41])
{

}

void _VirtualMap::InitializeTextures()
{

}
