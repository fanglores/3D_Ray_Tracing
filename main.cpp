#include "2d_library.h"
#include <math.h>
#include <Windows.h>
#include <string>
#include <iostream>

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(handle, coord);
	SetConsoleWindowInfo(handle, TRUE, &Rect);
}

int FPS = 60;
//" .:-=+*#%@"
//"@%#*+=-:. "
std::string gradient = "@#*+=-:.";
int gradient_len = gradient.size() - 1;

int main()
{
	// console sizes
	int width = 120;
	int height = 30;

	// precalculated aspects ratios
	float aspect = (float)width / height;
	float pixelAspect = 11.0f / 24.0f;

	// console buffer
	char* screen_buf = new char[width * height + 1];
	screen_buf[width * height] = '\0';

	// max distance between objects is (-1.0f; -1.0f) (1.0f; 1.0f)
	float MAX_DIST = sqrt(4.0f * (aspect * aspect * pixelAspect * pixelAspect + 1));

	// predefine variables used further
	Vec2 circle = Vec2(-0.5f * aspect * pixelAspect, 0.0f);
	char pixel, color;
	int dist;

	// source of light preinitialisation
	Vec2 light = Vec2(0.0f * aspect * pixelAspect, -1.0f);

	// simulation in time (t)
	float x, y;
	time_t start_time, end_time;
	for (int t = 0; t < 100000; t++)
	{
		start_time = clock();
		// movement simulation
		circle.x += 0.05 * sin(0.05 * t);
		circle.y += 0.025 * cos(0.05 * t + 0.5);

		// update console matrix
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				// center coordinates
				x = (float)i / width * 2.0f - 1.0f;
				y = (float)j / height * 2.0f - 1.0f;

				// scale coordinates
				x *= aspect * pixelAspect;

				// source of light is in the left up corner
				dist = (int)(gradient_len * distance(Vec2(x, y), light) / MAX_DIST);
				color = gradient[dist];

				// calculate new buffer
				pixel = ' ';

				if (distance(Vec2(x, y), light) < 0.05) pixel = gradient[0];
				else
				if (distance(Vec2(x,y), circle) < 0.5) pixel = color;
				
				screen_buf[i + j * width] = pixel;
			}
			
		}

		printf(screen_buf);
		end_time = clock();

		if (end_time - start_time < CLOCKS_PER_SEC / FPS) Sleep(1000 / FPS - 1000 * (end_time - start_time) / CLOCKS_PER_SEC);
		else printf("\nWarning! Low FPS!\n");

		//frame by frame debug
		//getchar();
	}

	delete[] screen_buf;

	return 0;
}