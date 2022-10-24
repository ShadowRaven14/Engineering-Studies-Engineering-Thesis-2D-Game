#pragma once
class _VirtualMap
{
public:
	void LoadMap(int arr[29][41]);
	void DrawMap();

private:
	SDL_Rect src, dest;
};

