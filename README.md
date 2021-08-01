# 310992_EMBEDDED_CASESTUDY

# CAR HEATER APPLICATION USING ATMEGA 328

## Badges
| Badge Name | Status |
|----|----|
|Build|[![Compile-Linux](https://github.com/Mazude/310992_EmbeddedC_CaseStudy/actions/workflows/Compile.yml/badge.svg)](https://github.com/Mazude/310992_EmbeddedC_CaseStudy/actions/workflows/Compile.yml)
|Cppcheck|[![Cppcheck](https://github.com/Mazude/310992_EmbeddedC_CaseStudy/actions/workflows/cpp_check.yml/badge.svg)](https://github.com/Mazude/310992_EmbeddedC_CaseStudy/actions/workflows/cpp_check.yml)
|Code Quality Score|
|Code Grade|
## Design Approach
| Requirement |Implementation Idea |
|-------------|------------------------|
| Considering the design specifications, it's clear that the application runs only based on the Passenger sitting on the seat and switching on the heater system | Connecting the sensors of the two condtions to the Microcontroller. Implemented this using a `PIN CHANGE Interrput` to check if there is any change in these two sensor readings as they drive rest of the functionalities, and setting a flag to TRUE if both are satisfied |    
| Taking the ADC input Continuously as the user can opt to set the temperature at any time | Starting the ADC based on the set flag condition being TRUE. Then Handling rest of the features in `ADC Conversion Complete Interrupt` as if there is an ADC Conversion we need to perform the display and send data functions |
| Displaying the Input ADC values as PWM to the Oscilloscope | Intiazling the  Fast PWM Generation in 10-bit mode using Timer 1 inside the `ADC Conversion Complete Interrupt` as we need to display continuously. Setting the PWM Duty based on the range of ADC value |  
| Sending the Temperature set data serially | Implementing a USART protocol to serially transmit data based on the set temperature range done in the `ADC Conversion Complete Interrupt` as we need to display continuously based on user input | 

## Operation 

### Pin Configuration 

*   Using Atmega328 as the Microcontroller for implementing the Functionalities.
*   Pins and the peripherals connected to it

| PIN | Connected Peripheral | Direction of PIN |
|-----|----------------------|------|
| PIN B0 | LED Actuator (Indicator LED) | Output |
| PIN B1 | Pulse Width Modulation Wave | Output |
| PIN B3 | Sensor for Passenger Seated | Input |
| PIN B4 | Switch for Heating System | Input |
| PIN C0 | Set Temperature using ADC | Input |

### Simulation Circuit
![Circuit Diagram](https://user-images.githubusercontent.com/69196622/127559466-ebb01750-01c6-4cd2-ac4c-f6ce31558199.JPG)


*   Passenger is not Seated and Heating System is OFF 
![Case1](https://user-images.githubusercontent.com/69196622/127559005-15d5cec8-92a9-4f26-9fb9-905db64649b9.JPG)


*   Passenger is Seated and Heating System is OFF
![Case2](https://user-images.githubusercontent.com/69196622/127558820-ceadbbae-d567-4a8a-ba9a-e8da6a7d104e.JPG)

*   Passenger is not Seated and Heating System is ON
![Case3](https://user-images.githubusercontent.com/69196622/127559152-87541a14-1b99-4107-82dd-fb3e5c5236b7.JPG)


*   Passenger is Seated and Heating System is ON
![Case4](https://user-images.githubusercontent.com/69196622/127559252-5bcce283-d591-418e-9262-2e88aa91f3fe.JPG)


*   System is running and suddenly one of the Condition Fails


### Functionality Check

*   **CASE-A :** Initial Conditions are True and ADC Input is in the range \[1 - 200\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 20%, Temperature - 20 C | ![CaseA](https://user-images.githubusercontent.com/69196622/127559296-73add209-1110-425f-8a74-39cdac1ea957.JPG)|
 

*   **CASE-2 :** Initial Conditions are True and ADC Input is in the range \[210 - 500\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 40%, Temperature - 25 C | ![CaseB(40 C)](https://user-images.githubusercontent.com/69196622/127559397-fc9e31f7-617a-4311-b7c3-d241b485c726.JPG)|
 

*   **CASE-3 :** Initial Conditions are True and ADC Input is in the range \[510 - 700\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 70%, Temperature - 29 C | ![CaseC(29 C)](https://user-images.githubusercontent.com/69196622/127559418-087afa87-1341-45f2-860f-e95f52016739.JPG)|
 

*   **CASE-4 :** Initial Conditions are True and ADC Input is in the range \[710 - 1023\]

| Expected Output | Simulation Output |
|-----------------|-------------------|
| LED Actuator- ON, PWM Output - 95%, Temperature - 33 C |![CaseD(33 C)](https://user-images.githubusercontent.com/69196622/127559439-1f92032f-bdd7-49b4-b744-2fcf3f46a7c0.JPG)|
  
