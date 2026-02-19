/**
 * @file DHT11_Monitor.ino
 * @author Ashish Kumar Yadav
 * @date 2026-02-20
 * @version 1.0
 *
 * @brief Reads temperature and humidity from DHT11 sensor.
 *
 * @details
 * This program initializes a DHT11 temperature and humidity sensor
 * connected to digital pin 2. It reads humidity (%) and temperature (°C)
 * values and prints them to the Serial Monitor.
 *
 * Sensor: DHT11
 * Communication: Single-wire digital
 *
 * @note
 * Ensure the DHT11 data pin is connected to digital pin 2.
 *
 * @warning
 * Frequent readings faster than 1 second may cause unstable results.
 */

#include <Arduino.h>
#include <DHT.h>

/** @brief Digital pin connected to DHT11 data line */
#define DHTPIN 2

/** @brief DHT sensor type */
#define DHTTYPE DHT11

/**
 * @brief Create DHT sensor object.
 */
DHT dht(DHTPIN, DHTTYPE);


/**
 * @brief Initializes serial communication and DHT sensor.
 */
void setup()
{
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 Sensor Initialized");
}


/**
 * @brief Main loop function.
 *
 * @details
 * Reads humidity and temperature from the DHT11 sensor.
 * If reading fails, prints error message.
 */
void loop()
{
    float humidity = dht.readHumidity();        ///< Read humidity (%)
    float temperature = dht.readTemperature();  ///< Read temperature (°C)

    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %  | ");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(1500);
}





