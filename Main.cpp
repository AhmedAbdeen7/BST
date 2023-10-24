#include "BST.cpp"

using namespace std;


int main()
{

string runType;
BST <string, double> tree;
string key, country;
double  lat1, lat2, lon1, lon2;
char direction1, direction2;
cout << "Choose the runtype ";
cin >> runType;

    if (runType == "initial") {
        tree.load_from_file("New Text Document (2).txt");

    


    } else if (runType == "cumulative") {
       tree.load_from_file("New Text Document (2).txt");
       cin >> key >> country >> lat1 >> lat2 >> lon1 >>lon2 >> direction1 >> direction2;
       tree.insert(tree, key, country, lat2,lat1,lon1, lon2,direction1, direction2);
    } else if (runType == "query") {
        tree.compute("London", "US");
    } else {
        cout << " The choice is invalid ";
    
    }



    return 0;
}
 initialRun()
 {

 }

 void cumulativeRun() {
 BST <string, double> tree;
    root = loadDictionaryFromFile("dictionary.txt");
    if (root == nullptr) {
        std::cerr << "Error: Unable to load dictionary from file." << std::endl;
        return;
    }
 }