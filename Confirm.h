#pragma once

#include "Mylib.h"

enum keyControl { dir_LEFT = 75, dir_RIGHT = 77, dir_UP = 72, dir_DOWN = 80, key_SPACE = 32, key_ENTER = 13, key_ESC = 27 };
enum notifyButton { YES, NO, CANCEL, YES_NO, YES_CANCEL };
enum eModeImportData { NUMBER, LOWER, UPPER, ALL, UPPER_LOWER, UPPER_NUMBER, ALL_SPACE, SEX, TYPEBILL, SCORE };


char* char_formartText(char *text);
char* char_substr(char *Source, unsigned int lcCut, unsigned int quantity);
char* EntryData(char *text, POINT lc, eModeImportData mode, int maxLength);
void drawBox(POINT lcDisplay, SIZE size, char *caption);
void dis_Clear(POINT lcHeadClear, SIZE size);
bool messagebox(char *content, int notifyButton, POINT lcDisplay);
