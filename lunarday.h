//file: lunarday.h
//author: cuichaox@gmail.com
//2007-02-13 11:22:04

#ifndef LUANR_CALENDAR_H
#define LUANR_CALENDAR_H

namespace lunar
{ 
     //����һ��ũ������
     typedef struct T_Date
     {
	  //��
	  int year;
	  //��
	  int month;
	  //��
	  int day;
	  //�Ƿ�����
	  bool leap;	  
     } Date;     
     
     //����תũ��
     Date LuanrDate(int solar_year,int solar_month,int solar_day);
     
     //����ũ�����ڷ���"*��*��*a��"��ʽ���ַ�����
     //�磺"������������³���", ���еĺ���Ϊgb2312����
     const char * to_ch_str(const Date &lunar_date);
     const char * to_ch_str_r(const Date &lunar_date, char *buf);
     const int MAX_CH_DATE_LEN=26;
}
#endif //LUANR_CALENDAR_H
