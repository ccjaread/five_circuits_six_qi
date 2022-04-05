//file: lunarday.h
//author: cuichaox@gmail.com
//2007-02-13 11:22:04

#ifndef LUANR_CALENDAR_H
#define LUANR_CALENDAR_H

namespace lunar
{ 
     //保存一个农历日期
     typedef struct T_Date
     {
	  //年
	  int year;
	  //月
	  int month;
	  //日
	  int day;
	  //是否闰月
	  bool leap;	  
     } Date;     
     
     //公历转农历
     Date LuanrDate(int solar_year,int solar_month,int solar_day);
     
     //根据农历日期返回"*年*月*a日"格式的字符串，
     //如："二零零八年七月初二", 其中的汉字为gb2312编码
     const char * to_ch_str(const Date &lunar_date);
     const char * to_ch_str_r(const Date &lunar_date, char *buf);
     const int MAX_CH_DATE_LEN=26;
}
#endif //LUANR_CALENDAR_H
