#pragma once

#define MACRO(x) x
#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define COMBINE_PATH2(x,y) x/y
#define COMBINE_PATH(x,y) STRING(COMBINE_PATH2(x,y))
