#include "MainWindow.h"

int main()
{
	e3::WindowCreateInfo info;
	info.Name = "RidersReels";
	info.Size.Width = 960;
	info.Size.Height = 640;
	info.Resoluction.Width = 960;
	info.Resoluction.Height = 640;

	MainWindow manWindow(&info);
	manWindow.Show();

	return 0;
}
