# corona project
Controls the humidity and UVC (ultra violet germicidal)  light over the internet to sanitize our home and working  places and reduce the risk of covid-19.


![calciHtmlLogo](photos/1.PNG)

# Story
1. **Introduction** 
1) In more humid condition the droplets containing virus come from sneezing or coughing come down to floor quickly and within few minutes drop containing virus settle to floor and hence virus transmission reduces so much.
But in low humidity condition the drops containing the virus long last about hours.
 2) UV light has been used for years to kill bacteria and viruses and ultraviolet light has been used as a disinfectant for a century in hospitals and water supplies. It shatters the genetic material inside viruses, bacteria and other microbes. Menachery said, and disinfecting UV light can’t be used with people around because it damages human cells.

As it damage human cells so it should not be used in presence of human but we can use it over the internet to make our home and working places sanitize and reduce the risk of covid-19 without our presence at that place.
UV light is lethal to viruses because of its high frequency that scramble and damage their nuclear material .when it damage the DNA (or RNA) codes of these pathogens it also trigger lethal mutation that prevent them from reproducing themselves.



**Reference**:
1. What the structure of the coronavirus can tell us(By Bonnie Berkowitz, Aaron Steckelberg and John Muyskens March 23, 2020
https://www.washingtonpost.com/graphics/2020/health/coronavirus-sars-cov-2-structure/
2. Does UV Light Kill Viruses and Germs?( MAR. 19, 2020)
(By Liza Corsillo) https://nymag.com/strategist/article/does-uv-light-kill-germs-best-sterilizer.html


**Demonstration** 
1.	Checking humidity reading from Bolt android app.               
2.	Controlling humidity and UV light over the internet.



# Things used in this project
Hardware components
1. Bolt IOT Wi-Fi module
2. Arduino Uno
3. Relay (2)
4. Breadboard
5. Humidity sensor (DHT11)
6. Humidity maker
7. Exhaust fan
8.  UVC (ultra violet germicidal)


**Software/apps and online services**
1. Bolt IOT android app
2. Fritzing 
3. Webpage(our web application)





# Steps for building the project
**1.	Connecting bolt Wi-Fi module with arduino**
To connect bolt device to arduino first install the Bolt arduino helper library in arduino IDE you may check the complete guide on this link https://docs.boltiot.com/docs/arduino-library.

Now connections 

      Bolt device    arduino
        Tx---->       Rx(D0)
        Rx---->       Tx(D1)
        5V---->       5V
        GND--->       GND

**2.	Getting humidity reading from arduino**
To get humidity value we use DHT11 sensor and connect to arduino digital pin 2 to take the value as it gives value in digital output.
Library installation

To use DHT11 we have to use install a library in arduino IDE 
1.	 Open arduino IDE and Click on 
Sketch -> Include Library ->Manage Libraries
2.	 Install the library 


**Connections**

                    DHT11          arduino
          Output (DATA)   ---->    pin2 (D2)
          Power pin (VDD) ---->    5V 
          GND             ---->    GND

Connect power pin of DHT11 to 5V and GND to GND.
And we use the code below to get humidity value and send it to bolt cloud with help of the command boltiot.processPushDataCommand()


**3.	Configure the bolt cloud and product**

Go to bolt cloud and select a new product of UART and input device.
Now set the product as below

Now chose file extention as Js and code as below

                setChartLibrary('google-chart');
                setChartTitle('Humidity Monitring');
                setChartType('lineGraph');
                setAxisName('time','humidity');
                plotChart('time_stamp','humidity');
Now cloud is ready to use and to plot the humidity with time.
