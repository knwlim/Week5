#pragma once
#pragma once
const int width = 640;   const int height = 480;
float* pixels = new float[width*height * 3];
double xpos, ypos;


void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue, int t)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 3 * t] = red;
	pixels[(i + width* j) * 3 + 6 * t] = red;

	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 1 + 3 * t] = green;
	pixels[(i + width* j) * 3 + 1 + 6 * t] = green;

	pixels[(i + width* j) * 3 + 2] = blue;
	pixels[(i + width* j) * 3 + 2 + 3 * t] = blue;
	pixels[(i + width* j) * 3 + 2 + 6 * t] = blue;

}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue, 0);
	}
}

void drawThickLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue, 1);
	}
}

bool isInsideCircleCor(double xcor, double ycor, double x, const double y)
{
	const double r = 40;
	const double f = (x - xcor)*(x - xcor) + (y - ycor)*(y - ycor) - r * r;
	if (f < 160 && f > -160) return true;
	else return false;
}

bool isInsideCircleBigRed(double xcor, double ycor, double x, const double y)
{
	const double r = 50;
	const double f = (x - xcor)*(x - xcor) + (y - ycor)*(y - ycor) - r * r;
	if (f < 160 && f > -160) return true;
	else return false;
}

bool isInsideCircleCorsmall(double xcor, double ycor, double x, const double y)
{
	const double r = 20;
	const double f = (x - xcor)*(x - xcor) + (y - ycor)*(y - ycor) - r * r;
	if (f < 60 && f > -60) return true;
	else return false;
}

bool isInsideCircleCorarea(double xcor, double ycor, double x, const double y)
{
	const double r = 40;
	const double f = (x - xcor)*(x - xcor) + (y - ycor)*(y - ycor) - r * r;
	if (f < 150) return true;
	else return false;
}

bool isInsideCircleCorarea2(double xcor, double ycor, double x, const double y)
{
	const double r = 80;
	const double f = (x - xcor)*(x - xcor) + (y - ycor)*(y - ycor) - r * r;
	if (f < 150) return true;
	else return false;
}

void drawrebigcircle(double x1, double y1, double xpos, double ypos)
{
	for (int x = 0; x < 640; x++) for (int y = 0; y < 480; y++)
	{
		if (isInsideCircleBigRed(x1, y1, x, y) == true)
		{
			drawPixel(x, y, 1.0f, 0.0f, 0.0f, 0);
		}
	}
}

void drawrebigcircle2(double x1, double y1, double xpos, double ypos)
{
	for (int x = 0; x < 640; x++) for (int y = 0; y < 480; y++)
	{
		if (isInsideCircleCor(x1, y1, x, y) == true)
		{
			if (isInsideCircleCorarea(x1, y1, xpos, 480 - ypos) == true) drawPixel(x, y, 0.0f, 0.0f, 1.0f, 0);
			else drawPixel(x, y, 1.0f, 0.0f, 0.0f, 0);
		}
	}
}

void drawsmallcircle(int x1, int y1)
{
	for (int x = 0; x < 640; x++) for (int y = 0; y < 480; y++)
	{
		if (isInsideCircleCorsmall(x1, y1, x, y) == true)
		{
			drawPixel(x, y, 1.0f, 0.0f, 0.0f, 0);
		}
	}
}

void drawrec(int a, int b, int c, int d)
{

	drawLine(a, d, b, d, 1.0f, 0.0f, 0.0f);
	drawLine(a, c, b, c, 1.0f, 0.0f, 0.0f);
	for (int i = c; i < d; i++)
	{
		drawPixel(a, i, 1.0f, 0.0f, 0.0f, 0);
	}
	for (int i = c; i < d; i++)
	{
		drawPixel(b, i, 1.0f, 0.0f, 0.0f, 0);
	}
}


class go
{
public:

	double cx, cy;
	go() {}


	virtual void draw()
	{
		drawrebigcircle(cx, cy, xpos, ypos);
		drawrebigcircle2(cx, cy, xpos, ypos);
	}

	go(int a, int b) : cx(a), cy(b)
	{}
};


class line : public go
{
public:

	int lx, ly, lx0, ly0;
	line() {}
	void draw()
	{
		drawThickLine(lx, ly, lx0, ly0, 1.0f, 0.0f, 0.0f);
	}
	line(int a, int b, int c, int d)
	{
		lx = a;
		ly = b;
		lx0 = c;
		ly0 = d;

	}
};

class smallcircle : public go
{
public:
	int scx, scy;
	void draw()
	{
		drawsmallcircle(scx, scy);
	}
	smallcircle(int x, int y)
	{
		scx = x;
		scy = y;
	}

};


class rec : public go
{
public:
	int a, b, c, d;
	void draw()
	{
		drawrec(a, b, c, d);
	}
	rec(int a, int b, int c, int d) : a(a), b(b), c(c), d(d)
	{

	}

};

class x : public go
{
public:
	int a, b, c, d;
	void draw()
	{
		drawLine(a, c, b, d, 1.0f, 0.0f, 0.0f);
		drawLine(a, d, b, c, 1.0f, 0.0f, 0.0f);
	}
	x(int a, int b, int c, int d) : a(a), b(b), c(c), d(d)
	{

	}

};



class arrow : public go
{
public:
	int a, b, c, d, e, f;
	void draw()
	{
		for (int i = d; i < f; i++)
		{
			drawPixel(a, i, 1.0f, 0.0f, 0.0f, 0);
		}
		drawLine(b, e, a, d, 1.0f, 0.0f, 0.0f);
		drawLine(a, d, c, e, 1.0f, 0.0f, 0.0f);
	}
	arrow(int a, int b, int c, int d, int e, int f) : a(a), b(b), c(c), d(d), e(e), f(f)
	{}
};





