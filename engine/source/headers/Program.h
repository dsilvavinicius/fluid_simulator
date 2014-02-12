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
		Program(const string& sourceFileName, const CGprofile& profile);
		~Program();
	private:
		static const string& ENTRY_POINT_NAME;
		CGprogram cgProgram;
	};
}

#endif