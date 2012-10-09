#ifndef _COMMONTOOLS_H_
#define _COMMONTOOLS_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

const uint32_t  MAX_FIELD_NUM = 128;
const uint32_t  MAX_STRING_LENGTH= 1024;

/*
*	get_file_size 获得文件大小
*	@param fp [in/out]	文件句柄，已经打开，函数会将指针移至文件头
*	@return 文件大小
*
*/
uint64_t get_file_size(FILE * fp);

/*
*	count_char 字符串中某字符的数量
*	@param buf [in] 字符串，非NULL
*	@param ch [in] 字符
*	@return	字符在字符串中出现的次数
*/
int count_char(const char * buf,const char ch);

/*
*     get_md5_64 计算字符串的md5值，64bit
*     @param str [in] 字符串
*     @return md5值
*
*/
uint64_t get_md5_64(const char * str);

/*
*     split_string 切分字符串，源字符串会被\0分开
*     @param chr [in] 切分字符
*     @param src [in] 切分源字符串
*     @param dstlimit [in] 切分结果限制
*     @param dstlist [out] 切分结果
*     @param dstnum [out] 切分结果数量，最大为dstlimit
*/
int split_string(char chr, char * src,uint32_t dstlimit,char ** dstlist,uint32_t * dstnum);

/**
 *切割字符串
 *@param  original    [in]    需要切分的字符串
 *@param  separator    [in]    分隔符
 *@param  col_limit   [in]    最多解析的栏目数,0解析全部域
 *@param  result  [out]   输出列表
 **/
void split_string(const std::string& original, char separator, uint32_t col_limit, std::vector<std::string>* result);

/**
 *切割字符串
 *@param  original    [in]    需要切分的字符串
 *@param  separator    [in]    分隔符
 *@param  result  [out]   输出列表
 **/
void split_string(const std::string& original, char separator, std::vector<std::string>* result);

int fetch_time(char * buf,uint32_t bufsize);

char * ltrim(char * ptr,const char * ptr_end);
char * rtrim(char * ptr,const char * ptr_start);

/*
*     get_cat_high 获得一个行业分类的以及分类
*     @return category的一级分类
*/
uint32_t get_cat_high(uint32_t category);

std::string get_full_path(const char* dir, const char* filename);

#define ADR_LOG(log_out,log_type,...) {\
char timebuf[1000];\
fetch_time(timebuf,1000);\
fprintf(log_out,"%s\4%s\4",#log_type,timebuf);\
fprintf(log_out,__VA_ARGS__);\
}

#define ADR_ACCESS(...) ADR_LOG(stdout,LM_ACCESS, __VA_ARGS__)
#define ADR_WARNING(...) ADR_LOG(stderr,LM_WARNING, __VA_ARGS__)
#define ADR_INFO(...) ADR_LOG(stderr,LM_INFO, __VA_ARGS__)
#define ADR_ERROR(...) ADR_LOG(stderr,LM_ERROR, __VA_ARGS__)

/*错误：文件错误*/
#define ERROR_LOADFILE_FILE (-0x20001)
/*错误：内存分配错误*/
#define ERROR_LOADFILE_MALLOC (-0x20002)
/*错误：文件读取错误*/
#define ERROR_LOADFILE_READ (-0x20003)
/*错误：文件大小错误，非itemtype整数倍*/
#define ERROR_LOADFILE_SIZE (-0x20004)

/**
 * 加载文件到缓冲区
 * @param[in] filename 文件名
 * @param[out] buf 加载缓冲区，会分配内存
 * @return >=0 读取项数 other 失败
 */
template <class itemtype>
int64_t load_file(const char * filename,itemtype * & buf)
{
        //打开文件
        FILE * fp=fopen(filename,"r");///文件句柄
        if(fp == NULL){
                return ERROR_LOADFILE_FILE;
        }
        //获取文件大小
        int64_t file_size = get_file_size(fp);///文件大小
        if(file_size <= 0)
                return ERROR_LOADFILE_FILE;
        //检查文件大小是否符合要求
        if(file_size % sizeof(itemtype) != 0){
                fclose(fp);
                return ERROR_LOADFILE_SIZE;
        }
        int64_t item_num = file_size / sizeof(itemtype);///项数

        //分配内存
        buf = (itemtype*)malloc(file_size);
        if(buf == NULL){
                fclose(fp);
                return ERROR_LOADFILE_MALLOC;
        }
        //读入文件
        int64_t ret = fread(buf,sizeof(itemtype),file_size/sizeof(itemtype),fp);///函数返回值
        fclose(fp);
        //检查读入大小，若正确则返回读入项数
        if(ret == item_num)
                return item_num;
        //读入项数错误，释放内存
        free(buf);
        buf = NULL;
        return ERROR_LOADFILE_READ;
}

#endif
