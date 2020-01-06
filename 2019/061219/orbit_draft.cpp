#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node{
    string name;
    Node* is_orbiting;
};

typedef Node* nodeptr;

int calc_orbits(nodeptr& n);
void traverse(vector<string>& v, nodeptr& n);
int you_orbit(vector<string>& v, nodeptr& n, string& s);
int santa_orbit(nodeptr& n, string& s);
int min_orbit(vector<nodeptr>& orbitals, int you, int santa);

int main(int argc, char** argv){
    int you, santa;

    vector<nodeptr> orbitals;
    nodeptr com = new Node;
    com->name = "COM";
    com->is_orbiting = NULL;

    orbitals.push_back(com);

    string s;
    ifstream infile;
    infile.open(argv[1]);

    while(infile >> s){
        int found1 = -1, found2 = -1;
        string first = s.substr(0, 3);
        string second = s.substr(4, 3);

        for(int i=0; i<orbitals.size(); i++){
            if(orbitals[i]->name == first){
                found1 = i;
            }

            if(orbitals[i]->name == second){
                found2 = i;
            }
        }

        if(found1 > -1 && found2 > -1){
            orbitals[found2]->is_orbiting = orbitals[found1];
        }

        else if(found1 > -1 && found2 == -1){
            nodeptr n = new Node;
            n->name = second;
            n->is_orbiting = orbitals[found1];

            orbitals.push_back(n);
        }

        else if(found1 == -1 && found2 > -1){
            nodeptr n = new Node;
            n->name = first;
            n->is_orbiting = NULL;

            orbitals.push_back(n);
            orbitals[found2]->is_orbiting = orbitals[orbitals.size()-1];
        }

        else if(found1 == -1 && found2 == -1){
            nodeptr m = new Node;
            m->name = first;
            m->is_orbiting = NULL;

            nodeptr n = new Node;
            n->name = second;
            n->is_orbiting = NULL;

            orbitals.push_back(m);
            orbitals.push_back(n);
            orbitals[orbitals.size()-1]->is_orbiting = orbitals[orbitals.size()-2];
        }

        if(second == "YOU"){
            you = orbitals.size()-1;
        }

        else if(second == "SAN"){
            santa = orbitals.size()-1;
        }
    }

    infile.close();

    int total = 0;

    for(int i=0; i<orbitals.size(); i++){
        total += calc_orbits(orbitals[i]);
    }

    cout << total << endl;

    cout << min_orbit(orbitals, you, santa) << endl << endl;

    return 0;
}

int calc_orbits(nodeptr& n){
    if(n->name == "COM" || n->is_orbiting == NULL){
        return 0;
    }

    else{
        return calc_orbits(n->is_orbiting)+1;
    }
}

void traverse(vector<string>& v, nodeptr& n){
    if(n->name == "COM"){
        return;
    }

    else{
        v.push_back(n->name);
        traverse(v, n->is_orbiting);
    }
}

int you_orbit(vector<string>& v, nodeptr& n, string& s){
    for(int i=0; i<v.size(); i++){
        if(n->name == v[i]){
            s = n->name;
            return i;
        }
    }

    return you_orbit(v, n->is_orbiting, s);
}

int santa_orbit(nodeptr& n, string& s){
    if(n->name == s){
        return 0;
    }

    else{
        return santa_orbit(n->is_orbiting, s)+1;
    }
}

int min_orbit(vector<nodeptr>& orbitals, int you, int santa){
    vector<string> v;
    string s;

    traverse(v, orbitals[you]);

    int a = you_orbit(v, orbitals[santa], s);
    int b = santa_orbit(orbitals[santa], s);

    return a+b-2;
}