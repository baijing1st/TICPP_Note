#include "stdafx.h"
#include "Generators.h"


Generators::Generators()
{
}


Generators::~Generators()
{
}

const char* CharGen::source = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int CharGen::len = std::strlen(source);