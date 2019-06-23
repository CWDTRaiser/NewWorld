/*
neuron::neuron(){
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
*/
neuron::neuron(int i){
    //initialize neuron    
    name = i;
    at = 0;
    
    dendrite = NULL;
    
    BMP = rand()%100;
    TH = rand()%100; //rand()%100
    BMPD = rand()%D;
    CD = rand()%C;

    OT = 0;
    RN = rand()%Y;
    PND = rand()%X;
}

void neuron::set_synapseGroup(int neuronNumber){
    dendrite = new synapseGroup [neuronNumber];
    for(int i = 0; i < neuronNumber; i++){
        dendrite[i].
    }
}

void neuron::NeuronExe(){
    
    if(BMP > TH){
        at = at + CD;
        OT = 1;
        BMP = BMP - TH;
        
        //test.open("log", ios::app);
        //test << "neuron" << name << " fire!! at time " << at << endl;
        //test.close();
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
