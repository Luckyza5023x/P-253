//  including ezbutton module (easy button module)
#include<ezButton.h>

//  connect both buttons to pin 4 and 22
const int button1 = 4;
const int button2 = 22;

//  defining a variable to track count of button press
int count = 0;

//  creating button objects
ezButton push_button1(button1);
ezButton push_button2(button2);

void setup()
{
  //  change the baud rate to 9600 if required
  Serial.begin(115200);
  
  //  set debounce time for both the button objects
  pinMode(RELAY_PIN, OUTPUT); 
  button.setDebounceTime(50);

}

void loop()
{
  //  loop both the push_buttons : continuous polling
  button.loop();


  //  check if push_button1 is pressed : store the button push count into count variable
  if (push_button1.isPressed())
  {
    Serial.println("The button is pressed");
   
    relay_state = !relay_state;

    digitalWrite(RELAY_PIN, relay_state);
  }

  //  else if push_button2 is pressed : print the table of the number stored in variable count
  else if (push_button2.isPressed())
  {
    //  draft a loop to print the table
    Serial.println(count);
    Serial.print("Table of ");

     for (int i = 1; i <= 10; i++)
    {
      Serial.print(count);
    }

    //  reset the number to 0, once table is printed
    count = 0;
  }
 
}
