#include"MSPath.h"
#include"TPath.h"
class AdjMGraph//邻接矩阵
{
	char *vex;//顶点集合
	int *edge;//边集合
	int n;//顶点数目
public:
	AdjMGraph(int a[],char b[][20],int n)
	{
		n=n;
		int m;
		m=n*n;
		vex=new char[n];
		for(int i=0;i<n;i++)
			vex[i]=b[i][20];
		edge=new int[m];
		for(int i=0;i<m;i++)
			edge[i]=a[i];
	}
	int getweight(int i,int j,int n);//获取弧<i,j>的权值
	void djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[]);

};
int AdjMGraph::getweight(int i,int j,int n)
{
	int k;
	k=i*n+j;
	return(edge[k]);
}
void AdjMGraph::djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[])//求解最短路径
{
	//参数的意义 
	//MSPath s[]--->存放求出的各条路径
	//TPath temp[]----->每一轮求解过程存放待比较长度的各条路径
	//int n----->顶点个数
	//int startvex---->起始点
	//int weight[]---->存放计算到达某一个顶点的各条路径的长度
	// 10000在本算法中的含义是无穷大
	int i,j,k,t,min,tempt,localtempt,tempweight,f,m;
	for(i=0;i<n;i++)//起始点的路径
	{
		s[i].path[0]=startvex;
	}
	s[startvex].flag=1;
	for(i=1;i<n;i++)
	{
		j=0;
		while(j<n)
		{ 
			if(j!=startvex)
			{for(m=0;m<n;m++)
			weight[m]=10000;
			if(s[j].flag ==0)//如果这个点没有添加在已有顶点集合，求出到该点的各条路径长度存放在weight[]中
			{
				for(k=0;k<n;k++)//到达该列(j)的所有节点
				{
					t=k*n+j;//相当于二维数组egde[k][j]
					if(edge[t]!=-1 && s[k].flag ==1)//如果有路且与它相临的这个点已经在已有顶点集合
					{
						tempweight=edge[t]+s[k].pathlength ;//计算路径长度
						weight[k]=tempweight;
					}
				}
				//求解weight[]中的最短；长度存放在temp[j].pathlength；到达该顶点的顶点是temp[j].sourcevex
				min=weight[0];
				localtempt=0;
				for(m=1;m<n;m++)
					if(min>weight[m])
					{
						min=weight[m];
						localtempt=m;
					}
					temp[j].pathlength=min;
					if(temp[j].pathlength==10000)
						temp[j].sourcevex=-1;
					else
						temp[j].sourcevex=localtempt;
					localtempt=-1;
			}
			}
			j++;
		}
		min=10000;//求本轮的最短路径，找到的顶点是tempt,存放到s[]中
		for(m=0;m<n;m++)
			if(min>temp[m].pathlength)
			{
				min=temp[m].pathlength;
				tempt=m;//tempt是本轮找到的最短的顶点序号
			}
			if (min!=10000)  
			{	
				s[tempt].pathlength=temp[tempt].pathlength;//该轮找到一条最短路径
				s[tempt].flag=1;
				f=temp[tempt].sourcevex;//f到达tempt路径的顶点
				//下面是路径的拷贝；把起点到f的路径拷贝到s[tempt]
				for(m=1;m<n;m++)
					if (s[f].path[m]==-1)
						break;
					else
						s[tempt].path[m]=s[f].path[m];
				s[tempt].path[m]=tempt;//拷贝顶点自己
				for(m=0;m<n;m++)
					temp[m].clear();//清空temp；以备下一轮
			}
	}
	//查找没有最短路径的顶点
	for(m=0;m<n;m++)
		if(s[m].pathlength==0 && m!=startvex)
			s[m].pathlength;

}
void map(){
	cout<<" \n       淮师王营校区平面简图   \n   "<<endl;    
	cout<<"                5.理工楼"<<endl;
	cout<<"                  |                  "<<endl;
	cout<<"                  |               "<<endl;
	cout<<"                4.生化楼————————8.弘文楼"<<endl;
	cout<<"                /     |                     |"<<endl;
	cout<<"               /      |                     |"<<endl;
	cout<<"              /       |                 7.体育馆"<<endl;
	cout<<"      9.南北苑———3.图书馆                |"<<endl;
	cout<<"         \\        /    \\                    |"<<endl;
	cout<<"          \\      /      \\            6.音乐楼"<<endl; 
	cout<<"           \\    /        \\              /"<<endl;
	cout<<"           2.崇文楼——1.大礼堂        /"<<endl;
	cout<<"               \\          /           /"<<endl;
	cout<<"                \\        /           / "<<endl;
	cout<<"                 \\      /——————"<<endl;
	cout<<"                  \\    /"<<endl;
	cout<<"                  0.正门"<<endl;
	cout<<endl;
}
void navigation(){
	MSPath s[10]={MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5)};
	TPath  t[10]={TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1)};
	char aa[10][20]={"0.正门","1.大礼堂","2.崇文楼","3.图书馆","4.生化楼","5.理工楼","6.音乐楼","7.体育馆","8.弘文楼","9.南北苑"};
	int  weight[100]={10000,300,280,10000,10000,10000,450,10000,10000,10000,
		300,10000,100,120,10000,10000,10000,10000,10000,10000,
		280,100,10000,150,10000,10000,10000,10000,10000,420,
		10000,120,150,10000,110,10000,10000,10000,10000,400,
		10000,10000,10000,110,10000,500,10000,10000,550,450,
		10000,10000,10000,10000,500,10000,10000,10000,10000,10000,
		450,10000,10000,10000,10000,10000,10000,200,10000,10000,
		10000,10000,10000,10000,10000,10000,200,10000,180,10000,
		10000,10000,10000,10000,550,10000,10000,180,10000,10000,
		10000,10000,420,400,450,10000,10000,10000,10000,10000};
	int w[10]={10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
	AdjMGraph mygraph(weight,aa,10);
	int m,n;
	cout<<"请输入您当前的位置编号:";
	cin>>m;
	cout<<"请输入您想去的位置编号:";
	cin>>n;
	mygraph.djspath(s,t,10,m,w);
	s[n].printpath();
}
void introduce(){
	cout<<endl<<"0.正门：学校大门"<<endl<<endl;
	cout<<"1.大礼堂：大型晚会举办的地方"<<endl<<endl;
	cout<<"2.崇文楼：有艺术感的教学楼"<<endl<<endl;
	cout<<"3.图书馆：知识的海洋"<<endl<<endl;
	cout<<"4.生化楼：生科和化院上课的地方"<<endl<<endl;
	cout<<"5.理工楼：理工科学生经常待的地方"<<endl<<endl;
	cout<<"6.音乐楼：动听音乐环绕的地方"<<endl<<endl;
	cout<<"7.体育馆：有室内运动场"<<endl<<endl;
	cout<<"8.弘文楼：文科生上课的地方"<<endl<<endl;
	cout<<"9.南北苑：学校最大的食堂"<<endl<<endl;
}
void menu(){
	map();
	cout<<"=============================================================="<<endl;
	cout<<"                 淮阴师范学院导游系统"<<endl;
	cout<<"                 1--显示校园所有景点信息"<<endl;
	cout<<"                 2--导航系统"<<endl;
	cout<<"                 3--退出导游资讯平台"<<endl;
	cout<<"=============================================================="<<endl;
}