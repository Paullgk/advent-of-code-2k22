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

void Tools::extractLines(string input_data, vector<string>* output_lines){
    const int input_data_length = input_data.length();
    int current_pos = 0;
    int carriage_pos = 0;
    string line;
    int absolute_calories = 0;
    int line_length = 0;


    while ( current_pos < input_data_length ) {
        carriage_pos = input_data.find('\n', current_pos);

        if( carriage_pos == -1)
            break;

        line = input_data.substr(current_pos, carriage_pos - current_pos);
        output_lines->push_back(line);

        line_length = line.length();
        current_pos = carriage_pos + 1;
    }
}
