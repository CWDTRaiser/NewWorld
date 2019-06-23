synapseGroup::synapseGroup(){
    how_many = 100;
    NS = new int [how_many]; //default synapse number is 100
    NIMP = new int [how_many];
}    
    
synapseGroup::synapseGroup(int Number){
    how_many = Number;
    NS = new int [how_many];
    for(int i = 0; i < how_many; i++){
        NS[i] = rand()%100;
    }
    NIMP = new int [how_many];
    for(int i = 0; i < how_many; i++){
        NIMP[i] = rand()%100;
    }
}    
/*    
float synapse_run(){
    for(int Ni = 0; Ni < PreN; Ni++){
        int rate = rand()%100;    
        if(NS >= rate){
            MP = MP + Z;
        }
    }
}    
*/    
