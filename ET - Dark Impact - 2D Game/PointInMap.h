#pragma once
class PointInMap
{
public:
	PointInMap();

	int xpos; //pozycja na mapie względem osi x
	int ypos; //pozycja na mapie względem osi y
	char input; //obecny klawisz
	char previnput;	//wcześniejszy klawisz
};

