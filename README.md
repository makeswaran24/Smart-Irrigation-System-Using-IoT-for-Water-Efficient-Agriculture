# Smart-Irrigation-System-Using-IoT-for-Water-Efficient-Agriculture
The Smart Precision Irrigation System Using IoT for Water-Efficient Agriculture  automates irrigation by managing two water sources, borewell and rainwater. 
This ensures a continuous and efficient water supply for crops.The system uses an ESP8266 microcontroller connected with ultrasonic sensors to monitor water levels in the tank.
It also has a DHT11 sensor to measure temperature and humidity, and a soil moisture sensor to check how dry the soil is. 
Based on real-time sensor data, the system favors borewell water for irrigation and switches to the rainwater tank when the borewell level drops below a certain point. Motor operations are controlled through relays.
All key parameters are sent to the Adafruit IO cloud platform, allowing for remote monitoring and data analysis.
This IoT-based method reduces manual work, saves water, and supports sustainable farming through smart, data-driven irrigation management. 
The system is a cost-effective and scalable solution for both small and large farms. 
It helps farmers make better decisions by showing live data and trends over time. Cloud monitoring increases transparency and accessibility from anywhere. 
The project also encourages using renewable rainwater resources to reduce groundwater depletion. 
Overall, it shows how IoT can transform modern agriculture by improving water use and crop productivity.
OBJECTIVE
To develop an IoT-based smart irrigation system for efficient farm management.
To monitor soil moisture levels in real time using sensors and IoT connectivity.
To regulate water flow automatically based on soil moisture data.
To reduce water wastage and enhance overall water usage efficiency for crops.
<img width="1436" height="322" alt="image" src="https://github.com/user-attachments/assets/473a4f88-fe67-43c2-9717-62a7122e69fc" />
PROPOSED APPROACH
STEP 1 : SYSTEM INITIALIZATION
Configure ESP8266 I/O pins for ultrasonic sensors (TRIG/ECHO), relay and servos, initialize Serial communication and DHT11 sensor for temperature acquisition.
STEP 2  : WATER LEVEL SENSING
Acquire distance measurements from Tank1 and Tank2 using HC-SR04 ultrasonic sensor & convert pulse duration to actual distance in centimeters.
STEP 3 : ENVIRONMENTAL DATA ACQUISTION
Read ambient temperature from DHT11 sensor (digital signal) and soil moisture from analog input (A0).
STEP 4: SIGNAL PROCESSING AND CONVERSION
Process ultrasonic echo times to distances, read temperature in °C, and scale analog soil moisture values for comparison.
STEP 5 : THRESHOLD EVALUATION
If Tank1 < WATER_THRESHOLD ,Temp > TEMP_THRESHOLD , Soil < POT_THRESHOLD → Relay ON, DCMOTOR1 ON, DCMOTOR2 OFF 
If Tank2 < WATER_THRESHOLD , Temp > TEMP_THRESHOLD , Soil < POT_THRESHOLD → Relay ON, DCMOTOR2 ON, DCMOTOR1 ON .
Otherwise → Relay OFF BOTH  Motors OFF
STEP 6 :MONITORING 
 Log sensor readings and actuator states via  UART for real-time monitoring .
<img width="2798" height="714" alt="image" src="https://github.com/user-attachments/assets/d09818ee-8ed4-462d-888b-d89bda763069" />
SYSTEM DESIGN 
<img width="1781" height="897" alt="image" src="https://github.com/user-attachments/assets/43ac625d-d186-4036-83ee-a8a1172362bd" />
Tank2 active, Servo1 ON, irrigation running


<img width="1359" height="752" alt="image" src="https://github.com/user-attachments/assets/17def952-f1dd-4d8a-8601-7a02f138a3e7" />




<img width="1547" height="897" alt="image" src="https://github.com/user-attachments/assets/47559297-5876-41a3-a511-4111408b11b9" />
