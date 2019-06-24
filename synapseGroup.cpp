synapseGroup::synapseGroup(){
    idn = 0;
    how_many = 100;
    NS = new int [how_many]; //default synapse number is 100
    NIMP = new float [how_many];
}    
    
synapseGroup::synapseGroup(int Number){
    idn = 0;
    how_many = Number;
    NS = new int [how_many];
    for(int i = 0; i < how_many; i++){
        NS[i] = rand()%100;
    }
    NIMP = new float [how_many];
    for(int i = 0; i < how_many; i++){
        NIMP[i] = rand()%100;
    }
}    

void synapseGroup::set_PreN(){
    PreN = Tag[idn].NT -> getsynapsePN();
}
    
float synapseGroup::synapse_run(){
    float sum = 0;
    for(int i = 0; i < how_many; i++){
        for(int j = 0; j < PreN; j++){
            int rate = rand()%100;    
            if(NS[i] >= rate){
                sum = sum + NIMP[i];
            }
        }
    }
    return sum;
}
/*
void synapseGroup::synapse_timepass(){
    if()
}
*/
/*__global__ synapse_run(){
    int i = threadIdx.x;
    int rate = rand()%100;
    if(NS[i] >= rate){
        retrun NIMP[i];
    }
}
*/
