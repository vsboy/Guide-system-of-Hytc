//用来存放找到的路径及长度
class AdjMGraph;
class MSPath
{
	friend  class AdjMGraph;
	int *path;//存放最短路径的信息；如2 3 1 0 -1表示顶点2到顶点0的路径；-1表示改点不存在
	int pathlength;//路径长度
	int n;//顶点的数目
	int flag;//标示该序号的顶点是否是已经找到的最短路径的顶点
	public:
	MSPath(int ncount)
	{
		path=new int[ncount];
		for(int i=0;i<ncount;i++)
			path[i]=-1;
		pathlength=0;
		n=ncount;
		flag=0;
	}
	void printpath()//输出路径
	{
		char aa[10][20]={"0.正门","1.大礼堂","2.崇文楼","3.图书馆","4.生化楼","5.理工楼","6.音乐楼","7.体育馆","8.弘文楼","9.南北苑"};
		cout<<"最短路线为:";
		for(int i=0;i<n;i++)
		{
			if(path[i]==-1)
				break;
			else
			{
				cout<<"-->"<<aa[path[i]];
			}
		}
		cout<<endl;
		cout<<"路程总长:";
		cout<<pathlength<<"米"<<endl;
	}
	int getpathlength()//取路径长度
	{
		return pathlength;
	}
	int getflag()//判断是否是查找过的点
	{
		return flag;
	}
};
	