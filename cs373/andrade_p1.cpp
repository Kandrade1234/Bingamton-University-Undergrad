/* By Kevin Andrade.
consulted the internet for the set data structure (to get rid of repetitions easily) and npos "until the end of the string".
Binghamton University CS 373 Program 1 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <set>
using namespace std;
void inputParser(std::vector<bool> &acceptStates, std::vector<std::vector<std::pair<char, int> > > &transition, int argc, char *argv[]);
void getPaths(char *argv[]);
void print (set <int> acceptRejectStates, string output);
int startState = -1;
std::vector <bool> acceptStates(1001, false);
std::vector<std::vector<std::pair<char, int> > > transition(1001);
int main(int argc, char* argv[]) {
  inputParser(acceptStates, transition, argc, argv);
  getPaths(argv);

}
void inputParser(vector<bool> &acceptStates, vector<vector<pair<char, int> > > &transition, int argc, char *argv[])
{
  if(argc != 3) {
    cerr << "Incorrect number of arguments, Please enter an input_file and test_string\n";
    exit(-1);
  }
  std::ifstream infile(argv[1]);
  if(!infile.is_open()) {
    cerr << "Cannot open input file\n";
    exit(-1);
  }
  string currentLine;
  while(getline(infile, currentLine)){
    //determening state or transition
    string stringRead = currentLine.substr(0, currentLine.find('\t'));
    currentLine = currentLine.substr(currentLine.find('\t') + 1);

    if(stringRead == "state")
    {
      int stateNumber = stoi(currentLine.substr(0, currentLine.find('\t')) );
      currentLine = currentLine.substr(currentLine.find('\t') + 1);
      while(currentLine.length() != 0)
      {
        string in;
	//"until the end of the string".
        if(currentLine.find('\t') == string::npos)
        {
          in = currentLine.substr(0, currentLine.find('\n'));
          currentLine = "";
        }
        else
        {
          in = currentLine.substr(0, currentLine.find('\t'));
          currentLine = currentLine.substr(currentLine.find('\t') + 1);
        }
        if(in == "start") startState = stateNumber;

        else if (in == "accept") acceptStates[stateNumber] = true;
	else if(in == "acceptstart" || in == "start\taccept" || in == "start accept")
	{
	  startState = stateNumber;
	  acceptStates[stateNumber] = true;
	}
        else {
          cerr << "Invalid input\n";
          exit(-1);
        }
      }
    }
    else if(stringRead == "transition")
    {
      int stateIn, transitionTo;
      char symbol;
      stateIn = stoi(currentLine.substr(0, currentLine.find('\t')));
      currentLine = currentLine.substr(currentLine.find('\t') + 1);
      symbol = currentLine[0];
      currentLine = currentLine.substr(currentLine.find('\t') + 1);

      transitionTo = stoi(currentLine.substr(0, currentLine.find('\t')));
      pair < char, int> temp(symbol, transitionTo);
      transition[stateIn].push_back(temp);
    }
    else {
      cerr << "Invalid input file\n";
      exit(-1);
    }
  }
}
void getPaths(char *argv[]){
  //algorithm from class.....take start state and see where you can go from there....take next symbol and see where you can go from there..
  string input = argv[2]; //input string
  bool flag = false;
  vector<pair<int, string> > paths;
  paths.push_back(pair<int, string>(startState, input));
  for(int i =0; i < paths.size(); i++){
    int state = paths[i].first;
    string remainingInput = paths[i].second;
    if(remainingInput == ""){if(acceptStates[state]) flag = true;}	//string has been consumed
    else
    {
      char next = remainingInput[0];
      remainingInput = remainingInput.substr(1);
      for(int i = 0; i < transition[state].size(); i++)
        if(transition[state][i].first == next) paths.push_back(pair<int, string> (transition[state][i].second, remainingInput));
    }
  }
  set<int> acceptRejectStates;	//sets only allow one of a kind...no repetition of states
  string output;
  // If accept states found list all possible states the partial NFA can end up. also note that an empty string means it has consumed input string
  if(flag) {
      output = "accept";
      for(int i = 0; i < paths.size(); i++) {
          if(paths[i].second == "" && acceptStates[paths[i].first])
              acceptRejectStates.insert(paths[i].first);
      }
  }
  else {
      output = "reject";
      for(int i = 0; i < paths.size(); i++) {
          if(paths[i].second == "" && !acceptStates[paths[i].first])
              acceptRejectStates.insert(paths[i].first);
      }
  }
  print(acceptRejectStates, output);
}

void print (set <int> acceptRejectStates, string output)
{
  for(auto it = acceptRejectStates.begin(); it != acceptRejectStates.end(); it++) {
      output += " ";
      output += to_string(*it);
  }
  cout << output << endl;
}
