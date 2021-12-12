/*
Aaron Hickman 12/12/2021
Version 1.4

Board: Arduino Pro Micro or Leonardo

*/


#include <Keyboard.h>

#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT  0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL  0x84
#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_ENTER       0xB0
#define KEY_ESC         0xB1
#define KEY_CAPS_LOCK   0xC1

int modeSwitch = 6; //pin used to read state of mode switch. prevents keyboard from typing when user is trying to flash with update.
int buttonOne = 9;
int buttonTwo = 8;
int buttonThree = 7;



//Runs once at boot to start up keyboard emulator and set pin modes
void setup()
{
    Keyboard.begin();
    pinMode(modeSwitch, INPUT);
    pinMode(buttonOne, INPUT);
    pinMode(buttonTwo, INPUT);
    pinMode(buttonThree, INPUT);


}

//Runs continuously. If program switch is high then the loop does nothing to prevent typeing on the screen when the user is flashing the device.
//If the switch is low then it checks the three buttons.
void loop() {
    if(digitalRead(modeSwitch) == HIGH){
        checkButton(buttonOne);
        checkButton(buttonTwo);
        checkButton(buttonThree);

    }
}

//If a button is pressed then its keyboard macro is called
void checkButton(int button){
    if(digitalRead(button) == HIGH){
        typeMacro(button);
    }
}

//Each case matches a button. 
void typeMacro(int button){
    switch(button){

        case 9:
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press('l');
            Keyboard.releaseAll();
            delay(200);
            break;

        case 8:
            Keyboard.print("               Merry Christmas!");
            
            Keyboard.write(KEY_ENTER);
            Keyboard.write(KEY_ENTER);
            
            Keyboard.print("   I hope you enjoy your gift! I have made all the");
            
            Keyboard.write(KEY_ENTER);

            Keyboard.print("         3D files and code avaible online.");

            Keyboard.write(KEY_ENTER);

            Keyboard.print("        https://github.com/Air0nH/ButtonBox");

            Keyboard.write(KEY_ENTER);

            delay(200);
            break;

        case 7:
             Keyboard.press(KEY_LEFT_GUI);
              Keyboard.press('r');
              Keyboard.releaseAll();
              
              delay(200);
              Keyboard.print("powershell.exe");
              Keyboard.write(KEY_ENTER);
            
            break;
        
    }
}
