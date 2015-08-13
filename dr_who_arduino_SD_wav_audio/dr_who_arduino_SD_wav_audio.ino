/*

DOCTOR WHO TARDIS WITH 
SD CARD SOUNDS AND LIGHT EFFECT

Chris Garrett
Twitter: @makerhacks @chrisgarrett
HTTP://MAKERHACKS.COM


pro mini
13 orange slk
12 purple miso
11 yellow mosi
10 blue cs

pro micro
15 orange slk
14 purple miso
16 yellow mosi
10 blue cs


*/

// Include the SD library
#include <SD.h>

// use pin 
#define SD_CARD 10  

// This library plays the audio
#include <TMRpcm.h>         

// create an audio object
TMRpcm sample;   

	// LED pin
	int led = 3; 			// the pin that the LED is attached to
	int brightness = 0;    // how bright the LED is
	int fadeAmount = 5;    // how many points to fade the LED by

// runs on startup 
void setup()
{

  // LED
  pinMode(led, OUTPUT); 

  // randomise
  randomSeed(analogRead(0));

  // set the speaker pin 
  sample.speakerPin = 9; 
  
  // see if the card is ok
  if (!SD.begin(SD_CARD)) 
  {  
	 return;   // It's not there, don't do anything
  }

 // quite loud
 sample.volume(9);
 
 // play the start up sound
 sample.play("theme.wav"); 
 
}
 
void loop()
{  

  	// wait until the current sound ends	
	while ( sample.isPlaying() )
	{
          // set the brightness of pin :
          analogWrite(led, brightness);    
        
          // change the brightness for next time through the loop:
          brightness = brightness + fadeAmount;
        
          // reverse the direction of the fading at the ends of the fade: 
          if (brightness == 0 || brightness == 255) 
          {
            fadeAmount = -fadeAmount ; 
          }     
          // wait for 30 milliseconds to see the dimming effect    
          delay(30);                            
        }

	// stopped so play another
	ran();


}

// Currently just picks random
// sound to play
void ran()
{
 	// pick a random number
 	int randNumber = random(12);
 
 // play the randomly picked sound	
 switch (randNumber) {
    case 1:
      sample.play("delete.wav");
      break;
    case 2:
      sample.play("deleted.wav");
      break;
	case 3:   
	  sample.play("emergency.wav");
      break;
	case 4:
	  sample.play("exterminate.wav");
      break;
    case 5:
      sample.play("fantastic.wav");
      break;
    case 6:
      sample.play("firsttakeoff.wav");
      break;
    case 7:
      sample.play("hum.wav");
      break;
    case 8:
      sample.play("obey.wav");
      break;
    case 9:
      sample.play("sonicscrewdriver.wav");
      break;
    case 10:
      sample.play("tardis.wav");
      break;
    case 11:
      sample.play("dontblink.wav");
      break;
    case 12:
      sample.play("doors.wav");
      break;



  }
 	
 

  
}
