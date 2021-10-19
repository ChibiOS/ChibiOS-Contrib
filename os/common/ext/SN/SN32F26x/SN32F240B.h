// This file exists as a workaround to get the 240B USB code building on a 260.
// Previously this was done with a symlink to SN32F260.h, but that doesn't work on Windows.
// Now the #include directive is used to just include SN32F260.h
#include "SN32F260.h"
