#include "template.h"
#include <iostream>
#include <string>
//显示实例化,为Demo提供定义
template void Fun(const int&);
template class Node<std::string>;