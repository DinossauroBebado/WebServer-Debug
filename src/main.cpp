
#include<webDebuger.h>

int outputState[5] ;
char variNames[31][32] = {"VAR 0","VAR 1","VAR 2"};
int var = 0;



void setup() {

Serial.begin(115200);
setupWebDebuger(false);
outputState[0] = 0 ;
outputState[1] = 1 ;
  
}

void loop(){
var = var + 1 ;
if(var>100){
    var = 0;
}
outputState[2] = var;
loopDebuger(outputState,variNames);
}

//TO DO 
// passa arguments to setup adn loop 