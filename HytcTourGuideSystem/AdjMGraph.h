#include"MSPath.h"
#include"TPath.h"
class AdjMGraph//�ڽӾ���
{
	char *vex;//���㼯��
	int *edge;//�߼���
	int n;//������Ŀ
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
	int getweight(int i,int j,int n);//��ȡ��<i,j>��Ȩֵ
	void djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[]);

};
int AdjMGraph::getweight(int i,int j,int n)
{
	int k;
	k=i*n+j;
	return(edge[k]);
}
void AdjMGraph::djspath(MSPath s[],TPath temp[],int n,int startvex,int weight[])//������·��
{
	//���������� 
	//MSPath s[]--->�������ĸ���·��
	//TPath temp[]----->ÿһ�������̴�Ŵ��Ƚϳ��ȵĸ���·��
	//int n----->�������
	//int startvex---->��ʼ��
	//int weight[]---->��ż��㵽��ĳһ������ĸ���·���ĳ���
	// 10000�ڱ��㷨�еĺ����������
	int i,j,k,t,min,tempt,localtempt,tempweight,f,m;
	for(i=0;i<n;i++)//��ʼ���·��
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
			if(s[j].flag ==0)//��������û����������ж��㼯�ϣ�������õ�ĸ���·�����ȴ����weight[]��
			{
				for(k=0;k<n;k++)//�������(j)�����нڵ�
				{
					t=k*n+j;//�൱�ڶ�ά����egde[k][j]
					if(edge[t]!=-1 && s[k].flag ==1)//�����·���������ٵ�������Ѿ������ж��㼯��
					{
						tempweight=edge[t]+s[k].pathlength ;//����·������
						weight[k]=tempweight;
					}
				}
				//���weight[]�е���̣����ȴ����temp[j].pathlength������ö���Ķ�����temp[j].sourcevex
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
		min=10000;//���ֵ����·�����ҵ��Ķ�����tempt,��ŵ�s[]��
		for(m=0;m<n;m++)
			if(min>temp[m].pathlength)
			{
				min=temp[m].pathlength;
				tempt=m;//tempt�Ǳ����ҵ�����̵Ķ������
			}
			if (min!=10000)  
			{	
				s[tempt].pathlength=temp[tempt].pathlength;//�����ҵ�һ�����·��
				s[tempt].flag=1;
				f=temp[tempt].sourcevex;//f����tempt·���Ķ���
				//������·���Ŀ���������㵽f��·��������s[tempt]
				for(m=1;m<n;m++)
					if (s[f].path[m]==-1)
						break;
					else
						s[tempt].path[m]=s[f].path[m];
				s[tempt].path[m]=tempt;//���������Լ�
				for(m=0;m<n;m++)
					temp[m].clear();//���temp���Ա���һ��
			}
	}
	//����û�����·���Ķ���
	for(m=0;m<n;m++)
		if(s[m].pathlength==0 && m!=startvex)
			s[m].pathlength;

}
void map(){
	cout<<" \n       ��ʦ��ӪУ��ƽ���ͼ   \n   "<<endl;    
	cout<<"                5.��¥"<<endl;
	cout<<"                  |                  "<<endl;
	cout<<"                  |               "<<endl;
	cout<<"                4.����¥����������������8.����¥"<<endl;
	cout<<"                /     |                     |"<<endl;
	cout<<"               /      |                     |"<<endl;
	cout<<"              /       |                 7.������"<<endl;
	cout<<"      9.�ϱ�Է������3.ͼ���                |"<<endl;
	cout<<"         \\        /    \\                    |"<<endl;
	cout<<"          \\      /      \\            6.����¥"<<endl; 
	cout<<"           \\    /        \\              /"<<endl;
	cout<<"           2.����¥����1.������        /"<<endl;
	cout<<"               \\          /           /"<<endl;
	cout<<"                \\        /           / "<<endl;
	cout<<"                 \\      /������������"<<endl;
	cout<<"                  \\    /"<<endl;
	cout<<"                  0.����"<<endl;
	cout<<endl;
}
void navigation(){
	MSPath s[10]={MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5),MSPath(5)};
	TPath  t[10]={TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1),TPath(10000,-1)};
	char aa[10][20]={"0.����","1.������","2.����¥","3.ͼ���","4.����¥","5.��¥","6.����¥","7.������","8.����¥","9.�ϱ�Է"};
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
	cout<<"����������ǰ��λ�ñ��:";
	cin>>m;
	cout<<"����������ȥ��λ�ñ��:";
	cin>>n;
	mygraph.djspath(s,t,10,m,w);
	s[n].printpath();
}
void introduce(){
	cout<<endl<<"0.���ţ�ѧУ����"<<endl<<endl;
	cout<<"1.�����ã��������ٰ�ĵط�"<<endl<<endl;
	cout<<"2.����¥���������еĽ�ѧ¥"<<endl<<endl;
	cout<<"3.ͼ��ݣ�֪ʶ�ĺ���"<<endl<<endl;
	cout<<"4.����¥�����ƺͻ�Ժ�Ͽεĵط�"<<endl<<endl;
	cout<<"5.��¥������ѧ���������ĵط�"<<endl<<endl;
	cout<<"6.����¥���������ֻ��Ƶĵط�"<<endl<<endl;
	cout<<"7.�����ݣ��������˶���"<<endl<<endl;
	cout<<"8.����¥���Ŀ����Ͽεĵط�"<<endl<<endl;
	cout<<"9.�ϱ�Է��ѧУ����ʳ��"<<endl<<endl;
}
void menu(){
	map();
	cout<<"=============================================================="<<endl;
	cout<<"                 ����ʦ��ѧԺ����ϵͳ"<<endl;
	cout<<"                 1--��ʾУ԰���о�����Ϣ"<<endl;
	cout<<"                 2--����ϵͳ"<<endl;
	cout<<"                 3--�˳�������Ѷƽ̨"<<endl;
	cout<<"=============================================================="<<endl;
}