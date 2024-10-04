#include <stdio.h>

float celsius_to_fahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

float celsius_to_kelvin(float celsius){
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin){
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit){
    return (fahrenheit - 32) * 5/9 + 273.15;
}

float kelvin_to_fahrenheit(float kelvin){
    return (kelvin - 273.15) * 9/5 + 32;
}

void kelvin_categories(float kelvin){
    if (kelvin < 273.15){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    if (kelvin >= 273.15 && kelvin <= 283.15){
        printf("\nTemperature category: Cold\nWeather advisory: wear a jacket.");
    }
    if (kelvin >= 283.15 && kelvin <= 298.15){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    if (kelvin >= 298.15 && kelvin <= 308.15){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    if (kelvin > 308.15){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

void fahrenheit_categories(float fahrenheit){
    if (fahrenheit < 32){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    if (fahrenheit >= 32 && fahrenheit <= 50){
        printf("\nTemperature category: Cold\nWeather advisory: Wear a jacket.");
    }
    if (fahrenheit >= 50 && fahrenheit <= 77){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    if (fahrenheit >= 77 && fahrenheit <= 95){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    if (fahrenheit > 95){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

void celsius_categories(float celsius){
    if (celsius < 0){
        printf("\nTemperature category: Freezing\nWeather advisory: Brrrr...its absolutely freezing!");
    }
    if (celsius >= 0 && celsius <= 10){
        printf("\nTemperature category: Cold\nWeather advisory: Wear a jacket.");
    }
    if (celsius >= 10 && celsius <= 25){
        printf("\nTemperature category: Comfortable\nWeather advisory: You should feel comfortable.");
    }
    if (celsius >= 25 && celsius <= 35){
        printf("\nTemperature category: Hot\nWeather advisory: The sun is out.");
    }
    if (celsius > 35){
        printf("\nTemperature category: Extreme Heat\nWeather advisory: Time to fry some eggs.");
    }
}

void output(float temperature, int scale, int convert){
    float celsius, fahrenheit, kelvin;
    if (scale == 1 && convert == 2){
        fahrenheit = celsius_to_fahrenheit(temperature);
        printf("\nConverted temperature: %0.2f*F", fahrenheit);
        fahrenheit_categories(fahrenheit);
    }
    if (scale == 1 && convert == 3){
        kelvin = celsius_to_kelvin(temperature);
        printf("\nConverted temperature: %0.2fK", kelvin);
        kelvin_categories(kelvin);
    }
    if (scale == 2 && convert == 1){
        celsius = fahrenheit_to_celsius(temperature);
        printf("\nConverted temperature: %0.2f*C", celsius);
        celsius_categories(celsius);
    }
    if (scale == 2 && convert == 3){
        kelvin = fahrenheit_to_kelvin(temperature);
        printf("\nConverted temperature: %0.2fK", kelvin);
        kelvin_categories(kelvin);
    }
    if (scale == 3 && convert == 1){
        celsius = kelvin_to_celsius(temperature);
        printf("\nConverted temperature: %0.2f*C", celsius);
        celsius_categories(celsius);
    }
    if (scale == 3 && convert == 2){
        fahrenheit = kelvin_to_fahrenheit(temperature);
        printf("\nConverted temperature: %0.2f*F", fahrenheit);
        fahrenheit_categories(fahrenheit);
    }
}

int main(){
    float temperature;
    int scale, convert;
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &scale);
    if (temperature < 0 && scale == 3){
        printf("Invalid temperature value for Kelvin. Please try again.\n\n");
        main();
    }
    else{
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &convert);
        if (scale == convert){
            printf("Invalid conversion choices. Please try again.\n\n");
            main();
        }
        else{
            output(temperature, scale, convert);
        }
    }
    return 0;
}