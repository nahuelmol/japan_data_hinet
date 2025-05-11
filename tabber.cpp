#include<fstream>

void tab(std::string dir) {
    std::ifstream input;
    input.open(dir);
    std::string line;
    std::string newline;
    std::string newfile;
    int spacecounter = 0;
    bool tabbed = false;
    std::string namefile = "datatabbed.txt";
    while (std::getline(input, line)) {
        std::cout << line << std::endl;
        //then I am going to go trough the current line
        for (auto c = line.begin(); c != line.end(); ++c) {
            if(!(*c == ' ')) {
                tabbed = false;
                newline.push_back(*c);
            } else {
                if(tabbed == false) {
                    tabbed = true;
                    newline.push_back('\t');
                }
                spacecounter++;
            }
        }
        std::cout << newline << std::endl;
        std::ofstream file(namefile);
        if(file.is_open()){
            file << newline << std::endl;
            file.close();
        } else {
            std::cout << "file not opened" << std::endl;
        }
    }
}
