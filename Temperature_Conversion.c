// The essential include
#include <stdio.h>

// The formula to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

// The formula to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

// The formula to convert celsius to kelvin
float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

// The formula to convert kelvin to celsius
float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

// The formula to convert fahrenheit to kelvin
float fahrenheit_to_kelvin(float fahrenheit){
    return (fahrenheit - 32) * 5/9 + 273.15;
}

// The formula to convert kelvin to fahrenheit
float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * 9/5 + 32;
}

// The outputs depending what temperature the kevin conversion is
void kelvin_categories(float kelvin){
    // If kelvin is less than 0 degrees celsius
    if (kelvin < 273.15){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    // If kelvin is greater than 0 degrees celsius, but less than 10 degrees celsius
    if (kelvin >= 273.15 && kelvin <= 283.15){
        printf("\nTemperature category: Cold\nWeather advisory: wear a jacket.");
    }
    // If kelvin is greater than 10 degrees celsius, but less than 25 degrees celsius
    if (kelvin >= 283.15 && kelvin <= 298.15){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    // If kelvin is greater than 25 degrees celsius, but less than 35 degrees celsius
    if (kelvin >= 298.15 && kelvin <= 308.15){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    // If kelvin is greater than 35 degrees celsius
    if (kelvin > 308.15){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

// The outputs depending what temperature the fahrenheit conversion is
void fahrenheit_categories(float fahrenheit){
    // If fahrenheit is less than 0 degrees celsius
    if (fahrenheit < 32){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    // If fahrenheit is greater than 0 degrees celsius, but less than 10 degrees celsius
    if (fahrenheit >= 32 && fahrenheit <= 50){
        printf("\nTemperature category: Cold\nWeather advisory: Wear a jacket.");
    }
    // If fahrenheit is greater than 10 degrees celsius, but less than 25 degrees celsius
    if (fahrenheit >= 50 && fahrenheit <= 77){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    // If fahrenheit is greater than 25 degrees celsius, but less than 35 degrees celsius
    if (fahrenheit >= 77 && fahrenheit <= 95){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    // If fahrenheit is greater than 35 degrees celsius
    if (fahrenheit > 95){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

// The outputs depending what temperature the celsius converison is
void celsius_categories(float celsius){
    // If celsius is less than 0 degrees
    if (celsius < 0){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    // If celsius is greater than 0 degrees, but less than 10 degrees
    if (celsius >= 0 && celsius <= 10){
        printf("\nTemperature category: Cold\nWeather advisory: Wear a jacket.");
    }
    // If celsius is greater than 10 degrees, but less than 25 degrees
    if (celsius >= 10 && celsius <= 25){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    // If celsius is greater than 25 degrees, but less than 35 degrees
    if (celsius >= 25 && celsius <= 35){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    // If celsius is greater than 35 degrees
    if (celsius > 35){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

// The output function which displays the conversion temperature, the corresponding category, and weather advisory
void output(float temperature, int scale, int convert){
    float celsius, fahrenheit, kelvin;
    // If the scale is celsius and the conversion is fahrenheit
    if (scale == 1 && convert == 2){
        fahrenheit = celsius_to_fahrenheit(temperature);
        printf("\nConverted temperature: %0.2f*F", fahrenheit);
        fahrenheit_categories(fahrenheit);
    }
    // If the scale is celsius and the conversion is kelvin
    if (scale == 1 && convert == 3){
        kelvin = celsius_to_kelvin(temperature);
        printf("\nConverted temperature: %0.2fK", kelvin);
        kelvin_categories(kelvin);
    }
    // If the scale is fahrenheit and the conversion is celsius
    if (scale == 2 && convert == 1){
        celsius = fahrenheit_to_celsius(temperature);
        printf("\nConverted temperature: %0.2f*C", celsius);
        celsius_categories(celsius);
    }
    // If the scale is fahrenheit and the conversion is kelvin
    if (scale == 2 && convert == 3){
        kelvin = fahrenheit_to_kelvin(temperature);
        printf("\nConverted temperature: %0.2fK", kelvin);
        kelvin_categories(kelvin);
    }
    // If the scale is kelvin and the conversion is celsius
    if (scale == 3 && convert == 1){
        celsius = kelvin_to_celsius(temperature);
        printf("\nConverted temperature: %0.2f*C", celsius);
        celsius_categories(celsius);
    }
    // If the scale is kelvin and the conversion is fahrenheit
    if (scale == 3 && convert == 2){
        fahrenheit = kelvin_to_fahrenheit(temperature);
        printf("\nConverted temperature: %0.2f*F", fahrenheit);
        fahrenheit_categories(fahrenheit);
    }
}

// The main function of the c program (required)
int main(){
    // Initalizing starting variables
    float temperature;
    int scale, convert;
    // Gets the starting temperature from the user
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    // Gets the current scale from the user
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &scale);
    // Error checking: checks if the scale is kelvin and the temperature is negative
    // If true, the program displays the error and the user is asked to try again
    // Otherwise, continues through the process
    if (temperature < 0 && scale == 3){
        printf("Invalid temperature value for Kelvin. Please try again.\n\n");
        main();
    }
    else{
        // Gets the conversion scale from the user
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &convert);
        // Error checking: Checks if the conversion scale is the same as the current scale
        // If true, the program displays the error and the user is asked to try again
        // Otherwise, continues through the program
        if (scale == convert){
            printf("Invalid conversion choices. Please try again.\n\n");
            main();
        }
        else{
            // If there were no errors, the program outputs the results to the user
            output(temperature, scale, convert);
        }
    }
    return 0;
}