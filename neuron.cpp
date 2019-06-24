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
    SG = 0;
    
    BMP = rand()%100;
    TH = rand()%100; //rand()%100
    BMPD = rand()%D;
    CD = rand()%C;
    
    axon = 1;
    OT = 0;
    RN = rand()%Y;
    PN = OT * RN;
    PND = rand()%X;
}

void neuron::set_name(int i){
    name = i;
}

void neuron::set_CD(int i){
    CD = i;
}

void neuron::set_TH(float i){
    TH = i;
}

void neuron::set_PN(int i){
    PN = i;
}

void neuron::set_PND(int i){
    PND = i;
}

void neuron::set_BMPD(float i){
    BMPD = i;
}

void neuron::set_RN(int i){
    RN = i;
}

void neuron::set_synapseGroup(int dendriteNumber){
    SG = dendriteNumber;
    axon = dendriteNumber;
    dendrite = new synapseGroup [SG];
}

int neuron::get_at(){
    return at;
}

bool neuron::get_OT(){
    return OT;
}

int neuron::get_RN(){
    return RN;
}

int neuron::get_PN(){
    return PN;
}

int neuron::getsynapsePN(){
    return PN / axon;
}

void neuron::NeuronExe(){
    float Nsum = 0;
    for(int i = 0; i < SG; i++){
        Nsum = Nsum + dendrite[i].synapse_run();
    }
    BMP = BMP + Nsum;
    if(BMP > TH){
        at = at + CD;
        OT = 1;
        BMP = BMP - TH;
        PN = OT * RN;
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
        test << "neurotransmitter sensitivity = " << "" << endl;
        test << "synape junction recycle = " << PND << endl;
        test << "membrane potential decrease = " << BMPD << endl;
        test << "neurotransmitter per bubble = " << RN << endl;
        test << endl;
        test << "time   MP PreN" << endl;
        test << "---- " << setw(4) << BMP << " " << setw(4) << PN << endl; 
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
    test << setw(4) << i << " " << setw(4) << BMP << " " << setw(4) << PN << endl;
    test.close();
}

void neuron::Neurontimepass(){
    if(BMP > BMPD){
        BMP = BMP - BMPD;
    }else{
        BMP = 0;
    }
    if(PN > PND){
        PN = PN - PND;
    }else{
        PN = 0;
    }
}
