#include "src/Core.h"

Core *system;

void start() {
    Serial.begin(115200);
    *system = new Core(&Serial);
}

void loop() {
    system->runMainThread();
}