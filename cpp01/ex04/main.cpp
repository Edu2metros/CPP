#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

std::ofstream* filename_out(const char *filename)
{
    const char *extension = ".replace";
    size_t len1 = std::strlen(filename);
    size_t len2 = std::strlen(extension);
    char *result = new char[len1 + len2 + 1];
    std::strcpy(result, filename);
    std::strcat(result, extension);
    std::ofstream* outfile = new std::ofstream(result);
    delete[] result;
    return outfile;
}

void write_outfile(std::ifstream &infile, std::ofstream *outfile, char *str_find, char *str_replace)
{
    std::string line;
    while(std::getline(infile, line)){
        std::string new_line;
        for(size_t i = 0; i < line.size();){
            if(line.substr(i, std::strlen(str_find)) == str_find){
                new_line += str_replace;
                i += std::strlen(str_find);
            } else {
                new_line += line[i];
                i++;
            }
        }
        (*outfile) << new_line << std::endl;
    }
}

int main(int argc, char **argv)
{
	if(argc != 4){
		std::cerr << "Error! Invalid usage of the program. \
The program can only take 3 parameters. <filename> string1 string2." << std::endl;
		return(1);
	}
	std::ifstream infile(argv[1]);
	if(!infile.is_open()){
		std::cerr << "Error reading the input file." << std::endl;
		return(1);
	}
	std::ofstream *outfile = filename_out(argv[1]);
	if(!outfile->is_open()){
		infile.close();
		std::cerr << "Error creating the output file." << std::endl;
		return(1);
	}
	write_outfile(infile, outfile, argv[2], argv[3]);
	infile.close();
	outfile->close();
	delete outfile;
	return(0);
}