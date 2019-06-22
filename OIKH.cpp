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
int atoi(const char * str);
//parameter
//PND
int X = 1;
//RN
int Y = 10;
//membrane potential increase per neurotransmitter
int Z = 100;
//CD
int C = 10;
//MPD
int D = 5;
//data name
char output[15] = "neuron";
char format[] = ".txt";
char datanumber[4];

fstream test;


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

//-------------------------
neuron::neuron(){
    cout << "error in creating neuron" << endl;
    CD = rand()%C;
    TH = rand()%100;
    NS = rand()%100;
    at = 0;
    MP = rand()%100;
    MPD = rand()%D;
    PreN = 0;
    PND = rand()%X;
    RN = rand()%Y;
    OT = 0;    
}

neuron::neuron(int i){
    //initialize neuron    
    name = i;
    CD = rand()%C;
    TH = rand()%100;
    NS = rand()%100;
    at = 0;
    MP = rand()%100;
    MPD = rand()%D;
    PreN = 0;
    PND = rand()%X;
    RN = rand()%Y;
    OT = 0;
}

void neuron::NeuronExe(){
    
    for(int Ni = 0; Ni < PreN; Ni++){
        int rate = rand()%100;    
        if(NS >= rate){
            MP = MP + Z;
        }
    }
    if(MP > TH){
        test.open("log", ios::app);
        test << "neuron" << name << " fire!! at time " << at << endl;
        test.close();
        at = at + CD;
        OT = 1;
        MP = MP - TH;
    }else{
        at = at + 1;
    }
    
}

void neuron::NeuronSave(){
    char tempput[15] = "";
    sprintf(datanumber, "%d", name);
    strcat(tempput, output);
    strcat(tempput, datanumber);
    strcat(tempput, format);
    test.open(tempput, ios::out);
    if(test.is_open()){
        test << "neuron number " << name << endl;
        test << "CD time = " << CD << endl;
        test << "Threshold = " << TH << endl;
        test << "neurotransmitter sensitivity = " << NS << endl;
        test << "synape junction recycle = " << PND << endl;
        test << "membrane potential decrease = " << MPD << endl;
        test << "neurotransmitter per bubble = " << RN << endl;
        test << endl;
        test << "time   MP PreN" << endl;
        test << "---- " << setw(4) << MP << " " << setw(4) << PreN << endl; 
        test.close();
        cout << "neuron" << name << " saved" << endl;
    }else{
        cout << "neuron" << name << " can not save!" << endl;
    }
}

void neuron::NeuronNote(int i){
    char tempput[15] = "";
    sprintf(datanumber, "%d", name);
    strcat(tempput, output);
    strcat(tempput, datanumber);
    strcat(tempput, format);
    test.open(tempput, ios::app);
    test << setw(4) << i << " " << setw(4) << MP << " " << setw(4) << PreN << endl;
    test.close();
}

void neuron::Neurontimepass(){
    if(MP > MPD){
        MP = MP - MPD;
    }else{
        MP = 0;
    }
    if(PreN > PND){
        PreN = PreN - PND;
    }else{
        PreN = 0;
    }
}
//--------------------
neuronTag::neuronTag(){
    idcounter = 0;
    NT = NULL;
}
/*
neuronTag::neuronTag(int id){
    idcounter = id;
    NT = new neuron(id);  
}
*/
void neuronTag::set_ID(int id){
    idcounter = id;
}

void neuronTag::gen_NT(){
    NT = new neuron(idcounter);
}

//---------------------
/*
collectTag::collectTag(int i){
    CTagid = i;
}
*/
//---------------------
map<int, neuronTag> Tag;

void check_preNeuron(){
    
}

void gen_neuron(int i){
    neuronTag *collect = NULL;
    collect = new neuronTag [i];
    
    for(int id = 1; id < i + 1; id++){
        collect[id].set_ID(id);
        collect[id].gen_NT();
        collect[id].NT -> NeuronSave();
        Tag.insert(pair<int, neuronTag>(id,collect[id]));
    }

}

string Nread_word(int number){
    string temp_buffer = "";
    for(int i = 0; i < number; i++){
        test >> temp_buffer;
    }
    return temp_buffer;
    //number is the thread of word
}

int get_neuron_check(){
    int tempN = 1;
    int neuronNumber = 0;
    for(int i = 0; i < 1; i++){
        string buffer;
        char tempput[15] = "";
        sprintf(datanumber, "%d", tempN);
        strcat(tempput, output);
        strcat(tempput, datanumber);
        strcat(tempput, format);
        test.open(tempput);
        if(test.is_open()){
            i = i - 1;
            neuronNumber = neuronNumber + 1;
            
            //cout << "check" ;
        }else{
            //cout << "note" << tempN << " no such file" << endl;
        }
        test.close();
        tempN = tempN + 1;
    }
    return neuronNumber;
}

void get_neuron(){
    int neuronNumber = get_neuron_check();
    neuronTag *collect = NULL;
    collect = new neuronTag [neuronNumber];
    //temp
    for(int i = 1/*need to change to log*/; i < neuronNumber + 1; i++){
        collect[i].NT = new neuron(i); 
        Tag.insert(pair<int, neuronTag>(i,collect[i]));
        char tempput[15] = "";
        sprintf(datanumber, "%d", i);
        strcat(tempput, output);
        strcat(tempput, datanumber);
        strcat(tempput, format);
        
        test.open(tempput, ios::in);
        Tag[i].NT -> name = atoi(Nread_word(3).c_str());
        Tag[i].NT -> CD = atoi(Nread_word(4).c_str());
        Tag[i].NT -> TH = atoi(Nread_word(3).c_str());
        Tag[i].NT -> NS = atoi(Nread_word(4).c_str());
        Tag[i].NT -> PND = atoi(Nread_word(5).c_str());
        Tag[i].NT -> MPD = atoi(Nread_word(5).c_str());
        Tag[i].NT -> RN = atoi(Nread_word(5).c_str());
        
        test.close();
    }
} 


int main(){
    srand(time(NULL));
    string temp_input;
    
    
    //initialization of neuron
    double START, END;
    START = clock();
    cout << get_neuron_check();
    if(get_neuron_check() != 0){
        cout << "!=0" << endl;
        get_neuron();
    }else{
        cout << "==0" << endl;
        gen_neuron(8);    
    }
    END = clock();
    
    //check log and get log
    test.open("log");
    if(test.is_open()){
    
    }else{
        test.open("log", ios::out);
        test << 0 << endl;
        test.close();
    }
    ifstream read("log", ios::in);
    read >> temp_input;
    read.close();
    int pastlog = atoi(temp_input.c_str());
    temp_input = "";
    /*
    cout << pastlog << endl;
    test.open("log", ios::out);
    test << "HAHAHA" << endl;
    test << pastlog << endl;
    test.close();
    */

    for(int i = pastlog; i < pastlog + 100; i++){
        for(int j = 1; j < 9; j++){
            if(Tag[j].NT -> at == i){
                Tag[j].NT -> NeuronExe();
                if(j == 8){
                    Tag[1].NT -> PreN = Tag[1].NT -> PreN + (Tag[j].NT -> OT) * (Tag[j].NT -> RN );
                }else{
                    Tag[j+1].NT -> PreN = Tag[j+1].NT -> PreN + (Tag[j].NT -> OT) * (Tag[j].NT -> RN );
                }
            }

            Tag[j].NT -> NeuronNote(i);
            Tag[j].NT -> Neurontimepass();
        }
    }
    /*
    test.open("log", ios::out | ios::app);
    test << pastlog << endl;
    test.close();
    */
    cout << (double)clock()/CLOCKS_PER_SEC << " s" << endl;
    cout << (END-START)/1000000 << " s" << endl;
    return 0;
}
