/*************************************************************************
    > File Name: derive.cpp
    > Author: zguiq
    > Created Time: 2016年11月15日 星期二 15时49分33秒
************************************************************************/

#include<iostream>
#include<string>

using namespace std;

class Base
{
	private:
		int width;
		int height;
	protected:
		string name;
	public:
		Base(string name);
		void setWidth(int width);
		void setHeight(int height);
		void showSize();
		void showName();
		virtual ~Base();
};
Base::Base(string name)
{
	this->name = name;
	cout<<"Base constructor"<<endl;
}
void Base::setWidth(int width)
{
	this->width = width;
}
void Base::setHeight(int height)
{
	this->height = height;
}
Base::~Base()
{
	cout<<"Base deconstructor"<<endl;
}
void Base::showSize()
{
	cout<<"Component "<<this->name<<" Width:"<<this->width<<" Height:"<<this->height<<endl;
}
void Base::showName()
{
	cout<<"Componet is:"<<this->name<<endl;
}

class Window:public Base
{
	private:
		string icon;
	public:
		Window(string name);
		void setIcon(string iconname);
		void showIcon();
		~Window();
};
Window::Window(string name):Base(name)
{
	cout<<"Window constructor"<<endl;
}
void Window::setIcon(string name)
{
	this->icon = name;
}
void Window::showIcon()
{
	cout<<"Icon is:"<<this->icon<<endl;
}
Window::~Window()
{
	cout<<"Window deconstructor"<<endl;
}
class ScrollBar:public Base
{
	private:
		string orientation;
	public:
		ScrollBar(string name):Base(name)
	{
		cout<<"ScrollBar constructor"<<endl;
	}
		void setorientation(string orien)
		{
			this->orientation = orien;
		}
		void showOrientation()
		{
			cout<<"Orientation is "<<this->orientation<<endl;
		}
		~ScrollBar()
		{
			cout<<"ScrollBar destructor"<<endl;
		}

};

class ScrollWindow:public Window, public ScrollBar
{
	private:
		string name;
	public:
		ScrollWindow(string windowname, string scrollname):Window(windowname), ScrollBar(scrollname)
	{
		this->name = windowname;
		cout<<"ScrollWindow constructor"<<endl;
	}
		void setWidth(int width, int scrollbarwidth);
		void setHeight(int height, int scrollbarheight);
		void showSize();
		void showName();
		~ScrollWindow()
		{
			cout<<"ScrollWindow destructor"<<endl;
		}
};
void ScrollWindow::showName()
{
	cout<<"Component Name is:"<<this->name<<endl;
}
void ScrollWindow::setWidth(int width, int barwidth)
{
	Window::setWidth(width);
	ScrollBar::setWidth(barwidth);
}
void ScrollWindow::setHeight(int height1, int height2)
{
	Window::setHeight(height1);
	ScrollBar::setHeight(height2);
}
void ScrollWindow::showSize()
{
	Window::showSize();
}

int main()
{
	{
		ScrollWindow scrollwindow("Form1","ScrollBar1");
		scrollwindow.setHeight(100,200);
		scrollwindow.setWidth(300,400);
		scrollwindow.setIcon("kawayi");
		scrollwindow.setorientation("Vertical");
		scrollwindow.showName();
		scrollwindow.showSize();
		scrollwindow.showIcon();
		scrollwindow.showOrientation();

	}
}
