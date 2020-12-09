// Wird ausgeführt, wenn das Programm auf einem PC ausgeführt wird.
// Startet einen localen TCP Server
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