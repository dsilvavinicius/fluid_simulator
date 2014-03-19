#ifndef UTILS_H
#define UTILS_H

#include <string>

using namespace std;

/**
 * Generic utilities.
 */
namespace utils {
	class Utils {
	private:
		Utils();
	public:
		static string loadFile(const string& fileName);
		static void checkGLError();
	};
}
#endif