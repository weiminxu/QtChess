#pragma once
#include <QPainter>
#include "QtChess_Board.h"
#define arr_length 32


class QtChess_Pieces
{
public:
	QtChess_Pieces();
	~QtChess_Pieces();

	enum TYPE {JIANG, CHE, MA, PAO, BING, SHI, XIANG};

	int _row;
	int _col;
	int _id;
	int _dead;
	int _red;
	TYPE _type;

	void init(int id)
	{
		_id = id;
		_dead = false;
		_red = id < 16;

		struct position
		{
			int row, col;
			QtChess_Pieces::TYPE type;
		} position[16] =
		{
			{0,0,CHE},
			{0,1,MA},
			{0,2,XIANG},
			{0,3,SHI},
			{0,4,JIANG},
			{0,5,SHI},
			{0,6,MA},
			{0,7,XIANG},
			{0,8,CHE},

			{2,1,PAO},
			{2,7,PAO},
			{3,0,BING},
			{3,2,BING},
			{3,4,BING},
			{3,6,BING},
			{3,8,BING},
		};

		/*struct Position
		{
			int row, col;
			QtChess_Pieces::TYPE type;
		};
		struct Position position[] =
		{
			{0,0,QtChess_Pieces::CHE},
			{0,1,QtChess_Pieces::MA},
			{0,2,QtChess_Pieces::XIANG},
			{0,3,QtChess_Pieces::SHI},
			{0,4,QtChess_Pieces::JIANG},
			{0,5,QtChess_Pieces::SHI},
			{0,6,QtChess_Pieces::MA},
			{0,7,QtChess_Pieces::XIANG},
			{0,8,QtChess_Pieces::CHE},

			{2,1,QtChess_Pieces::PAO},
			{2,7,QtChess_Pieces::PAO},
			{3,0,QtChess_Pieces::BING},
			{3,2,QtChess_Pieces::BING},
			{3,4,QtChess_Pieces::BING},
			{3,6,QtChess_Pieces::BING},
			{3,8,QtChess_Pieces::BING},
		};*/

		
		if (id < 16) 
		{
			_row = position[id].row;
			_col = position[id].col;
			_type = position[id].type;
		}
		else
		{
			_row = 9 - position[id - 16].row;
			_col = 8 - position[id - 16].col;
			_type = position[id - 16].type;
		}
	}

	QString getText()
	{
		switch (this->_type)
		{
		case CHE:
			return "CHE";
		case MA:
			return "MA";
		case PAO:
			return "PAO";
		case BING:
			return "BING";
		case JIANG:
			return "JIANG";
		case SHI:
			return "SHI";
		case XIANG:
			return "XIANG";
		}
		return "ERROR";
	}	
};

