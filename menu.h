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
class synapseGroup{
    public:
        synapseGroup();
        synapseGroup(int Number); //number means how many synapse there
        
        float synapse_run(); //preN to mp
        
    private:
        int how_many;
        //int PreN; //neurotransmitter number
        int *NS; //neurotransmitter sensitivity for each synapse
        float *NIMP; //MP increase per success neurontransmitter for each synapse
        
};

class neuron{
    public:
        neuron();
        neuron(int i);
        
        void set_synapseGroup(int synapseNumber, int neuronNumber); //set the group of synapse, number for the number of neuron(each to synapseGroups)
        
        void NeuronExe(); //time run
        void NeuronSave(); //open new neuron file
        void NeuronNote(int i); //output to txt
        void Neurontimepass(); //time pass decrease
        
        
    private:
        int name;
        int at; //at time

        synapseGroup *dendrite; //dendrite to connect each preNeuron (ex: neuron1 to neuron8, dendrite[0~7])
        //int *LtoB; //the time latency from synapse to body's axon
        
        float BMP; //membrane potential of the cell Body
        float TH; //threshold
        float BMPD; //membrane potential decrease of the cell Body
        int CD; //cool down
        
        bool OT; //success output
        int RN; //release neurotransmitter per time
        //int LtoS; //the time latency of the synapse junction
        int PND; //neurotransmitter number decrease
};

class neuronTag{
    public:
        neuronTag();
        neuronTag(int number);
        int idcounter;
        neuron *NT;

        void set_ID(int i);
        void gen_NT();
    private:
};

#include "neuron.cpp"
#include "neuronTag.cpp"
#include "synapseGroup.cpp"
