#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

auto main(int argc, char* argv[])->int{
	auto const pid = fork();
	
	if(pid == 0){
		
		cout<< "parent pid: " << getppid() << endl;
	}
	else{
		cout<<"child pid: " << pid << endl;
	}
}