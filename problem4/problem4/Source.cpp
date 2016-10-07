#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  
#include <algorithm>
#include <math.h>
#include <vector>
#include "Class.h"

int main(void)
{
	GLFWwindow* window;
	if (!glfwInit())return -1; window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window) { glfwTerminate(); return -1; }
	glfwMakeContextCurrent(window);
	std::fill_n(pixels, width*height * 3, 1.0f);

	go ** my_ob = new go*[40];

	for (int i = 0; i < 20; i++) my_ob[i] = new go((60 + (i * 130)) % 650, 420 - (i / 5) * 115);
	for (int i = 0; i < 4; i++) my_ob[20 + i] = new line(40, 400 - (i * 115), 70, 440 - (i * 115));
	for (int i = 0; i < 4; i++) my_ob[24 + i] = new smallcircle(190, 420 - (i * 115));
	for (int i = 0; i < 4; i++) my_ob[28 + i] = new rec(300, 340, 400 - (i * 115), 440 - (i * 115));
	for (int i = 0; i < 4; i++) my_ob[32 + i] = new x(430, 470, 400 - (i * 115), 440 - (i * 115));
	for (int i = 0; i < 4; i++) my_ob[36 + i] = new arrow(580, 560, 600, 400 - (i * 115), 430 - (i * 115), 450 - (i * 115));

	while (!glfwWindowShouldClose(window))
	{
		glfwGetCursorPos(window, &xpos, &ypos);

		for (int i = 0; i < 40; i++)
		{
			my_ob[i]->draw();
		} // one for loop

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	delete[] pixels;
	delete[] my_ob;
	return 0;
}
