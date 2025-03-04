#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <map>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    ifstream filename;
    string line1, line2, doctext;
    vector <string> doctoks;
    int maxvalue, score = 0;

    if(argc != 2){
        cout << "Please provide the name of a text file for scoring" << endl;
        return 1;
    }

    filename.open(argv[1]);

    //notification if the file is not open
    if(!filename.is_open()){ 
        cout << "Either the file is open (and thus locked), or you have provided an invalid filename. Please verify and try again." << endl;
    }

    //establish dictionary values
    map<char, int> dict;
    for(char i = 'a'; i <= 'z'; i++){dict.insert( pair<char, int> (i, 0));}

    //read each line
    while(getline(filename,line1, '\n')){

        //tokenize line
        stringstream filename_ss(line1);
        while(getline(filename_ss, line2, ' ')){

            bool valid = true;
            while(valid){

                //score word
                for (int i=0; i<line2.length(); i++){
                    if(isalpha(line2.at(i))){
                        dict[tolower(line2.at(i))]+=1;
                    }else{
                        valid=false;
                    }
                }

                //if word valid then word qualifies. update the score :)
                if(valid){
                    for(char i = 'a'; i <= 'z'; i++){
                        if(dict[i] > maxvalue){maxvalue = dict[i];}
                    }
                    score+=maxvalue;
                    valid=false;
                }

                maxvalue=0;
            }

        //clear out the dict values
            map<char, int>::iterator entry;
            for (entry = dict.begin(); entry != dict.end(); ++entry){entry->second=0;}
        }
    }
    
    cout << "The score for this text is: " << score << endl;

    //close the file
    filename.close();

    return 0;
}