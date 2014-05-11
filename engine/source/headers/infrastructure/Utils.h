#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

namespace utils {	
	/**
	* Generic utilities.
	*/
	class Utils {
	private:
		Utils();
	public:
		static string loadFile(const string& fileName);
	};
}
#endif