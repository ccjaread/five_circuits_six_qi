#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include "lunarday.cpp"

int jinian1(int year)
{int s=-1,m;
for(m=-1;s<=0||s>60;m++)
s=year-60*m-3;
return s;}

int jinian2(int year)
{int s=-1,m;
for(m=-1;s<=0||s>60;m++)
s=60*m-year-2;
return s;}

int jiyue(int sn,int nmonth)
{int syue,m;
for(syue=-1,m=-1;syue<=0||syue>60;m++)
syue=12*(sn-1)+nmonth-60*m+2;
return syue;}

int runnian(int year)
{int runnian;
if(year%4==0&&year%100||year%400==0)runnian=1;
else runnian=0;
return runnian;}

int jiri(int year,int month,int day)
{int N[2][12]={{0,1,-1,0,0,1,1,2,3,3,4,4},{-1,0,-1,0,0,1,1,2,3,3,4,4}};
int rn,y1,y2,y4,T,U,sr,m;double y3,y5;
rn=runnian(year);
y1=int(year/4);y2=int(year/100);y3=y2*0.75;y4=int(y3);y5=y3-y4;
if(y5)y4++;
T=5*year+y1-y4+10;
U=30*(month-1)+day+N[rn][month-1];
for(m=0,sr=-1;sr<=0||sr>60;m++)
sr=T+U-60*m;
return sr;}

int jishi(int sr,int hour,int min)
{int ss,m,q,bi;double h1,b,bx;
h1=hour+min/60;
for(q=0,b=-1;b<=0||b>12;q++)
b=h1/2-12*q+1;
bi=int(b);bx=b-bi;
if(bx>=0.5)bi=bi+1;
for(m=-1,ss=-1;ss<=0||ss>60;m++)
ss=12*(sr-1)+bi-60*m;
return ss;}





int gan0(int s)
{int g;g=s;
for(;g>10;)
g=g-10;
return g;}

int zhi0(int s)
{int z;z=s;
for(;z>12;)
z=z-12;
return z;}

void gan(int g)
{switch(g)
{case 1:printf("��");break;
case 2:printf("��");break;
case 3:printf("��");break;    
case 4:printf("��");break;      
case 5:printf("��");break;      
case 6:printf("��");break;      
case 7:printf("��");break;      
case 8:printf("��");break;      
case 9:printf("��");break;
case 10:printf("��");break;
default:printf("Error!");break; }     
      }
      
void zhi(int z)
{switch(z){
case 1:printf("��");break;      
case 2:printf("��");break;
case 3:printf("��");break;
case 4:printf("î");break;
case 5:printf("��");break;
case 6:printf("��");break;
case 7:printf("��");break;
case 8:printf("δ");break;
case 9:printf("��");break;
case 10:printf("��");break;
case 11:printf("��");break;
case 12:printf("��");break;
dafault:printf("Error!");break;}
}

void wuyun(int g)
{switch(g)
{case 0:printf("����(����)");break;
case 1:printf("̫��(����)");break;
case 2:printf("����(����)");break;
case 3:printf("̫��(ˮ��)");break;    
case 4:printf("�ٽ�(ľ��)");break;      
case 5:printf("̫��(����)");break;      
case 6:printf("�ٹ�(����)");break;      
case 7:printf("̫��(����)");break;      
case 8:printf("����(ˮ��)");break;      
case 9:printf("̫��(ľ��)");break;
case 10:printf("����(����)");break;
default:printf("Error!");break; }     
      }

void liuqi(int z)
{switch(z){
case 0:printf("������ľ+");break;
case 1:printf("��������-");break;      
case 2:printf("̫��ʪ��-");break;
case 3:printf("�������+");break;
case 4:printf("�������-");break;
case 5:printf("̫����ˮ-");break;
case 6:printf("������ľ-");break;
case 7:printf("��������+");break;
case 8:printf("̫��ʪ��+");break;
case 9:printf("�������-");break;
case 10:printf("�������+");break;
case 11:printf("̫����ˮ+");break;
case 12:printf("������ľ+");break;
dafault:printf("Error!");break;}
}

int gwx(int g)
{int wx;
switch(g)
{case 0:wx=3;break;
case 1:wx=0;break;
case 2:wx=1;break;
case 3:wx=2;break;    
case 4:wx=3;break;      
case 5:wx=4;break;      
case 6:wx=0;break;      
case 7:wx=1;break;      
case 8:wx=2;break;      
case 9:wx=3;break;
case 10:wx=4;break;
default:printf("Error!");break; }     
return wx;}

int zwx(int z)
{int wx;
switch(z){
case 0:wx=3;break;
case 1:wx=4;break;      
case 2:wx=0;break;
case 3:wx=4;break;
case 4:wx=1;break;
case 5:wx=2;break;
case 6:wx=3;break;
case 7:wx=4;break;
case 8:wx=0;break;
case 9:wx=4;break;
case 10:wx=1;break;
case 11:wx=2;break;
case 12:wx=3;break;
default:printf("Error!");break;}
return wx;}

void zyjysj(int g,int z)
{if(g>=4&&g<=8)
switch(z){case 1:
          case 5:
          case 9:printf("        �����ٽǣ������꣩���������������\n\n        ����̫�磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        �����ٹ���â�ֺ�ʮ��î��һ����ʮ��\n\n        ����̫�̣����������î�����̶�ʮ��\n\n        �����������������ճ�������ʮ��\n");break; 
          case 2:
          case 6:
          case 10:printf("        �����ٽǣ������꣩�����ȳ��������\n\n        ����̫�磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        �����ٹ���â�ֺ�ʮ�����һ����ʮ��\n\n        ����̫�̣�����������������̶�ʮ��\n\n        ������������������δ������ʮ��\n");break;
          case 3:
          case 7:
          case 11:printf("        �����ٽǣ������꣩��������������\n\n        ����̫�磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        �����ٹ���â�ֺ�ʮ���ϳ�һ����ʮ��\n\n        ����̫�̣�����������������̶�ʮ��\n\n        �������������������������ʮ��\n");break;
          case 4:
          case 8:
          case 12:printf("        �����ٽǣ������꣩���պ����������\n\n        ����̫�磺���ֺ�ʮ���պ���������ʮ��\n\n"); 
          printf("        �����ٹ���â�ֺ�ʮ���ӳ�һ����ʮ��\n\n        ����̫�̣�����������������̶�ʮ��\n\n        �����������������ճ������ʮ��\n"); break;
          default:printf("Error!");}      
else switch(z){case 1:
          case 5:
          case 9:printf("        ����̫�ǣ������꣩���������������\n\n        �������磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        ����̫����â�ֺ�ʮ��î��һ����ʮ��\n\n        �������̣����������î�����̶�ʮ��\n\n        ����̫�����������ճ�������ʮ��\n"); break;
          case 2:
          case 6:
          case 10:printf("        ����̫�ǣ������꣩�����ȳ��������\n\n        �������磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        ����̫����â�ֺ�ʮ�����һ����ʮ��\n\n        �������̣�����������������̶�ʮ��\n\n        ����̫������������δ������ʮ��\n");break;
          case 3:
          case 7:
          case 11:printf("        ����̫�ǣ������꣩��������������\n\n        �������磺���ֺ�ʮ��������������ʮ��\n\n"); 
          printf("        ����̫����â�ֺ�ʮ���ϳ�һ����ʮ��\n\n        �������̣�����������������̶�ʮ��\n\n        ����̫�������������������ʮ��\n");break;
          case 4:
          case 8:
          case 12:printf("        ����̫�ǣ������꣩���պ����������\n\n        �������磺���ֺ�ʮ���պ���������ʮ��\n\n"); 
          printf("        ����̫����â�ֺ�ʮ���ӳ�һ����ʮ��\n\n        �������̣�����������������̶�ʮ��\n\n        ����̫�����������ճ������ʮ��\n"); break;
          default:printf("Error!");break;}}
          
void keyun(int gn)
{int m=0,g=gn;printf("        ");
do{wuyun(g);printf("-->");g=(g+1)%10;m++;}while(m<4);wuyun(g);}

void zqjy(int zn)
{switch(zn){case 1:
          case 5:
          case 9:printf("        �����������꣩������������\n\n        ��������������������\n\n        ������С���պ�������\n\n"); 
          printf("        ��������������������\n\n        ������������������\n\n        ������Сѩ����������\n");break; 
          case 2:
          case 6:
          case 10:printf("        �����������꣩�����ȳ�����\n\n        ������������î������\n\n        ������С������������\n\n"); 
          printf("        ��������������������\n\n        ����������պ�������\n\n        ������Сѩ����������\n");break; 
          case 3:
          case 7:
          case 11:printf("        �����������꣩�����������\n\n        ��������������������\n\n        ������С�����ȳ�����\n\n"); 
          printf("        ������������î������\n\n        �������������������\n\n        ������Сѩ����������\n");break; 
          case 4:
          case 8:
          case 12:printf("        �����������꣩���պ�������\n\n        ��������������������\n\n        ������С�����������\n\n"); 
          printf("        ��������������������\n\n        ������������ȳ�����\n\n        ������Сѩ��î������\n");break; 
          default:printf("Error!");} }
          
void kqty(int zn)
{int zl=zn;
printf("                        ");liuqi(zl);printf("\n");zl=(zn+5)%12;printf("                     **************\n");
printf("                    *  *�������*  *\n");printf("                   * �� ******** ̫ *\n");
printf("        ");liuqi(zl);printf(" * ��*  *˾��*  *�� * ");zl=(zn+1)%12;liuqi(zl);
printf("\n                 * ��*��  ----  ��*ʪ *\n");printf("                * ��*��*   ��   *��*�� *\n               **      | ��  �� |      **\n");
printf("                * ľ*��*   ��   *��*�� *\n                 * ��*��  ----  ��*�� *\n");zl=(zn+4)%12;
printf("        ");liuqi(zl);printf(" * ��*  *��Ȫ*  *�� * ");zl=(zn+2)%12;liuqi(zl);
printf("\n                   * �� ******** �� *\n                    *  *ˮ����̫*  *\n                     **************\n                       ");
zl=(zn+3)%12;liuqi(zl);}

int shengke(int g,int z)
{int a,b,c,d,e,f;
a=gwx(g);b=zwx(z);c=(a+1)%5;d=(b+1)%5;e=(a+2)%5;f=(b+2)%5;//printf("%d,%d,%d,%d,%d,%d",a,b,c,d,e,f);
if(c==b)return 5;
else {if(d==a)return 6;
      else {if(e==b)return 7;
             else {if(f==a)return 8;
                   else return 9;}
                   }
             }
}

int stxb(int g,int z)
{int tag,tf;
tag=shengke(g,z);//printf("%d",tag);
switch(tag){
            case 5:printf("С��");break;
            case 6:printf("˳��");break;
            case 7:printf("����");break;
            case 8:printf("����");break;
            case 9:printf("���");tf=1;break;
            case 0:printf("Error2!");break;
            default:printf("Error1!");break;}
return tf;}

//int tianfu(int g,int z)
//{int a,b;a=gwx(g);b=zwx(z);
//if(a==b){printf("���");return 1;}else return 0;}

int suihui(int sn)
{int m,s[8]={4,11,13,22,26,41,55,56};
for(m=0;m<=7;m++)
{if(sn==s[m]){printf("��� ��");return 1;break;}}
return 0;}

int tongtianfu(int sn)
{int m,s[6]={7,9,11,37,39,41};
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("ͬ��� ��");return 1;break;}}
return 0;}

int tongsuihui(int sn)
{int m,s[6]={8,10,30,38,40,60};
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("ͬ���");return 1;break;}}
return 0;}

          
int tgbj(int g)
{int tg;
if (g%2==0){tg=0;printf("����");}
else {tg=1;printf("̫��");}return tg;}

//int gangdeifu()

void pingqi(int tg,int g,int z,int tf,int sn)
{int bz,m,s[6]={4,22,26,30,48,56};bz=shengke(g,z);if(tg==1&&bz==8)printf("�뻯ƽ�� ��");
if(tg==0&&tf==1)printf("ͬ��ƽ�� ��");if(tg==0&&bz==7)printf("����ƽ�� ��");
if(tg==0&&bz==8)printf("�滯ƽ�� ��");
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("��֧ͬ��֮ƽ�� ��");break;}}
}


int main()
{using namespace std;
using namespace lunar;
int year,nyear,month,nmonth,day,hour,min,sn,snn,sy,sr,ss,gn,zn,gy,zy,gr,zr,gs,zs,tg=-1,tf=-1,sh=-1,ttf=-1,tsh=-1;
char choice,jixu='N';//int asb=0,bsa=0,akb=0,bka=0;int* asb0=&asb,bsa0=&bsa,akb0=&akb,bka0=&bka;
printf("        ������������������������������������������������������\n");
printf("        ��__   __               ___   _         _     ___   ��\n");
printf("        ��\\ \\ / /_   _  _ __   / _ \\ (_)       / |   / _ \\  ��\n");
printf("        �� \\ V /| | | || '_ \\ | | | || | __ __ | |  | | | | ��\n");
printf("        ��  | | | |_| || | | || |_| || | \\ V / | | _| |_| | ��\n");
printf("        ��  |_|  \\__,_||_| |_| \\__\\_\\|_|  \\_/  |_|(_)\\___/  ��\n");
printf("        ��                                                  ��\n");
printf("        ������������������������������������������������������\n\n\n");
do {
printf("        ���������(1901-2099):");
scanf("%d",&year);
scanf("%*c");
printf("        �������·�:");
scanf("%d",&month);
scanf("%*c");
printf("        ����������:");
scanf("%d",&day);
scanf("%*c");
printf("        ������ʱ�䣨ʱ��:");
scanf("%d",&hour);
scanf("%*c");
printf("        ������ʱ�䣨�֣�:");
scanf("%d",&min);
scanf("%*c");
//printf("����ǹ�Ԫǰ�����롰Y���������롰N��");
//scanf("%c",&choice);
//if((choice=='Y')||(choice=='y')) sn=jinian2(year);
//else sn=jinian1(year);

//
Date lunar_date = LuanrDate(year,month,day);
nyear=lunar_date.year;
nmonth=lunar_date.month;
snn=jinian1(nyear);
//
sn=jinian1(year);
gn=gan0(snn);zn=zhi0(snn);
sy=jiyue(snn,nmonth);sr=jiri(year,month,day);ss=jishi(sr,hour,min);
gy=gan0(sy);zy=zhi0(sy);gr=gan0(sr);zr=zhi0(sr);gs=gan0(ss);zs=zhi0(ss);
printf("\n");
printf("        ������ʱ��֧����:\n"); 
printf("        ��------��------��------��------��\n");
printf("        ��  ��  ��  ��  ��  ��  ��  ʱ  ��\n");
printf("        ��------��------��------��------��\n"); 
printf("        �� ");gan(gn);zhi(zn);printf(" �� ");gan(gy);zhi(zy);printf(" �� ");
gan(gr);zhi(zr);printf(" �� ");gan(gs);zhi(zs);printf(" �� ");printf("\n");
printf("        ��------��------��------��------��");
//printf("%d,%d",sn,sy);
printf("\n\n");
printf("        ����Ϊ:\n");printf("        ��---------------��\n");printf("        ��");wuyun(gn);tg=tgbj(gn);
printf(" ��\n");printf("        ��---------------��\n");printf("        �岽����:\n        ----------------------\n");
zyjysj(gn,zn);printf("        ----------------------\n");printf("        ����:\n        ----------------------\n");keyun(gn);
printf("        \n        ----------------------\n");
printf("\n        һ����������:\n");printf("        ----------------------\n");zqjy(zn);printf("\n        ----------------------\n");
printf("        ����(��ȦΪ��������ȦΪ����):\n");printf("        ----------------------\n");kqty(zn);
printf("\n        ��ʤ�棬��ʤ��\n");
printf("        ----------------------\n");printf("        ���ͼ���:\n");printf("        ----------------------\n");
printf("        ��");tf=stxb(gn,zn);printf(" ��");
//stxb(gn,zn);printf(" | ");
sh=suihui(snn);if(tf==sh)printf("̫����� ��");ttf=tongtianfu(snn);tsh=tongsuihui(snn);printf("\n        ----------------------\n");
printf("        ��");pingqi(tg,gn,zn,tf,snn);//printf(" ��\n");//printf("%d,%d",tg,tf);


printf("\n");
printf("        Ҫ������(Y/N)");
scanf("%c",&jixu);
scanf("%*c");}
while(jixu=='y'||jixu=='Y');
printf("        ��������  ����������������  ��������\n");printf("        ������������������������������������\n");
printf("        ������������������������������������\n");
system("pause");}


 
