#pragma once
class PointInMap
{
public:
	PointInMap();

	int xpos; //pozycja na mapie wzglêdem osi x
	int ypos; //pozycja na mapie wzglêdem osi y
	char input; //obecny klawisz
	char previnput;	//wczeœniejszy klawisz
};

