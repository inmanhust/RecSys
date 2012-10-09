#include <string.h>
#include <time.h>
#include <openssl/md5.h>
#include "CommonTools.h"

using namespace std;

/*
 *	get_file_size 获得文件大小
 *	@param fp [in/out]	文件句柄，已经打开，函数会将指针移至文件头
 *	@return 文件大小
 *
*/
uint64_t get_file_size(FILE * fp)
{
	uint64_t file_size;//文件大小
	fseeko(fp,0,SEEK_END);
	file_size=ftello(fp);
	rewind(fp);
	return file_size;
}

/*
 *	count_char 字符串中某字符的数量
 *	@param buf [in] 字符串，非NULL
 *	@param ch [in] 字符
 *	@return	字符在字符串中出现的次数
*/
int count_char(const char * buf,const char ch)
{
	int num=0;//字符计数
	const char * pbuf;//指向当前字符在字符串中位置
	pbuf=strchr(buf,ch);
	while(pbuf){
		num++;
		pbuf=strchr(pbuf+1,ch);
	}
	return num;
}

/*
 *     get_md5_64 计算字符串的md5值，64bit
 *     @param str [in] 字符串
 *     @return md5值
 *
*/
uint64_t get_md5_64(const char * str)
{
	uint8_t md5buf[16];//计算MD5缓冲
	if(str == NULL)
		return 0;
	MD5((uint8_t*)str, strlen(str), md5buf);
	return *(uint64_t *)md5buf;
}


/*
 *     split_string 切分字符串，源字符串会被\0分开
 *     @param chr [in] 切分字符
 *     @param src [in] 切分源字符串
 *     @param dstlimit [in] 切分结果限制
 *     @param dstlist [out] 切分结果
 *     @param dstnum [out] 切分结果数量，最大为dstlimit
 */
int split_string(char chr,char * src,uint32_t dstlimit,char ** dstlist,uint32_t * dstnum)
{
	char * ptab;
	ptab = src;
	*dstnum = 0;
	if(*ptab != 0)
		dstlist[(*dstnum)++] = ptab;
	ptab = strchr(ptab,chr);
	while(ptab != NULL && *dstnum < dstlimit){
		*ptab++ = '\0';
		dstlist[(*dstnum)++] = ptab;
		ptab=strchr(ptab,chr);
	}
	return 0;
}

int fetch_time(char * buf,uint32_t bufsize)
{
	time_t timestamp;
	struct tm time_tm;
	if(buf == NULL)
		return -1;
	time(&timestamp);
	localtime_r(&timestamp,&time_tm);
	strftime(buf,bufsize,"%Y%m%d %H:%M:%S",&time_tm);
	return 0;
}


char * ltrim(char * ptr,const char * ptr_end)
{
	while((uint8_t)*ptr <= 32 && ptr < ptr_end)
		ptr++;
	return ptr;
}

char * rtrim(char * ptr,const char * ptr_start)
{
        while((uint8_t)*(ptr-1) <= 32 && ptr > ptr_start)
                ptr--;
        return ptr;
}


/*
 *     get_cat_high 获得一个行业分类的以及分类
 *     @return category的一级分类
 */
uint32_t get_cat_high(uint32_t category) 
{
    return ((uint32_t) (category / 10000));
}


/*
 *     get_full_path 通过给定目录名和文件名获取完整文件名
 *     @param dir [in] 输入的点击数
 *     @param filename [in] 输入的点击率
 *     @return 完整的文件名
 */
string get_full_path(const char* dir, const char* filename)
{
    ostringstream oss;
    oss << dir;
    if (dir[strlen(dir)-1] != '/')
    {
        oss << '/';
    }
    oss << filename;
    return oss.str();
}

void split_string(const string& original, char separator, uint32_t col_limit, vector<string>* result)
{
    result->clear();
    size_t current_pos = 0, previous_pos = 0;
    uint32_t col_count = 0;
    while((current_pos = original.find(separator, previous_pos)) != string::npos && (col_limit == 0 || col_count < col_limit))
    {   
        string part(original.substr(previous_pos, current_pos - previous_pos));
        result->push_back(part);
        previous_pos = current_pos + 1;
        col_count ++; 
    }   

    if(previous_pos < original.size() && (col_limit == 0 || col_count < col_limit))
    {   
        string part(original.substr(previous_pos));
        result->push_back(part);
    }   
}

void split_string(const string& original, char separator, vector<string>* result)
{
    return split_string(original, separator, 0, result);
}
