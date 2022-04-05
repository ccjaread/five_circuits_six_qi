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
{case 1:printf("甲");break;
case 2:printf("乙");break;
case 3:printf("丙");break;    
case 4:printf("丁");break;      
case 5:printf("戊");break;      
case 6:printf("己");break;      
case 7:printf("庚");break;      
case 8:printf("辛");break;      
case 9:printf("壬");break;
case 10:printf("癸");break;
default:printf("Error!");break; }     
      }
      
void zhi(int z)
{switch(z){
case 1:printf("子");break;      
case 2:printf("丑");break;
case 3:printf("寅");break;
case 4:printf("卯");break;
case 5:printf("辰");break;
case 6:printf("巳");break;
case 7:printf("午");break;
case 8:printf("未");break;
case 9:printf("申");break;
case 10:printf("酉");break;
case 11:printf("戌");break;
case 12:printf("亥");break;
dafault:printf("Error!");break;}
}

void wuyun(int g)
{switch(g)
{case 0:printf("少徵(火运)");break;
case 1:printf("太宫(土运)");break;
case 2:printf("少商(金运)");break;
case 3:printf("太羽(水运)");break;    
case 4:printf("少角(木运)");break;      
case 5:printf("太徵(火运)");break;      
case 6:printf("少宫(土运)");break;      
case 7:printf("太商(金运)");break;      
case 8:printf("少羽(水运)");break;      
case 9:printf("太角(木运)");break;
case 10:printf("少徵(火运)");break;
default:printf("Error!");break; }     
      }

void liuqi(int z)
{switch(z){
case 0:printf("厥阴风木+");break;
case 1:printf("少阴君火-");break;      
case 2:printf("太阴湿土-");break;
case 3:printf("少阳相火+");break;
case 4:printf("阳明燥金-");break;
case 5:printf("太阳寒水-");break;
case 6:printf("厥阴风木-");break;
case 7:printf("少阴君火+");break;
case 8:printf("太阴湿土+");break;
case 9:printf("少阳相火-");break;
case 10:printf("阳明燥金+");break;
case 11:printf("太阳寒水+");break;
case 12:printf("厥阴风木+");break;
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
          case 9:printf("        初运少角：（上年）大寒日寅初初刻零分\n\n        二运太徵：春分后十三日寅正初刻四十分\n\n"); 
          printf("        三运少宫：芒种后十日卯初一刻三十分\n\n        四运太商：处暑后七日卯正二刻二十分\n\n        终运少羽：立冬后四日辰初三刻十分\n");break; 
          case 2:
          case 6:
          case 10:printf("        初运少角：（上年）大寒日巳初初刻零分\n\n        二运太徵：春分后十三日巳正初刻四十分\n\n"); 
          printf("        三运少宫：芒种后十日午初一刻三十分\n\n        四运太商：处暑后七日午正二刻二十分\n\n        终运少羽：立冬后四日未初三刻十分\n");break;
          case 3:
          case 7:
          case 11:printf("        初运少角：（上年）大寒日申初初刻零分\n\n        二运太徵：春分后十三日申正初刻四十分\n\n"); 
          printf("        三运少宫：芒种后十日酉初一刻三十分\n\n        四运太商：处暑后七日酉正二刻二十分\n\n        终运少羽：立冬后四日戌初三刻十分\n");break;
          case 4:
          case 8:
          case 12:printf("        初运少角：（上年）大寒日亥初初刻零分\n\n        二运太徵：春分后十三日亥正初刻四十分\n\n"); 
          printf("        三运少宫：芒种后十日子初一刻三十分\n\n        四运太商：处暑后七日子正二刻二十分\n\n        终运少羽：立冬后四日丑初三刻十分\n"); break;
          default:printf("Error!");}      
else switch(z){case 1:
          case 5:
          case 9:printf("        初运太角：（上年）大寒日寅初初刻零分\n\n        二运少徵：春分后十三日寅正初刻四十分\n\n"); 
          printf("        三运太宫：芒种后十日卯初一刻三十分\n\n        四运少商：处暑后七日卯正二刻二十分\n\n        终运太羽：立冬后四日辰初三刻十分\n"); break;
          case 2:
          case 6:
          case 10:printf("        初运太角：（上年）大寒日巳初初刻零分\n\n        二运少徵：春分后十三日巳正初刻四十分\n\n"); 
          printf("        三运太宫：芒种后十日午初一刻三十分\n\n        四运少商：处暑后七日午正二刻二十分\n\n        终运太羽：立冬后四日未初三刻十分\n");break;
          case 3:
          case 7:
          case 11:printf("        初运太角：（上年）大寒日申初初刻零分\n\n        二运少徵：春分后十三日申正初刻四十分\n\n"); 
          printf("        三运太宫：芒种后十日酉初一刻三十分\n\n        四运少商：处暑后七日酉正二刻二十分\n\n        终运太羽：立冬后四日戌初三刻十分\n");break;
          case 4:
          case 8:
          case 12:printf("        初运太角：（上年）大寒日亥初初刻零分\n\n        二运少徵：春分后十三日亥正初刻四十分\n\n"); 
          printf("        三运太宫：芒种后十日子初一刻三十分\n\n        四运少商：处暑后七日子正二刻二十分\n\n        终运太羽：立冬后四日丑初三刻十分\n"); break;
          default:printf("Error!");break;}}
          
void keyun(int gn)
{int m=0,g=gn;printf("        ");
do{wuyun(g);printf("-->");g=(g+1)%10;m++;}while(m<4);wuyun(g);}

void zqjy(int zn)
{switch(zn){case 1:
          case 5:
          case 9:printf("        初气：（上年）大寒日寅初初刻\n\n        二气：春分日子正初刻\n\n        三气：小满日亥初初刻\n\n"); 
          printf("        四气：大暑日酉正初刻\n\n        五气：秋分日申初初刻\n\n        终气：小雪日午正初刻\n");break; 
          case 2:
          case 6:
          case 10:printf("        初气：（上年）大寒日巳初初刻\n\n        二气：春分日卯正初刻\n\n        三气：小满日寅初初刻\n\n"); 
          printf("        四气：大暑日子正初刻\n\n        五气：秋分日亥初初刻\n\n        终气：小雪日酉正初刻\n");break; 
          case 3:
          case 7:
          case 11:printf("        初气：（上年）大寒日申初初刻\n\n        二气：春分日午正初刻\n\n        三气：小满日巳初初刻\n\n"); 
          printf("        四气：大暑日卯正初刻\n\n        五气：秋分日寅初初刻\n\n        终气：小雪日子正初刻\n");break; 
          case 4:
          case 8:
          case 12:printf("        初气：（上年）大寒日亥初初刻\n\n        二气：春分日酉正初刻\n\n        三气：小满日申初初刻\n\n"); 
          printf("        四气：大暑日午正初刻\n\n        五气：秋分日巳初初刻\n\n        终气：小雪日卯正初刻\n");break; 
          default:printf("Error!");} }
          
void kqty(int zn)
{int zl=zn;
printf("                        ");liuqi(zl);printf("\n");zl=(zn+5)%12;printf("                     **************\n");
printf("                    *  *少阳相火*  *\n");printf("                   * 火 ******** 太 *\n");
printf("        ");liuqi(zl);printf(" * 君*  *司天*  *阴 * ");zl=(zn+1)%12;liuqi(zl);
printf("\n                 * 阴*右  ----  左*湿 *\n");printf("                * 少*间*   南   *间*土 *\n               **      | 东  西 |      **\n");
printf("                * 木*左*   北   *右*阳 *\n                 * 风*间  ----  间*明 *\n");zl=(zn+4)%12;
printf("        ");liuqi(zl);printf(" * 阴*  *在泉*  *燥 * ");zl=(zn+2)%12;liuqi(zl);
printf("\n                   * 厥 ******** 金 *\n                    *  *水寒阳太*  *\n                     **************\n                       ");
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
            case 5:printf("小逆");break;
            case 6:printf("顺化");break;
            case 7:printf("不和");break;
            case 8:printf("天刑");break;
            case 9:printf("天符");tf=1;break;
            case 0:printf("Error2!");break;
            default:printf("Error1!");break;}
return tf;}

//int tianfu(int g,int z)
//{int a,b;a=gwx(g);b=zwx(z);
//if(a==b){printf("天符");return 1;}else return 0;}

int suihui(int sn)
{int m,s[8]={4,11,13,22,26,41,55,56};
for(m=0;m<=7;m++)
{if(sn==s[m]){printf("岁会 │");return 1;break;}}
return 0;}

int tongtianfu(int sn)
{int m,s[6]={7,9,11,37,39,41};
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("同天符 │");return 1;break;}}
return 0;}

int tongsuihui(int sn)
{int m,s[6]={8,10,30,38,40,60};
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("同岁会");return 1;break;}}
return 0;}

          
int tgbj(int g)
{int tg;
if (g%2==0){tg=0;printf("不及");}
else {tg=1;printf("太过");}return tg;}

//int gangdeifu()

void pingqi(int tg,int g,int z,int tf,int sn)
{int bz,m,s[6]={4,22,26,30,48,56};bz=shengke(g,z);if(tg==1&&bz==8)printf("齐化平气 │");
if(tg==0&&tf==1)printf("同化平气 │");if(tg==0&&bz==7)printf("得政平气 │");
if(tg==0&&bz==8)printf("兼化平气 │");
for(m=0;m<=5;m++)
{if(sn==s[m]){printf("岁支同属之平气 │");break;}}
}


int main()
{using namespace std;
using namespace lunar;
int year,nyear,month,nmonth,day,hour,min,sn,snn,sy,sr,ss,gn,zn,gy,zy,gr,zr,gs,zs,tg=-1,tf=-1,sh=-1,ttf=-1,tsh=-1;
char choice,jixu='N';//int asb=0,bsa=0,akb=0,bka=0;int* asb0=&asb,bsa0=&bsa,akb0=&akb,bka0=&bka;
printf("        ※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
printf("        ※__   __               ___   _         _     ___   ※\n");
printf("        ※\\ \\ / /_   _  _ __   / _ \\ (_)       / |   / _ \\  ※\n");
printf("        ※ \\ V /| | | || '_ \\ | | | || | __ __ | |  | | | | ※\n");
printf("        ※  | | | |_| || | | || |_| || | \\ V / | | _| |_| | ※\n");
printf("        ※  |_|  \\__,_||_| |_| \\__\\_\\|_|  \\_/  |_|(_)\\___/  ※\n");
printf("        ※                                                  ※\n");
printf("        ※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n\n");
do {
printf("        请输入年份(1901-2099):");
scanf("%d",&year);
scanf("%*c");
printf("        请输入月份:");
scanf("%d",&month);
scanf("%*c");
printf("        请输入日期:");
scanf("%d",&day);
scanf("%*c");
printf("        请输入时间（时）:");
scanf("%d",&hour);
scanf("%*c");
printf("        请输入时间（分）:");
scanf("%d",&min);
scanf("%*c");
//printf("如果是公元前请输入“Y”否请输入“N”");
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
printf("        年月日时干支如下:\n"); 
printf("        ┌------┬------┬------┬------┐\n");
printf("        │  年  │  月  │  日  │  时  │\n");
printf("        ├------┼------┼------┼------┤\n"); 
printf("        │ ");gan(gn);zhi(zn);printf(" │ ");gan(gy);zhi(zy);printf(" │ ");
gan(gr);zhi(zr);printf(" │ ");gan(gs);zhi(zs);printf(" │ ");printf("\n");
printf("        └------┴------┴------┴------┘");
//printf("%d,%d",sn,sy);
printf("\n\n");
printf("        中运为:\n");printf("        ┌---------------┐\n");printf("        │");wuyun(gn);tg=tgbj(gn);
printf(" │\n");printf("        └---------------┘\n");printf("        五步主运:\n        ----------------------\n");
zyjysj(gn,zn);printf("        ----------------------\n");printf("        客运:\n        ----------------------\n");keyun(gn);
printf("        \n        ----------------------\n");
printf("\n        一年主气交运:\n");printf("        ----------------------\n");zqjy(zn);printf("\n        ----------------------\n");
printf("        客气(外圈为客气，内圈为主气):\n");printf("        ----------------------\n");kqty(zn);
printf("\n        主胜逆，客胜从\n");
printf("        ----------------------\n");printf("        主客加临:\n");printf("        ----------------------\n");
printf("        │");tf=stxb(gn,zn);printf(" │");
//stxb(gn,zn);printf(" | ");
sh=suihui(snn);if(tf==sh)printf("太乙天符 │");ttf=tongtianfu(snn);tsh=tongsuihui(snn);printf("\n        ----------------------\n");
printf("        │");pingqi(tg,gn,zn,tf,snn);//printf(" │\n");//printf("%d,%d",tg,tf);


printf("\n");
printf("        要继续吗？(Y/N)");
scanf("%c",&jixu);
scanf("%*c");}
while(jixu=='y'||jixu=='Y');
printf("        ┌——┌  ┌┌──┌——┌  ┌┌──\n");printf("        │—┘│─┘│─┘│—┘│─┘│─┘\n");
printf("        │—┘┌─┘│──│—┘┌─┘│──\n");
system("pause");}


 
