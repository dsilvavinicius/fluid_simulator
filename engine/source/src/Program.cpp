#include <fstream>
#include "Program.h"

namespace infrastructure {

	const string& Program::ENTRY_POINT_NAME = "main";

	CGcontext& Program::getContext() {
		static CGcontext cgContext = cgCreateContext();
		return cgContext;
	}
	
	Program::Program(const string& sourceFileName, const CGprofile& profile) {
		ifstream inputStream(sourceFileName, ios::in);
		if (!inputStream) {
			throw runtime_error("Could not find file: " + sourceFileName);
		}
		
		string sourceCode;
		char fileChar;
		while (inputStream.get(fileChar)) {
			sourceCode.append(&fileChar, 1);
		}
		
		cgProgram = cgCreateProgram(getContext(), CG_SOURCE, sourceCode.c_str(), profile, ENTRY_POINT_NAME.c_str(), NULL);
	}


	Program::~Program(){

	}
}