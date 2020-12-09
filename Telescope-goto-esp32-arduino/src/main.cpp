// Excectued, when compiled on the computer
// Will start a local TCP Server
#ifdef dev

void setup();
void loop();

int main(int argc, char const *argv[]){
    setup();
    while (true){
        loop();
    }
    
    return 0;
}

#else


#endif