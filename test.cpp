                                //  学生管理系统
#include <stdio.h>
#include<string.h>
struct student
{
	long xuehao;
	char name[20];
	int subject[6];
};
int main()
{
	FILE *fp;
	int n,len,peo,sub,i,j,flag=0,ret,sum[30];
	double ave[30];
	do
	{
		system("color 7");
		printf("            学生信息管理系统 6.0        \n");
		printf("(1)  录入或者删除每个学生的学号,姓名和各科考试成绩;\n");
		printf("(2)  计算每门课程的总分和平均分;\n");
		printf("(3)  计算每个学生的总分和平均分;\n");
		printf("(4)  按每个学生的总分由高到低排出名次;\n");
		printf("(5)  按每个学生的总分从低到高排出名次;\n");
		printf("(6)  按学号由小到大排出成绩表;\n");
		printf("(7)  按姓名的字典顺序排出成绩表;(目前仅支持英文姓名)\n");
		printf("(8)  按学号查询学生排名及其考试成绩;\n");
		printf("(9)  按姓名查询学生排名及其考试成绩;\n");
		printf("(10) 按优秀，良好，中等，及格，不及格5个类别，对每门课程分别统计每个类别的人数及其所占的百分比;\n");
		printf("(11) 输出每个学生的学号，姓名，各科考试成绩，及其每门成绩的总分和平均分;\n");
		printf("(12) 从文件中读出每个学生的记录信息并显示;\n");
		printf("(0)  退出;\n");
		fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","a+");
		struct student one[30];
		fseek(fp,0L,SEEK_END);
		len=ftell(fp);
		if(len!=0)
		{
			fseek(fp,0L,SEEK_SET);
			fscanf(fp,"%d",&peo);
			fscanf(fp,"%d",&sub);
			for(i=0; i<peo; i++)
			{
				fscanf(fp,"%ld",&one[i].xuehao);
				fscanf(fp,"%s",one[i].name);
				for(j=0; j<sub; j++)
					fscanf(fp,"%d",&one[i].subject[j]);
			}
			printf("欢迎回来继续使用学生管理系统。\n");
			printf("您上次设定的是管理%d个学生，%d个学科成绩的管理系统。\n",peo,sub);
			printf("请选择你所需要功能前面对应的编号。");
		}
		int begin=0;
		printf("请输入相应功能对应的编号：");
		if(len==0&&flag==0)
		{
			printf("\n这是你第一次启动系统,所以请初始化数据,我们默认帮你选择功能(1),按任意数字键继续.(按0退出)");
		}
		do
		{
			for(j=0; j<peo; j++)
			{
				sum[j]=0;
				ave[j]=0;
				for(i=0; i<sub; i++)
					sum[j]=one[j].subject[i]+sum[j];
				ave[j]=1.0*sum[j]/sub;
			}
			if(begin==1)
			{
				printf("请检查你输入是否正确，重新输入相应功能的编号：");
				getchar();
			}
			ret=scanf("%d",&n);
			begin=1;
		}
		while(ret==0);
		if(len==0&&flag==0&&n!=0)n=1;
		begin=0;
		system("cls");
		system("color C");
		printf("运行结果如下：\n");
		switch(n)
		{
			case 0:
			{
				exit(0);
				break;
			}
			case 1:
			{
				fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","a+");
				if(fp==NULL)
				{
					printf("Open wrong");
					exit(0);
				}
				else
				{
					fseek(fp,0L,SEEK_END);
					len=ftell(fp);
					if(flag!=0)
						len++;
					if(len==0)
					{
						printf("欢迎第一次使用学生信息管理系统。\n请输入班级的人数：（最多30人）");
						do
						{
							if(begin==1)
							{
								printf("请检查你输入是否正确，重新输入正确的人数：");
								getchar();
							}
							ret=scanf("%d",&peo);
							begin=1;
						}
						while(ret==0||peo>30||peo<0);
						begin=0;
						fprintf(fp,"%d\n",peo);
						printf("请输入考试的科目：");
						do
						{
							if(begin==1)
							{
								getchar();
								printf("请检查你输入是否正确，重新输入正确的科目数：");
							}
							ret=scanf("%d",&sub);
							begin=1;
						}
						while(ret==0);
						begin=0;
						fprintf(fp,"%d\n",sub);
						printf("这是一个管理%d个人，%d个科目的管理系统。\n",peo,sub);
						for(i=0; i<peo; i++)
						{
							printf("录入第%d个人的学号：",i+1);
							scanf("%ld",&one[i].xuehao);
							fprintf(fp,"%ld ",one[i].xuehao);
							printf("录入第%d个人的名字：",i+1);
							scanf("%s",one[i].name);
							fprintf(fp,"%s ",one[i].name);
							for(j=0; j<sub; j++)
							{
								printf("录入第%d个人的第%d个成绩:",i+1,j+1);
								do
								{
									if(begin==1)
									{
										getchar();
										printf("请检查你输入是否正确，重新输入相应的分数：");
									}
									ret=scanf("%d",&one[i].subject[j]);
									begin=1;
								}
								while(ret==0);
								begin=0;
								fprintf(fp,"%d ",one[i].subject[j]);
							}
							fprintf(fp,"\n");
							flag=1;
						}
					}
					if(len!=0)
					{
						char c,d;
						printf("你是否想要删除所有数据。（Y表示是，其他为否，0表示退出)");
						getchar();
						c=getchar();
						getchar();
						if(c=='Y'||c=='y')
						{
							printf("请确认你的操作，继续将删除所有已经存储的数据，并且不能够恢复（Y表示是，其他为否，0表示退出）");
							d=getchar();
							if(d=='Y'||d=='y')
							{
								fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","w");
							}
						}
					}
				}
				break;
			}
			case 2:
			{
				int jisuan[30];
				float pinjun[30];
				for(i=0; i<sub; i++)
				{
					jisuan[i]=0;
					for(j=0; j<peo; j++)
						jisuan[i]=one[j].subject[i]+jisuan[i];
					pinjun[i]=1.0*jisuan[i]/sub;
					printf("第%d门的成绩的总分是%d。",i+1,jisuan[i]);
					printf("第%d门的成绩的平均分是%.2f。\n",i+1,pinjun[i]);
				}
				break;
			}
			case 3:
			{
				for(j=0; j<peo; j++)
				{
					printf("学号为%ld,%s的成绩的总分是:%d\n",one[j].xuehao,one[j].name,sum[j]);
					printf("学号为%ld,%s的成绩的平均分是:%.2lf\n",one[j].xuehao,one[j].name,ave[j]);
				}
				break;
			}
			case 4:
			{
				int max,maxpos;
				for(j=0; j<peo; j++)
				{
					max=sum[0];
					maxpos=0;
					for(i=0; i<peo; i++)
					{
						if(sum[i]>max)
						{
							max=sum[i];
							maxpos=i;
						}
					}
					printf("第%d名是学号为%ld,的%s 总分是%d\n",j+1,one[maxpos].xuehao,one[maxpos].name,max);
					sum[maxpos]=-1;
				}
				break;
			}
			case 5:
			{
				int min,minpos;
				for(j=0; j<peo; j++)
				{
					min=sum[0];
					minpos=0;
					for(i=0; i<peo; i++)
					{
						if(sum[i]<min)
						{
							min=sum[i];
							minpos=i;
						}
					}
					printf("倒数第%d名是学号为%ld的%s 总分是%d\n",j+1,one[minpos].xuehao,one[minpos].name,min);
					sum[minpos]=999;
				}
				break;
			}
			case 6:
			{
				long temp;
				for(j=0; j<peo-1; j++)
				{
					for(i=0; i<peo-j-1; i++)
					{
						if(one[i].xuehao>one[i+1].xuehao)
						{
							temp=sum[i];
							sum[i]=sum[i+1];
							sum[i+1]=temp;
							temp=one[i].xuehao;
							one[i].xuehao=one[i+1].xuehao;
							one[i+1].xuehao=temp;
						}
					}
				}
				for(j=0; j<peo; j++)
					printf("学号为%ld的是%s，他的成绩是%d\n",one[j].xuehao,one[j].name,sum[j]);
				break;
			}
			case 7:
			{
				char zifu[20];
				int swap;
				for(j=0; j<peo; j++)
				{
					sum[j]=0;
					for(i=0; i<sub; i++)
					{
						sum[j]=one[j].subject[i]+sum[j];
					}
				}
				for(i=0; i<peo-1; i++)
				{
					for(j=0; j<peo-1-i; j++)
					{
						if(strcmp(one[j].name,one[j+1].name)>0)
						{
							strcpy(zifu,one[j].name);
							strcpy(one[j].name,one[j+1].name);
							strcpy(one[j+1].name,zifu);
							swap=sum[j];
							sum[j]=sum[j+1];
							sum[j+1]=swap;
						}
					}
				}
				for(i=0; i<peo; i++)
					printf("姓名为%s的成绩是%d。\n",one[i].name,sum[i]);
				break;
			}
			case 8:
			{
				long x,live=0,paiming=peo+1;
				printf("请输入你需要查找的学号：");
				scanf("%ld",&x);
				for(i=0; i<peo; i++)
				{
					if(x==one[i].xuehao)
					{
						for(j=0; j<peo; j++)
						{
							if(sum[i]>=sum[j])
								paiming--;
						}
						printf("学号为%ld的姓名是%s,排名为%ld,成绩为%d\n",x,one[i].name,paiming,sum[i]);
						live=1;
					}
				}
				if(live==0)
					printf("不存在学号为%ld的学生，请核实您的输入。\n",x);
				break;
			}
			case 9:
			{
				char asd[20];
				int live=0,paiming=peo+1,panduan;
				printf("请输入你需要查找的姓名：");
				scanf("%s",asd);
				for(i=0; i<peo; i++)
				{
					panduan=strcmp(asd,one[i].name);
					if(panduan==0)
					{
						for(j=0; j<peo; j++)
						{
							if(sum[i]>=sum[j])
								paiming--;
						}
						printf("学号为%ld的姓名是%s,排名为%d,成绩为%d\n",one[i].xuehao,one[i].name,paiming,sum[i]);
						live=1;
					}
				}
				if(live==0)
					printf("不存在姓名为%s的学生，请核实您的输入。\n",asd);
				break;
			}
			case 10:
			{
				double a=0,b=0,c=0,d=0,e=0;
				for(i=0; i<peo; i++)
				{
					for(j=0; j<sub; j++)
					{
						if(one[i].subject[j]>=90&&one[i].subject[j]<=100)
							a++;
						if(one[i].subject[j]>=80&&one[i].subject[j]<=89)
							b++;
						if(one[i].subject[j]>=70&&one[i].subject[j]<=79)
							c++;
						if(one[i].subject[j]>=60&&one[i].subject[j]<=69)
							d++;
						if(one[i].subject[j]>0&&one[i].subject[j]<60)
							e++;
					}
				}
				printf("  所有课程中优秀的有%.0lf个，占总的%.2lf%%\n",a,a*100/(sub*peo));
				printf("  所有课程中良好的有%.0lf个，占总的%.2lf%%\n",b,b*100/(sub*peo));
				printf("  所有课程中中等的有%.0lf个，占总的%.2lf%%\n",c,c*100/(sub*peo));
				printf("  所有课程中及格的有%.0lf个，占总的%.2lf%%\n",d,d*100/(sub*peo));
				printf("所有课程中不及格的有%.0lf个，占总的%.2lf%%\n",e,e*100/(sub*peo));
				break;
			}
			case 11:
			{
				for(i=0; i<peo; i++)
				{
					printf("学号：%ld,姓名：%s",one[i].xuehao,one[i].name);
					for(j=0; j<sub; j++)
						printf("第%d门成绩为：%d ",j+1,one[i].subject[j]);
					printf("总分为：%d,平均分为：%.2lf\n",sum[i],ave[i]);
				}
				break;
			}
			case 12:
			{
				for(i=0; i<peo; i++)
				{
					printf("姓名是%s,学号为%ld的总分是%d,平均分是%.2lf.\n",one[i].name,one[i].xuehao,sum[i],ave[i]);
				}
				break;
			}
			default :
			{
				printf("请检查你是否有相应的功能。\n");
				break;
			}
		}
		system("pause");
		printf("\n");
	}
	while(n!=0);
	return 0;
}
		system("color 7");
		printf("            学生信息管理系统 6.0        \n");
		printf("(1)  录入或者删除每个学生的学号,姓名和各科考试成绩;\n");
		printf("(2)  计算每门课程的总分和平均分;\n");
		printf("(3)  计算每个学生的总分和平均分;\n");
		printf("(4)  按每个学生的总分由高到低排出名次;\n");
		printf("(5)  按每个学生的总分从低到高排出名次;\n");
		printf("(6)  按学号由小到大排出成绩表;\n");
		printf("(7)  按姓名的字典顺序排出成绩表;(目前仅支持英文姓名)\n");
		printf("(8)  按学号查询学生排名及其考试成绩;\n");
		printf("(9)  按姓名查询学生排名及其考试成绩;\n");
		printf("(10) 按优秀，良好，中等，及格，不及格5个类别，对每门课程分别统计每个类别的人数及其所占的百分比;\n");
		printf("(11) 输出每个学生的学号，姓名，各科考试成绩，及其每门成绩的总分和平均分;\n");
		printf("(12) 从文件中读出每个学生的记录信息并显示;\n");
		printf("(0)  退出;\n");
		fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","a+");
		struct student one[30];
		fseek(fp,0L,SEEK_END);
		len=ftell(fp);
		if(len!=0)
		{
			fseek(fp,0L,SEEK_SET);
			fscanf(fp,"%d",&peo);
			fscanf(fp,"%d",&sub);
			for(i=0; i<peo; i++)
			{
				fscanf(fp,"%ld",&one[i].xuehao);
				fscanf(fp,"%s",one[i].name);
				for(j=0; j<sub; j++)
					fscanf(fp,"%d",&one[i].subject[j]);
			}
			printf("欢迎回来继续使用学生管理系统。\n");
			printf("您上次设定的是管理%d个学生，%d个学科成绩的管理系统。\n",peo,sub);
			printf("请选择你所需要功能前面对应的编号。");
		}
		int begin=0;
		printf("请输入相应功能对应的编号：");
		if(len==0&&flag==0)
		{
			printf("\n这是你第一次启动系统,所以请初始化数据,我们默认帮你选择功能(1),按任意数字键继续.(按0退出)");
		}
		do
		{
			for(j=0; j<peo; j++)
			{
				sum[j]=0;
				ave[j]=0;
				for(i=0; i<sub; i++)
					sum[j]=one[j].subject[i]+sum[j];
				ave[j]=1.0*sum[j]/sub;
			}
			if(begin==1)
			{
				printf("请检查你输入是否正确，重新输入相应功能的编号：");
				getchar();
			}
			ret=scanf("%d",&n);
			begin=1;
		}
		while(ret==0);
		if(len==0&&flag==0&&n!=0)n=1;
		begin=0;
		system("cls");
		system("color C");
		printf("运行结果如下：\n");
		switch(n)
		{
			case 0:
			{
				exit(0);
				break;
			}
			case 1:
			{
				fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","a+");
				if(fp==NULL)
				{
					printf("Open wrong");
					exit(0);
				}
				else
				{
					fseek(fp,0L,SEEK_END);
					len=ftell(fp);
					if(flag!=0)
						len++;
					if(len==0)
					{
						printf("欢迎第一次使用学生信息管理系统。\n请输入班级的人数：（最多30人）");
						do
						{
							if(begin==1)
							{
								printf("请检查你输入是否正确，重新输入正确的人数：");
								getchar();
							}
							ret=scanf("%d",&peo);
							begin=1;
						}
						while(ret==0||peo>30||peo<0);
						begin=0;
						fprintf(fp,"%d\n",peo);
						printf("请输入考试的科目：");
						do
						{
							if(begin==1)
							{
								getchar();
								printf("请检查你输入是否正确，重新输入正确的科目数：");
							}
							ret=scanf("%d",&sub);
							begin=1;
						}
						while(ret==0);
						begin=0;
						fprintf(fp,"%d\n",sub);
						printf("这是一个管理%d个人，%d个科目的管理系统。\n",peo,sub);
						for(i=0; i<peo; i++)
						{
							printf("录入第%d个人的学号：",i+1);
							scanf("%ld",&one[i].xuehao);
							fprintf(fp,"%ld ",one[i].xuehao);
							printf("录入第%d个人的名字：",i+1);
							scanf("%s",one[i].name);
							fprintf(fp,"%s ",one[i].name);
							for(j=0; j<sub; j++)
							{
								printf("录入第%d个人的第%d个成绩:",i+1,j+1);
								do
								{
									if(begin==1)
									{
										getchar();
										printf("请检查你输入是否正确，重新输入相应的分数：");
									}
									ret=scanf("%d",&one[i].subject[j]);
									begin=1;
								}
								while(ret==0);
								begin=0;
								fprintf(fp,"%d ",one[i].subject[j]);
							}
							fprintf(fp,"\n");
							flag=1;
						}
					}
					if(len!=0)
					{
						char c,d;
						printf("你是否想要删除所有数据。（Y表示是，其他为否，0表示退出)");
						getchar();
						c=getchar();
						getchar();
						if(c=='Y'||c=='y')
						{
							printf("请确认你的操作，继续将删除所有已经存储的数据，并且不能够恢复（Y表示是，其他为否，0表示退出）");
							d=getchar();
							if(d=='Y'||d=='y')
							{
								fp=fopen("D:\\C++专用文件夹\\20161101215\\123.txt","w");
							}
						}
					}
				}
				break;
			}
			case 2:
			{
				int jisuan[30];
				float pinjun[30];
				for(i=0; i<sub; i++)
				{
					jisuan[i]=0;
					for(j=0; j<peo; j++)
						jisuan[i]=one[j].subject[i]+jisuan[i];
					pinjun[i]=1.0*jisuan[i]/sub;
					printf("第%d门的成绩的总分是%d。",i+1,jisuan[i]);
					printf("第%d门的成绩的平均分是%.2f。\n",i+1,pinjun[i]);
				}
				break;
			}
			case 3:
			{
				for(j=0; j<peo; j++)
				{
					printf("学号为%ld,%s的成绩的总分是:%d\n",one[j].xuehao,one[j].name,sum[j]);
					printf("学号为%ld,%s的成绩的平均分是:%.2lf\n",one[j].xuehao,one[j].name,ave[j]);
				}
				break;
			}
			case 4:
			{
				int max,maxpos;
				for(j=0; j<peo; j++)
				{
					max=sum[0];
					maxpos=0;
					for(i=0; i<peo; i++)
					{
						if(sum[i]>max)
						{
							max=sum[i];
							maxpos=i;
						}
					}
					printf("第%d名是学号为%ld,的%s 总分是%d\n",j+1,one[maxpos].xuehao,one[maxpos].name,max);
					sum[maxpos]=-1;
				}
				break;
			}
			case 5:
			{
				int min,minpos;
				for(j=0; j<peo; j++)
				{
					min=sum[0];
					minpos=0;
					for(i=0; i<peo; i++)
					{
						if(sum[i]<min)
						{
							min=sum[i];
							minpos=i;
						}
					}
					printf("倒数第%d名是学号为%ld的%s 总分是%d\n",j+1,one[minpos].xuehao,one[minpos].name,min);
					sum[minpos]=999;
				}
				break;
			}
			case 6:
			{
				long temp;
				for(j=0; j<peo-1; j++)
				{
					for(i=0; i<peo-j-1; i++)
					{
						if(one[i].xuehao>one[i+1].xuehao)
						{
							temp=sum[i];
							sum[i]=sum[i+1];
							sum[i+1]=temp;
							temp=one[i].xuehao;
							one[i].xuehao=one[i+1].xuehao;
							one[i+1].xuehao=temp;
						}
					}
				}
				for(j=0; j<peo; j++)
					printf("学号为%ld的是%s，他的成绩是%d\n",one[j].xuehao,one[j].name,sum[j]);
				break;
			}
			case 7:
			{
				char zifu[20];
				int swap;
				for(j=0; j<peo; j++)
				{
					sum[j]=0;
					for(i=0; i<sub; i++)
					{
						sum[j]=one[j].subject[i]+sum[j];
					}
				}
				for(i=0; i<peo-1; i++)
				{
					for(j=0; j<peo-1-i; j++)
					{
						if(strcmp(one[j].name,one[j+1].name)>0)
						{
							strcpy(zifu,one[j].name);
							strcpy(one[j].name,one[j+1].name);
							strcpy(one[j+1].name,zifu);
							swap=sum[j];
							sum[j]=sum[j+1];
							sum[j+1]=swap;
						}
					}
				}
				for(i=0; i<peo; i++)
					printf("姓名为%s的成绩是%d。\n",one[i].name,sum[i]);
				break;
			}
			case 8:
			{
				long x,live=0,paiming=peo+1;
				printf("请输入你需要查找的学号：");
				scanf("%ld",&x);
				for(i=0; i<peo; i++)
				{
					if(x==one[i].xuehao)
					{
						for(j=0; j<peo; j++)
						{
							if(sum[i]>=sum[j])
								paiming--;
						}
						printf("学号为%ld的姓名是%s,排名为%ld,成绩为%d\n",x,one[i].name,paiming,sum[i]);
						live=1;
					}
				}
				if(live==0)
					printf("不存在学号为%ld的学生，请核实您的输入。\n",x);
				break;
			}
			case 9:
			{
				char asd[20];
				int live=0,paiming=peo+1,panduan;
				printf("请输入你需要查找的姓名：");
				scanf("%s",asd);
				for(i=0; i<peo; i++)
				{
					panduan=strcmp(asd,one[i].name);
					if(panduan==0)
					{
						for(j=0; j<peo; j++)
						{
							if(sum[i]>=sum[j])
								paiming--;
						}
						printf("学号为%ld的姓名是%s,排名为%d,成绩为%d\n",one[i].xuehao,one[i].name,paiming,sum[i]);
						live=1;
					}
				}
				if(live==0)
					printf("不存在姓名为%s的学生，请核实您的输入。\n",asd);
				break;
			}
			case 10:
			{
				double a=0,b=0,c=0,d=0,e=0;
				for(i=0; i<peo; i++)
				{
					for(j=0; j<sub; j++)
					{
						if(one[i].subject[j]>=90&&one[i].subject[j]<=100)
							a++;
						if(one[i].subject[j]>=80&&one[i].subject[j]<=89)
							b++;
						if(one[i].subject[j]>=70&&one[i].subject[j]<=79)
							c++;
						if(one[i].subject[j]>=60&&one[i].subject[j]<=69)
							d++;
						if(one[i].subject[j]>0&&one[i].subject[j]<60)
							e++;
					}
				}
				printf("  所有课程中优秀的有%.0lf个，占总的%.2lf%%\n",a,a*100/(sub*peo));
				printf("  所有课程中良好的有%.0lf个，占总的%.2lf%%\n",b,b*100/(sub*peo));
				printf("  所有课程中中等的有%.0lf个，占总的%.2lf%%\n",c,c*100/(sub*peo));
				printf("  所有课程中及格的有%.0lf个，占总的%.2lf%%\n",d,d*100/(sub*peo));
				printf("所有课程中不及格的有%.0lf个，占总的%.2lf%%\n",e,e*100/(sub*peo));
				break;
			}
			case 11:
			{
				for(i=0; i<peo; i++)
				{
					printf("学号：%ld,姓名：%s",one[i].xuehao,one[i].name);
					for(j=0; j<sub; j++)
						printf("第%d门成绩为：%d ",j+1,one[i].subject[j]);
					printf("总分为：%d,平均分为：%.2lf\n",sum[i],ave[i]);
				}
				break;
			}
			case 12:
			{
				for(i=0; i<peo; i++)
				{
					printf("姓名是%s,学号为%ld的总分是%d,平均分是%.2lf.\n",one[i].name,one[i].xuehao,sum[i],ave[i]);
				}
				break;
			}
			default :
			{
				printf("请检查你是否有相应的功能。\n");
				break;
			}
		}
		system("pause");
		printf("\n");
	}
	while(n!=0);
	return 0;
}
