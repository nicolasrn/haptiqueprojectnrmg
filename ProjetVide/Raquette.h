#pragma once

#ifndef __RAQUETTE__
#define __RAQUETTE__

class Raquette
{
private:
	int x, y;

public:
	Raquette(const int &x, const int &y);
	~Raquette(void);

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
		this->x = x;
	}

	void setY(const int &y)
	{
		this->y = y;
	}
};

#endif