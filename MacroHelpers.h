#pragma once

#define MACRO(...) __VA_ARGS__
#define STRING2(x) #x
#define STRING(x) STRING2(x)
#define COMBINE_PATH2(x,y) x/y
#define COMBINE_PATH(x,y) STRING(COMBINE_PATH2(x,y))
