/**
 * Copyright 2012 Inman, Personal Code Store
 * @File        CommonTools.h
 * @Author      Inman 
 * @Date        2012/7/20
 * @Brief       Common Function, including md5,String spliter...
 **/

#ifndef _COMMON_TOOLS_H_
#define _COMMON_TOOLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

/**
 * 64bit md5 encryption
 * @param    input    [in]    input string
 * @return
 *        64bit md5 value
 **/
uint64_t get_md5_64(const char * input);

/**
 * split string by the separator, then store the result by vector
 * @param    str    [in]    original string
 * @param    separator    [in]    separator
 * @param    result    [out]    result vector
 * @return   
 *           void
 **/
void split_string(string& str, char separator, vector<string> * result);

char * ltrim(char * str);

char * rtrim(char * str);

char * trim(char * str);

#endif // _COMMON_TOOLS_H_
