//
// Created by themastermind on 7/30/20.
//

#ifndef LDDMS3_CONFIG
#define LDDMS3_CONFIG

#include "template.cpp"
#include "constant.cpp"


namespace Config {
    string input;

    string output;

    int l = -1;
    int d1 = -1;
    int d2 = -1;

    void load_config_from_file() {
        ifstream config_file(Constant::CONFIG_FILE_NAME);
        while (config_file.good()) {
            string key;
            config_file >> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            if (key == "input:") config_file >> input;
            else if (key == "output:") config_file >> output;
            else if (key == "l:") config_file >> l;
            else if (key == "d1:") config_file >> d1;
            else if (key == "d2:") config_file >> d2;
        }

        if (input.empty() || l == -1 || d1 == -1 || d2 == -1) {
            cerr << "Config is missing field(s)!\n";
            exit(0);
        }
    }

    void print_config() {
    	cerr << "Input:\t\t\t" << input << "\n";
    	cerr << "Output:\t\t\t" << (output.empty() ? "standard output" : output) << "\n";
    	cerr << "l:\t\t\t" << l << "\n";
    	cerr << "d1:\t\t\t" << d1 << "\n";
    	cerr << "d2:\t\t\t" << d2 << "\n";
    }
}


#endif