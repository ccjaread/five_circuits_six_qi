
//file: lunarday.cpp
//author: cuichao@gmail.com
//2007-02-13 11:22:48
//2008-08-02 15:30:49 ���������ݲ���ȷ��bug

#include "lunarday.h"
#include <ctime>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;
using lunar::Date;


//ʹ�ñ���λ��¼ÿ������
//0~4 ��5bit �����շ�
//5~6 ��2bit �����·�
//7~19 ��13bit 13���µĴ�С�����(��������£����λ��Ч)������Ϊ1,С��Ϊ0
//20~23 ��4bit ��¼���µ��·ݣ����û������Ϊ0
static const int BEGIN_YEAR = 1901;
static const int NUMBER_YEAR = 199;
static const unsigned int LUNAR_YEARS[199] = {
     0x04AE53,0x0752C8,0x5526BD,0x0325D0,0x054DC4,     
     0x46AAB9,0x056A4D,0x05acc2,0x24AEB6,0x04AE4A,  //1901-1910
     0x6A4DBE,0x0592d2,0x0525c6,0x5D52BA,0x0156ce,       
     0x02b5c3,0x296D37,0x06d4cb,0x749BC1,0x049754,  //1911-1920
     0x0692c8,0x5B25BC,0x06A550,0x06D445,0x4ADAB8,
     0x02B64D,0x0754c2,0x2497B7,0x04974A,0x664B3E,  //1921-1930
     0x0295d1,0x052bc6,0x56D4BA,0x05AD4E,0x02B644,
     0x393738,0x03a4cb,0x7C96BF,0x0549d3,0x0295c8,  //1931-1940   
     0x6DA53B,0x0536cf,0x056A45,0x4AADB9,0x025D4D,
     0x05a4c2,0x2C95B6,0x054aca,0x7B4ABD,0x06CA51,  //1941-1950
     0x0556c6,0x555ABB,0x04DA4E,0x06d2c3,0x352BB8,
     0x052B4C,0x8A953F,0x054bd2,0x06AA48,0x7AD53C,  //1951-1960
     0x056acf,0x04B645,0x4A5739,0x0752cd,0x052642,
     0x3E9335,0x054dc9,0x75AABE,0x056A51,0x05b4c6,  //1961-1970
     0x54AEBB,0x04AD4F,0x0592c3,0x4D26B7,0x0525cb,
     0x8D52BF,0x0156d2,0x02b6c7,0x696D3C,0x06d4d0,  //1971-1980
     0x049B45,0x4A4BB9,0x0692cd,0xAB25C2,0x06A554,
     0x06D449,0x6ADA3D,0x036ad1,0x0754c6,0x5497BB,  //1981-1990
     0x04974F,0x064B44,0x36A537,0x052bca,0x86B2BF,
     0x05AC53,0x036ac7,0x5936BC,0x03a4d0,0x0349c5,  //1991-2000
     0x4D4AB8,0x0295cc,0x052dc1,0x25AAB6,0x056A49,
     0x7AADBD,0x05D252,0x05A4C7,0x5C95BA,0x054ace,  //2001-2010
     0x0296c3,0x4B5537,0x055aca,0x955ABF,0x04BA53,
     0x06d2c8,0x652BBC,0x052B50,0x064ac5,0x474AB9,  //2011-2020
     0x06AA4C,0x055ac1,0x24DAB6,0x04B64A,0x69573D,
     0x0392d1,0x0325c6,0x5E933A,0x0655cd,0x05AA43,  //2021-2030
     0x36B537,0x05b4cb,0xB4AEBF,0x04AD53,0x0592c8,
     0x6D25BC,0x0525cf,0x0255c4,0x5DAA38,0x02d6cc,  //2031-2040
     0x056D41,0x24ADB6,0x049B4A,0x7A4BBE,0x0692d1,
     0x052ac6,0x5B52BA,0x06D24E,0x02dac2,0x355B37,  //2041-2050
     0x0764cb,0x8497C1,0x049753,0x064B48,0x66A53C,
     0x052bcf,0x06B244,0x4AB638,0x03aacc,0x03a4c2,  //2051-2060
     0x3C9735,0x0349c9,0x7D4ABD,0x0295d1,0x052dc5,
     0x55AABA,0x056A4E,0x05b2c3,0x452EB7,0x052D4B,  //2061-2070
     0x8A95BF,0x054ad3,0x0296c7,0x6B553B,0x055acf,
     0x055A45,0x4A5D38,0x06d2cc,0x052B42,0x3A93B6,  //2071-2080
     0x069349,0x7729BD,0x06AA51,0x055ac6,0x54DABA,
     0x04B64E,0x0752c3,0x452738,0x0325ca,0x8E933E,  //2081-2090
     0x0255d2,0x02adc7,0x66B53B,0x056D4F,0x04AE45,
     0x4A4EB9,0x0592cc,0x0545c1,0x2D92B5            //2091-2099  
};

static const char *CH_NUMBER_V[] ={"��","һ","��","��","��","��",
			    "��","��","��","��","ʮ"};

static const char *CH_MONTH_V[] ={"*","��","��","��","��","��","��",
			   "��","��","��","ʮ","ʮһ","��"};

static const char *CH_DAY_V[] ={"*","��һ","����","����","����","����",
			 "����","����","����","����","��ʮ",
			 "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��",
			 "ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
			 "إһ","إ��","إ��","إ��","إ��",
			 "إ��","إ��","إ��","إ��","��ʮ"};

static const char *CH_YEAR = "��";
static const char *CH_MONTH = "��";
static const char *CH_DAY ="��";
static const char *CH_SP = "";
static const char *CH_LEAP = "��";


//�����������������һ���еĵڼ���
static int DayOfSolarYear(int year, int month, int day )
{
     //Ϊ�����Ч�ʣ���¼ÿ��һ����һ���еĵڼ���
     static const int NORMAL_YDAY[12] = {1,32,60,91,121,152,
					 182,213,244,274,305,335};
     //��������
     static const int LEAP_YDAY[12] = {1,32,61,92,122,153,
				       183,214,245,275,306,336};     
     const int *t_year_yday_ = NORMAL_YDAY;    
     
     //�ж��Ƿ��ǹ�������
     if( year % 4 ==0 )
     {
	  if(year%100 != 0)	  
	       t_year_yday_ = LEAP_YDAY;
	  if(year%400 == 0)
	       t_year_yday_ = LEAP_YDAY;	  	  	  
     }     
     return t_year_yday_[month -1] + (day -1);      
}



Date lunar::LuanrDate(int solar_year,int solar_month,int solar_day)
{
     Date luanr_date ;     
     luanr_date.year = solar_year;
     luanr_date.month = 0;
     luanr_date.day = 0;
     luanr_date.leap = false;
     
     //Խ���飬���Խ�磬������Ч����
     if(solar_year <= BEGIN_YEAR || solar_year > BEGIN_YEAR + NUMBER_YEAR - 1 )
     	  return luanr_date;
          
     int year_index = solar_year - BEGIN_YEAR;
     
     //���㴺�ڵĹ�������
     int spring_ny_month = ( LUNAR_YEARS[year_index] & 0x60 ) >> 5;
     int spring_ny_day = ( LUNAR_YEARS[year_index] & 0x1f);     
     
     //��������ǹ�����ĵڼ���
     int today_solar_yd = DayOfSolarYear(solar_year,solar_month,solar_day);
     //���㴺���ǹ�����ĵڼ���
     int spring_ny_yd = DayOfSolarYear(solar_year,spring_ny_month,spring_ny_day);
     //���������ũ����ĵڼ���
     int today_luanr_yd = today_solar_yd - spring_ny_yd + 1;
     //��������ڴ��ڵ�ǰ�棬���¼���today_luanr_yd
     if ( today_luanr_yd <= 0 ) 
     {
 	  //ũ����ȵ�ǰ������С1
	  year_index --;
	  luanr_date.year --;
	  //Խ�磬������Ч����
	  if(year_index <0)
	       return luanr_date;
	  spring_ny_month = ( LUNAR_YEARS[year_index] & 0x60 ) >> 5;
	  spring_ny_day = ( LUNAR_YEARS[year_index] & 0x1f);	  
	  spring_ny_yd = DayOfSolarYear(solar_year,spring_ny_month,spring_ny_day);
	  	  
	  int year_total_day = DayOfSolarYear(luanr_date.year,12,31);	  	  
	  today_luanr_yd = today_solar_yd + year_total_day - spring_ny_yd + 1;	  
     }
     
     int luanr_month = 1;
     //�����·ݺ�����
     for(;luanr_month<=13;luanr_month++)
     {	  
	  int month_day  = 29;	  
	  if( (LUNAR_YEARS[year_index] >> (6 + luanr_month)) & 0x1 )
	       month_day = 30;	       
	  if( today_luanr_yd <= month_day )
	       break;   
	  else
	       today_luanr_yd -= month_day;	       
     }
     luanr_date.day = today_luanr_yd;
     //��������
     int leap_month = (LUNAR_YEARS[year_index] >>20)  & 0xf;     
     if(leap_month > 0 && leap_month < luanr_month )
     {	  
	  luanr_month --;
	  //�����ǰ��Ϊ���£��������±�־
	  if( luanr_month == leap_month )	  
	       luanr_date.leap = true;	  	  
     }
     assert(leap_month <= 12);     
     luanr_date.month = luanr_month;          
     return luanr_date;     
}



const char * lunar::to_ch_str(const Date &lunar_date)
{
     static char buf[MAX_CH_DATE_LEN+1];
     return to_ch_str_r(lunar_date,buf);     
}

const char * lunar::to_ch_str_r(const Date &lunar_date,char *buf)
{
     assert(lunar_date.year >= 1000);
     assert(lunar_date.year <= 9999);
     
     assert(lunar_date.month >=1);
     assert(lunar_date.month <=12);
     
     assert(lunar_date.day >=1);
     assert(lunar_date.day <=30);
     
     char *pbuf = buf;
     
     int t_years = lunar_date.year;     
     
     int t_idx = t_years /1000;
     t_years -= t_idx*1000;     
     strcpy(pbuf,CH_NUMBER_V[t_idx]);
     pbuf += strlen(CH_NUMBER_V[t_idx]);
     
     t_idx = t_years /100;     
     t_years -= t_idx*100;     
     strcpy(pbuf,CH_NUMBER_V[t_idx]);     
     pbuf += strlen(CH_NUMBER_V[t_idx]);
     
     t_idx = t_years /10;
     t_years -= t_idx*10;
     strcpy(pbuf,CH_NUMBER_V[t_idx]);     
     pbuf += strlen(CH_NUMBER_V[t_idx]);

     t_idx = t_years;
     strcpy(pbuf,CH_NUMBER_V[t_idx]);     
     pbuf += strlen(CH_NUMBER_V[t_idx]);

     strcpy(pbuf,CH_YEAR);     
     pbuf += strlen(CH_YEAR);

     strcpy(pbuf,CH_SP);     
     pbuf += strlen(CH_SP);
     
     if(lunar_date.leap)
     {
	  strcpy(pbuf,CH_LEAP);	  
	  pbuf += strlen(CH_LEAP);	  
     }

     t_idx = lunar_date.month;
     strcpy(pbuf,CH_MONTH_V[t_idx]);
     pbuf += strlen(CH_MONTH_V[t_idx]);
     
     strcpy(pbuf,CH_MONTH);
     pbuf += strlen(CH_MONTH);

     t_idx = lunar_date.day;     
     strcpy(pbuf,CH_DAY_V[t_idx]);
     pbuf += strlen(CH_DAY_V[t_idx]);     
     pbuf = '\0';
     assert(pbuf - buf <= MAX_CH_DATE_LEN);     
     
     return buf;     
}   

