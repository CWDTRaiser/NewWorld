neuronTag::neuronTag(){
    idcounter = 0;
    NT = NULL;
}
/*
neuronTag::neuronTag(int number){
    ;
    NT = new neuron(id);  
}
*/
void neuronTag::set_ID(int id){
    idcounter = id;
}

void neuronTag::gen_NT(){
    NT = new neuron(idcounter);
}

