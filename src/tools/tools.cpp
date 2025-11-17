#include <tools/tools.h>

extern const string SPACE_DELIMITER = "SPACE\n";
extern const int SPACE_DELIMITER_LENGTH = SPACE_DELIMITER.length();

int Tools::readInputFile(string InputFile, string* FileContent){
    string line;
    ifstream MyReadFile(InputFile);

    if(MyReadFile.is_open()){
        cout << "DEBUG: Reading input file " << InputFile << "..." << endl;

        while ( getline (MyReadFile,line) )
        {
            if(line != ""){
                *FileContent += line;
                *FileContent += '\n';
            }
            else{
                *FileContent += SPACE_DELIMITER;
            }

        }
        *FileContent += '\0';
        MyReadFile.close();    }

    else{
        cout << "ERROR: Cannot open file: " << InputFile << endl;
        return -1;
    }

    return 0;
}
