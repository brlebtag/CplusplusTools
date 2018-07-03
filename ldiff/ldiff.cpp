/**
 * Developer: Bruno Lebtag <brlebtag@gmail.com>
 *
 * @version: 1.0.0
 */

#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    ifstream flist1;
    ifstream flist2;

    if (argc != 3)
    {
        cout<<"ldiff (v1.0.0)"<<endl<<endl;
        cout<<"Usage: ldiff [FILE1] [FILE2]"<<endl;
        cout<<"List all lines that contains in [FILE1] but not in [FILE2]" << endl 
            << " and all lines that contains in [FILE2] but not in [FILE1]."<< endl;
        
        return 0;
    }

    std::unordered_set<std::string> setLista1;
    std::unordered_set<std::string> setLista2;

    string filename1 = argv[1];
    string filename2 = argv[2];

    flist1.open(filename1);

    int total1 = 0, total2 = 0;

    if (flist1.is_open())
    {
        string input;

        while(getline(flist1,input))
        {
            setLista1.insert(input);
        }

        flist1.close();
    }
    else
    {
        cout<<"Couldn't open file "<< filename1 << endl;
    }
    
    flist2.open(filename2);

    if (flist2.is_open())
    {
        string input;

        while(getline(flist2,input))
        {
            setLista2.insert(input);
        }

        flist2.close();
    }
    else
    {
        cout<<"Couldn't open file "<< filename2 << endl;
    }

    for(auto it = setLista1.begin(); it != setLista1.end(); it++)
    {
        string el = *it;

        if (setLista2.find(el) == setLista1.end())
        {
            cout<<"1: \""<< el << "\"" <<endl;

            total1++;
        }
    }

    cout << "Total: " << total1 << endl << endl;

    for(auto it = setLista2.begin(); it != setLista2.end(); it++)
    {
        string el = *it;

        if (setLista1.find(el) == setLista2.end())
        {
            cout<<"2: \""<< el << "\"" <<endl;

            total2++;
        }
    }

    cout << "Total: " << total2 << endl;
}