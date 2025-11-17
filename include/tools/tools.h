#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

extern const string SPACE_DELIMITER;
extern const int SPACE_DELIMITER_LENGTH;

/**
 * @brief Contains every generic tools used by the different days.
 *
 */
class Tools {
    public:
        /**
         * @brief Generic input file reader.
         *
         * @param InputFile the file to read.
         * @param FileContent a string pointer where the read data should go.
         * @return 0 if read is OK, -1 is NOK.
         *
         */
        int readInputFile(string InputFile, string* FileContent);
};
#endif
