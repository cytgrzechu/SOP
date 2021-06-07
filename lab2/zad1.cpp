#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

auto main(int argc, char* argv[])->int{
	int* adres = 0xdeadbeef;
	cout<<adres;
}