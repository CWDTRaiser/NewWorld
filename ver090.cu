//PND
#define X 1
//RN
#define Y 10
//membrane potential increase per neurotransmitter
#define Z 100
//CD
#define C 10
//MPD
#define D 5
#include <cuda_runtime.h>
#include "menu.h"
using namespace std;

map<int, neuronTag> Tag;
/*
void check_preNeuron(){
    
}
*/
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
