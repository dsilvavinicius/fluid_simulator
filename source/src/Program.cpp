#include <fstream>
#include "Program.h"

namespace infrastructure {

	CGcontext& getContext() {
		static CGcontext cgContext = cgCreateContext();
		return cgContext;
	}
	
	Program::Program(string& const sourceFileName, CGprofile& const profile) {
		ifstream inputStream;
		inputStream.open(sourceFileName, ios::in);
		
		cgProgram = cgCreateProgram(getContext(), CG_SOURCE, );
	}


	Program::~Program(){

	}
}