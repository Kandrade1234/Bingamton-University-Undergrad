#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
using namespace std;
int tournamentCounter = 0;
void singleBitInitializer(vector<int> &, int size);
void dualBitInitializer(vector<int> &, int size);
void selectorInitializer(vector<int> &, int size);
int singleBitPredictor(vector<int> &, int size, bool, unsigned long long);  //returns number of correct predictions and updates the vector to the correct bit if incorrect
int dualBitPredictor(vector<int> &, int size, bool, unsigned long long);
bool dualBitPredictorTour(vector<int> &, int size, bool, unsigned long long, bool prefer);
int gSharePredictor(vector<int> &, bool outcome, int  ghr[], int mask[], int gshareBitSize, unsigned long long);
bool gSharePredictorTour(vector<int> &, bool outcome, int  ghr[], int mask[], int gshareBitSize, unsigned long long, bool prefer);
void tournamentPredictor(vector<int> & , vector<int> & , vector<int> & , int size, bool outcome, unsigned long long address,int GHRTournament[], int maskTournament [], int gshareBitSize);

int main(int argc, const char * argv[]) {
  if(argc < 3){
    cout << "ERROR: Incorrect number of arguments." << endl;
    exit(-1);
  }
  else
  {
    string inputFile = argv[1];
    string outputFile = argv[2];
    string line;
    string outcome;
    unsigned long long address;
    int takenCount = 0;
    int notTakenCount = 0;
    int totalLines = 0;
    //INITIALIZING SINGLE BIT BIMODALS
    vector<int> singleBitHistory16 (16);
    vector<int> singleBitHistory32 (32);
    vector<int> singleBitHistory128 (128);
    vector<int> singleBitHistory256 (256);
    vector<int> singleBitHistory512 (512);
    vector<int> singleBitHistory1024 (1024);
    vector<int> singleBitHistory2048 (2048);

    singleBitInitializer(singleBitHistory16, 16);
    singleBitInitializer(singleBitHistory32, 32);
    singleBitInitializer(singleBitHistory128, 128);
    singleBitInitializer(singleBitHistory256, 256);
    singleBitInitializer(singleBitHistory512, 512);
    singleBitInitializer(singleBitHistory1024, 1024);
    singleBitInitializer(singleBitHistory2048, 2048);

    int singleBit16Count = 0;
    int singleBit32Count = 0;
    int singleBit128Count = 0;
    int singleBit256Count = 0;
    int singleBit512Count = 0;
    int singleBit1024Count = 0;
    int singleBit2048Count = 0;
    //INITIALIZING DUAL BIT BIMODALS
    vector<int> dualBitHistory16 (16);
    vector<int> dualBitHistory32 (32);
    vector<int> dualBitHistory128 (128);
    vector<int> dualBitHistory256 (256);
    vector<int> dualBitHistory512 (512);
    vector<int> dualBitHistory1024 (1024);
    vector<int> dualBitHistory2048 (2048);

    dualBitInitializer(dualBitHistory16, 16);
    dualBitInitializer(dualBitHistory32, 32);
    dualBitInitializer(dualBitHistory128, 128);
    dualBitInitializer(dualBitHistory256, 256);
    dualBitInitializer(dualBitHistory512, 512);
    dualBitInitializer(dualBitHistory1024, 1024);
    dualBitInitializer(dualBitHistory2048, 2048);

    int dualBit16Count = 0;
    int dualBit32Count = 0;
    int dualBit128Count = 0;
    int dualBit256Count = 0;
    int dualBit512Count = 0;
    int dualBit1024Count = 0;
    int dualBit2048Count = 0;
    //INITIALIZING GSHARE
    vector<int> gshare2048_3bits (2048);
    vector<int> gshare2048_4bits(2048);
    vector<int> gshare2048_5bits(2048);
    vector<int> gshare2048_6bits(2048);
    vector<int> gshare2048_7bits(2048);
    vector<int> gshare2048_8bits(2048);
    vector<int> gshare2048_9bits(2048);
    vector<int> gshare2048_10bits(2048);
    vector<int> gshare2048_11bits(2048);

    dualBitInitializer(gshare2048_3bits, 2048);
    dualBitInitializer(gshare2048_4bits, 2048);
    dualBitInitializer(gshare2048_5bits, 2048);
    dualBitInitializer(gshare2048_6bits, 2048);
    dualBitInitializer(gshare2048_7bits, 2048);
    dualBitInitializer(gshare2048_8bits, 2048);
    dualBitInitializer(gshare2048_9bits, 2048);
    dualBitInitializer(gshare2048_10bits, 2048);
    dualBitInitializer(gshare2048_11bits, 2048);

    int gShareCount3Bit = 0;
    int gShareCount4Bit = 0;
    int gShareCount5Bit = 0;
    int gShareCount6Bit = 0;
    int gShareCount7Bit = 0;
    int gShareCount8Bit = 0;
    int gShareCount9Bit = 0;
    int gShareCount10Bit = 0;
    int gShareCount11Bit = 0;

    int GHR[9] = {0,0,0,0,0,0,0,0,0};
    int masks[9] = {7,15,31,63,127,255,511,1023,2047};
    //INITIALIZING TOURNAMENT Predictor
    vector<int> bimodalTournament (2048);
    vector<int> gShareTournament (2048);
    vector<int> selectorTable (2048);

    int GHRTournament[1] = {0};
    int maskTournament[1] = {2047};

    dualBitInitializer(bimodalTournament, 2048);
    dualBitInitializer(gShareTournament, 2048);
    selectorInitializer(selectorTable, 2048);

    ifstream input(inputFile.c_str());
    if(input.is_open())
    {
      ofstream fout(outputFile.c_str());
      while(getline(input, line))
      {
        stringstream ss(line);
        ss >> std::hex >> address >> outcome;
        totalLines++;

        if (outcome == "T"){
          takenCount++;
          //SingleBit Predictor
          singleBit16Count += singleBitPredictor(singleBitHistory16, 16, true, address);
          singleBit32Count += singleBitPredictor(singleBitHistory32, 32, true, address);
          singleBit128Count += singleBitPredictor(singleBitHistory128, 128, true, address);
          singleBit256Count += singleBitPredictor(singleBitHistory256, 256, true, address);
          singleBit512Count += singleBitPredictor(singleBitHistory512, 512, true, address);
          singleBit1024Count += singleBitPredictor(singleBitHistory1024, 1024, true, address);
          singleBit2048Count += singleBitPredictor(singleBitHistory2048, 2048, true, address);
          //DualBit Predictor
          dualBit16Count += dualBitPredictor(dualBitHistory16, 16, true, address);
          dualBit32Count += dualBitPredictor(dualBitHistory32, 32, true, address);
          dualBit128Count += dualBitPredictor(dualBitHistory128, 128, true, address);
          dualBit256Count += dualBitPredictor(dualBitHistory256, 256, true, address);
          dualBit512Count += dualBitPredictor(dualBitHistory512, 512, true, address);
          dualBit1024Count += dualBitPredictor(dualBitHistory1024, 1024, true, address);
          dualBit2048Count += dualBitPredictor(dualBitHistory2048, 2048, true, address);
          //GSHARE
          gShareCount3Bit += gSharePredictor(gshare2048_3bits, true, GHR, masks, 3, address);
          gShareCount4Bit += gSharePredictor(gshare2048_4bits, true, GHR, masks, 4, address);
          gShareCount5Bit += gSharePredictor(gshare2048_5bits, true, GHR, masks, 5, address);
          gShareCount6Bit += gSharePredictor(gshare2048_6bits, true, GHR, masks, 6, address);
          gShareCount7Bit += gSharePredictor(gshare2048_7bits, true, GHR, masks, 7, address);
          gShareCount8Bit += gSharePredictor(gshare2048_8bits, true, GHR, masks, 8, address);
          gShareCount9Bit += gSharePredictor(gshare2048_9bits, true, GHR, masks, 9, address);
          gShareCount10Bit += gSharePredictor(gshare2048_10bits, true, GHR, masks, 10, address);
          gShareCount11Bit += gSharePredictor(gshare2048_11bits, true, GHR, masks, 11, address);
          //TOURNAMENT PREDICTOR
          tournamentPredictor(selectorTable, bimodalTournament, gShareTournament, 2048, true, address, GHRTournament, maskTournament, 11);
        }

        if(outcome == "NT"){
          notTakenCount++;
          //SingleBit Predictor
          singleBit16Count += singleBitPredictor(singleBitHistory16, 16, false, address);
          singleBit32Count += singleBitPredictor(singleBitHistory32, 32, false, address);
          singleBit128Count += singleBitPredictor(singleBitHistory128, 128, false, address);
          singleBit256Count += singleBitPredictor(singleBitHistory256, 256, false, address);
          singleBit512Count += singleBitPredictor(singleBitHistory512, 512, false, address);
          singleBit1024Count += singleBitPredictor(singleBitHistory1024, 1024, false, address);
          singleBit2048Count += singleBitPredictor(singleBitHistory2048, 2048, false, address);
          //DualBit Predictor
          dualBit16Count += dualBitPredictor(dualBitHistory16, 16, false, address);
          dualBit32Count += dualBitPredictor(dualBitHistory32, 32, false, address);
          dualBit128Count += dualBitPredictor(dualBitHistory128, 128, false, address);
          dualBit256Count += dualBitPredictor(dualBitHistory256, 256, false, address);
          dualBit512Count += dualBitPredictor(dualBitHistory512, 512, false, address);
          dualBit1024Count += dualBitPredictor(dualBitHistory1024, 1024, false, address);
          dualBit2048Count += dualBitPredictor(dualBitHistory2048, 2048, false, address);
          //GSHARE
          gShareCount3Bit += gSharePredictor(gshare2048_3bits, false, GHR, masks, 3, address);
          gShareCount4Bit += gSharePredictor(gshare2048_4bits, false, GHR, masks, 4, address);
          gShareCount5Bit += gSharePredictor(gshare2048_5bits, false, GHR, masks, 5, address);
          gShareCount6Bit += gSharePredictor(gshare2048_6bits, false, GHR, masks, 6, address);
          gShareCount7Bit += gSharePredictor(gshare2048_7bits, false, GHR, masks, 7, address);
          gShareCount8Bit += gSharePredictor(gshare2048_8bits, false, GHR, masks, 8, address);
          gShareCount9Bit += gSharePredictor(gshare2048_9bits, false, GHR, masks, 9, address);
          gShareCount10Bit += gSharePredictor(gshare2048_10bits, false, GHR, masks, 10, address);
          gShareCount11Bit += gSharePredictor(gshare2048_11bits, false, GHR, masks, 11, address);
          //TOURNAMENT PREDICTOR
          tournamentPredictor(selectorTable, bimodalTournament, gShareTournament, 2048, false, address, GHRTournament, maskTournament, 11);
        }
      }

      //WRITING TO OUTPUT FILE
        //Always taken
      fout << takenCount << "," << totalLines << ";" << endl;
      fout << notTakenCount << "," << totalLines << ";" << endl;
      fout << singleBit16Count << "," << totalLines << ";" << " " << singleBit32Count << "," << totalLines << ";" << " " << singleBit128Count << "," << totalLines << ";" << " " << singleBit256Count << "," << totalLines << ";" << " " << singleBit512Count << "," << totalLines << ";" << " " <<singleBit1024Count << "," << totalLines << ";" << " " << singleBit2048Count <<"," << totalLines << ";" << endl;
      fout << dualBit16Count << "," << totalLines <<";" << " " << dualBit32Count << "," << totalLines <<";" << " " << dualBit128Count << "," << totalLines <<";" << " " << dualBit256Count << "," << totalLines <<";" << " " << dualBit512Count<< "," << totalLines <<";" << " " << dualBit1024Count<< "," << totalLines <<";" << " " << dualBit2048Count << "," << totalLines <<";" << endl;
      fout << gShareCount3Bit << "," << totalLines << ";" << " " << gShareCount4Bit << "," << totalLines << ";" << " " << gShareCount5Bit<< "," << totalLines<< ";" << " " << gShareCount6Bit<< "," << totalLines<< ";" << " " << gShareCount7Bit << "," << totalLines<< ";" << " " << gShareCount8Bit<< "," << totalLines<< ";" << " " <<gShareCount9Bit<< "," << totalLines<< ";" << " " <<gShareCount10Bit<< "," << totalLines << ";" << " " <<gShareCount11Bit << ","  <<totalLines<<";"<<endl;
      fout << tournamentCounter << "," << totalLines << ";" << endl;
      //closing the input and output since we do not need it anymore
      input.close();
      fout.close();
    }

  }
  return 0;
}
//////////////////////////////INITIALIZERS//////////////////////////////////////////////////////////////
void singleBitInitializer(vector<int> &vec, int size){
  for(int i = 0; i < size; i++){
    vec[i] = 1;
  }
}
void dualBitInitializer(vector <int> & vec, int size){
  for(int i =0; i < size; i++){
    vec[i] = 3;
  }
}
void selectorInitializer(vector<int> & vec, int size){
  for(int i =0; i < size; i++){
    vec[i] = 0;
  }
}

//////////////////////////////PREDICTOR LOGIC/////////////////////////////////////////////////
                      //Single Bit Logic
int singleBitPredictor(vector<int> &vec, int size, bool outcome, unsigned long long address){
  //if outcome == true (taken)....if outcome == false(NT)
  int count = 0;
  if(outcome)  //if taken
  {
    if(vec[address % size] == 0) vec[address % size] = 1; //Misspredicted
    else if(vec[address % size] == 1) count ++;           //Predicted
  }
  else  //if outcome is false (NT)
  {
    if(vec[address % size] == 0) count++; //Predicted
    else if (vec[address % size] == 1) vec[address % size] = 0; //Misspredicted

  }
  return count;
}
                      //Dual Bit Logic
int dualBitPredictor(vector<int> &vec, int size, bool outcome, unsigned long long address){
  int count = 0;

  if(outcome) //Taken
  {
    if(vec[address % size] == 0 || vec[address % size] == 1)  //Misspredicted
    {
      if(vec[address % size] == 0) vec[address % size] = 1;
      else if(vec[address % size] == 1) vec[address % size] = 2;
    }
    else if(vec[address % size] == 2 || vec[address % size] == 3) //Predicted
    {
      if(vec[address % size] == 2) vec[address % size] = 3;
      else if (vec[address % size] == 3) vec[address % size] = 3;
      count++;
    }
  }
  else  //Not Taken
  {
    if(vec[address % size] == 0 || vec[address % size] == 1)  //Predicted
    {
      if(vec[address % size] == 0) vec[address % size] = 0;
      else if(vec[address % size] == 1) vec[address % size] = 0;
      count++;
    }
    else if(vec[address % size] == 2 || vec[address % size] == 3) //Misspredicted
    {
      if(vec[address % size] == 2) vec[address % size] = 1;
      else if (vec[address % size] == 3) vec[address % size] = 2;
    }
  }
  return count;
}
                       //Dual bit TOURNAMENT LOGIC
bool dualBitPredictorTour(vector<int> &vec, int size, bool outcome, unsigned long long address, bool prefers){
  bool flag = false;
  if(outcome) //Taken
  {
    if(vec[address % size] == 0 || vec[address % size] == 1)  //Misspredicted
    {
      if(vec[address % size] == 0) vec[address % size] = 1;
      else if(vec[address % size] == 1) vec[address % size] = 2;
      flag = false;
    }
    else if(vec[address % size] == 2 || vec[address % size] == 3) //Predicted
    {
      if(vec[address % size] == 2) vec[address % size] = 3;
      else if (vec[address % size] == 3) vec[address % size] = 3;
      if(prefers) tournamentCounter++;
      flag = true;
    }
  }
  else  //Not Taken
  {
    if(vec[address % size] == 0 || vec[address % size] == 1)  //Predicted
    {
      if(vec[address % size] == 0) vec[address % size] = 0;
      else if(vec[address % size] == 1) vec[address % size] = 0;
      if (prefers) tournamentCounter ++;
      flag = true;
    }
    else if(vec[address % size] == 2 || vec[address % size] == 3) //Misspredicted
    {
      if(vec[address % size] == 2) vec[address % size] = 1;
      else if (vec[address % size] == 3) vec[address % size] = 2;
      flag = false;
    }
  }
  return flag;
}

                      //GShare Predictor logic
int gSharePredictor(vector<int> & vec, bool outcome, int  GHR[], int mask[], int gshareBitSize, unsigned long long address)
{
  int count = 0;
  int indexM_GHR = 0;
  if(gshareBitSize == 3) indexM_GHR = 0;
  if(gshareBitSize == 4) indexM_GHR = 1;
  if(gshareBitSize == 5) indexM_GHR = 2;
  if(gshareBitSize == 6) indexM_GHR = 3;
  if(gshareBitSize == 7) indexM_GHR = 4;
  if(gshareBitSize == 8) indexM_GHR = 5;
  if(gshareBitSize == 9) indexM_GHR = 6;
  if(gshareBitSize == 10) indexM_GHR = 7;
  if(gshareBitSize == 11) indexM_GHR = 8;

  int extract = mask[indexM_GHR] & GHR[indexM_GHR];
  int index = (extract ^ (address%2048));

  if(outcome) //Taken
  {
    if(vec[index] == 0 || vec[index] == 1)  //Misspredicted
    {
      if(vec[index] == 0) vec[index] = 1;
      else if(vec[index] == 1) vec[index] = 2;
    }
    else if(vec[index] == 2 || vec[index] == 3) //Predicted
    {
      if(vec[index] == 2) vec[index] = 3;
      else if (vec[index] == 3) vec[index] = 3;
      count++;
    }
    GHR[indexM_GHR] = GHR[indexM_GHR]<< 1;
    GHR[indexM_GHR] +=1;
  }
  else  //Not Taken
  {
    if(vec[index] == 0 || vec[index]  == 1)  //Predicted
    {
      if(vec[index] == 0) vec[index] = 0;
      else if(vec[index] == 1) vec[index] = 0;
      count++;
    }
    else if(vec[index] == 2 || vec[index] == 3) //Misspredicted
    {
      if(vec[index] == 2) vec[index] = 1;
      else if (vec[index] == 3) vec[index] = 2;
    }
    GHR[indexM_GHR] = GHR[indexM_GHR]<< 1;

  }
  return count;
}
                        //GSHARE TOURNAMENT PREDICTOR LOGIC
bool gSharePredictorTour(vector<int> & vec, bool outcome, int  GHR[], int mask[], int gshareBitSize, unsigned long long address, bool prefers)
{
  bool flag = false;
  int indexM_GHR = 0;

  int extract = mask[indexM_GHR] & GHR[indexM_GHR];
  int index = (extract ^ (address%2048));

  if(outcome) //Taken
  {
    if(vec[index] == 0 || vec[index] == 1)  //Misspredicted
    {
      if(vec[index] == 0) vec[index] = 1;
      else if(vec[index] == 1) vec[index] = 2;
      flag = false;  //must be Not taken
    }
    else if(vec[index] == 2 || vec[index] == 3) //Predicted
    {
      if(vec[index] == 2) vec[index] = 3;
      else if (vec[index] == 3) vec[index] = 3;
      if(prefers) tournamentCounter++;
      flag = true;
    }
    GHR[indexM_GHR] = GHR[indexM_GHR]<< 1;  //shifts
    GHR[indexM_GHR] +=1;            //now adds one to least significatn bit
  }
  else  //Not Taken
  {
    if(vec[index] == 0 || vec[index]  == 1)  //Predicted
    {
      if(vec[index] == 0) vec[index] = 0;
      else if(vec[index] == 1) vec[index] = 0;
      flag = true;
      if (prefers) tournamentCounter++;
    }
    else if(vec[index] == 2 || vec[index] == 3) //Misspredicted
    {
      if(vec[index] == 2) vec[index] = 1;
      else if (vec[index] == 3) vec[index] = 2;
      flag = false;
    }
    GHR[indexM_GHR] = GHR[indexM_GHR] << 1;
  }
  return flag;
}

void tournamentPredictor(vector<int> & selectorTable, vector<int> & bimodalTournament, vector<int> & gShareTournament, int size, bool outcome, unsigned long long address,int GHRTournament[], int maskTournament [], int gshareBitSize)
{
  //Boolean values below will return T/F if it predicted correctly
  int index = address % size; //index for selector selectorTable
  if(outcome) //if taken
  {
    if(selectorTable[index] == 0)  //strongly GSHARE
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address, false);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, true);
      if(bimodal && !gshare) selectorTable[index] = 1;
    }
    else if(selectorTable[index] == 1)  //weak GShare
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address, false);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, true);
      if(bimodal && !gshare) selectorTable[index] = 2; //demoting
      else if(!bimodal && gshare) selectorTable[index] = 0; //promoting
    }
    else if(selectorTable[index] == 2)  //weakly bimodal
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address,true);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, false);
      if(bimodal && !gshare) selectorTable[index] = 3;  //promotion
      else if(!bimodal && gshare) selectorTable[index] = 1;  //demotion
    }
    else    //strongly bimodal
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address,true);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, false);
      if(!bimodal && gshare) selectorTable[index] = 2;  //demotion
    }
  }
  else    //NT
  {
    if(selectorTable[index] == 0)  //strongly GSHARE
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address, false);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, true);
      if(bimodal && !gshare) selectorTable[index] = 1;
    }
    else if(selectorTable[index] == 1)  //weak GShare
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address, false);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, true);
      if(bimodal && !gshare) selectorTable[index] = 2; //demoting
      else if(!bimodal && gshare) selectorTable[index] = 0; //promoting
    }
    else if(selectorTable[index] == 2)  //weakly bimodal
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address,true);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, false);
      if(bimodal && !gshare) selectorTable[index] = 3;  //promotion
      else if(!bimodal && gshare) selectorTable[index] = 1;  //demotion
    }
    else    //strongly bimodal
    {
      bool bimodal = dualBitPredictorTour(bimodalTournament, size, outcome, address,true);
      bool gshare = gSharePredictorTour(gShareTournament, outcome, GHRTournament, maskTournament, gshareBitSize, address, false);
      if(!bimodal && gshare) selectorTable[index] = 2;  //demotion
    }
  }
}
