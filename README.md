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
* To develop an IoT-based smart irrigation system for efficient farm management.
* To monitor soil moisture levels in real time using sensors and IoT connectivity.
* To regulate water flow automatically based on soil moisture data.
* To reduce water wastage and enhance overall water usage efficiency for crops.
PROPOSED APPROACH
### **System Operation Steps**

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

  ----

SYSTEM DESIGN 
<img width="1781" height="897" alt="image" src="https://github.com/user-attachments/assets/43ac625d-d186-4036-83ee-a8a1172362bd" />
---


RESULT
<img width="850" height="626" alt="image" src="https://github.com/user-attachments/assets/9e420a61-6de3-4eea-b040-1099d97bdca2" />


<img width="738" height="626" alt="image" src="https://github.com/user-attachments/assets/be98ddb5-978b-4986-8e06-248eba11e716" />


<img width="825" height="747" alt="image" src="https://github.com/user-attachments/assets/9a752283-133a-4842-9db4-5034fbda3501" />

<img width="762" height="746" alt="image" src="https://github.com/user-attachments/assets/530742d9-56cb-49f2-a829-7450b6687643" />

###  **CHALLENGES SOLVED**

* **Water Level Monitoring** → Ultrasonic sensors prevent tank overflow and dry run.
* **Soil Moisture Control** → Potentiometer ensures irrigation occurs only when needed.
* **Temperature-Based Irrigation** → DHT11 sensor prevents crop stress during high heat.
* **Automation** → Relay and servo mechanisms eliminate the need for manual control.
* **Dual Tank Management** → Enables independent operation of two separate water sources.
* **Real-Time Monitoring** → Adafruit IO dashboard provides live sensor data and irrigation status remotely.
* Here’s your content formatted clearly as **applications of the smart irrigation system** 👇

---

### **APPLICATIONS**

* **Agricultural Fields** – Automatically waters crops based on soil moisture and weather conditions, reducing water wastage.
* **Greenhouses** – Maintains ideal moisture levels for plants through automatic irrigation control.
* **Gardens and Lawns** – Helps households and parks save water by watering plants only when required.
* **Smart Villages** – Enables rural areas to automate irrigation and improve water resource management.
* **Plant Nurseries** – Ensures healthy plant growth through precise and timely irrigation.
* **Government and Community Projects** – Supports sustainable farming and water conservation initiatives.

---








