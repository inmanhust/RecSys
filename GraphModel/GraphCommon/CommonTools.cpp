#include "CommonTools.h"
#include <openssl/md5.h>

uint64_t get_md5_64(const char * input)
{
    uint8_t md5_buff[16];
    if(input == NULL)
        return 0;
 
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
