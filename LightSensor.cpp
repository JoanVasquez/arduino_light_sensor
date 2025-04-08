// 🌟 Separación de responsabilidades con un patrón tipo MVC simple

// 📦 --- Modelo: Lógica del sensor ---
class SensorService {
    int pin; // 📍 Pin donde está conectado el sensor
  public:
    // 🛠️ Constructor: inicializa el pin como entrada
    SensorService(int sensorPin) {
      pin = sensorPin;
      pinMode(pin, INPUT); // 🎛️ Configura el pin como entrada
    }
  
    // 📏 Método para leer el valor analógico del sensor
    int read() {
      return analogRead(pin); // 🔍 Devuelve el valor leído del sensor
    }
  };
  
  // 🧠 --- Controlador: Control del actuador ---
  class ActuatorController {
    int pin; // 📍 Pin donde está conectado el actuador (ej. LED)
  public:
    // 🛠️ Constructor: inicializa el pin como salida
    ActuatorController(int outputPin) {
      pin = outputPin;
      pinMode(pin, OUTPUT); // 💡 Configura el pin como salida
    }
  
    // ✅ Método para encender el actuador
    void turnOn() {
      digitalWrite(pin, HIGH); // 🔌 Enciende el dispositivo
    }
  
    // ❌ Método para apagar el actuador
    void turnOff() {
      digitalWrite(pin, LOW); // 🔕 Apaga el dispositivo
    }
  };
  
  // 🔗 --- Instancias globales ---
  SensorService lightSensor(A2);        // 📥 Sensor conectado al pin A2
  ActuatorController ledActuator(0);   // 💡 LED conectado al pin digital 0
  
  void setup() {
    // ⚙️ Todo se configura automáticamente desde los constructores
  }
  
  void loop() {
    int value = lightSensor.read(); // 📋 Lee el valor del sensor
  
    // 🧪 Verifica si el valor leído es menor a 200
    if (value < 200) {
      ledActuator.turnOn(); // 🔆 Enciende el LED si hay poca luz
    } else {
      ledActuator.turnOff(); // 🌑 Apaga el LED si hay suficiente luz
    }
  
    delay(10); // ⏱️ Pequeña pausa para estabilidad
  }
  