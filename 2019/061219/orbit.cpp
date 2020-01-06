#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node{
    string name;
    Node* is_orbiting;
    Node* orbited_by;
};

int main(int argc, char** argv){
    vector<Node> orbitals;
    Node com = {"COM", NULL, NULL};
    orbitals.push_back(com);

    string s;
    ifstream infile;
    infile.open(argv[1]);

    while(infile >> s){
        string first = s.substr(0, 3);
        string second = s.substr(4, 3);
    }

    infile.close();

    return 0;
}