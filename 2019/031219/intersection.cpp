#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv){
    ifstream infile;
    string s;
    vector<string> path1, path2;
    vector<pair<int, int> > points1, points2, intersect;
    vector<int> steps;

    infile.open(argv[1]);

    while(infile >> s){
        path1.push_back(s);
    }

    infile.close();

    infile.open(argv[2]);

    while(infile >> s){
        path2.push_back(s);
    }

    infile.close();

    int x=0, y=0;

    for(int i=0; i<path1.size(); i++){
        if(path1[i][0] == 'U'){
            path1[i].erase(path1[i].begin());
            int num = stoi(path1[i]);

            for(int j=0; j<num; j++){
                y++;
                points1.push_back(make_pair(x, y));
            }
        }

        if(path1[i][0] == 'D'){
            path1[i].erase(path1[i].begin());
            int num = stoi(path1[i]);

            for(int j=0; j<num; j++){
                y--;
                points1.push_back(make_pair(x, y));
            }
        }

        if(path1[i][0] == 'L'){
            path1[i].erase(path1[i].begin());
            int num = stoi(path1[i]);

            for(int j=0; j<num; j++){
                x--;
                points1.push_back(make_pair(x, y));
            }
        }

        if(path1[i][0] == 'R'){
            path1[i].erase(path1[i].begin());
            int num = stoi(path1[i]);

            for(int j=0; j<num; j++){
                x++;
                points1.push_back(make_pair(x, y));
            }
        }
    }

    x=0, y=0;
    int step1, step2;

    for(int i=0; i<path2.size(); i++){
        if(path2[i][0] == 'U'){
            path2[i].erase(path2[i].begin());
            int num = stoi(path2[i]);

            for(int j=0; j<num; j++){
                y++;
                points2.push_back(make_pair(x, y));

                for(int k=0; k<points1.size(); k++){
                    if(points1[k].first == x && points1[k].second == y){
                        intersect.push_back(points1[k]);
                        step1 = k+1;
                        step2 = points2.size();
                        steps.push_back(step1+step2);
                        break;
                    }
                }
            }
        }

        if(path2[i][0] == 'D'){
            path2[i].erase(path2[i].begin());
            int num = stoi(path2[i]);

            for(int j=0; j<num; j++){
                y--;
                points2.push_back(make_pair(x, y));

                for(int k=0; k<points1.size(); k++){
                    if(points1[k].first == x && points1[k].second == y){
                        intersect.push_back(points1[k]);
                        step1 = k+1;
                        step2 = points2.size();
                        steps.push_back(step1+step2);
                        break;
                    }
                }
            }
        }

        if(path2[i][0] == 'L'){
            path2[i].erase(path2[i].begin());
            int num = stoi(path2[i]);

            for(int j=0; j<num; j++){
                x--;
                points2.push_back(make_pair(x, y));

                for(int k=0; k<points1.size(); k++){
                    if(points1[k].first == x && points1[k].second == y){
                        intersect.push_back(points1[k]);
                        step1 = k+1;
                        step2 = points2.size();
                        steps.push_back(step1+step2);
                        break;
                    }
                }
            }
        }

        if(path2[i][0] == 'R'){
            path2[i].erase(path2[i].begin());
            int num = stoi(path2[i]);

            for(int j=0; j<num; j++){
                x++;
                points2.push_back(make_pair(x, y));

                for(int k=0; k<points1.size(); k++){
                    if(points1[k].first == x && points1[k].second == y){
                        intersect.push_back(points1[k]);
                        step1 = k+1;
                        step2 = points2.size();
                        steps.push_back(step1+step2);
                        break;
                    }
                }
            }
        }
    }

    int distance = 1000000;

    for(int i=0; i<intersect.size(); i++){
        int sum = abs(intersect[i].first) + abs(intersect[i].second);

        if(sum < distance){
            distance = sum;
        }
    }

    cout << "Part 1: " << distance << endl;
    cout << "Part 2: " << *min_element(steps.begin(), steps.end()) << endl << endl;

    return 0;
}