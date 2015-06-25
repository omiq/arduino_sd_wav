// Include SPI library
#include <SPI.h>


// Include the SD library
#include <SD.h>

// use SD Card pin 
#define SD_CARD 10  

// This library plays the audio
#include <TMRpcm.h>         

// create an audio object
TMRpcm sample;   


// runs on startup 
void setup(){

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
 sample.volume(6);
 
 // play the start up sound
 sample.play("theme.wav"); 
 

}
 
void loop(){  

	// wait until the current sound ends	
	while ( sample.isPlaying() )
	{
		// do nothing
	}
 
 	// pick a random number
 	int randNumber = random(12);
 
 // play the randomly picked sound	
 switch (randNumber) {
    case 1:
      //sample.play("delete.wav");
      break;
    case 2:
      //sample.play("deleted.wav");
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
