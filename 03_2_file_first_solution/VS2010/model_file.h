#ifndef _MODEL_FILE_H_
#define _MODEL_FILE_H_

#include "common.h"
#include <stdio.h>

boolean model_file_read(char* fileName, FILE* writeFp);
boolean model_file_write(char* fileName, FILE* readFp);
boolean model_file_buildStack(FILE* readFp);

#endif