#include<iostream>
#include<windows.h>
using namespace std;
#include"AdjMGraph.h"
void main()
{
	int i=0;
	while(i!=3)
	{
		menu();
		cin>>i;
		switch(i)
		{
		case 1:introduce();break;
		case 2:navigation();break;
		case 3:cout<<"系统已退出！";break;
		}
		Sleep(3000);
	}
}