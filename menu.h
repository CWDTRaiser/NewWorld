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
 
        void set_PreN();
        float synapse_run(); //preN to mp
        void synapse_timepass();
        
    private:
        int idn; //the correlate neuron number
        int how_many;
        
        int PreN; //neurotransmitter number
        int *NS; //neurotransmitter sensitivity for each synapse
        float *NIMP; //MP increase per success neurontransmitter for each synapse
        
};

class neuron{
    public:
        neuron();
        neuron(int i);
        
        void set_name(int i);
        void set_CD(int i);
        void set_TH(float i);
        void set_PN(int i);
        void set_PND(int i);
        void set_BMPD(float i);
        void set_RN(int i);
        void set_synapseGroup(int dendriteNumber); //set the group of synapse, number for the number of neuron(each to synapseGroups)
        //void setPN();
        int get_at();
        bool get_OT();
        int get_RN();        
        int get_PN();
        int getsynapsePN();
        
        void NeuronExe(); //time run
        void Neurontimepass(); //time pass decrease
        
        void NeuronSave(); //open new neuron file
        void NeuronNote(int i); //output to txt
        
        
        
    private:
        int name;
        int at; //at time

        synapseGroup *dendrite; //dendrite to connect each preNeuron (ex: neuron1 to neuron8, dendrite[0~7])
        int SG; //Number of dendrite
        //int *LtoB; //the time latency from synapse to body's axon
        
        float BMP; //membrane potential of the cell Body
        float TH; //threshold
        float BMPD; //membrane potential decrease of the cell Body
        int CD; //cool down
        
        int axon; //how many axons
        bool OT; //success output
        int RN; //release neurotransmitter per time
        int PN; //post neuron meurotransmitter
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
map<int, neuronTag> Tag;

#include "neuron.cpp"
#include "neuronTag.cpp"
#include "synapseGroup.cpp"
