#include "CommonTools.h"
#include <openssl/md5.h>

uint64_t get_md5_64(const char * input)
{
    if(input == NULL)
        return 0;
 
    uint8_t md5_buff[16];
    MD5((uint8_t *)input, strlen(input), md5_buff);
    return *(uint64_t *)md5_buff;
}

void split_string(string& str, char separator, vector<string> * result)
{
    result->clear();
    size_t pre_pos = 0;
    size_t cur_pos = 0;
    while((cur_pos=str.find(separator, pre_pos)) != string::npos)
    {
        result->push_back(str.substr(pre_pos, cur_pos-pre_pos));
        pre_pos = cur_pos + 1;
    }

    if(pre_pos < cur_pos)
    {
        result->push_back(str.substr(pre_pos, str.length()));
    }
}

char * ltrim(char * str)
{
	if(NULL == str)
		return NULL;

	while( *str != '\0')
	{
		if(*str <= 32) str++;
	}

	return str;
}

char * rtrim(char * str)
{
	if(NULL == str)
		return NULL;
	char * ptr_end = str + strlen(str) - 1;
	while(ptr_end != str)
	{
		if(*ptr_end <= 32) ptr_end--;
	}

	if (ptr_end == str && *str<=32)
		return '\0';
	ptr_end++;
	ptr_end = '\0';

	return str;
}

char * trim(char * str)
{
	if(NULL == str)
		return NULL;
	char * ltrim_str = ltrim(str);
	char * rtrim_str = rtrim(ltrim_str);
	return rtrim_str;
}
