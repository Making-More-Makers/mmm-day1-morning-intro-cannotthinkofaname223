  // Project - Traffic light
  
int carRed = 12;    // Pin for the car's red light  
int carYellow = 11; // Pin for the car's yellow light  
int carGreen = 10;  // Pin for the car's green light  
int button = 9;     // Pin connected to the button  
int pedRed = 8;     // Pin for the pedestrian's red light  
int pedGreen = 7;   // Pin for the pedestrian's green light  
int crossTime = 5000; 
// Time allowed for pedestrians to cross in milliseconds  
unsigned long changeTime; // Timestamp of the last button press  

void setup() {
  // Initialize pin modes  
    pinMode(carRed, OUTPUT);  
    pinMode(carYellow, OUTPUT);  
    pinMode(carGreen, OUTPUT);  
    pinMode(pedRed, OUTPUT);  
    pinMode(pedGreen, OUTPUT);  
    pinMode(button, INPUT); // Set the button pin to INPUT mode  
  
    // Set initial light states  
    digitalWrite(carGreen, HIGH); // Turn on the car's green light  
digitalWrite(pedRed, HIGH);   
// Turn on the pedestrian's red light
}

void loop() {
 int state = digitalRead(button); // Read the state of the button  
    /* Check if the button is pressed (assuming LOW is pressed) and enough time has elapsed  */
    if (state == HIGH && (millis() - changeTime) > 5000) {  
        // Call the function to change the lights  
        changeLights(); 
    }
}

void changeLights() {  
    // Change the car's green light to yellow  
    digitalWrite(carGreen, LOW);  
    digitalWrite(carYellow, HIGH);  
    delay(2000); // Wait for 2 seconds  
  
    // Change the car's yellow light to red  
    digitalWrite(carYellow, LOW);  
    digitalWrite(carRed, HIGH);  
    delay(1000); // Wait for an additional 1 second for safety  
  
    // Change the pedestrian's red light to green  
    digitalWrite(pedRed, LOW);  
    digitalWrite(pedGreen, HIGH);  
  
    /* Keep the pedestrian's green light on for crossTime milliseconds  */
    delay(crossTime);  
  
    /*Flash the pedestrian's green light to indicate time is running out  */
    for (int x = 0; x < 10; x++) {  
        digitalWrite(pedGreen, HIGH);  
        delay(250);  
        digitalWrite(pedGreen, LOW);  
        delay(250);  
    }  
  
    // Turn the pedestrian's red light back on  
    digitalWrite(pedRed, HIGH);  
    delay(500); // Optional delay for stability  
  
    // Restore the car's lights to green (via yellow)  
    digitalWrite(carRed, LOW);  
    digitalWrite(carYellow, HIGH);  
    delay(1000);  
    digitalWrite(carYellow, LOW);  
    digitalWrite(carGreen, HIGH);  
  
    // Update the timestamp of the last button press  
    changeTime = millis();  
}
