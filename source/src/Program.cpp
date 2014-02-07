#include "Program.h"

namespace infrastructure {

	CGcontext& getContext() {
		static CGcontext cgContext = cgCreateContext();
		return cgContext;
	}
	
	Program::Program() {
		
	}


	Program::~Program(){

	}
}