#ifndef _MODEL_FILE_H_
#define _MODEL_FILE_H_

#include "common.h"
#include <stdio.h>

boolean model_file_read(const char* fileName, FILE** writeFp);
boolean model_file_write(const char* fileName, FILE* readFp);
boolean model_file_buildStack(FILE* readFp);

#endif