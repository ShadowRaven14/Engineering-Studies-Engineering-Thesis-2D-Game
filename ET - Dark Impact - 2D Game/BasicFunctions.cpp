#include "Utils.h"

static void Utils::Copy2DTable(int matrix1, int matrix2, int sizeY, int sizeX)
{
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
            matrix2[y][x] = matrix1[y][x];
    }
}