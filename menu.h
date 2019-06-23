#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <ctime> //include time. clock()
#include <fstream>
#include <string.h>
//#include <time.h>
#include <iomanip> //for setw to arrange word
using namespace std;
//data name
char output[15] = "neuron";
char format[] = ".txt";
char datanumber[4];
fstream test;
//int atoi(const char * str);
class neuron{
    public:
        neuron();
        neuron(int i);
        
        int name;
        int CD; //cool down
        int TH; //threshold
        int at; //at time
        int MP; //membrane potential
        int MPD; //membrane potential decrease
        int PND; //neurotransmitter decrease
        int RN; //release neurotransmitter per time
        int OT; //success output
        
        int NS; //neurotransmitter sensitivity
        int PreN; //neurotransmitter number
        
        
        void NeuronExe(); //time run
        void NeuronSave(); //open new neuron file
        void NeuronNote(int i); //output to txt
        void Neurontimepass(); //time pass decrease
         
    private:
    
    
};

class neuronTag{
    public:
        neuronTag();
        neuronTag(int i);
        int idcounter;
        neuron * NT;

        void set_ID(int i);
        void gen_NT();
    private:
};

#include "neuron.cpp"
#include "neuronTag.cpp"
