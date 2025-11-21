#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
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

        /**
         * @brief Generic lines extractor. Extract each lines from the
         * input_data and push back them into output_lines vector.
         *
         * @param input_data The raw input data.
         * @param output_lines A vector containing each line extracted.
         */
        void extractLines(string input_data, vector<string>* output_lines);
};
#endif
