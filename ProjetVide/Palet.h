#pragma once

#ifndef __PALET__
#define __PALET__

class Palet
{
private:
	int x, y;
	int xOld, yOld;

public:
	Palet(const int &x, const int &y);
	~Palet(void);

	int getX() const
	{
		return x;
	}

	int getY() const
	{
		return y;
	}

	void setX(const int &x)
	{
		this->xOld = this->x;
		this->x = x;
	}

	void setY(const int &y)
	{
		this->yOld = this->y;
		this->y = y;
	}
};

#endif