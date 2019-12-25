
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <deque>
using namespace std;


class Node {
  public:
      Node* parent;
      Node* left;
      Node* right;
      bool  pathLeft;
      unsigned long long value;

      Node(){
        parent = NULL;
        left = NULL;
        right = NULL;
        pathLeft = true;  //left = hot, right = cold
        value = 0;
      }
};


/*Global Variables*/
int associativity = 2;

/** DirectMapped functions **/
void directMappedInit(int entries, unsigned long long directCache []);
int directMapped(unsigned long long directCache[], int indexD, int cacheEntries, unsigned long long &tagDirect, unsigned long long addr);

/** SetAssociative functions **/
void setAssocInit(vector<deque<unsigned long long int>>& setAssocCache, int cacheRows);
int setAssociative(vector<deque<unsigned long long int>>& setAssocCache, int cacheRows, unsigned long long addr, bool store, bool nextLinePref, bool nextLinePrefCacheMiss);

/** PLRU Tree Functions **/
Node* createSubtree(vector<Node*>& valuesRow, const int& depth, Node* parent);
int FullyAssocCachePLRU(Node * head, vector<Node*> & valuesRow, unsigned long long addr);


int main(int argc, char *argv[])
{
  if(argc != 3){
     cout << "Incorrect number of inputs, please provide an input file and the name of an output file.\n";
     exit(-1);
   }
  string inputF = argv[1];
  string outputF = argv[2];

  unsigned long long addr;
  string instruction, line;
  double total = 0;

  /** Direct mapped initialization **/
  int hitD1KB = 0;
  int hitD4KB = 0;
  int hitD16KB = 0;
  int hitD32KB = 0;
  //Total Cache / cacheLineSize
  int cacheEntries1KB = 32;
  int cacheEntries4KB = 128;
  int cacheEntries16KB = 512;
  int cacheEntries32KB = 1024;

  int indexD1KB = 0;
  int indexD4KB = 0;
  int indexD16KB = 0;
  int indexD32KB = 0;

  unsigned long long tagDirect1KB =0;
  unsigned long long tagDirect4KB =0;
  unsigned long long tagDirect16KB =0;
  unsigned long long tagDirect32KB =0;

  unsigned long long directCache1KB [32];
  unsigned long long directCache4KB [128];
  unsigned long long directCache16KB [512];
  unsigned long long directCache32KB [1024];

  directMappedInit(cacheEntries1KB, directCache1KB);
  directMappedInit(cacheEntries4KB, directCache4KB);
  directMappedInit(cacheEntries16KB, directCache16KB);
  directMappedInit(cacheEntries32KB, directCache32KB);

  /** Set associative initialization **/
  int hitSA2w = 0;
  int hitSA4w = 0;
  int hitSA8w = 0;
  int hitSA16w = 0;
  // Total Cache/(ways x cache line size)
  int cacheRows2W = 256;
  int cacheRows4W = 128;
  int cacheRows8W = 64;
  int cacheRows16W = 32;

  vector <deque<unsigned long long int>> setAssocCache2W;
  vector <deque<unsigned long long int>> setAssocCache4W;
  vector <deque<unsigned long long int>> setAssocCache8W;
  vector <deque<unsigned long long int>> setAssocCache16W;

  setAssocInit(setAssocCache2W, cacheRows2W);
  associativity = 4;
  setAssocInit(setAssocCache4W, cacheRows4W);
  associativity = 8;
  setAssocInit(setAssocCache8W, cacheRows8W);
  associativity = 16;
  setAssocInit(setAssocCache16W, cacheRows16W);

  /** Fully associative initialization **/
  int FullyAssocCacheRows = 1;
  int hitFA_LRU = 0;
  vector <deque<unsigned long long int>> FullyAssocCache;

  associativity = 512;
  setAssocInit(FullyAssocCache, FullyAssocCacheRows);

  /** Tree PLRU **/
  Node * head = NULL;
  vector<Node*> valuesRow; //The final (bottom) row that holds all of our values
  int hitTree_PLRU = 0;
  head = createSubtree(valuesRow, 10, NULL);

  /** Set associative initialization with LOAD and Store **/
  int hitSA_S_L2w = 0;
  int hitSA_S_L4w = 0;
  int hitSA_S_L8w = 0;
  int hitSA_S_L16w = 0;

  vector <deque<unsigned long long int>> setAssocCacheL_S2W;
  vector <deque<unsigned long long int>> setAssocCacheL_S4W;
  vector <deque<unsigned long long int>> setAssocCacheL_S8W;
  vector <deque<unsigned long long int>> setAssocCacheL_S16W;

  associativity = 2;
  setAssocInit(setAssocCacheL_S2W, cacheRows2W);
  associativity = 4;
  setAssocInit(setAssocCacheL_S4W, cacheRows4W);
  associativity = 8;
  setAssocInit(setAssocCacheL_S8W, cacheRows8W);
  associativity = 16;
  setAssocInit(setAssocCacheL_S16W, cacheRows16W);


  /** Set associative initialization with Next Line Prefetching **/
  int hitSA_NLP_2w = 0;
  int hitSA_NLP_4w = 0;
  int hitSA_NLP_8w = 0;
  int hitSA_NLP_16w = 0;

  vector <deque<unsigned long long int>> setAssocCache_NLP_2W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_4W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_8W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_16W;

  associativity = 2;
  setAssocInit(setAssocCache_NLP_2W, cacheRows2W);
  associativity = 4;
  setAssocInit(setAssocCache_NLP_4W, cacheRows4W);
  associativity = 8;
  setAssocInit(setAssocCache_NLP_8W, cacheRows8W);
  associativity = 16;
  setAssocInit(setAssocCache_NLP_16W, cacheRows16W);

  /** Set associative initialization with Next Line Prefetching Cache Miss **/
  int hitSA_NLP_CACHE_MISS_2w = 0;
  int hitSA_NLP_CACHE_MISS_4w = 0;
  int hitSA_NLP_CACHE_MISS_8w = 0;
  int hitSA_NLP_CACHE_MISS_16w = 0;

  vector <deque<unsigned long long int>> setAssocCache_NLP_CACHE_MISS_2W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_CACHE_MISS_4W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_CACHE_MISS_8W;
  vector <deque<unsigned long long int>> setAssocCache_NLP_CACHE_MISS_16W;

  associativity = 2;
  setAssocInit(setAssocCache_NLP_CACHE_MISS_2W, cacheRows2W);
  associativity = 4;
  setAssocInit(setAssocCache_NLP_CACHE_MISS_4W, cacheRows4W);
  associativity = 8;
  setAssocInit(setAssocCache_NLP_CACHE_MISS_8W, cacheRows8W);
  associativity = 16;
  setAssocInit(setAssocCache_NLP_CACHE_MISS_16W, cacheRows16W);


  /** Reading Trace Files **/
  ifstream input(inputF.c_str());
  if(input.is_open()){
    ofstream fout(outputF.c_str());
    while(getline(input, line))
    {
      stringstream ss(line);
      ss>>instruction>>std::hex>>addr;
      total++;

      //** Diredt Mapped Cache Simulation **//
      hitD1KB += directMapped(directCache1KB, indexD1KB, cacheEntries1KB, tagDirect1KB, addr);
      hitD4KB += directMapped(directCache4KB, indexD4KB, cacheEntries4KB, tagDirect4KB, addr);
      hitD16KB += directMapped(directCache16KB, indexD16KB, cacheEntries16KB, tagDirect16KB, addr);
      hitD32KB += directMapped(directCache32KB, indexD32KB, cacheEntries32KB, tagDirect32KB, addr);

      //** Set Associative Cache Simulation **//
      associativity = 2;
      hitSA2w += setAssociative(setAssocCache2W, cacheRows2W, addr, false, false, false);
      associativity = 4;
      hitSA4w += setAssociative(setAssocCache4W, cacheRows4W, addr, false, false, false);
      associativity = 8;
      hitSA8w += setAssociative(setAssocCache8W, cacheRows8W, addr, false, false, false);
      associativity = 16;
      hitSA16w += setAssociative(setAssocCache16W, cacheRows16W, addr, false, false, false);


      /** Fully Associative Cache Simulation **/
      associativity = 512;
      hitFA_LRU += setAssociative(FullyAssocCache, FullyAssocCacheRows, addr, false, false, false);

      /** PLRU **/
      hitTree_PLRU += FullyAssocCachePLRU(head, valuesRow, addr);

      /** Set Associative Cache Simulation with store and load **/
      int store = false;
      if (instruction == "S") store = true;
      associativity = 2;
      hitSA_S_L2w += setAssociative(setAssocCacheL_S2W, cacheRows2W, addr, store, false, false);
      associativity = 4;
      hitSA_S_L4w += setAssociative(setAssocCacheL_S4W, cacheRows4W, addr, store, false, false);
      associativity = 8;
      hitSA_S_L8w += setAssociative(setAssocCacheL_S8W, cacheRows8W, addr, store, false, false);
      associativity = 16;
      hitSA_S_L16w += setAssociative(setAssocCacheL_S16W, cacheRows16W, addr, store, false, false);
      store = false;

      /** Set Associative Cache Simulation with Next Line Prefetching **/
      associativity = 2;
      hitSA_NLP_2w += setAssociative(setAssocCache_NLP_2W, cacheRows2W, addr, store, true, false);
      associativity = 4;
      hitSA_NLP_4w += setAssociative(setAssocCache_NLP_4W, cacheRows4W, addr, store, true, false);
      associativity = 8;
      hitSA_NLP_8w += setAssociative(setAssocCache_NLP_8W, cacheRows8W, addr, store, true, false);
      associativity = 16;
      hitSA_NLP_16w += setAssociative(setAssocCache_NLP_16W, cacheRows16W, addr, store, true, false);

      /** Set Associative Cache Simulation with Next Line Prefetching on Cache MISS**/
      associativity = 2;
      hitSA_NLP_CACHE_MISS_2w += setAssociative(setAssocCache_NLP_CACHE_MISS_2W, cacheRows2W, addr, store, false, true);
      associativity = 4;
      hitSA_NLP_CACHE_MISS_4w += setAssociative(setAssocCache_NLP_CACHE_MISS_4W, cacheRows4W, addr, store, false, true);
      associativity = 8;
      hitSA_NLP_CACHE_MISS_8w += setAssociative(setAssocCache_NLP_CACHE_MISS_8W, cacheRows8W, addr, store, false, true);
      associativity = 16;
      hitSA_NLP_CACHE_MISS_16w += setAssociative(setAssocCache_NLP_CACHE_MISS_16W, cacheRows16W, addr, store, false, true);

    }

    /** Writing to file **/
    fout << std::fixed << std::setprecision(0)<< hitD1KB << "," << total <<"; " << hitD4KB << "," << total << "; " << hitD16KB << "," << total <<"; "<< hitD32KB << "," << total<<";\n";
    fout << hitSA2w << "," << total << "; " << hitSA4w << "," << total << "; "<< hitSA8w << "," << total << "; "<< hitSA16w << "," << total << ";\n";
    fout << hitFA_LRU << "," << total << ";\n";   //fully associative LRU replacement
    fout << hitTree_PLRU << "," << total << ";\n";
    fout << hitSA_S_L2w << "," << total << "; " << hitSA_S_L4w << "," << total << "; " << hitSA_S_L8w << "," << total << "; " << hitSA_S_L16w << "," << total << ";\n";
    fout << hitSA_NLP_2w << "," << total << "; " << hitSA_NLP_4w << "," << total << "; " << hitSA_NLP_8w << "," << total << "; " << hitSA_NLP_16w << "," << total << ";\n";
    fout << hitSA_NLP_CACHE_MISS_2w << "," << total << "; " << hitSA_NLP_CACHE_MISS_4w << "," << total << "; " << hitSA_NLP_CACHE_MISS_8w << "," << total << "; " << hitSA_NLP_CACHE_MISS_16w << "," << total << ";\n";
  }
  else cout << "File not found!/n";
  return 0;
}



////////////**DIRECT MAPPED FUNCTION DEFINITIONS**/////////////////
void directMappedInit(int entries, unsigned long long directCache[])
{
  for(int i = 0; i < entries; i++)
    directCache[i] = 0;
}
int directMapped(unsigned long long directCache[], int indexD, int cacheEntries, unsigned long long &tagDirect, unsigned long long addr)
{
  //This will get us the index to index into
  indexD = (addr >> 5) % cacheEntries;
  tagDirect = addr>>((unsigned long long)(log2(cacheEntries)) + 5);
  if(directCache[indexD] == tagDirect) return 1;  //Hit
  else directCache[indexD] = tagDirect;           //Miss
  return 0;
}

//////////////** SETASSOCIATIVE FUNCTION DEFINITIONS **//////////////////////////////
void setAssocInit(vector<deque<unsigned long long int>>& setAssocCache, int cacheRows){
  for (int i = 0; i < cacheRows; i++)
  {
    deque<unsigned long long int > line;
    for(int j = 0; j < associativity; j++)  line.push_back(0);
    setAssocCache.push_back(line);
  }
}

int setAssociative(vector<deque<unsigned long long int>>& setAssocCache, int cacheRows, unsigned long long addr, bool store, bool nextLinePref, bool nextLinePrefCacheMiss){
  int setInd = (addr >> 5) % cacheRows;
  unsigned long long tag = addr >> ((unsigned long long)(log2(cacheRows) + 5));
  bool found = false;

  //linePreFetch
  unsigned long long nextAddress;
  int nextSetInd;
  unsigned long long nextTag;

  if(nextLinePref || nextLinePrefCacheMiss)
  {
     nextAddress = addr + 32;
     nextSetInd = (nextAddress >> 5) % cacheRows;
     nextTag = nextAddress >> ((unsigned long long)(log2(cacheRows) + 5));
  }

  //Lets look for the tag in set
  for(int i =0; i <  associativity; i++)
  {
    if(setAssocCache[setInd][i] == tag) //hit
    {
      //we will be moving the most recently used to the front of the set to mantain our LRU (oldest goes on back)
      setAssocCache[setInd].erase(setAssocCache[setInd].begin()+i);
      setAssocCache[setInd].push_front(tag);
      found = true;
      if(!nextLinePref || nextLinePrefCacheMiss) return 1;
    }
  }
  if (found == false) //Miss
  {
    if(!store){
    setAssocCache[setInd].pop_back(); //oldest
    setAssocCache[setInd].push_front(tag);  //insert new at front
    }

    /** THIS WILL EXECUTE ONLY WHEN NLP ON CACHE MISSES IS SET TO TRUE **/
    if(nextLinePrefCacheMiss)
    {
      //if its nextLinePref and it was a hit save the hit value to return.
      /**Next line**/
      found = false;
      for(int i =0; i <  associativity; i++)
      {
        if(setAssocCache[nextSetInd][i] == nextTag) //hit
        {
          //we will be moving the most recently used to the front of the set to mantain our LRU (oldest goes on back)
          setAssocCache[nextSetInd].erase(setAssocCache[nextSetInd].begin()+i);
          setAssocCache[nextSetInd].push_front(nextTag);
          found = true;
        }
      }
      if (found == false) //miss
      {
        setAssocCache[nextSetInd].pop_back(); //oldest
        setAssocCache[nextSetInd].push_front(nextTag);  //insert new at front
      }
      return 0;       //if both misses then return nothing
    }
  }
  if(!nextLinePref) return 0;


  //if its nextLinePref and it was a hit save the hit value to return.
  int val = 0;
  if(found == true) val = 1; //hit value.

  /**Next line**/
  found = false;
  for(int i =0; i <  associativity; i++)
  {
    if(setAssocCache[nextSetInd][i] == nextTag) //hit
    {
      //we will be moving the most recently used to the front of the set to mantain our LRU (oldest goes on back)
      setAssocCache[nextSetInd].erase(setAssocCache[nextSetInd].begin()+i);
      setAssocCache[nextSetInd].push_front(nextTag);
      found = true;
    }
  }
  if (found == false) //miss
  {
    setAssocCache[nextSetInd].pop_back(); //oldest
    setAssocCache[nextSetInd].push_front(nextTag);  //insert new at front
  }
  if(val) return 1; //returning the hit value saved before if it was a hit
  return 0;       //if both misses then return nothing
}


//////////** PLRU FUNCTION DEFINITIONS **////
Node* createSubtree(vector<Node*>& valuesRow, const int& depth, Node* parent)
{
  Node * node = new Node();
  node->parent = parent;
  if(depth == 1){
    valuesRow.push_back(node);
    return node;
  }
  //else
  node->left = createSubtree(valuesRow, depth - 1, node);
  node->right = createSubtree(valuesRow, depth - 1, node);
  return node;
}

int FullyAssocCachePLRU(Node * head, vector<Node*> & valuesRow, unsigned long long addr)
{
  unsigned long long  tag = addr >> 5; //since no index bits then everything but the offset is the tag
  bool found = false;

  //lets check if its already in the array (hit)
  for(int i = 0; i < valuesRow.size(); i++)
  {
    if(valuesRow[i]->value == tag)
    {
      found = true;
      Node* current = valuesRow[i];
      Node * tempNode = valuesRow[i]->parent;
      while(tempNode != NULL)
      { //inverting the bits
        if(tempNode->left == current && tempNode->pathLeft == true) tempNode->pathLeft = false;
        if(tempNode->right == current && tempNode->pathLeft == false) tempNode->pathLeft = true;

        //going backwards changing bits
        current = tempNode;
        tempNode = tempNode ->parent;
      }
      return 1;
    }
  }

  //not in the array (miss)
  if(!found)
  {
    Node * current = head;
    Node * next = NULL;
    Node * copy = NULL;

    while(current != NULL)
    {
      copy = current;
      //traversing the tree following the hot or cold path
      if(current->pathLeft) next = current->left;
      else if(!current->pathLeft)  next = current->right;

      //updating our path values, if it was true before, set it to false...vice versa
      if(current->pathLeft) current->pathLeft = false;
      else if(!current->pathLeft) current->pathLeft = true;

      current = next;
    }
    copy->value = tag;  //updating the LRU
  }
  return 0;

}
