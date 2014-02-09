#ifndef PROGRAM_H
#define PROGRAM_H

#include <memory>
#include <Cg/cg.h>
#include <Cg/cgGL.h>
#include <string>

using namespace std;

/**
 * Shader Program class.
 */
namespace infrastructure {
	class Program
	{
	public:
		static CGcontext& getContext();
		Program(string& const sourceFileName);
		~Program();
	private:
		CGprogram& cgProgram;
	};
}

#endif