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

**OBJECTIVE**
* To develop an IoT-based smart irrigation system for efficient farm management.
* To monitor soil moisture levels in real time using sensors and IoT connectivity.
* To regulate water flow automatically based on soil moisture data.
* To reduce water wastage and enhance overall water usage efficiency for crops.


  ----

**SYSTEM DESIGN**
<img width="1781" height="897" alt="image" src="https://github.com/user-attachments/assets/43ac625d-d186-4036-83ee-a8a1172362bd" />

**Step 1: System Initialization**

* Configure ESP8266 I/O pins for ultrasonic sensors (TRIG/ECHO), relay, and servo motors.
* Initialize Serial communication and DHT11 sensor for temperature acquisition.

**Step 2: Water Level Sensing**

* Measure the water levels in Tank 1 and Tank 2 using the HC-SR04 ultrasonic sensors.
* Convert the pulse duration into actual distance (in centimeters).

**Step 3: Environmental Data Acquisition**

* Read ambient temperature from the DHT11 sensor (digital).
* Measure soil moisture through the analog input pin (A0).

**Step 4: Signal Processing and Conversion**

* Process ultrasonic echo times to compute distance.
* Convert temperature readings to °C and scale analog soil moisture values for comparison.

**Step 5: Threshold Evaluation and Control Action**

* If **Tank 1 < WATER_THRESHOLD**, **Temp > TEMP_THRESHOLD**, and **Soil < POT_THRESHOLD** → **Relay ON**, **DC Motor 1 ON**, **DC Motor 2 OFF**.
* If **Tank 2 < WATER_THRESHOLD**, **Temp > TEMP_THRESHOLD**, and **Soil < POT_THRESHOLD** → **Relay ON**, **DC Motor 2 ON**, **DC Motor 1 OFF**.
* Otherwise → **Relay OFF**, **Both Motors OFF**.

---


RESULT
---
•	The entire configuration of electronic components used to monitor and regulate water levels in two distinct tanks, as well as environmental factors like soil moisture and temperature, is depicted in the hardware setup in Figure 4.4. The ESP8266 NodeMCU is the system's main controller and acts as its main processing and decision-making component.

•	To continuously measure the water levels in Tanks 1 and 2, two HC-SR04 Ultrasonic Sensors are placed at the top of each tank. Each sensor uses TRIG and ECHO pins to function. The ESP8266 sends out ultrasonic pulses and uses the echo return time to determine the water level. A soil moisture sensor is attached to the A0 analog input pin, and a DHT11 sensor is used in conjunction with the system to measure the ambient temperature.



<img width="850" height="626" alt="image" src="https://github.com/user-attachments/assets/9e420a61-6de3-4eea-b040-1099d97bdca2" />


•This illustrates the overall wiring and signal connections between the sensors, actuators, and the ESP8266 microcontroller used in the Dual Tank Management System. Each tank is equipped with an HC-SR04 ultrasonic sensor, whose TRIG and ECHO pins are connected to the digital GPIO pins of the ESP8266 for accurate water-level measurement. The DHT11 sensor is connected to provide real-time temperature readings, while the soil moisture sensor is interfaced through the analog input pin (A0) of the controller.


•	A relay module is used to control the power supply to the two DC motors, where Motor 1 pumps water to Tank 1 and Motor 2 supplies water to Tank 2. The ESP8266 sends switching signals to the relay based on sensor inputs, ensuring that water is pumped only when required. Power connections are shared through a regulated 5V supply line to maintain stable operation.

<img width="738" height="626" alt="image" src="https://github.com/user-attachments/assets/be98ddb5-978b-4986-8e06-248eba11e716" />

•	The Adafruit IO dashboard displays live sensor values such as soil moisture, temperature, humidity, and water level, allowing the user to observe the field conditions continuously from anywhere.

•	Interactive widgets like gauges, charts, and toggle switches enable the user to both monitor data trends and manually control the irrigation pump if needed, making the system flexible and user-friendly.

•	By viewing real-time updates on the dashboard, farmers can make quick and informed decisions, reducing water wastage and improving crop health through data-driven irrigation management.

<img width="825" height="747" alt="image" src="https://github.com/user-attachments/assets/9a752283-133a-4842-9db4-5034fbda3501" />

<img width="762" height="746" alt="image" src="https://github.com/user-attachments/assets/530742d9-56cb-49f2-a829-7450b6687643" />

###  **CHALLENGES SOLVED**

* **Water Level Monitoring** → Ultrasonic sensors prevent tank overflow and dry run.
* **Soil Moisture Control** → Potentiometer ensures irrigation occurs only when needed.
* **Temperature-Based Irrigation** → DHT11 sensor prevents crop stress during high heat.
* **Automation** → Relay and servo mechanisms eliminate the need for manual control.
* **Dual Tank Management** → Enables independent operation of two separate water sources.
* **Real-Time Monitoring** → Adafruit IO dashboard provides live sensor data and irrigation status remotely.
---

### **APPLICATIONS**

* **Agricultural Fields** – Automatically waters crops based on soil moisture and weather conditions, reducing water wastage.
* **Greenhouses** – Maintains ideal moisture levels for plants through automatic irrigation control.
* **Gardens and Lawns** – Helps households and parks save water by watering plants only when required.
* **Smart Villages** – Enables rural areas to automate irrigation and improve water resource management.
* **Plant Nurseries** – Ensures healthy plant growth through precise and timely irrigation.
* **Government and Community Projects** – Supports sustainable farming and water conservation initiatives.

---
###  **Alignment with UN Sustainable Development Goals (SDGs)**

* **SDG 2 – Zero Hunger:** Promotes sustainable agriculture and enhances food security.
* **SDG 6 – Clean Water and Sanitation:** Ensures efficient water usage and minimizes wastage.
* **SDG 9 – Industry, Innovation & Infrastructure:** Encourages the integration of IoT technology in modern farming.
* **SDG 11 – Sustainable Cities & Communities:** Supports eco-friendly and water-efficient urban farming practices.
* **SDG 12 – Responsible Consumption & Production:** Promotes efficient resource utilization and reduces waste generation.
* **SDG 13 – Climate Action:** Minimizes environmental impact and fosters climate-resilient agricultural methods.








