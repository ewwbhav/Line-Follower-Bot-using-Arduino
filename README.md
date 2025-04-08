# 🛣️ Line Follower Robot — Team Trace X

We, the team **"Trace X"**, have developed a fully functional **Line Follower Robot** using an **Arduino Uno**, **L293D motor driver**, **QTR-8A sensor array**, and **N20 gear motors**. The robot is capable of smooth line following using a **PID control algorithm** and can handle complex junctions such as **T-junctions**, **crossroads**, and **left/right turns**. 

> 🔋 An additional **TP4056 charging module** has been used to recharge the **7.4V Lithium-ion battery** powering the system.

All hardware connections, the circuit diagram, and workflow are documented in the file:  
📄 **`TraceX-line Follower.doc`**

---

## 🚀 Features

- ✅ Smooth PID-based line following
- ✅ Analog QTR-8A sensor array for precision tracking
- ✅ Junction detection: T, X, Left, and Right
- ✅ Real-time proportional motor speed adjustment
- ✅ Compact, efficient, and optimized for competition
- ✅ Built using Arduino Uno and L293D (no motor shield)

---

## 🧰 Hardware Components

| Component                      | Quantity |
|-------------------------------|----------|
| Arduino Uno                   | 1        |
| L293D Motor Driver IC         | 1        |
| N20 Gear Motors               | 2        |
| QTR-8A Analog IR Sensor Array | 1        |
| TP4056 Charging Module        | 1        |
| Li-ion Battery Pack (7.4V)    | 1        |
| Robot Chassis, Wheels, Mounts | 1 set    |

---

## 🛠️ Software & Dependencies

- Arduino IDE (any version)
- Core libraries:
  - ✅ `AFMotor` (for motor control, if using shield)
  - ✅ `QTRSensors` by Pololu (for reading QTR sensor)

### 📥 Installing Required Libraries

In Arduino IDE:
1. Go to `Sketch > Include Library > Manage Libraries`
2. Search for and install:
   - `"Adafruit Motor Shield library"` by Adafruit
   - `"QTRSensors"` by Pololu

---

## 📐 Track Specifications

- Background: **White**
- Line color: **Black**
- Line width: ~**3 cm**
- Includes: **Curves, T-junctions, crossroads, L/R branches**

---

## 🧠 How It Works

1. QTR-8 sensors detect the reflected IR value from the line.
2. Analog values are processed to determine position error.
3. A custom PID controller calculates the correction.
4. Motor speeds are adjusted in real time to keep the robot centered on the line.
5. Additional junction detection logic triggers decision-making at intersections.

---

## 📹 Demo Video

🎥 [Watch the test video](https://drive.google.com/file/d/15DaXyZ0le-dNE7H-1j3aGisXQl89BcCx/view?usp=sharing)

---

## 🧾 Documentation

📄 Full workflow, circuit diagram, and assembly:  
**`TraceX-line Follower.doc`**

💻 Arduino Code:  
**`Linefollower_code.ino`**

---

## 📎 License

This project is licensed under the **MIT License** — feel free to use, modify, and distribute.

---

## 🙌 Team & Credits

Project by **Team Trace X**  
Code & documentation by: [@ewwbhav](https://github.com/ewwbhav)  
Special thanks to:
- The Arduino open-source community
- Adafruit & Pololu libraries

---

Let me know if you'd like to embed images, circuit diagrams, or generate a pretty header badge/logo next!
