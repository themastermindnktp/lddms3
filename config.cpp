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

    int n = -1;
    int l = -1;
    int d = -1;

    void load_config_from_file() {
        ifstream input_file(Constant::CONFIG_FILE);
        while (input_file.good()) {
            string key;
            input_file >> key;
            transform(key.begin(), key.end(), key.begin(), ::toupper);
            if (key == "INPUT:") input_file >> input;
            else if (key == "OUTPUT:") input_file >> output;
            else if (key == "N:") input_file >> n;
            else if (key == "L:") input_file >> l;
            else if (key == "D:") input_file >> d;
        }

        if (input.empty() || l == -1 || d == -1)
        {
            cerr << "Config is missing field(s)!\n";
            exit(0);
        }

    }

    void print_config() {
    	cout << "Input:\t\t" << input << "\n";
    	cout << "Output:\t\t" << (output.empty() ? "standard output" : output) << "\n";
    	cout << "n:\t\t" << (n == -1 ? "Unknown" : to_string(n)) << "\n";
    	cout << "l:\t\t" << l << "\n";
    	cout << "d:\t\t" << d << "\n";
    }

}


#endif