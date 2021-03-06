#include <fstream>
#include <stdexcept>
#include <GL/glew.h>
#include "infrastructure/Utils.h"

namespace utils {
	Utils::Utils() {}

	string Utils::loadFile(const string& fileName) {
		ifstream inputStream(fileName.c_str(), ios::in);
		if (!inputStream) {
			throw runtime_error("Could not find file: " + fileName);
		}

		string contents;
		char fileChar;
		while (inputStream.get(fileChar)) {
			contents.append(&fileChar, 1);
		}

		return contents;
	}
}
